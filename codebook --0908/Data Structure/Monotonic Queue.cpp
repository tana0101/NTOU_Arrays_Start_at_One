vector<int> a; //array
deque<pair<int,int>> mx,mn;    //index, value 
vector<pair<int,int>> dp(MAXN);//min,max
pair<int,int> calc(){
    pair<int,int> temp;
    temp.first = mn.front().second; temp.second = mx.front().second;
    return temp;
}
if(k>n)k=n;// k = windows size, n = array size
for(i=0;i<n;i++){   // dp 求最大值
    while(!mn.empty() && mn.front().first <= i-k)   
        mn.pop_front();  //判斷dq裡的東西有沒有過期
    while(!mn.empty() && mn.back().second >= a[i])   
        mn.pop_back();  
    while(!mx.empty() && mx.front().first <= i-k)   
        mx.pop_front();  //判斷dq裡的東西有沒有過期
    while(!mx.empty() && mx.back().second <= a[i])   
        mx.pop_back();  
    mn.push_back(make_pair(i,a[i]));
    mx.push_back(make_pair(i,a[i]));
    if(i>=k-1) dp[i] = calc();
}