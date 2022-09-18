# sample
from random import *
t = randint(1,10)
print(t)
for i in range(t):
    n = randint(1,5)
    m = randint(1,3)
    print(n, m)
    for j in range(n):
        print(randint(1,n),end=" ")
    print()
    for j in range(m):
        print(randint(1,m),end=" ")
    print()
# rand
n = randint(1, 100)                       
ch = chr(randint(ord('a'), ord('z')))
choiceSet = sample(s, 4)             # s choice 4
choiceSet = sample(range(1, n+1), 4) # 1~n choice 4
shuffle(arr) # permutation
# tree
for i in range(2, n+1):
    print(i, randint(1, i-1))
# cpp
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int randint(int lb, int ub)
{ return uniform_int_distribution<int>(lb, ub)(gen); }