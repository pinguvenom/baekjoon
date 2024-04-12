#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::string s;
  std::cin >> s;

  int alphabet[26] = {0};
  for (auto c : s) {
    alphabet[c - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    std::cout << alphabet[i] << ' ';
  }
  return 0;
}