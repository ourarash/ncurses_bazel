#include "src/lib/solution.h"
#include <iostream>
#include <ncurses.h>
#include <string>
#include <unistd.h>

int main() {
  Solution solution;

  initscr();
  solution.drawcircle(10, 20, 5);
  refresh(); // Print it on to the real screen
  getch();   // Wait for user input
  endwin();
  return 0;
}