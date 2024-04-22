#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0) {
      break;
    }
    int max_element = max({a, b, c});
    if (max_element * 2 >= a + b + c) {
      cout << "Invalid\n";
    } else if (a == b && b == c && c == a) {
      cout << "Equilateral\n";
    } else if (a == b || b == c || c == a) {
      cout << "Isosceles\n";
    } else {
      cout << "Scalene\n";
    }
  }

  return 0;
}