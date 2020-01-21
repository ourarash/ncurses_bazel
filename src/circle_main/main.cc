#include "src/lib/solution.h"
#include <iostream>
#include <ncurses.h>
#include <string>
#include <unistd.h>
void putpixel(int i, int j, char val) {
  std::string str = std::string(1, val);
  mvwprintw(stdscr, i, j, "%s", str.c_str());
  usleep(1000 * 100); // Sleep for 100 ms
  refresh();
}

void drawcircle(int x0, int y0, int radius) {
  int i = radius;
  int j = 0;
  int err = 0;

  char c = '*';
  int k = 0;
  while (i >= j) {
    putpixel(x0 + i, y0 + j , c);
    putpixel(x0 + j, y0 + i + k, c);
    putpixel(x0 - j, y0 + i + k, c);
    putpixel(x0 - i, y0 + j + k, c);
    putpixel(x0 - i, y0 - j + k, c);
    putpixel(x0 - j, y0 - i + k, c);
    putpixel(x0 + j, y0 - i + k, c);
    putpixel(x0 + i, y0 - j + k, c);

    if (err <= 0) {
      j += 1;
      err += 2 * j + 1;
    }

    if (err > 0) {
      i -= 1;
      err -= 2 * i + 1;
    }
  }
}

int main() {
  initscr();
  drawcircle(10, 20, 5);
  refresh(); // Print it on to the real screen
  getch();   // Wait for user input
  endwin();
  return 0;
}