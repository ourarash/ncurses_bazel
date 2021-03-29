#include <ncurses.h>

#include <map>

#include "solution.h"

std::string Solution::GetHelloWorld() { return "**** Hello World ****"; }
std::string Solution::GetLongText() {
  // return "1234 This is a very long text. Use this to demo a long text!
  // 56789";
  return "Lorem Ipsum is simply dummy text. Lorem Ipsum has been the "
         "industry's standard dummy text ever since the 1500s";
}
