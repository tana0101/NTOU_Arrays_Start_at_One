unordered_set<int> u_set;
multiset<int> st;
• insert(val)
• erase(l, r) //l與r皆為iterator
• erase(it)
• erase(val)
• count(val) //元素是否存在
it = st.find(val);
it = st.lower_bound(val); 
it = st.upper_bound(val); 
//遍歷
int mints[] = { 75,23,65,42,13,75,65 };
set<int> myset(myints, myints + 7);
for (auto it = myset.begin(); it != myset.end(); it++)
    cout << ' ' << *it;