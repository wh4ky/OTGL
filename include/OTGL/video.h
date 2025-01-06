#ifndef VIDEO_H
#define VIDEO_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <OTGL/color.h>

#ifdef _WIN32 // Maybe for a working Windows API implementation.
//
#include <windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#endif

typedef struct Video {
#ifdef _WIN32 // Maybe for a working Windows API implementation.
  HANDLE vConsole;
  DWORD vMode;
#endif
  Cell **videoBuf;
  uint_fast16_t xRes;
  uint_fast16_t yRes;
} Video;

Video *vnew(uint_fast16_t, uint_fast16_t);
void vdelete(Video *video);
void vclear();
void vcellSet(const Video *video, uint_fast16_t x, uint_fast16_t y, Cell input);
Cell vcellGet(const Video *video, uint_fast16_t x, uint_fast16_t y);
void vfill(const Video *video, Cell input);
void vprint(const Video *video);

#endif // VIDEO_H
