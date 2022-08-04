#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// returns number of white squares in a row
// given the the color of the first square in the row
ll num_whites(int n, bool white){
    if(white){
        return ceil((double)n / 2);
    }
    else{
        return n / 2;
    }
}

int main() {

    init_io();
    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;       
        ll ans = 0;
        for(ll row = 0; row < n; row++){
            ll s = min(row, n - row - 1);
            ll whites = num_whites(n, row % 2 == 0);
            ans += (whites * (whites - 1)) / 2 - ((whites - s) * (whites - s - 1)) / 2;        
        }
        cout << ans << endl; 
    }
    return 0;
}