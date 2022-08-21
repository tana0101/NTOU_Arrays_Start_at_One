void phi_table(int n,int *phi){
    memset(phi,0,sizeof(phi)); //初始化
    phi[1] = 1;
    for(int i=2;i<=n;i++){
        if(phi[i]==0){  
            for(int j=i;j<=n;j+=i){  
                if(phi[j]==0) phi[j] = j; 
                phi[j] = phi[j] / i * (i - 1);
            }                            
        }
    }
}