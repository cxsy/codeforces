#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int sta[N];
int top = 0;
string s;
void solve() {
  cin >> s;
  sta[top++] = -1;
  int maxx = 0, cnt = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      sta[top++] = i;
    } else if(top > 1) {
      top--;
      int len = i - sta[top - 1];
      if (len > maxx) {
        maxx = len;
        cnt = 1;
      } else if (maxx == len) {
        cnt++;
      }
    } else {
      sta[0] = i;
    }
  }
  cout << maxx << " " << cnt << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}