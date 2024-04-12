#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n, 0);
  vector<int> psum(n + 1, 0);

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
    psum[i + 1] = psum[i] + arr[i];
  }

  int max = INT_MIN;
  for (int i = k; i < n + 1; i++) {
    int val = psum[i] - psum[i - k];
    if (val > max) {
      max = val;
    }
  }

  std::cout << max;

  return 0;
}