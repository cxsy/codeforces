#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int len = s.length();
    vector<bool> dp(1001);
    for (char c : s)
    {
        int d = c - '0';
        if (d % 8 == 0) {
            cout << "YES\n" << d << "\n";
            return 0;
        }
        vector<int> tmp;
        for (int num = 1000; num >= 0; num--)
        {
            if (dp[num])
            {
                int nn = num * 10 + d;
                if (nn > 1000) {
                    tmp.push_back(nn % 1000);
                } else {
                    dp[nn] = true;
                }
                if (nn % 8 == 0) {
                    cout << "YES\n" << nn << "\n";
                    return 0;
                }
            }
        }
        while (tmp.size() > 0) {
            dp[tmp.back()] = true;
            tmp.pop_back();
        }
        dp[d] = true;
    }
    cout << "NO\n";
    return 0;
}
