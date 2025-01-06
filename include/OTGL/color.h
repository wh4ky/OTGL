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

// 20 (excl null terminator) is the largest possible RGB ANSI escape sequence
// for one dimension (gb or fg) without an extra character.
// \033[38;2;255;255;255m%s = 20 characters

char *colorBG(const uint_fast8_t *color);
char *colorFG(const uint_fast8_t *color);

char *colorBGrgb(uint_fast8_t red, uint_fast8_t green, uint_fast8_t blue);
char *colorFGrgb(uint_fast8_t red, uint_fast8_t green, uint_fast8_t blue);

#endif // COLOR_H
