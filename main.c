#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
//#include <signal.h>
//#include <pthreads.h>

#include <raylib.h>

void lerTecladoMovimentoCubo( Vector3* posicaoCubo )
{
    if (IsKeyPressed( KEY_W ))
    {
      posicaoCubo->x += 0.5f;
    }
      
    if (IsKeyPressed( KEY_S ))
    {
      posicaoCubo->x -= 0.5f ;
    }
      
    if (IsKeyPressed( KEY_D ))
    {
      posicaoCubo->z += 0.5f ;
    }
      
    if (IsKeyPressed( KEY_A ))
    {
      posicaoCubo->z -= 0.5f ;
    }
}

void tratarEncerramentoComESC()
{
  if ( IsKeyPressed( KEY_ESCAPE ) )
  {
    printf("Encerrando demo\n");
    CloseWindow();
    exit(0);
  }
}

int main(int argc, char *argv[])
{
  const int larguraTela = 800;
  const int alturaTela = 450;

  uint8_t flag = 0;

  Camera3D camera = { 0 };

  camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
  camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
  camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Vector3 posicaoCubo = { 0.0f, 0.0f, 0.0f };

  InitWindow( larguraTela, alturaTela, "raylib demo" );
  SetTargetFPS(30);

  while ( !WindowShouldClose() )
  {
    tratarEncerramentoComESC();

    BeginDrawing();
    ClearBackground( BLACK );
    lerTecladoMovimentoCubo( &posicaoCubo );

    BeginMode3D(camera);
    DrawCube( posicaoCubo, 2.0f, 2.0f, 2.0f, BLUE );
    DrawGrid( 10, 1.0f );
    EndMode3D();

    DrawText( "exemplo", 10, 10, 20, WHITE );

    EndDrawing();
  }

  CloseWindow();
  exit(0);
}
