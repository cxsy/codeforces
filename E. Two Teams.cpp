#include <bits/stdc++.h>
using namespace std;

const int NMAX = 2e5 + 5;

int le[NMAX], ri[NMAX];
int arr[NMAX], team[NMAX];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int l = 0, cur;
  for (int i = 1; i <= n; i++) {
    cin >> cur;
    arr[i] = cur;
    ri[l] = cur;
    le[cur] = l;
    l = cur;
  }
  ri[cur] = 0;
  int tn = 1;
  for (int i = n; i >= 1; i--) {
    if (team[i] > 0) continue;
    team[i] = tn;
    int count = 0, ll = le[i];
    while (count < k && ll > 0) {
      count++;
      team[ll] = tn;
      ll = le[ll];
    }
    count = 0;
    int rr = ri[i];
    while (count < k && rr > 0) {
      count++;
      team[rr] = tn;
      rr = ri[rr];
    }
    le[rr] = ll;
    ri[ll] = rr;
    tn = 3 - tn;
  }
  for (int i = 1; i <= n; i++) {
    cout << team[arr[i]];
  }
  cout << "\n";
  return 0;
}