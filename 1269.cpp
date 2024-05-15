#include <bits/stdc++.h>
using namespace std;

int a, b;
set<long long> st1, st2, inter, uni;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    long long x;
    cin >> x;
    st1.insert(x);
  }
  for (int i = 0; i < b; i++) {
    long long x;
    cin >> x;
    st2.insert(x);
  }

  set_intersection(st1.begin(), st1.end(), st2.begin(), st2.end(),
                   inserter(inter, inter.begin()));
  set_union(st1.begin(), st1.end(), st2.begin(), st2.end(),
            inserter(uni, uni.begin()));

  cout << uni.size() - inter.size();

  return 0;
}