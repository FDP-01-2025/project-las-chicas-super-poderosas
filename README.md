🎲 Lane Escape X v1.0: Introducción al Juego



🧩 Descripción



Lane Escape X es un emocionante juego realizado por un grupo de estudiantes comprometidos, basado en esquivar obstáculos inspirado en los clásicos juegos de carreras de consola. Es un juego de habilidad y reacción rápida, diseñado para un solo jugador, donde el objetivo es sobrevivir el mayor tiempo posible esquivando obstáculos que aparecen aleatoriamente.



El tablero consiste en una carretera de 4 carriles (numerados de 0 a 3) con obstáculos representados por `#` que caen desde la parte superior. El jugador controla un vehículo (`A`) que puede moverse entre carriles usando las teclas A (izquierda) y D (derecha).



📜 Reglas del Juego



1. Configuración:

   - El jugador comienza en el carril central (posición 1)

   - Los obstáculos aparecen aleatoriamente en los 4 carriles



2. Controles:

   - Tecla A: Mover hacia el carril izquierdo

   - Tecla D: Mover hacia el carril derecho

   - Tecla Q: Salir del juego



3. Dinámica del Juego:

   - Cada obstáculo (#) cae desde la parte superior hacia abajo

   - El jugador debe esquivar los obstáculos cambiando de carril

   - Si un obstáculo golpea al jugador (A), el juego termina



4. Puntuación:

   - Cada ciclo del juego suma 1 punto al marcador

   - La velocidad aumenta gradualmente cada 50 puntos

   - El récord se guarda automáticamente en "puntajes.txt"



5. Final del Juego:

   - El juego termina cuando ocurre una colisión

   - Se muestra la puntuación final y se guarda el récord



🚀 Características Técnicas



Este repositorio incluye una versión para terminal del juego con las siguientes características:

- Un solo jugador: El objetivo es alcanzar la mayor puntuación posible

- Dificultad progresiva: La velocidad aumenta cada 50 puntos

- Sistema de récords: Guarda automáticamente las mejores puntuaciones



Se recomienda expandir este código para agregar:

1. Modo de dos jugadores (competitivo o cooperativo)

2. Power-ups o bonificaciones especiales

3. Diferentes tipos de obstáculos con comportamientos únicos



📝 Notas de Implementación



- Desarrollado en C++ para terminal

- Usa la biblioteca Windows.h para funciones de consola

- Estructura modular con separación de lógica, renderizado y utilidades

- Compatible con sistemas Windows (requiere MinGW para compilación)



▶️ Cómo Jugar



1. Compilar el juego: g++ main.cpp src/Game.cpp src/Obstacle.cpp src/Utils.cpp -o game.exe

2. Ejecutar: .\game.exe

3. Usar teclas A/D para esquivar obstáculos

4. Presionar Q para salir en cualquier momento



¡Demuestra tus reflejos y trata de batir tu récord en este adictivo juego de esquiva!
