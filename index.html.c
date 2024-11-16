<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Ludo Game</title>
  <link rel="stylesheet" href="style.css">
</head>
<body>
  <div class="container">
    <h1>Ludo Game</h1>
    <div class="game-controls">
      <button id="startBtn">Start Game</button>
      <label for="playerCount">Number of Players:</label>
      <select id="playerCount">
        <option value="2">2 Players</option>
        <option value="3">3 Players</option>
        <option value="4">4 Players</option>
      </select>
      <button id="rollDiceBtn" disabled>Roll Dice</button>
    </div>

    <div class="game-board">
      <div id="ludoBoard"></div>
    </div>
  </div>

  <script src="game.js"></script>
</body>
</html>