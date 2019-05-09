#include <bits/stdc++.h>
using namespace std;

int ceilDiv(int a, int b) { return a % b ? a / b + 1 : a / b; }

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int hy, ay, dy, hm, am, dm, ph, pa, pd;
  cin >> hy >> ay >> dy >> hm >> am >> dm >> ph >> pa >> pd;
  int amdy = am - dy, aydm = ay - dm;
  if (amdy <= 0) {
    cout << pa * max(0, -aydm + 1) << "\n";
    exit(0);
  }
  int ans = amdy * pd + pa * max(0, -aydm + 1);
  for (int ba = max(0, -aydm + 1);; ba++) {
    int md = aydm + ba, costa = pa * ba;
    int tm = ceilDiv(hm, md);
    for (int bh = 0;; bh++) {
      int yh = hy + bh, costh = ph * bh;
      if (ceilDiv(yh, amdy) > tm) {
        ans = min(ans, costa + costh);
        break;
      }
      for (int bd = 0; bd < amdy; bd++) {
        int yd = amdy - bd, costd = pd * bd;
        if (ceilDiv(yh, yd) > tm) {
          ans = min(ans, costa + costh + costd);
          break;
        }
      }
    }
    if (tm == 1) break;
  }
  cout << ans << "\n";
  return 0;
}