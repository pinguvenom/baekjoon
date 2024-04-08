#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::string a, b;
  std::cin >> a >> b;

  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());

  int a_num, b_num;
  a_num = std::atoi(a.c_str());
  b_num = std::atoi(b.c_str());

  if (a_num > b_num) {
    std::cout << a_num;
  } else {
    std::cout << b_num;
  }

  return 0;
}