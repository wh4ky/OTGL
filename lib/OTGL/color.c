#include <OTGL/color.h>

Cell cnew(const char *newbg, const char *newfg, char newchr) {
  Cell *pixel = (Cell *)malloc(sizeof(Cell));

  if ((newbg == NULL) || (newfg == NULL)) {
    fprintf(stderr, "ERROR: Provided values are NULL.");
    return (Cell){};
  }
  if (strcmp(newbg, "") == 0) {
    strcpy(pixel->bg, "\x1b[48;5;0m");
  } else {
    strcpy(pixel->bg, newbg);
  }
  if (strcmp(newfg, "") == 0) {
    strcpy(pixel->fg, "\x1b[38;5;15m");
  } else {
    strcpy(pixel->fg, newfg);
  }

  pixel->chr = newchr;

  Cell retpixel = *pixel;
  free(pixel);

  return retpixel;
}

char *colorBG(const uint_fast8_t *color) { // 8-bit
  static char outBuf[20];
  if (snprintf(outBuf, sizeof(outBuf), "\x1b[48;5;%" PRIuFAST8 "m", *color) <
      0) {
    fprintf(stderr, "ERROR: Failed to copy buffer.");
    return NULL;
  }
  return outBuf;
}

char *colorFG(const uint_fast8_t *color) { // 8-bit
  static char outBuf[20];
  if (snprintf(outBuf, sizeof(outBuf), "\x1b[38;5;%" PRIuFAST8 "m", *color) <
      0) {
    fprintf(stderr, "ERROR: Failed to copy buffer.");
    return NULL;
  }
  return outBuf;
}

char *colorBGrgb(uint_fast8_t red, uint_fast8_t green,
                 uint_fast8_t blue) { // rgb
  static char outBuf[20];
  if (snprintf(outBuf, sizeof(outBuf),
               "\x1b[48;2;%" PRIuFAST8 ";%" PRIuFAST8 ";%" PRIuFAST8 "m", red,
               green, blue) < 0) {
    fprintf(stderr, "ERROR: Failed to copy buffer.");
    return NULL;
  }
  return outBuf;
}

char *colorFGrgb(uint_fast8_t red, uint_fast8_t green,
                 uint_fast8_t blue) { // rgb
  static char outBuf[20];
  if (snprintf(outBuf, sizeof(outBuf),
               "\x1b[38;2;%" PRIuFAST8 ";%" PRIuFAST8 ";%" PRIuFAST8 "m", red,
               green, blue) < 0) {
    fprintf(stderr, "ERROR: Failed to copy buffer.");
    return NULL;
  }
  return outBuf;
}
