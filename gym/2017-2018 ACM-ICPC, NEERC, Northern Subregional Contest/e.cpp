#include<bits/stdc++.h>
#define ll long long
#define int long long
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<int> arr(300005);
map<int,int> cnt;
// vector<int> cnt(1000005,0);

bool cmp(int a,int b){
    if(cnt[a]==cnt[b])
        return a<b;
    return cnt[a]<cnt[b];
}

signed main(){
    io
    //freopen("equal.in","r",stdin);    // 讀 file.in 檔
    //freopen("equal.out","w",stdout);  // 寫入 file.out 檔

    int n,mx=0;
    cin>>n;
    set<int> num;
    for(int i=0,tmp;i<n;i++){
        cin>>arr[i];
        cnt[arr[i]]++;
        num.insert(arr[i]);
        mx = max(mx,arr[i]);
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i] arr[j]
        }

    }
    /*bool mul=true;
    for(int i=0;i<n;i++){
        if(mx%arr[i]!=0){
            mul=false;
            break;
        }
    }*/
    sort(arr.begin(),arr.begin()+n,cmp);
    
    
    
    
    /*if(mul){
        int sz=num.size();
        cout << sz <<" ";
        for(int i=0;i<n;i++){
            while(cnt[arr[i]]){
                if(cnt[arr[i]]==1){
                    sz--;
                    if(sz)cout<<sz<<" ";
                    else cout<<sz+1<<" ";
                }else
                    cout<<sz<<" ";
                cnt[arr[i]]--;
            }
        }
    }else{
        int sz=num.size();
        cout << sz <<" ";
        sz++;
        for(int i=0;i<n;i++){
            while(cnt[arr[i]]){
                if(cnt[arr[i]]==1){
                    sz--;
                    if(sz)cout<<sz<<" ";
                    else cout<<sz+1<<" ";
                }else{
                    cout<<sz<<" ";
                }
                cnt[arr[i]]--;
            }
        }     
    }
    cout << "\n";*/
}

/*
6
1 1 2 2 3 5 5 -> 1 2 2 2 5 5 -> 2 2 2 2 5 5 -> 1 5 2 2 5 5 -> 5 5 2 2 3 5 5 -> 15 15 2 2 15 15 15 -> 10 10 10 10 10 10
3 3 2 2 2 2 1


6
1 1 2 2 4 4
-> 3 (3) 2 2 1 1 1

// ---------------------

5
1 2 2 5 5
-> 3 3 3 2 2 1

6
1 1 2 2 5 5
-> 3 4 3 3 2 2 1

6
3 4 1 2 1 2
-> 4 4 3 3 2 2 1

5
1 2 2 4 4 
-> 3 2 2 1 1 1 

3
1 2 3

*/