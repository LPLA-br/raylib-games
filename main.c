#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
//#include <signal.h>
//#include <pthreads.h>

#include <raylib.h>
#include "Personagem.h"
#include "Camera.h"

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

  Camera3D* camera = camera_construtor( 0, 1.0f, 10.0f,10.0f,10.0f, 0.0f,0.0f,0.0f, 0.0f,1.0f,0.0f, 45.0f, CAMERA_PERSPECTIVE );
  PersonagemCubico* personagem = personagemCubico_construtor( 0, 1.0f, 1.0f,1.0f,1.0f, 0.0f,0.0f,0.0f );

  InitWindow( larguraTela, alturaTela, "raylib demo" );
  SetTargetFPS(30);

  while ( !WindowShouldClose() )
  {
    tratarEncerramentoComESC();

    BeginDrawing();
    ClearBackground( BLACK );

    BeginMode3D(*camera);
    DrawCube( *personagem->posicao, personagem->altura, personagem->largura, personagem->comprimento, BLUE );
    personagem->mover( personagem->posicao, &personagem->incremento );
    DrawGrid( 10, 1.0f );
    EndMode3D();

    DrawText( "exemplo", 10, 10, 20, WHITE );

    EndDrawing();
  }
  
  personagemCubico_destrutor( personagem );
  camera_destrutor( camera );
  CloseWindow();
  exit(0);
}
