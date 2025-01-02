#ifndef COLOR_H
#define COLOR_H

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// 20 is the largest possible RGB ANSI escape sequence
// for one dimension (gb or fg) without an extra character.
// \033[38;2;255;255;255m%s\0 -> 21 characters

char *colorBG(const uint8_t *color, char character);
char *colorFG(const uint8_t *color, char character);

char *colorBGrgb(const uint8_t *red, const uint8_t *green, const uint8_t *blue,
                 char character);
char *colorFGrgb(const uint8_t *red, const uint8_t *green, const uint8_t *blue,
                 char character);

#endif // COLOR_H
