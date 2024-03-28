#include <bits/stdc++.h>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  if (a == b && b == c && c == a) {
    std::cout << 10000 + a * 1000;
  } else if (a == b || b == c) {
    std::cout << 1000 + b * 100;
  } else if (c == a) {
    std::cout << 1000 + c * 100;
  } else {
    std::cout << std::max({a, b, c}) * 100;
  }

  return 0;
}