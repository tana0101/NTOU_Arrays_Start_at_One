/*floor向下取整，ceil向上取整*/
int floor(int a,int b){ return a/b - (a%b and a<0^b<0); }
int ceil (int a,int b){ return a/b + (a%b and a<0^b>0); }