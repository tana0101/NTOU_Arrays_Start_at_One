#include <bits/extc++.h>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx; //rope
using pq_t = __gnu_pbds::priority_queue<int>;
using set_t = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;

// hash_map
cc_hash_table<int, int> mp1;
gp_hash_table<int, int> mp2;

// priority_queue
pq_t pq;
pq.join(PQ);

// Tree(Treap,rank)
// 0-base,O(logn)
set_t Tree;
Tree.insert(val);
Tree.erase(val);
Tree.join(tree);               // 插入tree
Tree.split(v, tree);           // Tree(<=v),tree(>v)
rank = Tree.order_of_key(val); // val的排名 
it   = Tree.find_by_order(rk); // 第rk小的it 
it   = Tree.lower_bound(val);  
it   = Tree.upper_bound(val);  
// Replacing treap and rank tree
// Cannot be repeated (like set)

// rope (可持久化)
// string
rope<char> s[2];
s[1] = s[0] //O(1)複製 可持久化
s[0].insert(pos,str.c_str());
s[0].erase(pos.str.c_str());
s[0].size();
s[0].substr(pos, x);
s[0].copy(pos, x, s);
cout << s[0] + s[1] <<"\n";
// int[]
rope<int> x;
x.insert(0,12);
x.push_back(val);
for(auto val:x) cout << val <<"\n";