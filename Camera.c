#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <raylib.h>

#include "Camera.h"

/* p=posição a=alvo up */
Camera3D* camera_construtor(
      uint8_t id,
      float incremento,
      float px, float py, float pz,
      float ax, float ay, float az,
      float upx, float upy, float upz,
      float fovy,
      CameraProjection projection
    )
{
  Camera3D* inst = malloc( sizeof(Camera3D) );

  inst->position.x = px;
  inst->position.y = py;
  inst->position.z = pz;

  inst->target.x = ax;
  inst->target.y = ay;
  inst->target.z = az;

  inst->up.x = upx;
  inst->up.y = upy;
  inst->up.z = upz;

  inst->fovy = fovy;

  inst->projection = projection;

  printf("%s%i%s", "Câmera de id=", id, " instânciada.\n" );

  return inst;
}

/* Cria câmera cuja posição é a mesma de outro objeto */
Camera3D* camera_posicaoDependente_construtor(
      uint8_t id,
      float incremento,
      Vector3* posicaoXYZ,
      float ax, float ay, float az,
      float upx, float upy, float upz,
      float fovy,
      CameraProjection projection
    )
{
  Camera3D* inst = malloc( sizeof(Camera3D) );

  inst->position = *(Vector3*) posicaoXYZ;

  inst->target.x = ax;
  inst->target.y = ay;
  inst->target.z = az;

  inst->up.x = upx;
  inst->up.y = upy;
  inst->up.z = upz;

  inst->fovy = fovy;
  inst->projection = projection;

  printf("%s%i%s", "Câmera de id=", id, " instânciada.\n" );

  return inst;
}

/* Cria câmera cujo alvo de observação é outro objeto */
Camera3D* camera_observadoraAlvoDependente_construtor(
      uint8_t id,
      float incremento,
      float px, float py, float pz,
      Vector3* alvoXYZ,
      float upx, float upy, float upz,
      float fovy,
      CameraProjection projection
    )
{
  Camera3D* inst = malloc( sizeof(Camera3D) );

  inst->position.x = px;
  inst->position.y = py;
  inst->position.z = pz;

  inst->target = *(Vector3*) alvoXYZ;

  inst->up.x = upx;
  inst->up.y = upy;
  inst->up.z = upz;

  inst->fovy = fovy;

  inst->projection = projection;

  printf( "%s%i%s", "Câmera de id=", id, " instânciada.\n" );

  return inst;
}

void camera_destrutor( Camera3D* cam )
{
  if ( !(cam == NULL) )
  {
    //principal
    memset( cam, 0x00, sizeof(Camera3D) );
    free( cam );
    return;
  }
  perror( "Ponteiro para Camera3D é NULL !" );
  exit(1);
}

void camera_posicaoDependente_destrutor( Camera3D* cam )
{
  if ( !(cam == NULL) )
  {
    memset( cam, 0x00, sizeof(Camera3D) );
    free( cam );
    return;
  }
  perror( "Ponteiro para Camera3D é NULL !" );
  exit(1);
}

void camera_observadoraAlvoDependente_destrutor( Camera3D* cam )
{
  if ( !(cam == NULL) )
  {
    //principal
    memset( cam, 0x00, sizeof(Camera3D) );
    free( cam );
    return;
  }
  perror( "Ponteiro para Camera3D é NULL !" );
  exit(1);
}


