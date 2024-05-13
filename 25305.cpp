#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> vec;

bool cmp(int a, int b) { return a > b; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec.push_back(x);
  }
  sort(vec.begin(), vec.end(), cmp);

  cout << vec[k - 1];

  return 0;
}