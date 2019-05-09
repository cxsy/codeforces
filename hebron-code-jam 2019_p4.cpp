#include <bits/stdc++.h>
using namespace std;
const string di[4]{"north", "east", "south", "west"};
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string op;
  int d = 0;
  for (int i = 0; i < n; i++) {
    cin >> op;
    if (op == "right") {
      d = (d + 1) % 4;
    } else if (op == "left") {
      d = (d + 3) % 4;
    } else {
      d = (d + 2) % 4;
    }
  }
  cout << di[d] << "\n";
  return 0;
}