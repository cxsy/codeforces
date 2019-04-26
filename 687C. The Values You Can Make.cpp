#include <iostream>
using namespace std;
const int NMAX = 505;
int coins[NMAX];
int dp[NMAX][NMAX];

int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int v = k; v >= coins[i]; v--) {
      for (int subv = 0; subv <= v - coins[i]; subv++) {
        if (dp[v - coins[i]][subv] == 1) {
          dp[v][subv] = 1;
          dp[v][subv + coins[i]] = 1;
        }
      }
    }
  }
  int q = 0;
  for (int i = 0; i <= k; i++) {
    if (dp[k][i] == 1) {
      q++;
    }
  }
  cout << q << "\n";
  int count = 0;
  for (int i = 0; i <= k; i++) {
    if (dp[k][i] == 1) {
      count++;
      if (count < q) {
        cout << dp[k][i] << " ";
      } else {
        cout << dp[k][i];
      }
    }
  }
  return 0;
}
