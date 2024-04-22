#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> a >> b >> c;

  int max_element = max({a, b, c});
  int sum = a + b + c;

  int real_max_element = min({sum - max_element - 1, max_element});
  cout << sum - max_element + real_max_element;

  return 0;
}