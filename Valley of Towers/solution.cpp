#include <bits/stdc++.h>

using namespace std;

#define YES "YES"
#define NO "NO"
#define ALICE "Alice"
#define BOB "Bob"
#define pb push_back
#define mp make_pair
#define all(vec) vec.begin(), vec.end()
#define watch(var) cout << (#var) << " is " << var << "\n";
#define INF lli(1e14)

typedef vector<bool> vb;
typedef long long int lli;
typedef vector<string> vs;
typedef vector<short> v16;
typedef vector<int> v32;
typedef vector<lli> v64;
typedef vector<char> vc;
typedef vector<v64> vv64;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, v32, greater<int>> min_heap;

template <typename T>
void take(vector<T> &vec, int n = -1) {
    if(n != -1) {
        vec.resize(n);
    }
    for(T &ele : vec) {
        cin >> ele;
    }
}

template <typename T>
void print(vector<T> &vec) {
    for(T ele : vec) {
        cout << ele << " ";
    }
    cout << "\n";
}

lli relu(lli n) {
    if(n < 0) {
        return 0;
    }
    return n;
}

template <typename T>
int bin_l(vector<T> &vec, int key) {
    int idx = -1;
    int low = 0, high = vec.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(vec[mid] <= key) {
            idx = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return idx;
}

template <typename T>
int bin_r(vector<T> &vec, int key) {
    int idx = vec.size();
    int low = 0, high = vec.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(vec[mid] >= key) {
            idx = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return idx;
}

lli gcd(lli a, lli b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

template <typename T>
lli vsum(vector<T> &vec, int s = 0, int e = -1) {
    if(e == -1) {
        e = vec.size();
    }
    lli sum = 0;
    for(int i = s; i < e; i++) {
        sum += vec[i];
    }
    return sum;
}

int median(const v32 &a, int l, int r) {
    v32 sorted;
    for(int i = l; i <= r; i++) {
        sorted.pb(a[i]);
    }
    sort(all(sorted));
    // (r - l + 1) : Number of elements (n)
    int n = r - l + 1;
    // (n + 1) / 2 th element : Median
    int m = (n + 1) / 2;
    // cout << l << "->" << r << ": " << sorted[m - 1] << "\n";
    // print(sorted);
    return sorted[m - 1];
}

void insert(int ele, max_heap &left, lli &sl, min_heap &right, lli &sr) {
    if(ele >= right.top()) {
        right.push(ele);
        sr += ele;
    }
    else {
        left.push(ele);
        sl += ele;
    }
    if(left.size() > right.size()) {
        right.push(left.top());
        sr += left.top();
        sl -= left.top();
        left.pop();
    }
    if(right.size() > left.size() + 1) {
        left.push(right.top());
        sl += right.top();
        sr -= right.top();
        right.pop();
    }
}

lli dp(const v32 &a, int idx, v64 &d) {
    const int n = a.size();
    if(idx == n) {
        return 0;
    }
    if(d[idx] != - 1) {
        return d[idx];
    }
    d[idx] = LLONG_MAX;
    max_heap left;
    lli sl = 0;
    min_heap right;
    lli sr = a[idx];
    right.push(a[idx]);
    for(int i = idx + 1; i < n; i++) {
        insert(a[i], left, sl, right, sr);
        const int med = right.top();
        lli tmp = ((med * left.size()) - sl) + (sr - (med * right.size()));
        d[idx] = min(d[idx], tmp + dp(a, i + 1, d));
    }
    return d[idx];
}

lli solve(const v32 &a) {
    const  int n = a.size();
    v64 d(n, -1);
    d[n - 1] = INF;
    lli soln = dp(a, 0, d);
    return soln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    short t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        v32 a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(a) << "\n";
    }
    return 0;
}