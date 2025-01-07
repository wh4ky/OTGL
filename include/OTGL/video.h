#ifndef VIDEO_H
#define VIDEO_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <OTGL/color.h>

#ifdef _WIN32
#include <windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#endif

typedef struct Video {
#ifdef _WIN32
  HANDLE vConsole;
  DWORD vMode;
#endif
  Cell **videoBuf;
  uint_fast16_t xRes;
  uint_fast16_t yRes;
} Video;

// Returns a Video struct with xRes as x and yRes as y.
Video *vnew(uint_fast16_t, uint_fast16_t);

// Deletes the given Video struct.
void vdelete(Video *video);

// Clears the terminal
void vclear();

// Sets a Cell at x, y to the given input.
void vcellSet(const Video *video, uint_fast16_t x, uint_fast16_t y, Cell input);

// Gets a Cell at x, y.
Cell vcellGet(const Video *video, uint_fast16_t x, uint_fast16_t y);

// Fills the whole video buffer with the gien input cell.
void vfill(const Video *video, Cell input);

// Prints the video buffer to the terminal.
void vprint(const Video *video);

#endif // VIDEO_H
