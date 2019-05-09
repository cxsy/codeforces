#include <bits/stdc++.h>
using namespace std;
char s[10];
int T;
int A[2][10];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> s;
      if (j < 2) {
        for (int k = 0; k < 10; k++) A[j][k] = s[k] - '0';
      } else {
        int o = 0, max = 0;
        for (int k = 0; k < 10; k++) o += s[k] - '0';
        int z = 10 - o;
        vector<int> t(10), sol(10);
        sort(&A[0][0], &A[0][0] + 10);
        do {
          sort(&A[1][0], &A[1][0] + 10);
          do {
            int cc = 0, one = o, zero = z;
            for (int k = 0; k < 10; k++) {
              t[k] = A[0][k] ^ A[1][k];
              if (t[k] == 1) {
                if (zero) {
                  zero--;
                } else {
                  t[k] = 0;
                }
              } else {
                if (one) {
                  one--;
                  t[k] = 1;
                }
              }
              cc += (t[k] << (9 - k));
            }
            if (cc > max) {
              max = cc;
              sol = t;
            }
          } while (next_permutation(&A[1][0], &A[1][0] + 10));
        } while (next_permutation(&A[0][0], &A[0][0] + 10));
        for (int k = 0; k < 10; k++) cout << sol[k];
        cout << "\n";
      }
    }
  }
  return 0;
}