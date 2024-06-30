<h1>Tic Tac Toe</h1>
A fully functioning tic tac toe game that allows 2 local players to play against each other. <br>
The winning condition is for a player to get 3 of their markers in a row on the grid.

<h2>Controls</h2>
Use WASD to move the selection pointer across the grid and press X to place down a marker.

<h2>Code</h2>
The grid is stored by a 3x3 2D char array (places) intended to hold either 'x' or 'o' to represent the markers of the players. Another 3x3 2d char array (selects) is used to store the position of the pointer on the grid, allowing the player to visually control where to place their markers. <br>
The printGrid() function prints the status of the game, showing each players' markers on the grid. <br>
The placeMarker() first locates the position of the pointer (^) in the selects array and stores its row and column in the selectRow and selectCol variables. It then overwrites '^' to ' ' in preparation for moving to the next position. Player input is handled using the _getch() function and a switch function. WASD allow the selector pointer to move by updating the pointer's row or column in relation to what key was pressed. '^' is then written in the selects array at the pointer's new position. <br> <br>

tbc
