#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int maxx = max(s1, max(s2, s3));
    int minn = min(s1, min(s2, s3));
    int sum = s1 + s2 + s3;
    cout << "Case " + i << ": " << sum - maxx - minn << "\n";
  }
  return 0;
}