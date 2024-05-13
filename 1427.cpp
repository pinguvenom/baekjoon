#include <bits/stdc++.h>
using namespace std;

vector<char> vec;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    vec.push_back(s[i]);
  }

  sort(vec.begin(), vec.end(), greater<char>());

  for (auto c : vec) {
    cout << c;
  }

  return 0;
}