* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}

body {
  font-family: Arial, sans-serif;
  background-color: #f0f0f0;
  display: flex;
  justify-content: center;
  align-items: center;
  height: 100vh;
}

.container {
  text-align: center;
}

h1 {
  margin-bottom: 20px;
}

.game-controls {
  margin-bottom: 20px;
}

#ludoBoard {
  display: grid;
  grid-template-columns: repeat(15, 40px);
  grid-template-rows: repeat(15, 40px);
  gap: 2px;
  margin-top: 20px;
  justify-content: center;
}

.grid-cell {
  width: 40px;
  height: 40px;
  background-color: #e0e0e0;
  display: flex;
  justify-content: center;
  align-items: center;
}

.dice {
  margin: 20px;
  font-size: 2em;
  font-weight: bold;
}

.player {
  border-radius: 50%;
  width: 30px;
  height: 30px;
  background-color: red;
  display: flex;
  justify-content: center;
  align-items: center;
}

.player2 {
  background-color: blue;
}

.player3 {
  background-color: green;
}

.player4 {
  background-color: yellow;
}