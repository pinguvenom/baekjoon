#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int arr[1000] = {0};
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  int max_num = *std::max_element(arr, arr + n);
  std::cout << (double)std::accumulate(arr, arr + n, 0) * 100 / max_num / n;

  return 0;
}