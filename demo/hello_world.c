#include <OTGL/video.h>

#include <string.h>

int main() {
  char message[] = "Hello, World!";        // the message to be printed.
  Video *video = vnew(strlen(message), 1); // Make a new video structure.

  vclear();       // Clear the terminal.

  for (int i = 0; i < (int)strlen(message); i++) {
    Cell c = cnew("", "", message[i]); // Initialize a new cell called 'c' with
                                       // the default foreground and background
                                       // color and the char 'message[i]'.
    vcellSet(video, i, 0, c); // Set the cell at (i, 0) to the cell 'c'.
  }

  vprint(video); // Print the video buffer.
  vdelete(video); // Delete the video structure.

  return 0;
}
