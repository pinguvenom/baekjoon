#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  int arr[100] = {0};
  for (int i = 0; i < M; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    for (int j = a - 1; j < b; j++) {
      arr[j] = c;
    }
  }

  for (int i = 0; i < N; i++) {
    std::cout << arr[i] << ' ';
  }
  return 0;
}