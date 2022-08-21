/*--------map--------*/
map<char, int> mymap;
mymap['b'] = 100, mymap['a'] = 200, mymap['c'] = 300;

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