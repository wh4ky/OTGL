#include <OTGL/color.h>

Cell cnew(const char *newbg, const char *newfg, char newchr) {
  Cell *pixel = (Cell *)malloc(sizeof(Cell));

  if ((newbg == NULL) || (newfg == NULL)) {
    fprintf(stderr, "ERROR: Provided values are NULL.");
    Cell dummycell = {};
    return dummycell;
  }
  if (strcmp(newbg, "") == 0) {
    strcpy(pixel->bg, "\033[38;5;15m");
  } else {
    strcpy(pixel->bg, newbg);
  }
  if (strcmp(newfg, "") == 0) {
    strcpy(pixel->fg, "\033[48;5;0m");
  } else {

    strcpy(pixel->fg, newfg);
  }

  pixel->chr = newchr;

  Cell retpixel = *pixel;
  return retpixel;
}

char *colorBG(const uint8_t *color) { // 8-bit
  static char outBuf[21];
  if (snprintf(outBuf, sizeof(outBuf), "\033[48;5;%" PRIu8 "m", *color) < 0) {
    fprintf(stderr, "ERROR: Failed to copy buffer.");
    return NULL;
  }
  return outBuf;
}

char *colorFG(const uint8_t *color) { // 8-bit
  static char outBuf[21];
  if (snprintf(outBuf, sizeof(outBuf), "\033[38;5;%" PRIu8 "m", *color) < 0) {
    fprintf(stderr, "ERROR: Failed to copy buffer.");
    return NULL;
  }
  return outBuf;
}

char *colorBGrgb(uint8_t red, uint8_t green, uint8_t blue) { // rgb
  static char outBuf[21];
  if (snprintf(outBuf, sizeof(outBuf),
               "\033[48;2;%" PRIu8 ";%" PRIu8 ";%" PRIu8 "m", red, green,
               blue) < 0) {
    fprintf(stderr, "ERROR: Failed to copy buffer.");
    return NULL;
  }
  return outBuf;
}

char *colorFGrgb(uint8_t red, uint8_t green, uint8_t blue) { // rgb
  static char outBuf[21];
  if (snprintf(outBuf, sizeof(outBuf),
               "\033[38;2;%" PRIu8 ";%" PRIu8 ";%" PRIu8 "m", red, green,
               blue) < 0) {
    fprintf(stderr, "ERROR: Failed to copy buffer.");
    return NULL;
  }
  return outBuf;
}
