#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

int nanosleep(const struct timespec *req, struct timespec *rem);

void sleep_millis(int milliseconds) {
#ifdef _WIN32
  Sleep(milliseconds);
#else
  struct timespec ts;
  ts.tv_sec = milliseconds / 1000;
  ts.tv_nsec = (milliseconds % 1000) * 1000000;
  nanosleep(&ts, NULL);
#endif
}

#include <OTGL/color.h>
#include <OTGL/video.h>

#define XRES 100
#define YRES 50

int main() {
  srand(time(NULL));

  Video *video = vnew(XRES, YRES);

  vclear();

  for (int n = 0; n < 300; n++) {
    for (int i = 0; i < YRES; i++) {
      for (int j = 0; j < XRES; j++) {
        Cell temp = cnew(colorBGrgb(rand() % 256, rand() % 256, rand() % 256),
                         colorFGrgb(rand() % 256, rand() % 256, rand() % 256),
                         (rand() % 95 + 32));
        vcellSet(video, j, i, temp);
      }
    }

    sleep_millis(33); // Around 30 fps

    vclear();
    vprint(video);
  }

  vdelete(video);
  return 0;
}
