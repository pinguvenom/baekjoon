#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::string s;
  std::cin >> s;

  char prev_c = ' ';
  char pprev_c = ' ';
  int cnt = s.size();
  for (auto c : s) {
    if (c == '=') {
      if (prev_c == 'c' || prev_c == 's') {
        cnt--;
      } else if (prev_c == 'z') {
        if (pprev_c == 'd') {
          cnt -= 2;
        } else {
          cnt--;
        }
      }
    } else if (c == '-') {
      if (prev_c == 'c' || prev_c == 'd') {
        cnt--;
      }
    } else if (c == 'j') {
      if (prev_c == 'l' || prev_c == 'n') {
        cnt--;
      }
    }

    pprev_c = prev_c;
    prev_c = c;
  }

  std::cout << cnt;

  return 0;
}