#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, v;
unordered_set<int> ss1, ss2;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> v;
      for (int p : ss1) {
        ss2.insert(p | v);
      }
      ss1.insert(v);
    }
    cout << ss1.size() << "\n";
    ss1.clear();
    ss2.clear();
  }
  return 0;
}