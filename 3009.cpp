#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x_arr[3], y_arr[3];
  for (int i = 0; i < 3; i++) {
    cin >> x_arr[i] >> y_arr[i];
  }

  if (x_arr[0] == x_arr[1]) {
    cout << x_arr[2] << ' ';
  } else if (x_arr[0] == x_arr[2]) {
    cout << x_arr[1] << ' ';
  } else if (x_arr[1] == x_arr[2]) {
    cout << x_arr[0] << ' ';
  }

  if (y_arr[0] == y_arr[1]) {
    cout << y_arr[2];
  } else if (y_arr[0] == y_arr[2]) {
    cout << y_arr[1];
  } else if (y_arr[1] == y_arr[2]) {
    cout << y_arr[0];
  }

  return 0;
}