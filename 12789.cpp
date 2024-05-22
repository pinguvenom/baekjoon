#include <bits/stdc++.h>
using namespace std;
int arr[1000];
stack<int> stk;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int match = 1;
  int i = 0;
  while (true) {
    if (i == n && !(stk.size() && stk.top() == match)) {
      break;
    }

    if (arr[i] == match) {
      i++;
      match++;
    } else if (stk.size() && stk.top() == match) {
      stk.pop();
      match++;
    } else {
      stk.push(arr[i]);
      i++;
    }
  }

  if (stk.empty()) {
    cout << "Nice";
  } else {
    cout << "Sad";
  }

  return 0;
}