/*Binary Search*/
int binary_search(int L,int R,int list[],int target,int mid){
    while(L<=R){
        mid=(L+R)/2;
        if(target==list[mid])
            return mid;
        else if(target<list[mid])
            R=mid-1;
        else
            L=mid+1;
    }
    return -1;
}