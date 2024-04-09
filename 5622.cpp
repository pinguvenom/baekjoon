#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::string s;
  std::cin >> s;
  int num = 0;
  int sum = 0;
  for (auto c : s) {
    if (c <= 'C') {
      num = 2;
    } else if (c <= 'F') {
      num = 3;
    } else if (c <= 'I') {
      num = 4;
    } else if (c <= 'L') {
      num = 5;
    } else if (c <= 'O') {
      num = 6;
    } else if (c <= 'S') {
      num = 7;
    } else if (c <= 'V') {
      num = 8;
    } else if (c <= 'Z') {
      num = 9;
    }

    sum += (num + 1);
  }

  std::cout << sum;
  return 0;
}