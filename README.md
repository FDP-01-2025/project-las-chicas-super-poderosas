🎲 Lane Escape X v1.0: Game introduction

🧩 Description.

Lane Escape X; is an exciting obstacle dodging game inspired by classic console racing games. It is a game of skill and fast reaction, designed for a single player, where the goal is to survive as long as possible by dodging randomly appearing obstacles.

The board consists of a 4-lane road (numbered 0 to 3) with obstacles represented by # falling from the top. The player controls a vehicle (A) that can move between lanes using the A (left) and D (right) keys.

📜 Game Rules
1. Setup:
   - The player starts in the middle lane (position 1) 2.
   - Obstacles appear randomly in the 4 lanes.

2. Controls:
   - A key: Move to the left lane.
   - D key: Move to right lane
   - Q key: Exit the game

3. Dynamics of the game:
   - Each obstacle (#) falls from the top down.
   - The player must avoid the obstacles by changing lanes.
   - If an obstacle hits the player (A), the game ends.

4. Scoring:
   - Each cycle of the game adds 1 point to the score.
   - The speed increases gradually every 50 points
   - The record is automatically saved in "scores.txt".

5. Game End:
   - The game ends when a collision occurs
   - The final score is displayed and the record is saved.

🚀 Technical Features
This repository includes a terminal version of the game with the following features:
- Single player: The goal is to reach the highest score possible.
- Progressive difficulty: The speed increases every 50 points.
- Highscore system: Automatically saves the best scores.


Implementation Notes
- Developed in C++ for terminal
- Uses Windows.h library for console functions
- Modular structure with separation of logic, rendering and utilities
- Compatible with Windows systems (requires MinGW for compilation)

▶How to Play
1. Compile the game: g++ main.cpp src/Game.cpp src/Obstacle.cpp src/Utils.cpp -o game.exe
2. Run: .\game.exe
3. Use A/D keys to avoid obstacles.
4. Press Q to exit at any time

👤Members
- Alvarado Landaverde, Cesar Melquisedec - 00029425
- Banderas Ruiz, Andrés Antonio - 00044125
- Franco Landaverde, Josué Alejandro - 00083825
- González Recinos, Evelyn Sofía - 00181825
