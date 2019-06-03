# 4 players on each team
# 3 rounds: move, dash, shoot
# relay new state to all clients

import random
from time import sleep

class Player:
	initial_positions = []
	
	def __init__(self, name, team):
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
		
	def add_player(self,player):
		self.players.append(player)
	
	def get_move(self):
		sleep(Game.timer)
		for player in self.players:
			# retrieve the position where each player want to move to
			print "Player %s is moving to %s" %(player.name, player.position)
		self.round = "dash"

	def get_shoot_target(self):
		sleep(Game.timer)
		for player in self.players:
			# retrieve the shooting target of each player
			print "Player %s is shooting at %s" %(player.name, player.shoot_target)
		self.round = "shoot"

game_1 = Game("game_1")
player_1 = Player("Sandy", "A team")
player_2 = Player("Charles", "B team")
game_1.add_player(player_1)
game_1.add_player(player_2)
game_1.get_move()
game_1.get_shoot_target()