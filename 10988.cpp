#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::string s;
  std::cin >> s;

  int b_palindrome = 1;
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - i - 1]) {
      b_palindrome = 0;
      break;
    }
  }
  std::cout << b_palindrome;
  return 0;
}