#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <raylib.h>
#include <stdint.h>

typedef struct {
  uint8_t id;
  uint8_t incremento;
  Camera3D* camera;
  void (*moverPosicao)(Vector3*,float*);
  void (*moverAlvo)(Vector3*,float*);
} Camera3DIdentificada;

Camera3D* camera_construtor(
      uint8_t id,
      float incremento,
      float px, float py, float pz,
      float ax, float ay, float az,
      float upx, float upy, float upz,
      float fovy,
      CameraProjection projection
    );

Camera3D* camera_posicaoDependente_construtor(
      uint8_t id,
      float incremento,
      Vector3* posicaoXYZ,
      float ax, float ay, float az,
      float upx, float upy, float upz,
      float fovy,
      CameraProjection projection
    );

Camera3D* camera_observadoraAlvoDependente_construtor(
      uint8_t id,
      float incremento,
      float px, float py, float pz,
      Vector3* alvoXYZ,
      float upx, float upy, float upz,
      float fovy,
      CameraProjection projection
    );


void camera_destrutor( Camera3D* cam );
void camera_posicaoDependente_destrutor( Camera3D* cam );
void camera_observadoraAlvoDependente_destrutor( Camera3D* cam );

#endif
