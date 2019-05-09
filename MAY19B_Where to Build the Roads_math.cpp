#include <bits/stdc++.h>
using namespace std;

#define LL int64_t
#define ii pair<LL, LL>
#define mp make_pair

const int NMAX = 1e4 + 5;

ii A[NMAX];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T, N, x, y;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    for (int j = 0; j < N; j++) cin >> x >> y, A[j] = mp(x, y);
    LL minDiff = INT64_MAX;
    sort(A, A + N, [](const ii &a, const ii &b) -> bool {
      return a.first + a.second < b.first + b.second;
    });
    for (int j = 1; j < N; j++) {
      LL d = (A[j].first + A[j].second) - (A[j - 1].first + A[j - 1].second);
      minDiff = min(minDiff, abs(d));
    }
    sort(A, A + N, [](const ii &a, const ii &b) -> bool {
      return a.first - a.second < b.first - b.second;
    });
    for (int j = 1; j < N; j++) {
      LL d = (A[j].first - A[j].second) - (A[j - 1].first - A[j - 1].second);
      minDiff = min(minDiff, abs(d));
    }
    cout.precision(7);
    cout << fixed << minDiff / 2.0 << "\n";
  }
  return 0;
}