#include <iostream>;
#include <string>;
#include <vector>;
#include <fstream>;
using namespace std;
int main(int argc, char const *argv[])
{
    ifstream in("in.txt");
    string s;
    in >> s;
    int n = s.length();
    vector<int> p(n);
    vector<int> sum(n + 1);
    int j = 0;
    for (int i = 1; i < s.length(); i++)
    {
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    for (int i = 0; i < n; i++)
    {
        sum[p[i]]++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        sum[p[i - 1]] += sum[i];
    }
    vector<int> v;
    int j = s.length() - 1;
    while (j > 0 && p[j] > 0)
    {
        v.push_back(p[j]);
        j = p[j] - 1;
    }
    cout << v.size() + 1 << "\n";
    while (v.size() > 0)
    {
        cout << v.back() << " " << sum[v.back()] + 1 << "\n";
        v.pop_back();
    }
    cout << s.length() << " " << 1 << "\n";
    return 0;
}
