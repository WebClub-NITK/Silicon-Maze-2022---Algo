#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (1<<20);
int dp[MAX_N];
int arr[20];
int n;

int getdp(int bitmask){

    if(dp[bitmask] != -1){
        return dp[bitmask];
    }

    int cntfree = 0;
    int sz = -1;

    for(int i = 0; i < n; i++){
        if((bitmask>>i)&1){
            continue;
        }
        sz = max(sz,arr[i]);
        cntfree++;
    }

    if(sz != cntfree){
        dp[bitmask] = 0;
        return 0;
    }

    if(cntfree == 1){
        dp[bitmask] = 1;
        return 1;
    }

    int newbitmask = bitmask;

    for(int i = 0; i < n; i++){
        if((bitmask>>i)&1){
            continue;
        }

        if(arr[i] == sz){
            newbitmask |= (1 << i);
            break;
        }
    }

    if(getdp(newbitmask)){
        dp[bitmask] = 1;
        return 1;
    }

    int bitmask1, bitmask2;
    int maxbits = (1<<(cntfree-1));

    for(int i = 0; i < maxbits; i++){
        int maskptr = 0;
        bitmask1 = newbitmask;
        bitmask2 = newbitmask;

        for(int j = 0; j < cntfree-1; j++){
            while((newbitmask>>maskptr)&1){
                maskptr++;
                continue;
            }
            if((i>>j)&1){
                bitmask1 |= (1 << maskptr);
            }
            else{
                bitmask2 |= (1 << maskptr);
            }       
            maskptr++;     
        }

        if(getdp(bitmask1) & getdp(bitmask2)){
            dp[bitmask] = 1;
            return 1;
        }
    }

    dp[bitmask] = 0;
    return 0;
}


int main(){
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    dp[(1<<n) - 1] = 1; //empty tree is always possible
    if(getdp(0)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

    return 0;
}