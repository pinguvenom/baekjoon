#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;
    if (s == "push") {
      int x;
      cin >> x;
      q.push(x);
    } else if (s == "pop") {
      if (q.size()) {
        cout << q.front() << '\n';
        q.pop();
      } else {
        cout << "-1\n";
      }
    } else if (s == "size") {
      cout << q.size() << '\n';
    } else if (s == "empty") {
      if (q.empty()) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    } else if (s == "front") {
      if (q.size()) {
        cout << q.front() << '\n';
      } else {
        cout << "-1\n";
      }
    } else if (s == "back") {
      if (q.size()) {
        cout << q.back() << '\n';
      } else {
        cout << "-1\n";
      }
    }
  }

  return 0;
}