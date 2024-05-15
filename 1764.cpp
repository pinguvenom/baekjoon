#include <bits/stdc++.h>
using namespace std;

int n, m;
set<string> st1, st2, intersect;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    st1.insert(s);
  }
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    st2.insert(s);
  }

  set_intersection(st1.begin(), st1.end(), st2.begin(), st2.end(),
                   inserter(intersect, intersect.begin()));

  cout << intersect.size() << '\n';
  for (auto x : intersect) {
    cout << x << '\n';
  }

  return 0;
}
