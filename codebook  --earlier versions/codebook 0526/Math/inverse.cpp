/*模反元素*/
//ab被n除的餘數是1,ab≡1(mod n)。

const int MAXN = 1000006;
int inv[MAXN]; 
void invTable(int bound, int p){
    inv[1] = 1;
    for (int i=2; i<bound; i++){
        inv[i] = (ll)inv[p%i] * (p-p/i) %p;
    }
}

int inv(int b, int p){
    if (b==1) return 1;
    return (ll)inv(p%b,p) * (p-p/b) %p;
}