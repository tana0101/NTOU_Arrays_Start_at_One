#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){
    io
    int t;
    cin>>t;
    while(t--){
        int n, x1,y1,x2,y2;
        cin>>n;
        int mat[n + 1][n + 1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>mat[i][j];
            }
        }
        cin>>x1>>y1>>x2>>y2;
        int mn = mat[x1][y1],mx = mat[x2][y2];
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mat[i][j]>mn&&mat[i][j]<mx){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}