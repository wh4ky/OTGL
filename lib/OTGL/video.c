#include <OTGL/video.h>

// Initializes the class with a name, and Log process and initializes the video
// buffer with x_width and y_height then fills it with fill().
Video *vnew(uint16_t nx, uint16_t ny) {
  Video *video = (Video *)malloc(sizeof(Video));
  video->xRes = nx;
  video->yRes = ny;

  video->videoBuf = (char ***)calloc(video->yRes, sizeof(char **));
  if (video->videoBuf == NULL) {
    fprintf(stderr, "ERROR: Video buffer in TE::Screen constructor is NULL.\n");
    return NULL;
  }

  for (uint16_t i = 0; i < video->yRes; i++) {
    video->videoBuf[i] = (char **)calloc(video->xRes, sizeof(char *));
    if (video->videoBuf[i] == NULL) {
      fprintf(stderr, "ERROR: Column %u is NULL.\n", i);
      return NULL;
    }

    for (uint16_t j = 0; j < video->xRes; j++) {
      // 39 is the maximum size of an RGB ANSI escape sequence.
      // \033[38;2;255;255;255m\033[48;2;255;255;255mX\0 -> 39 chars
      video->videoBuf[i][j] = (char *)malloc(39);
      if (video->videoBuf[i][j] == NULL) {
        fprintf(stderr, "ERROR: Cell at %u %u is NULL.\n", i, j);
        return NULL;
      }
    }
  }

  // Fill videoBuf with dummy values.
  vfill(video, "\033[38;5;15m\033[48;5;0mX");

  fprintf(stderr, "STATUS: Made Video with dimensions %u by %u.\n", video->xRes,
          video->yRes);
  return video;
}

// Deletes the video buffer
void vdelete(Video *video) {
  for (uint16_t i = 0; i < video->yRes; i++) {
    for (uint16_t j = 0; j < video->xRes; j++) {
      free(video->videoBuf[i][j]);
    }
    free(video->videoBuf[i]);
  }
  free(video->videoBuf);
  free(video);
  return;
}

// Clears the terminal.
void vclear() { printf("\033[0;0H\033[0J"); }

// Sets the 'pixel' at {x, y}.
void vcellSet(const Video *video, uint16_t x, uint16_t y, const char *input) {
  if (video == NULL) {
    fprintf(stderr, "ERROR: Pointer to Video passed is NULL.\n");
    return;
  }

  char *inputcpy = malloc(strlen(input) + 1);
  strncpy(inputcpy, input, strlen(input));

  if (x >= video->xRes || y >= video->yRes) {
    fprintf(stderr, "ERROR: %u, %u out of range, ignoring.\n", x, y);
    free(inputcpy);
    return;
  }

  if (video->videoBuf[y][x] == NULL) {
    fprintf(stderr, "ERROR: trying to write to NULL at x:%u y:%u.\n", x, y);
    return;
  }

  strncpy(video->videoBuf[y][x], inputcpy, strlen(inputcpy));
  video->videoBuf[y][x][strlen(inputcpy)] = '\0';
  free(inputcpy);
  return;
}

// Gets the 'pixel' at {x, y}.
char *vcellGet(const Video *video, uint16_t x, uint16_t y) {
  strncpy((char *)video->cellGetBuffer, video->videoBuf[y][x], 39);
  return (char *)video->cellGetBuffer;
}

// fills the video buffer with a char[] of your choice.
void vfill(const Video *video, const char input[]) {
  for (uint16_t i = 0; i < video->yRes; i++) {
    for (uint16_t j = 0; j < video->xRes; j++) {
      // Has to be 'j' then 'i' because 'j' is the x and 'i' is the y,
      vcellSet(video, j, i, input);
    }
  }
}

// Prints the whole video buffer.
void vupdate(const Video *video) {
  for (uint16_t i = 0; i < video->yRes; i++) {
    for (uint16_t j = 0; j < video->xRes; j++) {
      printf("%s", video->videoBuf[i][j]);
    }
    printf("\n");
  }
  printf("%s", "\033[38;5;15m\033[48;5;0m");
}
