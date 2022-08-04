#include<iostream>
#define loop(i, start, end) for(ll i=start; i<end; i++) 
typedef long long int ll;
 
using namespace std;

void solve()
{
    ll n;
    cin>>n;

    string s;
    cin>>s;

    int isGuarded = 0;

    int currlen = 0, maxlen = 0;
    for(ll i=0; i<n; i++) {
        if(s[i] == 'G') {
            isGuarded = 1;
            currlen = 0;
        }
        else if(s[i] == 'W') {
            isGuarded = 0;
            currlen = 0;
        }
        else if(s[i] == '.')
            currlen = isGuarded?currlen:(currlen+1);
        
        maxlen = max(maxlen, currlen);
    }
    maxlen = max(currlen, maxlen);
    cout<<maxlen<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}