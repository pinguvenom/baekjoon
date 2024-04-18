#include <bits/stdc++.h>
using namespace std;

char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    string s;
    cin >> s;

    if (s == "end") {
      break;
    }

    bool b_acceptable = false;
    int successive_vowel_cnt = 0;
    int successive_constant_cnt = 0;
    char prev_c = ' ';
    for (char c : s) {
      if (c == vowel[0] || c == vowel[1] || c == vowel[2] || c == vowel[3] ||
          c == vowel[4]) {
        b_acceptable = true;
        successive_vowel_cnt++;
        successive_constant_cnt = 0;
      } else {
        successive_vowel_cnt = 0;
        successive_constant_cnt++;
      }

      if (successive_vowel_cnt >= 3 || successive_constant_cnt >= 3) {
        b_acceptable = false;
        break;
      }

      if (prev_c == c && c != 'e' && c != 'o') {
        b_acceptable = false;
        break;
      }
      prev_c = c;
    }

    if (b_acceptable) {
      cout << "<" << s << "> is acceptable.\n";
    } else {
      cout << "<" << s << "> is not acceptable.\n";
    }
  }

  return 0;
}