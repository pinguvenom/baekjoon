#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  set<string> st;

  for (int i = 1; i <= s.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      if (j + i > s.size()) {
        break;
      }
      st.insert(s.substr(j, i));
    }
  }

  cout << st.size();

  return 0;
}