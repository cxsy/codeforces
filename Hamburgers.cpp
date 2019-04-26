#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  string rec;
  cin >> rec;
  int nb, ns, nc, pb, ps, pc;
  int64_t r;
  int count[3] = {};
  for (int i = 0; i < rec.length(); i++) {
    if (rec[i] == 'B') {
      count[0]++;
    } else if (rec[i] == 'S') {
      count[1]++;
    } else {
      count[2]++;
    }
  }

  int n[3];
  int p[3];
  cin >> n[0] >> n[1] >> n[2] >> p[0] >> p[1] >> p[2] >> r;
  int64_t l = 0, h = r + n[0] + n[1] + n[2];
  while (l <= h) {
    int64_t mid = (h - l) / 2 + l;
    int64_t need[3] = {};
    int64_t cost = 0;
    for (int i = 0; i < 3; i++) {
      need[i] = max(0LL, 1LL * count[i] * mid - n[i]);
      cost += need[i] * p[i];
    }
    if (cost > r) {
      h = mid - 1;
    } else if (cost == r) {
      cout << mid << "\n";
      return 0;
    } else {
      l = mid + 1;
    }
  }
  cout << r << "\n";
  return 0;
}