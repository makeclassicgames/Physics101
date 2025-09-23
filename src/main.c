/*
* Fisicas basicas: posicion, velocidad e inercia
* Ejemplo basico de como implementar fisicas simples en un juego 2D
* usando raylib.
* Licencia MIT
*/
#include "raylib.h"
 //estructura para el jugador
typedef struct {
    Vector2 position;
    Vector2 velocity;
} Player;

int main(void) {
    //inicializcion de la ventana y contexto GL
    InitWindow(800, 600, "Fisicas basicas: posicion, velocidad e inercia");
    SetTargetFPS(60);

    Player player = {0};
    player.position = (Vector2){400, 300};
    player.velocity = (Vector2){0, 0};

    while (!WindowShouldClose()) {
        // Delta time (tiempo entre frames)
        float dt = GetFrameTime();

        // Controles: aplicamos aceleración
        Vector2 acceleration = {0, 0};
        if (IsKeyDown(KEY_RIGHT)) acceleration.x += 200;
        if (IsKeyDown(KEY_LEFT))  acceleration.x -= 200;
        if (IsKeyDown(KEY_DOWN))  acceleration.y += 200;
        if (IsKeyDown(KEY_UP))    acceleration.y -= 200;

        // Actualizar velocidad con inercia
        player.velocity.x += acceleration.x * dt;
        player.velocity.y += acceleration.y * dt;

        // Simular fricción
        player.velocity.x *= 0.98f;
        player.velocity.y *= 0.98f;

        // Actualizar posición
        player.position.x += player.velocity.x * dt;
        player.position.y += player.velocity.y * dt;

        // Dibujar
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircleV(player.position, 20, BLUE);
            DrawText("Usa flechas para mover con inercia", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }
    //cierre de la ventana y deinicion del contexto GL
    CloseWindow();
    return 0;
}
