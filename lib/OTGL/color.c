#include <OTGL/color.h>

/*
const char TE::Color::esc[] = "\033[";
const char TE::Color::foregroundPref[] = "38;";
const char TE::Color::backgroundPref[] = "48;";
const char TE::Color::eightBitPref[] = "5;";
const char TE::Color::rgbPref[] = "2;";
*/

char *cologBG(const uint8_t *color, char character) { // 8-bit
  static char outBuf[21];
  if (snprintf(outBuf, sizeof(outBuf), "\033[48;5;%" PRIu8 "m%c", *color,
               character) < 0) {
    fprintf(stderr, "ERROR: Failed to copy buffer.");
    return NULL;
  }
  return outBuf;
}

char *colorFG(const uint8_t *color, char character) { // 8-bit
  static char outBuf[21];
  if (snprintf(outBuf, sizeof(outBuf), "\033[38;5;%" PRIu8 "m%c", *color,
               character) < 0) {
    fprintf(stderr, "ERROR: Failed to copy buffer.");
    return NULL;
  }
  return outBuf;
}

char *colorBGrgb(const uint8_t *red, const uint8_t *green, const uint8_t *blue,
                 char character) { // rgb
  static char outBuf[21];
  if (snprintf(outBuf, sizeof(outBuf),
               "\033[48;2;%" PRIu8 ";%" PRIu8 ";%" PRIu8 "m%c", *red, *green,
               *blue, character) < 0) {
    fprintf(stderr, "ERROR: Failed to copy buffer.");
    return NULL;
  }
  return outBuf;
}

char *colorFGrgb(const uint8_t *red, const uint8_t *green, const uint8_t *blue,
                 char character) { // rgb
  static char outBuf[21];
  if (snprintf(outBuf, sizeof(outBuf),
               "\033[48;2;%" PRIu8 ";%" PRIu8 ";%" PRIu8 "m%c", *red, *green,
               *blue, character) < 0) {
    fprintf(stderr, "ERROR: Failed to copy buffer.");
    return NULL;
  }
  return outBuf;
}
