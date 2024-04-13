#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<string> vec;
  map<string, int> map;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    vec.push_back(s);
    map[s] = i + 1;
  }

  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;

    if (atoi(s.c_str()) != 0) {
      std::cout << vec[atoi(s.c_str()) - 1] << '\n';
    } else {
      std::cout << map[s] << '\n';
    }
  }

  return 0;
}