#include <bits/stdc++.h>
using namespace std;

int arr[5];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
  }

  int val = 0;
  for (int i = 0; i < 5; i++) {
    val += (int)pow(arr[i], 2);
  }
  cout << val % 10;
  return 0;
}