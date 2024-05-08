#include <bits/stdc++.h>
using namespace std;

int arr[8];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 8; i++) {
    cin >> arr[i];
  }

  bool b_ascending = true;
  bool b_descending = true;
  for (int i = 0; i < 8; i++) {
    if (arr[i] != i + 1) {
      b_ascending = false;
    }
    if (arr[i] != 8 - i) {
      b_descending = false;
    }
  }
  if (b_ascending) {
    cout << "ascending";
  } else if (b_descending) {
    cout << "descending";
  } else {
    cout << "mixed";
  }
}