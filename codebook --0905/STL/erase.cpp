// erase
iterator erase (iterator position);//刪除指定元素
iterator erase (iterator first, iterator last);//刪除指定範圍
// 刪除指定數值
auto it = find(p.begin(), p.end(), val);
p.erase(it);
// 刪除所有指定數值
p.erase(remove(p.begin(), p.end(), val), p.end());