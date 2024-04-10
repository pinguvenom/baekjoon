#include <bits/stdc++.h>

int main() {
  int arr_gt[6] = {1, 1, 2, 2, 2, 8};
  int arr_input[6];
  for (int i = 0; i < 6; i++) {
    std::cin >> arr_input[i];
  }
  for (int i = 0; i < 6; i++) {
    std::cout << arr_gt[i] - arr_input[i] << ' ';
  }
  return 0;
}