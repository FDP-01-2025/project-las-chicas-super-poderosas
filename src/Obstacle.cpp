#include "Obstacle.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <ctime>

void initObstacles(Obstacle obstacles[]) {
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        obstacles[i].active = false;
    }
}

void spawnObstacle(Obstacle obstacles[]) {
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        if (!obstacles[i].active) {
            obstacles[i].active = true;
            obstacles[i].lane = rand() % LANE_COUNT;
            obstacles[i].y = 0;
            break;
        }
    }
}

void moveObstacles(Obstacle obstacles[]) {
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        if (obstacles[i].active) {
            obstacles[i].y++;
            if (obstacles[i].y >= HEIGHT) {
                obstacles[i].active = false;
            }
        }
    }
}

bool checkCollision(Obstacle obstacles[], int playerLane) {
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        if (obstacles[i].active && obstacles[i].lane == playerLane && obstacles[i].y == HEIGHT - 1) {
            return true;
        }
    }
    return false;
}

void drawGame(int playerLane, Obstacle obstacles[], int score) {
    system("cls");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < LANE_COUNT; x++) {
            bool drawn = false;
            for (int i = 0; i < MAX_OBSTACLES; i++) {
                if (obstacles[i].active && obstacles[i].lane == x && obstacles[i].y == y) {
                    std::cout << "#";
                    drawn = true;
                    break;
                }
            }
            if (!drawn && y == HEIGHT - 1 && x == playerLane) {
                std::cout << "A";
            } else if (!drawn) {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Score: " << score << " | Q to quit | A/D to move" << std::endl;
}

void saveScore(int score) {
    std::ofstream file("scores.txt", std::ios::app);
    time_t t = time(0);
    file << "Score: " << score << " - Date: " << ctime(&t);
    file.close();
}