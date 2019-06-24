# 4 players on each team
# 3 rounds: move, dash, shoot
# relay new state to all clients

import random
import datetime
from time import sleep
from flask import Flask, request, jsonify
from flask_restful import Resource, Api

class Player:
	initial_positions = []
	number_of_players = 0
	
	def __init__(self, name, team):
		Player.number_of_players += 1
		self.id = Player.number_of_players
		self.name = name
		self.team = team
		
		def random_position():
			grid_size = 20
			return [random.randint(0, grid_size - 1), random.randint(0, grid_size - 1)]		
		position = random_position()
		while position in Player.initial_positions:
			position = random_position()
		self.position = position
		Player.initial_positions.append(position)
		
		self.shoot_target = []
		
	def update_position(self, position):
		self.position = position


class Game:
	timer = 2.0
	
	def __init__(self, name):
		self.name = name
		self.round = "move"
		self.players = []
		
	def add_player(self, player):
		self.players.append(player)
		
	def find_player(self, player_id):
		for player in self.players:
			if player.id == player_id:
				return player
	
	def get_move(self):
		positions = {}
		for player in self.players:
			# retrieve the position where each player wants to move to
			positions["player_" + str(player.id)] = player.position
		self.round = "dash"
		return positions

	def get_shoot_target(self):
		sleep(Game.timer)
		for player in self.players:
			# retrieve the shooting target of each player
			print ("Player {} is shooting at {}".format(player.name, player.shoot_target))
		self.round = "shoot"

game_1 = Game("game_1")
player_1 = Player("Sandy", "A team")
player_2 = Player("Charles", "B team")
game_1.add_player(player_1)
game_1.add_player(player_2)
# game_1.get_move()
# game_1.get_shoot_target()

app = Flask(__name__)
api = Api(app)

class Timer(Resource):
	def get(self):
		timer_start = datetime.datetime.utcnow() + datetime.timedelta(seconds = 60)
		return jsonify(timer_start = timer_start.strftime("%Y/%m/%d %H:%M:%S"))

class PositionList(Resource):
	def get(self):
		positions = game_1.get_move()
		return jsonify(positions = positions)
	
	
class Position(Resource):	
	def put(self, id):
		position = request.get_json()['position']
		player = game_1.find_player(id)
		player.update_position(position)
		return ("{} moved to {}".format(player.name, position)) 
        

api.add_resource(Timer, '/timer')
api.add_resource(PositionList, '/positions')
api.add_resource(Position, '/position/player_<int:id>')

if __name__ == '__main__':
    app.run(debug=True)