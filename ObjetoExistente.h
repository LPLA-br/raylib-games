#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <raylib.h>

/* SUBCONJUNTO
 * Objeto existente
 * 1.identificador
 * 2.incremento de posição espacial
 * 3.posição espacial
 * */
typedef struct
{
  uint8_t id;
  float incremento;
  Vector3* posicao;
} ObjetoExistente;

#endif
