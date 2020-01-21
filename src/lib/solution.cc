#include "solution.h"
#include <map>
#include <ncurses.h>

Solution::Solution() {

  char_map_[' '] = 56;

  char_map_['!'] = 0b10000110;
  char_map_['\"'] = 0b00100010;
  char_map_['#'] = 0b01111110;
  char_map_['$'] = 0b01101101;
  char_map_['%'] = 0b11010010;
  char_map_['&'] = 0b01000110;
  char_map_['\''] = 0b00100000;
  char_map_['('] = 0b00101001;
  char_map_[')'] = 0b00001011;
  char_map_['*'] = 0b00100001;
  char_map_['+'] = 0b01110000;
  char_map_[','] = 0b00010000;
  char_map_['-'] = 0b01000000;
  char_map_['.'] = 0b10000000;
  char_map_['/'] = 0b01010010;
  char_map_['0'] = 0b00111111;
  char_map_['1'] = 0b00000110;
  char_map_['2'] = 0b01011011;
  char_map_['3'] = 0b01001111;
  char_map_['4'] = 0b01100110;
  char_map_['5'] = 0b01101101;
  char_map_['6'] = 0b01111101;
  char_map_['7'] = 0b00000111;
  char_map_['8'] = 0b01111111;
  char_map_['9'] = 0b01101111;
  char_map_[':'] = 0b00001001;
  char_map_[';'] = 0b00001101;
  char_map_['<'] = 0b01100001;
  char_map_['='] = 0b01001000;
  char_map_['>'] = 0b01000011;
  char_map_['?'] = 0b11010011;
  char_map_['@'] = 0b01011111;
  char_map_['A'] = 0b01110111;
  char_map_['B'] = 0b01111100;
  char_map_['C'] = 0b00111001;
  char_map_['D'] = 0b01011110;
  char_map_['E'] = 0b01111001;
  char_map_['F'] = 0b01110001;
  char_map_['G'] = 0b00111101;
  char_map_['H'] = 0b01110110;
  char_map_['I'] = 0b00110000;
  char_map_['J'] = 0b00011110;
  char_map_['K'] = 0b01110101;
  char_map_['L'] = 0b00111000;
  char_map_['M'] = 0b00010101;
  char_map_['N'] = 0b00110111;
  char_map_['O'] = 0b00111111;
  char_map_['P'] = 0b01110011;
  char_map_['Q'] = 0b01101011;
  char_map_['R'] = 0b00110011;
  char_map_['S'] = 0b01101101;
  char_map_['T'] = 0b01111000;
  char_map_['U'] = 0b00111110;
  char_map_['V'] = 0b00111110;
  char_map_['W'] = 0b00101010;
  char_map_['X'] = 0b01110110;
  char_map_['Y'] = 0b01101110;
  char_map_['Z'] = 0b01011011;
  char_map_['['] = 0b00111001;
  char_map_['\\'] = 0b01100100;
  char_map_[']'] = 0b00001111;
  char_map_['^'] = 0b00100011;
  char_map_['_'] = 0b00001000;
  char_map_['`'] = 0b00000010;
  char_map_['a'] = 0b01011111;
  char_map_['b'] = 0b01111100;
  char_map_['c'] = 0b01011000;
  char_map_['d'] = 0b01011110;
  char_map_['e'] = 0b01111011;
  char_map_['f'] = 0b01110001;
  char_map_['g'] = 0b01101111;
  char_map_['h'] = 0b01110100;
  char_map_['i'] = 0b00010000;
  char_map_['j'] = 0b00001100;
  char_map_['k'] = 0b01110101;
  char_map_['l'] = 0b00110000;
  char_map_['m'] = 0b00010100;
  char_map_['n'] = 0b01010100;
  char_map_['o'] = 0b01011100;
  char_map_['p'] = 0b01110011;
  char_map_['q'] = 0b01100111;
  char_map_['r'] = 0b01010000;
  char_map_['s'] = 0b01101101;
  char_map_['t'] = 0b01111000;
  char_map_['u'] = 0b00011100;
  char_map_['v'] = 0b00011100;
  char_map_['w'] = 0b00010100;
  char_map_['x'] = 0b01110110;
  char_map_['y'] = 0b01101110;
  char_map_['z'] = 0b01011011;
  char_map_['{'] = 0b01000110;
  char_map_['|'] = 0b00110000;
  char_map_['}'] = 0b01110000;
  char_map_['~'] = 0b00000001;
}

