#include <OTGL/video.h>

// Initializes the class with a name, and Log process and initializes the video
// buffer with x_width and y_height then fills it with fill().
Video *vnew(uint16_t x, uint16_t y) {
  Video *video = (Video *)malloc(sizeof(Video));
  video->xRes = x;
  video->yRes = y;

  video->videoBuf = (Cell **)calloc(video->yRes, sizeof(Cell *));
  if (video->videoBuf == NULL) {
    fprintf(stderr, "ERROR: Video buffer in TE::Screen constructor is NULL.\n");
    return NULL;
  }

  for (uint16_t i = 0; i < video->yRes; i++) {
    video->videoBuf[i] = (Cell *)calloc(video->xRes, sizeof(Cell));
    if (video->videoBuf[i] == NULL) {
      fprintf(stderr, "ERROR: Column %u is NULL.\n", i);
      return NULL;
    }
    for (uint16_t j = 0; j < video->xRes; j++) {
      video->videoBuf[i][j] = cnew("", "", '\0');
    }
  }

  // Fill videoBuf with dummy values.
  vfill(video, cnew("", "", ' '));

  fprintf(stderr, "STATUS: Made Video with dimensions %u by %u.\n", video->xRes,
          video->yRes);
  return video;
}

// Deletes the video buffer
void vdelete(Video *video) {
  for (uint16_t i = 0; i < video->yRes; i++) {
    free(video->videoBuf[i]);
  }
  free(video->videoBuf);
  free(video);
  return;
}

// Clears the terminal.
void vclear() { printf("\033[0;0H\033[0J"); }

// Sets the 'pixel' at {x, y}.
void vcellSet(const Video *video, uint16_t x, uint16_t y, Cell input) {
  if (video == NULL) {
    fprintf(stderr, "ERROR: Video pointer is NULL.\n");
    return;
  }
  if (x >= video->xRes || y >= video->yRes) {
    fprintf(stderr, "ERROR: %u, %u out of range, ignoring.\n", x, y);
    return;
  }

  video->videoBuf[y][x] = input;
  return;
}

// Gets the 'pixel' at {x, y}.
Cell vcellGet(const Video *video, uint16_t x, uint16_t y) {
  return video->videoBuf[y][x];
}

// fills the video buffer with a char[] of your choice.
void vfill(const Video *video, Cell input) {
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
      printf("%s%s%c%c", video->videoBuf[i][j].bg, video->videoBuf[i][j].fg,
             video->videoBuf[i][j].chr, '\0');
    }
    printf("\n");
  }
  printf("%s", "\033[38;5;15m\033[48;5;0m");
}
