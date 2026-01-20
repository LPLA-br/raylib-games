#ifndef PERSONAGEM_H_INCLUDED
#define PERSONAGEM_H_INCLUDED

#include <raylib.h>

/* LPLA-br
  Estrutura de dados para
  personagem cúbico controlável por WASD.
Atualizar
  1. ponteiro para função
  2. protótipo da função
     neste header
  3. implementação da função no arquivo fonte
     correspondente.
*/

typedef struct
{
  uint8_t id;
  float incremento;
  Vector3* posicao;

  float altura;
  float largura;
  float comprimento;
  
  void (*mover)(Vector3*,float*);

} PersonagemCubico;

PersonagemCubico* personagemCubico_construtor(
    uint8_t id, float incremento,
    float altura, float largura, float comprimento,
    float x, float y, float z
    );

void personagemCubico_destrutor( PersonagemCubico* personagemCubico );

void mover( Vector3* posicao, float* incremento );

#endif // PERSONAGEM_H_INCLUDED
