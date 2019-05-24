#include <bits/stdc++.h>
using namespace std;
char passwd[100];
void solve() {
  cin >> passwd;
  int cnt = 0;
  bool r2 = false, r3 = false, r4 = false;
  for (int i = 0; passwd[i]; i++) {
    if (passwd[i] >= 'A' && passwd[i] <= 'Z') r2 |= true;
    if (passwd[i] >= 'a' && passwd[i] <= 'z') r3 |= true;
    if (passwd[i] >= '0' && passwd[i] <= '9') r4 |= true;
    cnt++;
  }
  cout << (cnt >= 5 && r2 && r3 && r4 ? "Correct" : "Too weak") << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}