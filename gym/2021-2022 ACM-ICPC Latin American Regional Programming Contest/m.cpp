#include <bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define int long long
using namespace std;

struct job{
    ll t,d,id;
    job(){}
    job(ll _t,ll _d,ll _id){
        id=_id;
        t=_t;
        d=_d;
    }
};
vector<job> jobs,ordered_jobs;
vector<int> ans,check;
vector<ll> pre_sum;
map<int,int> loc;


bool cmp(job a,job b){
    if(a.d==b.d)return a.id<b.id;
    return a.d<b.d;
}

bool possible(int n){
    bool has_ans=true;
    sort(jobs.begin(),jobs.end(),cmp);
    pre_sum.resize(n+5);
    ll now=0;
    for(int i=0;i<n;i++){
        now+=jobs[i].t;
        pre_sum[i]=now;
        loc[jobs[i].id]=i;
        if(now>jobs[i].d)has_ans=false;
    }
    return has_ans;
}

signed main(){
    io
    ll n,t,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t>>d;
        jobs.push_back(job(t,d,i));
        ordered_jobs.push_back(job(t,d,i));
    }
    bool has_ans=possible(n);
    check.resize(n+5,0);
    if(has_ans){
        for(int i=0;i<n;i++){
            if(check[jobs[i].id])continue;
            for(int j=0;j<jobs[i].id;j++){
                if(check[j])continue;
                bool can=true;
                for(int k=i;k<loc[j];k++){
                    if(check[jobs[k].id])continue;
                    if(pre_sum[k]+ordered_jobs[j].t>jobs[k].d){
                        can=false;
                        break;
                    }
                }
                if(can){
                    for(int k=i;k<loc[j];k++){
                        if(check[jobs[k].id])continue;
                        pre_sum[k]+=ordered_jobs[j].t;
                    }
                    check[j]=1;
                    ans.push_back(j+1);
                }
            }
            ans.push_back(jobs[i].id+1);
            check[jobs[i].id]=1;
        }
        cout<<ans[0];
        for(int i=1;i<ans.size();i++){
            cout<<" "<<ans[i];
        }
        cout<<"\n";
    }else{
        cout<<"*\n";
    }
}
