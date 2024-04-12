#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  std::cin >> n;

  int alph[26] = {0};

  while (n--) {
    std::string s;
    std::cin >> s;

    alph[s[0] - 'a']++;
  }

  bool b_predaja = true;
  for (int i = 0; i < 26; i++) {
    if (alph[i] >= 5) {
      std::cout << (char)('a' + i);
      b_predaja = false;
    }
  }

  if (b_predaja) {
    std::cout << "PREDAJA";
  }

  return 0;
}