std::string Solution::GetHelloWorld() { return "**** Hello World ****"; }

void Solution::drawcircle(int i0, int j0, int radius) {
  int i = radius;
  int j = 0;
  int err = 0;

  std::string c = "X";
  int k = 0;
  while (i >= j) {
    putpixel(i0 + i, j0 + j, c);
    putpixel(i0 + j, j0 + i + k, c);
    putpixel(i0 - j, j0 + i + k, c);
    putpixel(i0 - i, j0 + j + k, c);
    putpixel(i0 - i, j0 - j + k, c);
    putpixel(i0 - j, j0 - i + k, c);
    putpixel(i0 + j, j0 - i + k, c);
    putpixel(i0 + i, j0 - j + k, c);

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

bool Solution::DrawLine(const int i0, const int j0, const int i1, const int j1,
                        const std::string &str) const {

  if (j1 == j0) {
    for (int i = std::min(i0, i1); i <= std::max(i0, i1); i++) {
      putpixel(i, j0, str);
    }
    return true;
  }

  if (i0 == i1) {
    for (int i = std::min(j0, j1); i <= std::max(j0, j1); i++) {
      putpixel(i0, i, str);
    }
    return true;
  }

  // diagonal non-45 degree line
  float i, j, di, dj, step;
  int count;

  di = abs(i1 - i0);
  dj = abs(j1 - j0);

  if (di >= dj)
    step = di;
  else
    step = dj;

  di = di / step;
  dj = dj / step;

  i = i1;
  j = j1;

  count = 1;
  while (count <= step) {
    putpixel(i, j, str);
    i = i + di;
    j = j + dj;
    i = i + 1;
  }
  return true;
}

bool Solution::DrawLine(const Point &start, const Point &end,
                        const std::string &str) const {
  return DrawLine(start.GetI(), start.GetJ(), end.GetI(), end.GetJ(), str);
}

bool Solution::DrawSevenSegment(const int i0, const int j0, const int width,
                                const int height, const unsigned char char_code,
                                const std::string &str) const {

  // A
  if (char_code & 0b00000001)
    DrawLine(i0, j0 + 1, i0, j0 + width - 1, str.c_str());
  else {
    DrawLine(i0, j0 + 1, i0, j0 + width - 1, " ");
  }

  // B
  if (char_code & 0b00000001 << 1)
    DrawLine(i0, j0 + width, i0 + height / 2, j0 + width, str.c_str());
  else {
    DrawLine(i0, j0 + width, i0 + height / 2, j0 + width, " ");
  }
  // C
  if (char_code & 0b00000001 << 2)
    DrawLine(i0 + height / 2, j0 + width, i0 + height, j0 + width, str.c_str());
  else {
    DrawLine(i0 + height / 2, j0 + width, i0 + height, j0 + width, " ");
  }

  // D
  if (char_code & 0b00000001 << 3)
    DrawLine(i0 + height, j0 + 1, i0 + height, j0 + width - 1, str.c_str());
  else {
    DrawLine(i0 + height, j0 + 1, i0 + height, j0 + width - 1, " ");
  }

  // E
  if (char_code & 0b00000001 << 4)
    DrawLine(i0 + height / 2, j0, i0 + height, j0, str.c_str());
  else {
    DrawLine(i0 + height / 2, j0, i0 + height, j0, " ");
  }
  // F
  if (char_code & 0b00000001 << 5)
    DrawLine(i0, j0, i0 + height / 2, j0, str.c_str());
  else {
    DrawLine(i0, j0, i0 + height / 2, j0, " ");
  }
  // G
  if (char_code & 0b00000001 << 6)
    DrawLine(i0 + height / 2, j0 + 1, i0 + height / 2, j0 + width - 1,
             str.c_str());
  else {
    DrawLine(i0 + height / 2, j0 + 1, i0 + height / 2, j0 + width - 1, " ");
  }

  return true;
}

void Solution::PrintStringOnSevenSegment(int i, int j, int width, int height,
                                         int margin, const std::string &text,
                                         const std::string &str) {
  for (auto c : text) {
    DrawSevenSegment(i, j, width, height, char_map_[c], str);
    j += width + margin;
  }
}
