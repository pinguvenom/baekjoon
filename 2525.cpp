#include <bits/stdc++.h>

int main() {
  int h, m;
  std::cin >> h >> m;

  int cook_time;
  std::cin >> cook_time;

  int time = 60 * h + m + cook_time;
  if (time >= 60 * 24) {
    time -= 24 * 60;
  }

  std::cout << time / 60 << ' ' << time % 60;
  return 0;
}