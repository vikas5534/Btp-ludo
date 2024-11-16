document.addEventListener('DOMContentLoaded', () => {
  const startBtn = document.getElementById('startBtn');
  const rollDiceBtn = document.getElementById('rollDiceBtn');
  const playerCountSelect = document.getElementById('playerCount');
  const ludoBoard = document.getElementById('ludoBoard');

  let players = [];
  let currentPlayer = 0;
  const boardSize = 15;
  const totalCells = boardSize * boardSize;
  const playerPositions = {};

  // Initialize board
  function createBoard() {
    ludoBoard.innerHTML = ''; // Clear the board

    for (let i = 0; i < totalCells; i++) {
      const cell = document.createElement('div');
      cell.classList.add('grid-cell');
      ludoBoard.appendChild(cell);
    }
  }

  // Start the game
  startBtn.addEventListener('click', () => {
    const playerCount = parseInt(playerCountSelect.value);
    players = Array.from({ length: playerCount }, (_, i) => i + 1);
    playerPositions.length = playerCount;
    currentPlayer = 0;

    createBoard();
    placePlayers();
    rollDiceBtn.disabled = false;
    startBtn.disabled = true;
  });

  // Place players on the board
  function placePlayers() {
    players.forEach((player, index) => {
      const cell = document.getElementsByClassName('grid-cell')[index * 2]; // Start at different positions for each player
      const playerPiece = document.createElement('div');
      playerPiece.classList.add('player', `player${player}`);
      cell.appendChild(playerPiece);

      // Save initial positions of players
      playerPositions[player] = [index * 2];
    });
  }

  // Roll Dice
  rollDiceBtn.addEventListener('click', () => {
    const diceRoll = Math.floor(Math.random() * 6) + 1;
    alert(`Player ${currentPlayer + 1} rolled a ${diceRoll}`);
    movePlayer(diceRoll);
  });

  // Move Player based on dice roll
  function movePlayer(diceRoll) {
    const currentPlayerPiece = document.querySelector(`.player${currentPlayer + 1}`);
    const playerPosition = playerPositions[currentPlayer + 1];
    const currentCell = document.getElementsByClassName('grid-cell')[playerPosition[playerPosition.length - 1]];

    currentCell.removeChild(currentPlayerPiece); // Remove player from current cell

    const newPosition = playerPosition[playerPosition.length - 1] + diceRoll;
    playerPosition.push(newPosition);

    // Handle wrapping around the board
    if (newPosition >= totalCells) {
      playerPosition.push(newPosition % totalCells);
    }

    const newCell = document.getElementsByClassName('grid-cell')[newPosition];
    newCell.appendChild(currentPlayerPiece);

    currentPlayer = (currentPlayer + 1) % players.length; // Move to next player
  }
});