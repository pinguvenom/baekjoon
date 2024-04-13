#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }

  sort(vec.begin(), vec.end());

  int i = 0;
  int j = vec.size() - 1;
  int cnt = 0;

  while (true) {
    if (i >= j) {
      break;
    }

    int sum = vec[i] + vec[j];
    if (sum == m) {
      cnt++;
      i++;
      j--;
    } else if (sum < m) {
      i++;
    } else if (sum > m) {
      j--;
    }
  }

  std::cout << cnt;
  return 0;
}