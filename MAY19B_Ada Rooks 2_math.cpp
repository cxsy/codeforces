#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1005;
char A[NMAX][NMAX];
int ne[NMAX], li[8];
int T, N;
void init() {
  for (int i = 0; i < N; i++) {
    ne[i] = i + 1;
    for (int j = 0; j < N; j++) A[i][j] = '.';
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    init();
    int st = 0;
    for (int j = 0; j < N && st < N; j++) {
      int k = 0, e = st;
      while (k < 8 && e < N) li[k++] = e, e = ne[e];
      if (k < 8) j--;
      for (int t = 0; t < k; t++) {
        A[j][li[t]] = 'O';
        ne[li[t]] = e;
      }
      if (e == N) st++;
    }
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) cout << A[i][j] << "\n"[j != N - 1];
  }
  return 0;
}