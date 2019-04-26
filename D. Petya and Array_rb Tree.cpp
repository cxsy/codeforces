#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll int64_t

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, t;
  cin >> n >> t;
  ll sum = 0;
  ll ans = 0;
  ll tmp;
  ordered_set ss;
  ss.insert(0);
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    sum += tmp;
    ans += ss.order_of_key(t - sum);
    ss.insert(-sum);
  }
  cout << ans << "\n";
  return 0;
}