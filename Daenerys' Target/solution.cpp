#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
#define fo(i,n) for(int i=0 ; i<n ; i++)
#define get(arr,n) fo(i,n){ int x; cin>>x; arr.push_back(x);}

using namespace std;

int n, target;
vector<int> a,b;
int dp[101][3][5001];

int func(int i, int prev, int sum) 
{
    if(sum > target)
        return 0;
    if(i >= n)
    {
        if(sum == target)
            return 1;
        return 0;
    }
    if(dp[i][prev][sum] != -1)
        return dp[i][prev][sum];
    if(prev == 0)
    {
        return dp[i][prev][sum] = ((func(i+1, 1, sum+a[i])+func(i+1, 2, sum+b[i]))%mod+func(i+1, 0, sum))%mod;
    }
    else if(prev == 1)
    {
        return dp[i][prev][sum] = (func(i+1, 2, sum+b[i])+func(i+1, 0, sum))%mod;
    }
    else
    {
        return dp[i][prev][sum] = (func(i+1, 1, sum+a[i])+func(i+1, 0, sum))%mod;
    }
}

void solve()
{
    cin >> n >> target;
    get(a, n);
    get(b, n);
    memset(dp, -1, sizeof(dp));
    cout << func(0, 0, 0);
}

int32_t main()
{
    fast;

    int tc = 1;
    //cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}