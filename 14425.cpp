#include <bits/stdc++.h>
using namespace std;

int n, m;
set<string> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    st.insert(s);
  }

  int cnt = 0;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (st.find(s) != st.end()) {
      cnt++;
    }
  }

  cout << cnt;

  return 0;
}