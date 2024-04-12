#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int a, b, c;
  std::cin >> a >> b >> c;

  int arr[100] = {0};
  for (int i = 0; i < 3; i++) {
    int in, out;
    std::cin >> in >> out;

    for (int j = in - 1; j < out - 1; j++) {
      arr[j]++;
    }
  }

  int price = 0;
  for (int i = 0; i < 100; i++) {
    if (arr[i] == 3) {
      price += (3 * c);
    } else if (arr[i] == 2) {
      price += (2 * b);
    } else if (arr[i] == 1) {
      price += (a);
    }
  }
  std::cout << price;

  return 0;
}