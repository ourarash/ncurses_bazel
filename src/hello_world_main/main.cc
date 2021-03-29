#include "src/lib/ncurses_wrapper.h"
#include <iostream>
#include <ncurses.h>

int main() {
  NCursesWrapper ncurses_wrapper;
  const char *hello_world = ncurses_wrapper.GetHelloWorld().c_str();
  initscr();           // Start curses mode
  printw(hello_world); // Print Hello World
  refresh();           // Print it on to the real screen
  getch();             // Wait for user input
  endwin();            // End curses mode

  return EXIT_SUCCESS;
}