#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    map<string, int> _map;
    while (n--) {
      string clothes, type;
      cin >> clothes >> type;
      _map[type]++;
    }

    int tc = 1;
    for (auto i : _map) {
      tc *= (i.second + 1);
    }
    std::cout << tc - 1 << '\n';
  }

  return 0;
}