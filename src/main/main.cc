#include "src/lib/solution.h"
#include <iostream>
#include <ncurses.h>

int main() {
  Solution solution;
  const char *hello_world = solution.GetHelloWorld().c_str();
  initscr();           // Start curses mode
  printw(hello_world); // Print Hello World
  refresh();           // Print it on to the real screen
  getch();             // Wait for user input
  endwin();            // End curses mode

  return EXIT_SUCCESS;
}