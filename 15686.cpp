#include <bits/stdc++.h>
using namespace std;

int n, m;
int min_dist;
int arr[50][50];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int get_city_chicken_distance(vector<int>& b) {
  int city_chicken_dist = 0;
  for (int j = 0; j < house.size(); j++) {
    int chicken_dist = n * n;
    for (int i = 0; i < b.size(); i++) {
      int dist = (abs(chicken[b[i]].first - house[j].first) +
                  abs(chicken[b[i]].second - house[j].second));
      if (dist < chicken_dist) {
        chicken_dist = dist;
      }
    }
    city_chicken_dist += chicken_dist;
  }
  return city_chicken_dist;
}

void combi(int start, vector<int>& b) {
  if (b.size() == m) {
    int dist = get_city_chicken_distance(b);
    if (dist < min_dist) {
      min_dist = dist;
    }
    return;
  }

  for (int i = start + 1; i < chicken.size(); i++) {
    b.push_back(i);
    combi(i, b);
    b.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];

      if (arr[i][j] == 2) {
        chicken.push_back({i, j});
      } else if (arr[i][j] == 1) {
        house.push_back({i, j});
      }
    }
  }
  min_dist = house.size() * n * n;

  vector<int> b;
  combi(-1, b);

  cout << min_dist;
  return 0;
}