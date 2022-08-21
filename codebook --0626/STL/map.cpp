// 無序map O(1)
unordered_map<type,type> u_map;
//find
auto iter = mymap.find("a");
if (iter != mapStudent.end())
    cout << "Find, the value is" << iter->second << endl;
else
    cout << "Do not Find" << endl;
//erase
auto iter = mymap.find("a");
mymap.erase(iter);
//map遍歷
for (auto it = mymap.begin(); it != mymap.end(); it++)
cout << it->first << ", " << it->second << endl