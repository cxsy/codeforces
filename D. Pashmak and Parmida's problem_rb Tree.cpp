#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const int NMAX = 1e6 + 5;
int arr[NMAX];

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ordered_set ss;
  int n;
  cin >> n;
  unordered_map<int, int> mm;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mm[arr[i]]++;
  }
  unordered_map<int, int> mm1;
  int64_t ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans += ss.order_of_key(mm[arr[i]]);
    mm1[arr[i]]++;
    ss.insert(mm1[arr[i]]);
    mm[arr[i]]--;
  }
  cout << ans << "\n";
  return 0;
}