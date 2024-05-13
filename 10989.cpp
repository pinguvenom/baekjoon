#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[10001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[x]++;
  }

  for (int i = 1; i <= 10000; i++) {
    for (int j = 0; j < arr[i]; j++) {
      cout << i << '\n';
    }
  }

  return 0;
}