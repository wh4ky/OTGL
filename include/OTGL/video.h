#ifndef VIDEO_H
#define VIDEO_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Video {
  char *name;
  char ***videoBuf;
  uint16_t xRes;
  uint16_t yRes;
  char cellGetBuffer[39];
} Video;

Video *vnew(uint16_t nx, uint16_t ny);
void vdelete(Video *video);

void vclear();
void vcellSet(const Video *video, uint16_t x, uint16_t y, const char input[]);
char *vcellGet(const Video *video, uint16_t x, uint16_t y);
void vfill(const Video *video, const char input[]);
void vupdate(const Video *video);

#endif // VIDEO_H
