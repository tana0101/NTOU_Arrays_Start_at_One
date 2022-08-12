#include<bits/stdc++.h>
using namespace std;

/*
map<string,string> tar;
map<string,int> cnt;


abcde
a
b
c
d
e
ab
bc
cd
de
abc
bcd
cde
abcd
bcde
abcde
*/

struct trie{
    trie *nxt[37];
    int cnt,sz;
    vector<int>cnt_idx,sz_idx;
    trie():cnt(0),sz(0){
        memset(nxt,0,sizeof(nxt));
    }
};
trie *root=new trie();
void ins(string &s,int idx){
    trie *now=root;
    for(auto i:s){
        now->sz++;
        if(i-'a'>=0 && i-'a'<26){
            if(now->nxt[i-'a']==NULL){
                now->nxt[i-'a']=new trie();
            }
            now=now->nxt[i-'a'];
        }else if(i-'0'>=0 && i-'0'<=9){
            if(now->nxt[i-'0'+26]==NULL){
                now->nxt[i-'0'+26]=new trie();
            }
            now=now->nxt[i-'0'+26];
        }else{
            if(now->nxt[i-'.'+36]==NULL){
                now->nxt[i-'.'+36]=new trie();
            }
            now=now->nxt[i-'.'+36];
        }
    }
    now->cnt++;
    now->sz++;
    now->sz_idx.push_back(idx);
    now->cnt_idx.push_back(idx);
}

pair<int,int> query(string &s){
    trie *now = root;
    for(auto i:s){
        if(i-'a'>=0 && i-'a'<26){
            if(now->nxt[i-'a']==NULL){
                return make_pair(0,0);
            }
            now=now->nxt[i-'a'];
        }else if(i-'0'>=0 && i-'0'<=9){
            if(now->nxt[i-'0'+26]==NULL){
                return make_pair(0,0);
            }
            now=now->nxt[i-'0'+26];
        }else{
            if(now->nxt[i-'.'+36]==NULL){
                return make_pair(0,0);
            }
            now=now->nxt[i-'.'+36];
        }
    }
    return make_pair(unique(now->sz_idx.begin(),now->sz_idx.end())-now->sz_idx.begin(),now->sz_idx[0]);
}
// [l,r]有沒有存在於str的前綴中
bool query(string&s,int l,int r){
    trie *now = root;
    for(auto i:s){
        if(i-'a'>=0 && i-'a'<26){
            if(now->nxt[i-'a']!=NULL && now->nxt[i-'a']->sz >0){
                now=now->nxt[i-'a'];
            }else return false;
        }else if(i-'0'>=0 && i-'0'<=9){
            if(now->nxt[i-'0'+26]!=NULL && now->nxt[i-'0'+26]->sz >0){
                now=now->nxt[i-'0'+26];
            }else return false;
        }else{
            if(now->nxt[i-'.'+36]!=NULL && now->nxt[i-'.'+36]->sz >0){
                now=now->nxt[i-'.'+36];
            }else return false;
        }
        auto L = now->cnt_idx.lower_bound(l);
        if(l<=*L && *L<=r)return true;
    } return false;
}

int main(){
    int n, q;
    string str, sub, que;
    cin>>n;
    vector<string>st(n+1);
    st[0]="-";
    for(int i=0;i<n;i++){
        cin>>str;
        st[i+1]=str;
        for(int j=0;j<str.size();j++){
            for(int k=1;k<=str.size()-j;k++){
                sub=str.substr(j,k);
                ins(sub,i+1);
            }
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>que;
        pair<int,int>p=query(que);
        cout<<p.first<<" "<<st[p.second]<<"\n";
    }
}