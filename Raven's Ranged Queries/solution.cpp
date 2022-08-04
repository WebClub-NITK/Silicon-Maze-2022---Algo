#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define ll long long int
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define mkpr make_pair
#define loop(i,k,n) for(ll i = k; i < n;i++)
#define roop(i,n,k) for(ll i = n; i >= k; i--)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define F first
#define S second

class FenwickTree{
public:
    ll n;
    vl fentree;

    FenwickTree(ll n){
        this->n = n;
        fentree.assign(n+1,0);
    }

    ll sum(ll k){
        ll res = 0;
        while(k > 0){
            res += fentree[k];
            k -= k&(-k);         
        }
        return res;
    }

    ll sum(ll a, ll b){
        return sum(b) - sum(a-1);
    }

    void add(ll k, ll x){
        while(k <= n){
            fentree[k] += x;
            k += k&(-k);
        }
    }

    void set(ll k, ll x){
        add(k, x - sum(k,k));
    }
};

typedef __gnu_pbds::tree<
ll,
__gnu_pbds::null_type,
less<ll>,
__gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>
ordered_set;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin>>n;
    ll arr[n];
    loop(i,0,n){
        cin>>arr[i];
    }
    ll q;
    cin>>q;

    FenwickTree fentree(n+q);
    ll new_ind = n+1;

    ordered_set st;

    loop(i,1,n+1){
        fentree.set(i,arr[i-1]);
        st.insert(i);
    }

    ll type, l, r, x;
    ll newl, newr;

    loop(_, 0 , q){
        cin>>type;
        if(type == 2){
            cin>>x;
            st.insert(new_ind);
            fentree.set(new_ind, x);
            new_ind++;
            continue;
        }

        if(type == 1){
            cin>>l>>r;
            newl = *st.find_by_order(l-1);
            newr = *st.find_by_order(r-1);
            cout<<fentree.sum(newl, newr)<<"\n";
            continue;
        }

        cin>>l>>r;
        loop(i, l, r+1){
            x = *st.find_by_order(l-1);
            fentree.set(x, 0);
            st.erase(x);
        }
    }
    
    return 0;
}