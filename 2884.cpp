#include <bits/stdc++.h>

int main() {
  int h, m;
  std::cin >> h >> m;

  int time = 60 * h + m;
  int alarm = time - 45;
  if (alarm < 0) {
    alarm += 24 * 60;
  }

  std::cout << alarm / 60 << ' ' << alarm % 60;
  return 0;
}