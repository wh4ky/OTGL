#ifndef COLOR_H
#define COLOR_H

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cell {
  char bg[20];
  char fg[20];
  char chr;
} Cell;

Cell cnew(const char *newbg, const char *newfg, char newchar);

// 21 is the largest possible RGB ANSI escape sequence
// for one dimension (gb or fg) without an extra character.
// \033[38;2;255;255;255m%s\0 -> 21 characters

char *colorBG(const uint8_t *color);
char *colorFG(const uint8_t *color);

char *colorBGrgb(uint8_t red, uint8_t green, uint8_t blue);
char *colorFGrgb(uint8_t red, uint8_t green, uint8_t blue);

#endif // COLOR_H
