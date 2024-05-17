#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> vec;

long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    vec.push_back(x);
  }

  sort(vec.begin(), vec.end());

  long long step = vec[1] - vec[0];
  for (int i = 1; i < n; i++) {
    step = gcd(vec[i] - vec[i - 1], step);
  }

  cout << (vec[vec.size() - 1] - vec[0]) / step - vec.size() + 1;

  return 0;
}