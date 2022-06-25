void binary_search(ll n,ll target){
	ll L=0, R=n;
    while(L<R){
        ll mid=(L+R)>>1;
        if(check(mid))  R=mid;
        else            L=mid+1;
    }
	cout << L << "\n";
}
