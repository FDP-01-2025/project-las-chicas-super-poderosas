#ifndef OBSTACLE_H
#define OBSTACLE_H

const int MAX_OBSTACULOS = 100;
const int NUM_CARRILES = 4;
const int ALTO = 10;

struct Obstaculo {
    int carril;
    int y;
    bool activo;
};

void inicializarObstaculos(Obstaculo obs[]);
void generarObstaculo(Obstaculo obs[]);
void moverObstaculos(Obstaculo obs[]);
bool detectarColision(Obstaculo obs[], int carrilJugador);
void dibujar(int carrilJugador, Obstaculo obs[], int puntos);
void guardarPuntaje(int puntos);

#endif