#include "Game.h"
#include "Obstacle.h"
#include "Utils.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

void runGame() {
    // Initialize game
    srand(time(NULL));
    hideCursor();
    system("title Lane Escape X");
    system("color 0A");

    // Game variables
    int playerLane = 1;
    int score = 0;
    int ticks = 0;
    int speed = 100;
    bool gameOver = false;
    
    Obstacle obstacles[MAX_OBSTACLES];
    initObstacles(obstacles);

    // Main game loop
    while (!gameOver) {
        // Input handling
        if (_kbhit()) {
            char key = _getch();
            if (key == 'a' && playerLane > 0) playerLane--;
            if (key == 'd' && playerLane < LANE_COUNT - 1) playerLane++;
            if (key == 'q') gameOver = true;
        }

        // Game logic
        if (ticks % 5 == 0) spawnObstacle(obstacles);
        moveObstacles(obstacles);
        
        if (checkCollision(obstacles, playerLane)) {
            gameOver = true;
            system("color 4F");
        }

        // Rendering
        drawGame(playerLane, obstacles, score);

        // Update game state
        score++;
        ticks++;
        Sleep(speed);

        // Difficulty increase
        if (score % 50 == 0 && speed > 30) {
            speed -= 5;
        }
    }

    // Game over screen
    system("cls");
    std::cout << "GAME OVER! Final score: " << score << std::endl;
    saveScore(score);
    
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
    std::cin.get();
}