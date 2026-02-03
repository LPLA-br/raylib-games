#include <stdlib.h>
#include <stdint.h>

#include <raylib.h>

#include "Personagem.h"

PersonagemCubico* personagemCubico_construtor(
      uint8_t id, float incremento,
      float altura, float largura, float comprimento,
      float x, float y , float z
    )
{
  PersonagemCubico* inst = malloc( sizeof(PersonagemCubico) );

  //definido/alocando variáveis membro
  inst->id = 0;
  inst->incremento = incremento;
  inst->posicao = malloc( sizeof(Vector3) );

  inst->posicao->x = x;
  inst->posicao->y = y;
  inst->posicao->z = z;

  inst->altura = altura;
  inst->largura = largura;
  inst->comprimento = comprimento;

  //acoplando funções membro
  inst->mover = &mover;

  return inst;
}

void personagemCubico_destrutor( PersonagemCubico* personagemCubico )
{
  //dependências
  free( personagemCubico->posicao );

  //principal
  free( personagemCubico );
}

//--- SETOR DAS FUNÇÕES MEMBRO PÚBLICAS

void mover( Vector3* posicao, float* incremento )
{
  if (IsKeyPressed( KEY_W ))
  {
    posicao->x += *incremento;
  }
    
  if (IsKeyPressed( KEY_S ))
  {
    posicao->x -= *incremento;
  }
    
  if (IsKeyPressed( KEY_D ))
  {
    posicao->z += *incremento;
  }
    
  if (IsKeyPressed( KEY_A ))
  {
    posicao->z -= *incremento;
  }
}

// SETOR DAS FUNÇÕES MEMBRO SEMÂNTICAMENTES PRIVADAS.

