#include <bits/stdc++.h>
using namespace std;
int arr[10];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long a, b, c;
  cin >> a >> b >> c;
  long long rst = a * b * c;

  while (rst) {
    arr[rst % 10]++;
    rst /= 10;
  }

  for (auto x : arr) {
    cout << x << '\n';
  }
  return 0;
}