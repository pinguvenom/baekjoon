#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<pair<int, int>> jewel;
vector<int> bag;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int weight, price;
    cin >> weight >> price;
    jewel.push_back({weight, price});
  }
  for (int i = 0; i < k; i++) {
    int weight;
    cin >> weight;
    bag.push_back(weight);
  }
  sort(jewel.begin(), jewel.end());
  sort(bag.begin(), bag.end());

  int j = 0;
  long long total = 0;
  priority_queue<int> pq;
  for (int i = 0; i < k; i++) {
    while (j < n && jewel[j].first <= bag[i]) {
      pq.push(jewel[j].second);
      j++;
    }
    if (pq.size()) {
      total += pq.top();
      pq.pop();
    }
  }
  cout << total;

  return 0;
}