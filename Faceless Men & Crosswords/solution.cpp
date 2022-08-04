#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct trie{
    trie* child[26];
    int minIdx;
    trie(){
        for(int i =0;i<26;i++){
            child[i] = NULL;
        }
        minIdx = INT_MAX;
    }
};

trie* froot;
trie* broot;

void finsert(string &s,int st){
    trie* curr = froot;
    int n = s.length();
    for(int i =0;i<n;i++){
        int idx = s[i] - 'a';
        if(curr->child[idx]==NULL){
            curr->child[idx] = new trie();

        }
        curr = curr->child[idx];
        curr->minIdx = min(curr->minIdx,st);
        st++;
    }
    return ;
}

void binsert(string &s,int st){
    trie* curr = broot;
    int n = s.length();
    for(int i =0;i<n;i++){
        int idx = s[i] - 'a';
        if(curr->child[idx]==NULL){
            curr->child[idx] = new trie();
        }
        curr = curr->child[idx];
        curr->minIdx = min(curr->minIdx,st);
        st--;
    }
    return ;
}

void fquery(string &s,vector<int> &intPt){
  int n = s.length();  
  trie* curr = froot;
  curr = curr->child[s[0]-'a'];
  int i =1;
  while(i<=n&&curr!=NULL){
    intPt[i-1] = curr->minIdx;
    if(i==n){
        curr=NULL;
    }
    else{
    curr = curr->child[s[i]-'a'];
    }
    i++;
  }

  return;
}

void bquery(string &s,vector<int> &intPt){
    int n =s.length();
    trie* curr = broot;
    curr = curr->child[s[0]-'a'];
    int i =1;
   while(i<=n&&curr!=NULL){
    intPt[i-1] = curr->minIdx;
    if(i==n){
        curr=NULL;
    }
    else{
    curr = curr->child[s[i]-'a'];
    }
    i++;
  }
  reverse(intPt.begin(),intPt.end());
  return;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        froot = new trie();
        broot = new trie();
        string s;
        cin>>s;
        int ls =s.length();
        for(int i =0;i<ls;i++){
            string temp = s.substr(i,ls-i);
            finsert(temp,i);
        }
        reverse(s.begin(),s.end());
        for(int i =0;i<ls;i++){
            string temp = s.substr(i,ls-i);
            binsert(temp,ls-i-1);
        }

        int q;
        cin>>q;
        while(q>0){
            string p;
            cin>>p;
            int pl = p.length();
            vector<int> rl(pl,-1);
            fquery(p,rl);
            vector<int> lr(pl,-1);
            reverse(p.begin(),p.end());
            bquery(p,lr);
            vector<int> res(2,-1);
            int sum =INT_MAX;
            for(int i =0;i<pl;i++){
                if(rl[i]!=-1&&lr[i]!=-1&&(rl[i]+lr[i]<sum)){
                    sum = rl[i] + lr[i];
                    res[0] = rl[i];
                    res[1] = lr[i];
                }
            }
            if(res[0] == -1 && res[1] == -1){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
            q--;
        }
        t--;
    }
    return 0;
}
