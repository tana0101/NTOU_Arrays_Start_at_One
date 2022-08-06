import random

f = open('input.in', 'w')


n=random.randint(2,200)
f.write(str(n)+" ")
m=random.randint(1,200)
f.write(str(m)+" ")
s=""
for i in range(n):
    p=random.randint(1,100000)
    s+=str(p)
    s+=" "
f.write(s)
s=""
for i in range(m):
    x=random.randint(1,100000)
    s+=str(x)
    s+=" "
f.write(s)
f.close

'''
set -e
g++ i.cpp -o ac
g++ i_wa.cpp -o wa
for ((i=0;;i++))
do
    echo "$i"
    python3 gen.py > input
    ./i < input > ac.out
    ./i_wa < input > wa.out
    diff ac.out wa.out || break
done
'''