#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::string s;
  std::cin >> s;

  int arr[26];
  std::memset(arr, -1, sizeof(arr));

  for (int i = 0; i < s.size(); i++) {
    if (arr[s[i] - 'a'] == -1) {
      arr[s[i] - 'a'] = i;
    }
  }

  for (int a : arr) {
    std::cout << a << ' ';
  }

  return 0;
}