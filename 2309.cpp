#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve(int arr[]) {
  int sum = std::accumulate(arr, arr + 9, 0);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < i; j++) {
      if (sum - arr[i] - arr[j] == 100) {
        return {i, j};
      }
    }
  }
  return {0, 0};
}

int main() {
  int arr[9];
  for (int i = 0; i < 9; i++) {
    cin >> arr[i];
  }

  pair<int, int> outlier = solve(arr);

  vector<int> rst;
  for (int i = 0; i < 9; i++) {
    if (i == outlier.first || i == outlier.second) {
      continue;
    }
    rst.push_back(arr[i]);
  }

  sort(rst.begin(), rst.end());
  for (int i : rst) {
    std::cout << i << "\n";
  }

  return 0;
}