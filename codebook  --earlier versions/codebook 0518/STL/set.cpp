• insert()
• erase(l, r) //l與r皆為iterator
• erase()
• empty()
• clear()
• count() //元素是否存在
//遍歷
int mints[] = { 75,23,65,42,13,75,65 };
set<int> myset(myints, myints + 7);
for (auto it = myset.begin(); it != myset.end(); it++)
    cout << ' ' << *it;