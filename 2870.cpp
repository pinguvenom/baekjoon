#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
  if (a.size() > b.size()) {
    return false;
  } else if (a.size() < b.size()) {
    return true;
  } else {
    for (int i = 0; a.size(); i++) {
      if (a[i] > b[i]) {
        return false;
      } else if (a[i] < b[i]) {
        return true;
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<string> vec;
  while (n--) {
    string s;
    cin >> s;

    int start_idx = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        if (start_idx == -1) {
          start_idx = i;
        } else if (s[start_idx] == '0') {
          start_idx = i;
        }
      } else if (start_idx != -1) {
        vec.push_back(s.substr(start_idx, i - start_idx));
        start_idx = -1;
      }
    }
    if (start_idx != -1) {
      vec.push_back(s.substr(start_idx));
    }
  }

  sort(vec.begin(), vec.end(), cmp);
  for (auto i : vec) {
    cout << i << '\n';
  }

  return 0;
}