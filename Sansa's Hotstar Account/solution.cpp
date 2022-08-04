#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string tt;
    getline(cin,tt);
    int t = stoi(tt);
    while(t--)
    {
        string u,p;
        getline(cin,u);
        getline(cin,p);
        unordered_map<char,bool>done;
        for(auto ch : u)
            done[ch] = true;
        int ans = 0;
        for(auto ch : p)
        {
            if(!done[ch])ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}