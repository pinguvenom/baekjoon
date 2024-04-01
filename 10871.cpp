#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, X;
  std::cin >> N >> X;

  int arr[10000];
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  for (int i = 0; i < N; i++) {
    if (arr[i] < X) {
      std::cout << arr[i] << ' ';
    }
  }

  return 0;
}