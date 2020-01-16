#include "src/lib/solution.h"
#include <iostream>
#include <ncurses.h>
#include <string>
#include <unistd.h>

int main() {
  Solution solution;
  const char *hello_world = solution.GetHelloWorld().c_str();

  initscr();     // Start curses mode
  start_color(); // Start color

  // Initialize some color pairs (foreground, background)
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);

  for (int i = 0; i < 100; i++) {
    attron(COLOR_PAIR(i % 3 + 1)); // Change color

    mvwprintw(stdscr, 0, i, "%s", hello_world);
    if (i > 0) {
      mvwprintw(stdscr, 0, i - 1, "%s", " ");
    }
    refresh();          // Print it on to the real screen
    usleep(1000 * 100); // Sleep for 100 ms
  }
  mvwprintw(stdscr, 10, 0, "%s", "Press any key to exit.");
  refresh(); // Print it on to the real screen
  getch();   // Wait for user input
  endwin();  // End curses mode

  return EXIT_SUCCESS;
}