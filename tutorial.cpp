#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif
std::tuple<int, float, std::string> foo() {
  return std::make_tuple(1, 2.0, "hello");
}

int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    std::vector<int> v = {1, 2, 3, 4, 5};

    auto [a, b, c] = foo();
    std::cout <<"a: " << a << " b: " << b << " c: " << c << std::endl;
    //print version
    std::cout << "Version: " << Tutorial_VERSION_MAJOR << "."<< Tutorial_VERSION_MINOR << std::endl;
    return 1;
  }

  const double inputValue = atof(argv[1]);

  #ifdef USE_MYMATH
    const double outputValue = mathfunctions::sqrt(inputValue);
  #else
    const double outputValue = sqrt(inputValue);
  #endif
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}