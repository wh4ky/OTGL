#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <OTGL/color.h>
#include <OTGL/video.h>

#define XRES 40
#define YRES 20

int main() {
  srand(time(NULL));

  Video *video = vnew(XRES, YRES);

  vclear();

  for (int n = 0; n < 100; n++) {
    for (int i = 0; i < YRES; i++) {
      for (int j = 0; j < XRES; j++) {
        Cell temp = cnew(colorBGrgb(rand() % 256, rand() % 256, rand() % 256),
                         colorFGrgb(rand() % 256, rand() % 256, rand() % 256),
                         (rand() % 95 + 32));
        vcellSet(video, j, i, temp);
      }
    }
    usleep(50000);
    vclear();
    vupdate(video);
  }

  vdelete(video);
  return 0;
}
