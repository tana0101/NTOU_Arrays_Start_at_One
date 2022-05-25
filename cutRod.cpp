int cutRod(int rod[], int n, int price){
    rod[0] = 0;
    for(int j=1;j<=n;j++){
        int q = -1;
        for(int i=1;i<=j;i++)
            q = max(q, price[j] + rod[j-i] - 2);
        rod[j]=q;
    }
    return r[n];
}
