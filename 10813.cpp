#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  int arr[100] = {0};
  for (int i = 0; i < N; i++) {
    arr[i] = i + 1;
  }

  for (int i = 0; i < M; i++) {
    int a, b;
    std::cin >> a >> b;

    int temp = arr[b - 1];
    arr[b - 1] = arr[a - 1];
    arr[a - 1] = temp;
  }

  for (int i = 0; i < N; i++) {
    std::cout << arr[i] << ' ';
  }
  return 0;
}