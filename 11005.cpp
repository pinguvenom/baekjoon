#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n;
  int b;
  cin >> n >> b;

  vector<char> vec;
  while (true) {
    if (n % b >= 10) {
      vec.push_back((char)('A' - 10 + (n % b)));
    } else {
      vec.push_back((char)('0' + (n % b)));
    }
    if (n >= b) {
      n = n / b;
    } else {
      break;
    }
  }

  reverse(vec.begin(), vec.end());
  for (auto c : vec) {
    cout << c;
  }

  return 0;
}