#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int w, b;
double dp[N][N][2];

double helper(int ww, int bb, int t) {
  if (ww < 0 || bb < 0) return 0.0;
  if (dp[ww][bb][t] >= 0.0) return dp[ww][bb][t];
  if (ww == 0) return dp[0][bb][t] = 0.0;
  if (t == 1) {
    if (bb == 0) return dp[ww][0][1] = 0.0;
    return dp[ww][bb][1] = bb / (ww + bb) *
                           ((bb - 1) / (ww + bb - 1) * helper(ww, bb - 2, 0) +
                            ww / (ww + bb - 1) * helper(ww - 1, bb - 1, 0));

  } else {
    if (bb == 0) return dp[ww][0][0] = 1.0;
    return dp[ww][bb][0] =
               ww / (ww + bb) + bb / (ww + bb) * helper(ww, bb - 1, 1);
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> w >> b;
  fill(&dp[0][0][0], &dp[0][0][0] + N * N * 2, -1.0);
  cout.precision(10);
  cout << fixed << helper(w, b, 0) << "\n";
  return 0;
}