#include "Obstacle.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <ctime>

void inicializarObstaculos(Obstaculo obs[]) {
    for (int i = 0; i < MAX_OBSTACULOS; i++) {
        obs[i].activo = false;
    }
}

void generarObstaculo(Obstaculo obs[]) {
    for (int i = 0; i < MAX_OBSTACULOS; i++) {
        if (!obs[i].activo) {
            obs[i].activo = true;
            obs[i].carril = rand() % NUM_CARRILES;
            obs[i].y = 0;
            break;
        }
    }
}

void moverObstaculos(Obstaculo obs[]) {
    for (int i = 0; i < MAX_OBSTACULOS; i++) {
        if (obs[i].activo) {
            obs[i].y++;
            if (obs[i].y >= ALTO) {
                obs[i].activo = false;
            }
        }
    }
}

bool detectarColision(Obstaculo obs[], int carrilJugador) {
    for (int i = 0; i < MAX_OBSTACULOS; i++) {
        if (obs[i].activo && obs[i].carril == carrilJugador && obs[i].y == ALTO - 1) {
            return true;
        }
    }
    return false;
}

void dibujar(int carrilJugador, Obstaculo obs[], int puntos) {
    system("cls");
    for (int y = 0; y < ALTO; y++) {
        for (int x = 0; x < NUM_CARRILES; x++) {
            bool dibujado = false;
            for (int i = 0; i < MAX_OBSTACULOS; i++) {
                if (obs[i].activo && obs[i].carril == x && obs[i].y == y) {
                    std::cout << "#";
                    dibujado = true;
                    break;
                }
            }
            if (!dibujado && y == ALTO - 1 && x == carrilJugador) {
                std::cout << "A";
            } else if (!dibujado) {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Puntos: " << puntos << " | Q para salir | A/D para mover" << std::endl;
}

void guardarPuntaje(int puntos) {
    std::ofstream archivo("puntajes.txt", std::ios::app);
    time_t t = time(0);
    archivo << "Puntaje: " << puntos << " - Fecha: " << ctime(&t);
    archivo.close();
}