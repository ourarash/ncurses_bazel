#include "src/lib/ncurses_wrapper.h"
#include <iostream>
#include <ncurses.h>
#include <string>
#include <unistd.h>

int main() {
  NCursesWrapper ncurses_wrapper;

  initscr();
  ncurses_wrapper.drawcircle(10, 20, 5);
  refresh(); // Print it on to the real screen
  getch();   // Wait for user input
  endwin();
  return 0;
}