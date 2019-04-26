#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    if (n < 3)
    {
        cout << 0 << "\n";
        return 0;
    }
    int64_t sum = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    if (sum % 3 != 0)
    {
        cout << "0"
             << "\n";
        return 0;
    }
    sum /= 3;
    unordered_map<int64_t, int> map;
    int64_t count = 0;
    int64_t ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        count += v[i];
        if (count == 2 * sum && map.count(sum))
        {
            ans += map[sum];
        }
        map[count]++;
    }
    cout << ans << "\n";
    return 0;
}
