#include "src/lib/solution.h"
#include <iostream>
#include <ncurses.h>
#include <string>
#include <unistd.h>
#include <iostream>
#include <ncurses.h>
void putpixel(int x, int y, char val)
{
  mvwprintw(stdscr, x, y, "%s", val);
}

void drawcircle(int x0, int y0, int radius)
{
  int x = radius;
  int y = 0;
  int err = 0;

  while (x >= y)
  {
    putpixel(x0 + x, y0 + y, 7);
    putpixel(x0 + y, y0 + x, 7);
    putpixel(x0 - y, y0 + x, 7);
    putpixel(x0 - x, y0 + y, 7);
    putpixel(x0 - x, y0 - y, 7);
    putpixel(x0 - y, y0 - x, 7);
    putpixel(x0 + y, y0 - x, 7);
    putpixel(x0 + x, y0 - y, 7);

    if (err <= 0)
    {
      y += 1;
      err += 2 * y + 1;
    }

    if (err > 0)
    {
      x -= 1;
      err -= 2 * x + 1;
    }
  }
}

int main()
{
  initscr();
  drawcircle(1, 1, 10);
  refresh(); // Print it on to the real screen
  getch();   // Wait for user input
  endwin();
  return 0;
}