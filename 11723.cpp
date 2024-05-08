#include <bits/stdc++.h>
using namespace std;

int m, s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m;
  std::string bufferflash;
  std::getline(std::cin, bufferflash);

  for (int i = 0; i < m; i++) {
    string line;
    getline(cin, line);

    string str;
    int x;

    if (line.find(" ") != string::npos) {
      str = line.substr(0, line.find(" "));
      x = atoi(line.substr(line.find(" ") + 1).c_str());
    } else {
      str = line;
      x = 0;
    }

    if (str == "add") {
      s |= (1 << x);
    } else if (str == "remove") {
      s &= ~(1 << x);
    } else if (str == "check") {
      cout << (bool)(s & (1 << x)) << '\n';
    } else if (str == "toggle") {
      s ^= (1 << x);
    } else if (str == "all") {
      s = ~0;
    } else if (str == "empty") {
      s = 0;
    }
  }

  return 0;
}