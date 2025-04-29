#include <iostream>
#include <math.h>

class Solution
{
public:
  int divide(int dividend, int divisor)
  {
    int result = dividend / divisor;
    long long res = pow(2, 31);
    if (result > res - 1)
      return res - 1;
    if (result < -(res))
      return -(res);
    return result;
  }
};

int main()
{
  Solution s1;
  std::cout << s1.divide(pow(2, 66), 3) << std::endl;
  return 0;
}
