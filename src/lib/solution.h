#ifndef A0350CCA_EFE2_4782_B0EB_045ED82F3760
#define A0350CCA_EFE2_4782_B0EB_045ED82F3760

#include <map>
#include <string>
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
  Solution(){}

  std::string GetHelloWorld();
  std::string GetLongText();
};

#endif /* A0350CCA_EFE2_4782_B0EB_045ED82F3760 */
