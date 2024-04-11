#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int alphabet[26] = {0};
  std::string s;
  std::cin >> s;

  for (auto c : s) {
    if (c >= 'a' && c <= 'z') {
      alphabet[c - 'a']++;
    } else if (c >= 'A' && c <= 'Z') {
      alphabet[c - 'A']++;
    }
  }
  int max_element = 0;
  int max_idx = 0;
  int max_cnt = 0;
  for (int i = 0; i < 26; i++) {
    if (alphabet[i] > max_element) {
      max_element = alphabet[i];
      max_idx = i;
      max_cnt = 0;
    } else if (alphabet[i] == max_element) {
      max_cnt++;
    }
  }

  if (max_cnt) {
    std::cout << "?";
  } else {
    std::cout << (char)('A' + max_idx);
  }

  return 0;
}