#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k;
  cin >> k;

  stack<int> stk;
  int sum = 0;
  while (k--) {
    int x;
    cin >> x;
    if (x == 0) {
      sum -= stk.top();
      stk.pop();
    } else {
      stk.push(x);
      sum += x;
    }
  }

  cout << sum;
  return 0;
}