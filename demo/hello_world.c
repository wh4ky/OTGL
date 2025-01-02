#include <OTGL/video.h>

#include <string.h>

int main() {
  char message[] = "Hello, World!";
  Video *video = vnew(strlen(message), 1);

  for (int i = 0; i < (int)strlen(message); i++) {
    char tmp[2];
    tmp[0] = message[i];
    tmp[1] = '\0';
    vcellSet(video, i, 0, tmp);
  }

  vupdate(video);

  return 0;
}
