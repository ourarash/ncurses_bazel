#include "src/lib/ncurses_wrapper.h"
#include <chrono>
#include <ctime>
#include <iomanip> // put_time
#include <iostream>
#include <ncurses.h>
#include <sstream> // stringstream

int main() {
  NCursesWrapper ncurses_wrapper;

  initscr();     // Start curses mode
  start_color(); // Start color

  // Initialize some color pairs (foreground, background)
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  attron(COLOR_PAIR(1)); // Change color

  curs_set(0); // Don't show the cursor
  std::string str = "X";

  attron(A_BOLD);
  int name_offset = 20;
  int name_y = 15;
  std::string my_text = "HELLO";
  ncurses_wrapper.PrintStringOnSevenSegment(/*i=*/15, /*j=*/24, /*width=*/10,
                                     /*height=*/12, /*margin=*/4, my_text, str);

  int i = 0;
  while (true) {
    auto now = std::chrono::system_clock::now();
    auto now_in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream hour, min, seconds, time;
    hour << std::put_time(std::localtime(&now_in_time_t), "%H");
    min << std::put_time(std::localtime(&now_in_time_t), "%M:");
    seconds << std::put_time(std::localtime(&now_in_time_t), "%S");
    time << std::put_time(std::localtime(&now_in_time_t), "%H:%M:%S");

    mvwprintw(stdscr, 0, 0, "%s", time.str().c_str());

    attron(COLOR_PAIR(1)); // Change color

    ncurses_wrapper.DrawSevenSegment(1, 0, 10, 10, ncurses_wrapper.char_map_[hour.str()[0]],
                              str);
    ncurses_wrapper.DrawSevenSegment(1, 14 * 1, 10, 10,
                              ncurses_wrapper.char_map_[hour.str()[1]], str);

    if ((seconds.str()[1] - '0') % 2 == 1) {
      ncurses_wrapper.DrawSevenSegment(1, 14 * 2, 10, 10, ncurses_wrapper.char_map_[':'],
                                str);
    } else {
      ncurses_wrapper.DrawSevenSegment(1, 14 * 2, 10, 10, 0, str);
    }

    attron(COLOR_PAIR(2)); // Change color

    ncurses_wrapper.DrawSevenSegment(1, 14 * 3, 10, 10,
                              ncurses_wrapper.char_map_[min.str()[0]], str);
    ncurses_wrapper.DrawSevenSegment(1, 14 * 4, 10, 10,
                              ncurses_wrapper.char_map_[min.str()[1]], str);

    if ((seconds.str()[1] - '0') % 2 == 1) {

      ncurses_wrapper.DrawSevenSegment(1, 14 * 5, 10, 10, ncurses_wrapper.char_map_[':'],
                                str);
    } else {
      ncurses_wrapper.DrawSevenSegment(1, 14 * 5, 10, 10, 0, str);
    }

    attron(COLOR_PAIR(3)); // Change color

    ncurses_wrapper.DrawSevenSegment(1, 14 * 6, 10, 10,
                              ncurses_wrapper.char_map_[seconds.str()[0]], str);
    ncurses_wrapper.DrawSevenSegment(1, 14 * 7, 10, 10,
                              ncurses_wrapper.char_map_[seconds.str()[1]], str);
    usleep(1000 * 50); // Sleep for 100 ms
  }

  return EXIT_SUCCESS;
}