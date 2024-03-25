#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;

  std::printf("%.9lf", (double)a / b);
  return 0;
}