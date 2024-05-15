#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n;
  cin >> n;

  set<string> st;
  for (int i = 0; i < n; i++) {
    string name, action;
    cin >> name >> action;

    if (action == "enter") {
      st.insert(name);
    } else {
      st.erase(name);
    }
  }
  for (auto it = st.rbegin(); it != st.rend(); it++) {
    cout << *it << '\n';
  }

  return 0;
}