struct job{
    int t; // 工作時間
    int d; // 工作期限
}

bool cmp(job a, job b) // 先對di做排序，再對ti做排序
    return a.d==b.d? a.t<b.t : a.d < b.t ;

int find_minimize_maximum_lateness(vector<job> job_array){
    sort(job_array.begin(), job_array.end(), cmp);
    int s=0; // 開始時間
    int L=0; // minimize maximum lateness
    for(auto i:job_array){
        s+=i.t; // 此工作的結束時間
        L=max({ L, 0, s-i.d }); // find maximum lateness(結束時間-期限時間)
    }
    return L;
}

