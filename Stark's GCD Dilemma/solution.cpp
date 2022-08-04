#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int MAX_N = 2e5 + 1;

ll gcd(ll x, ll y){
    if(y == 0){
        return x;
    }
    return gcd(y,x%y);
}

ll prefgcd[MAX_N];
ll suffgcd[MAX_N];

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    prefgcd[0] = 0;
    for(int i = 1; i < n; i++){
        prefgcd[i] = gcd(prefgcd[i-1], arr[i-1]);
    }
    suffgcd[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        suffgcd[i] = gcd(suffgcd[i+1], arr[i+1]);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, gcd(prefgcd[i],suffgcd[i]));
    }
    cout<<ans<<"\n";
    return 0;
}