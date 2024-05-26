#include <bits/stdc++.h>
using namespace std;

int era[4000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 2; i <= 4000000; i++) {
    if (era[i]) {
      continue;
    }
    for (int j = i * 2; j <= 4000000; j += i) {
      era[j] = 1;
    }
  }

  vector<int> vec;
  for (int i = 2; i <= 4000000; i++) {
    if (era[i] == 0) {
      vec.push_back(i);
    }
  }

  int n;
  cin >> n;

  int sum = 0;
  int cnt = 0;
  int start = 0, end = 0;
  while (true) {
    if (sum >= n) {
      sum -= vec[start];
      start++;
    } else if (end == vec.size()) {
      break;
    } else {
      sum += vec[end];
      end++;
    }

    if (sum == n) {
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}