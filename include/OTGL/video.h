#ifndef VIDEO_H
#define VIDEO_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <OTGL/color.h>

typedef struct Video {
  Cell **videoBuf;
  uint16_t xRes;
  uint16_t yRes;
} Video;

Video *vnew(uint16_t nx, uint16_t ny);
void vdelete(Video *video);

void vclear();
void vcellSet(const Video *video, uint16_t x, uint16_t y, Cell input);
Cell vcellGet(const Video *video, uint16_t x, uint16_t y);
void vfill(const Video *video, Cell input);
void vupdate(const Video *video);

#endif // VIDEO_H
