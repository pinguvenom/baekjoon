#include <bits/stdc++.h>

int main() {
  int total;
  std::cin >> total;

  int cnt;
  std::cin >> cnt;

  int sum = 0;
  for (int i = 0; i < cnt; i++) {
    int a, b;
    std::cin >> a >> b;
    sum += (a * b);
  }

  if (total == sum) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
  return 0;
}