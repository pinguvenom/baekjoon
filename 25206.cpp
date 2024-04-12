#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n = 20;
  double weight_sum = 0.0, score_by_weight_sum = 0.0;

  while (n--) {
    std::string subject, score_str;
    double weight, score;
    std::cin >> subject >> weight >> score_str;

    if (score_str == "P") {
      continue;
    } else if (score_str == "A+") {
      score = 4.5;
    } else if (score_str == "A0") {
      score = 4.0;
    } else if (score_str == "B+") {
      score = 3.5;
    } else if (score_str == "B0") {
      score = 3.0;
    } else if (score_str == "C+") {
      score = 2.5;
    } else if (score_str == "C0") {
      score = 2.0;
    } else if (score_str == "D+") {
      score = 1.5;
    } else if (score_str == "D0") {
      score = 1.0;
    } else if (score_str == "F") {
      score = 0.0;
    }

    weight_sum += weight;
    score_by_weight_sum += (score * weight);
  }

  std::cout.precision(7);
  std::cout << score_by_weight_sum / weight_sum;

  return 0;
}