#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <map>
#include <ncurses.h>
#include <string>
#include <unistd.h>
#include <vector>

class Point {
public:
  Point(int i, int j) {
    i_ = i;
    j_ = j;
  }
  int GetI() const { return i_; };
  int GetJ() const { return j_; };
  void SetI(int i) { i_ = i; };
  void SetJ(int j) { j_ = j; };

private:
  int i_;
  int j_;
};

class Solution {
public:
  Solution();

  std::string GetHelloWorld();
  void drawcircle(int i0, int j0, int radius);
  bool DrawLine(const Point &start, const Point &end,
                const std::string &str) const;

  bool DrawLine(const int i0, const int j0, const int i1, const int j1,
                const std::string &str) const;

  bool DrawSevenSegment(const int i0, const int j0, const int width,
                        const int height, const unsigned char char_code,
                        const std::string &str) const;

  void putpixel(const Point &pixel, const std::string &str,
                bool do_refresh = true) const {
    putpixel(pixel.GetI(), pixel.GetJ(), str.c_str(), do_refresh);
  }

  void putpixel(int i, int j, const std::string &str,
                bool do_refresh = true) const {
    mvwprintw(stdscr, i, j, "%s", str.c_str());
    if (do_refresh) {
      refresh();
    }
  }

  void PrintStringOnSevenSegment(int i, int j, int width, int height,
                                 int margin, const std::string &text,
                                 const std::string &str);

  std::map<unsigned char, unsigned char> char_map_;
};

#endif