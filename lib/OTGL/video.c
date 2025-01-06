#include <OTGL/video.h>
#include <stdio.h>
#include <unistd.h>

// Returns a Video struct and initializes the video buffer with x and y then
// fills it with vfill().
Video *vnew(uint_fast16_t x, uint_fast16_t y) {
  Video *video = (Video *)malloc(sizeof(Video));
  video->xRes = x;
  video->yRes = y;

#ifdef _WIN32
  video->vConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleMode(video->vConsole,
                 video->vMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif

  video->videoBuf = (Cell **)calloc(video->yRes, sizeof(Cell *));
  if (video->videoBuf == NULL) {
    fprintf(stderr, "ERROR: Video buffer is NULL.\n");
    return NULL;
  }

  for (uint_fast16_t i = 0; i < video->yRes; i++) {
    video->videoBuf[i] = (Cell *)calloc(video->xRes, sizeof(Cell));
    if (video->videoBuf[i] == NULL) {
      fprintf(stderr, "ERROR: Column %" PRIuFAST16 " is NULL.\n", i);
      return NULL;
    }
    for (uint_fast16_t j = 0; j < video->xRes; j++) {
      video->videoBuf[i][j] = cnew("", "", ' ');
    }
  }

  // Fill videoBuf with dummy values.
  vfill(video, cnew("", "", ' '));
  return video;
}

// Deletes the video buffer
void vdelete(Video *video) {
  for (uint_fast16_t i = 0; i < video->yRes; i++) {
    free(video->videoBuf[i]);
  }
  free(video->videoBuf);
  free(video);
#ifdef _WIN32
  SetConsoleMode(video->vConsole, video->vMode);
#endif
  return;
}

// Clears the terminal.
inline void vclear() {
  printf("\x1b[H\x1b[J");
  fflush(stdout);
  return;
}

// Sets the 'pixel' at {x, y}.
void vcellSet(const Video *video, uint_fast16_t x, uint_fast16_t y,
              Cell input) {
  if (x >= video->xRes || y >= video->yRes) {
    fprintf(stderr,
            "ERROR: %" PRIuFAST16 ", %" PRIuFAST16 " out of range, ignoring.\n",
            x, y);
    return;
  }

  video->videoBuf[y][x] = input;
  return;
}

// Gets the 'pixel' at {x, y}.
inline Cell vcellGet(const Video *video, uint_fast16_t x, uint_fast16_t y) {
  return video->videoBuf[y][x];
}

// fills the video buffer with a char[] of your choice.
void vfill(const Video *video, Cell input) {
  for (uint_fast16_t y = 0; y < video->yRes; y++) {
    for (uint_fast16_t x = 0; x < video->xRes; x++) {
      vcellSet(video, x, y, input);
    }
  }
}

// Print the video buffer to stdout.
#ifdef _WIN32 // TODO: Make it work with the Windows API (fuck you Windows API).
void vprint(const Video *video) {
  size_t bufferSize =
      video->xRes * video->yRes * sizeof(Cell) + video->yRes + 1;
  char *buffer = (char *)malloc(bufferSize);
  int index = 0;

  for (uint_fast8_t i = 0; i < video->yRes; i++) {
    for (uint_fast8_t j = 0; j < video->xRes; j++) {
      index += snprintf(buffer + index, bufferSize - index, "%s%s%c",
                        video->videoBuf[i][j].bg, video->videoBuf[i][j].fg,
                        video->videoBuf[i][j].chr);
    }
    buffer[index++] = '\n';
  }
  buffer[bufferSize] = '\0';

  write(STDOUT_FILENO, "\x1b[0m", 4);
  WriteConsole(video->vConsole, buffer, index, NULL, NULL);
  free(buffer);
  return;
}
#else
void vprint(const Video *video) {
  size_t bufferSize =
      video->xRes * video->yRes * sizeof(Cell) + video->yRes + 1;
  char *buffer = (char *)malloc(bufferSize);
  int index = 0;

  for (int i = 0; i < video->yRes; i++) {
    for (int j = 0; j < video->xRes; j++) {
      index += snprintf(buffer + index, bufferSize - index, "%s%s%c",
                        video->videoBuf[i][j].bg, video->videoBuf[i][j].fg,
                        video->videoBuf[i][j].chr);
    }
    buffer[index++] = '\n';
  }
  buffer[bufferSize] = '\0';

  write(STDOUT_FILENO, buffer, index);
  write(STDOUT_FILENO, "\x1b[0m", 4);
  free(buffer);
  return;
}
#endif
