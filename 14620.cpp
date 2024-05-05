#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10][10];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  vector<pair<int, int>> vec;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      vec.push_back({i, j});
    }
  }

  int min_cost = 20000;
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        int x1, y1, x2, y2, x3, y3;
        tie(y1, x1) = vec[i];
        tie(y2, x2) = vec[j];
        tie(y3, x3) = vec[k];

        if (abs(x1 - x2) + abs(y1 - y2) < 3 ||
            abs(x2 - x3) + abs(y2 - y3) < 3 ||
            abs(x1 - x3) + abs(y1 - y3) < 3) {
          continue;
        }

        int cost = 0;
        cost += (arr[y1 - 1][x1] + arr[y1][x1] + arr[y1 + 1][x1] +
                 arr[y1][x1 - 1] + arr[y1][x1 + 1]);
        cost += (arr[y2 - 1][x2] + arr[y2][x2] + arr[y2 + 1][x2] +
                 arr[y2][x2 - 1] + arr[y2][x2 + 1]);
        cost += (arr[y3 - 1][x3] + arr[y3][x3] + arr[y3 + 1][x3] +
                 arr[y3][x3 - 1] + arr[y3][x3 + 1]);

        min_cost = min({min_cost, cost});
      }
    }
  }

  cout << min_cost;
  return 0;
}