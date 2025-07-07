#ifndef OBSTACLE_H
#define OBSTACLE_H

const int MAX_OBSTACLES = 100;
const int LANE_COUNT = 4;
const int HEIGHT = 10;

struct Obstacle {
    int lane;
    int y;
    bool active;
};

void initObstacles(Obstacle obstacles[]);
void spawnObstacle(Obstacle obstacles[]);
void moveObstacles(Obstacle obstacles[]);
bool checkCollision(Obstacle obstacles[], int playerLane);
void drawGame(int playerLane, Obstacle obstacles[], int score);
void saveScore(int score);

#endif