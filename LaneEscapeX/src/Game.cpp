#include "Game.h"
#include "Obstacle.h"
#include "Utils.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>

// Eliminé la primera definición vacía de runGame()

void runGame() {
    srand(time(NULL));
    ocultarCursor();
    system("title Lane Escape X");
    system("color 0A");

    int carrilJugador = 1;
    int puntos = 0;
    int ticks = 0;
    int velocidad = 100;
    bool gameOver = false;

    Obstaculo obs[MAX_OBSTACULOS];
    inicializarObstaculos(obs);

    while (!gameOver) {
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 'a' && carrilJugador > 0) carrilJugador--;
            if (tecla == 'd' && carrilJugador < NUM_CARRILES - 1) carrilJugador++;
            if (tecla == 'q') gameOver = true;
        }

        if (ticks % 5 == 0) generarObstaculo(obs);
        moverObstaculos(obs);
        
        if (detectarColision(obs, carrilJugador)) {
            gameOver = true;
            system("color 4F");
        }

        dibujar(carrilJugador, obs, puntos);

        puntos++;
        ticks++;
        Sleep(velocidad);

        if (puntos % 50 == 0 && velocidad > 30) {
            velocidad -= 5;
        }
    }

    system("cls");
    std::cout << "GAME OVER! Puntaje final: " << puntos << std::endl;
    guardarPuntaje(puntos);
    
    std::cout << "\nPresione Enter para salir...";
    std::cin.ignore();
    std::cin.get();
}
