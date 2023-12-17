#include <iostream>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin >> n;
    int mx = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int current;
        cin >> current;
        mx = max(mx, current);
        ans += mx - current;
    }
    cout << ans;
}