#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N;
  std::cin >> N;

  int arr[100];
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  int v;
  std::cin >> v;

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (arr[i] == v) {
      cnt++;
    }
  }

  std::cout << cnt;

  return 0;
}