#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UFDS {
    private: vi rank, p;
    public:
    UFDS(int n) {
        rank.assign(n, 0);
        p.assign(n, 0); for (int i = 0; i < n; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    void joinSets(int i, int j) {
        if(findSet(i) != findSet(j)) {
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) 
            {   p[y] = x;  }
            else 
            {   p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;  }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int _TC;
    cin >> _TC;
    while(_TC--)
    {
        

        int v, e;
        cin >> v >> e;

        UFDS uf(v + 1);
        vector<vector<int>> edges(e);
        for (int i = 0; i < e; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = {-w, u, v};
        }

        int st, ed;
        cin >> st >> ed;

        sort(edges.begin(), edges.end());

        for(int i = 0; i < e; i++) {
            uf.joinSets(edges[i][1], edges[i][2]);
            if(uf.findSet(st) == uf.findSet(ed)) {
                cout << -edges[i][0] << endl;
                break;
            }
        }
    }

    return 0;
}