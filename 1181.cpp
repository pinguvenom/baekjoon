#include <bits/stdc++.h>
using namespace std;

string arr[20001];

bool comp(const string& a, const string& b) {
  if (a.size() == b.size()) {
    return a < b;
  } else {
    return a.size() < b.size();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(&arr[0], &arr[0] + n, comp);

  for (int i = 0; i < n; i++) {
    if (arr[i] == arr[i + 1]) {
      continue;
    }
    cout << arr[i] << '\n';
  }

  return 0;
}