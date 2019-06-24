# Hurley Server API

### Get the timer start time

**Definition**

`GET /timer`

**Response**

- `200 OK` on success

```json
{
  "timer_start": "2019/06/10 12:10:50"
}
```

### Get the position of all players

**Definition**

`GET /positions`

**Response**

- `200 OK` on success

```json
{
  "positions": {
    "player_1": [
      7,
      2
    ],
    "player_2": [
      0,
      3
    ]
  }
}
```

### Posting a move

**Definition**

`PUT /position/player_<int:id>`

**Arguments**

- `"position":int[]` the pair of coordinates to which the player wants to move to

**Response**

- `201 Created` on success

```json
"player_<int:id>" moved to "position"
```