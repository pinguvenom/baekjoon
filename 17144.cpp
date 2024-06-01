#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int arr[50][50];

pair<int, int> air_cleaner1;
pair<int, int> air_cleaner2;
bool cleaner_flag = false;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> r >> c >> t;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == -1) {
        arr[i][j] = 0;
        if (!cleaner_flag) {
          air_cleaner1 = {i, j};
          cleaner_flag = true;
        } else {
          air_cleaner2 = {i, j};
        }
      }
    }
  }

  while (t--) {
    // spread fine dust
    int arr_tmp[50][50];
    memset(arr_tmp, 0, sizeof(arr_tmp));

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (arr[i][j] == 0) {
          continue;
        }

        int adj_new_val = arr[i][j] / 5;
        int center_new_val = arr[i][j];
        if (i + 1 < r) {
          if (!(j == 0 && i + 1 == air_cleaner1.first)) {
            arr_tmp[i + 1][j] += adj_new_val;
            center_new_val -= adj_new_val;
          }
        }
        if (i - 1 >= 0) {
          if (!(j == 0 && i - 1 == air_cleaner2.first)) {
            arr_tmp[i - 1][j] += adj_new_val;
            center_new_val -= adj_new_val;
          }
        }
        if (j + 1 < c) {
          arr_tmp[i][j + 1] += adj_new_val;
          center_new_val -= adj_new_val;
        }
        if (j - 1 >= 0) {
          if (!(j == 1 &&
                (i == air_cleaner1.first || i == air_cleaner2.first))) {
            arr_tmp[i][j - 1] += adj_new_val;
            center_new_val -= adj_new_val;
          }
        }
        arr_tmp[i][j] += center_new_val;
      }
    }

    // run air cleaner1
    for (int i = air_cleaner1.first - 2; i >= 0; i--) {
      arr_tmp[i + 1][air_cleaner1.second] = arr_tmp[i][air_cleaner1.second];
    }
    for (int j = 0; j < c - 1; j++) {
      arr_tmp[0][j] = arr_tmp[0][j + 1];
    }
    for (int i = 0; i < air_cleaner1.first; i++) {
      arr_tmp[i][c - 1] = arr_tmp[i + 1][c - 1];
    }
    for (int j = c - 2; j >= 0; j--) {
      arr_tmp[air_cleaner1.first][j + 1] = arr_tmp[air_cleaner1.first][j];
    }

    // run air cleaner2
    for (int i = air_cleaner2.first + 1; i < r - 1; i++) {
      arr_tmp[i][air_cleaner2.second] = arr_tmp[i + 1][air_cleaner2.second];
    }
    for (int j = 0; j < c - 1; j++) {
      arr_tmp[r - 1][j] = arr_tmp[r - 1][j + 1];
    }
    for (int i = r - 2; i >= air_cleaner2.first; i--) {
      arr_tmp[i + 1][c - 1] = arr_tmp[i][c - 1];
    }
    for (int j = c - 2; j >= 0; j--) {
      arr_tmp[air_cleaner2.first][j + 1] = arr_tmp[air_cleaner2.first][j];
    }

    memcpy(arr, arr_tmp, sizeof(arr));
  }

  int sum = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      sum += arr[i][j];
    }
  }
  cout << sum;

  return 0;
}