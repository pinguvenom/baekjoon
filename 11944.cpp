#include <bits/stdc++.h>
using namespace std;
string n;
int m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  int n_int = atoi(n.c_str());
  int _min = min({n_int * (int)n.size(), m});
  for (int i = 0; i < _min; i++) {
    cout << n[i % n.size()];
  }

  return 0;
}