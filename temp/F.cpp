#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,time,corTol=0,ptTol=0;
    string str,str2,str3;

    map<string,int> cor; // (1,AC)(0,WA)
    map<string,int> pt;

    cin >> n;

    for(int i=0;i<n;i++){

        cin >> str >> str2 >> str3;

        time = (str[0]-'0')*60*10 + (str[1]-'0')*60 + (str[3]-'0')*10 + (str[4]-'0');

        if(pt.find(str2)==pt.end()){   //add
            if(str3=="CORRECT"){
                cout << "penalty += " << pt[str2] + time << "\n";
                corTol++;
                ptTol += pt[str2] + time;
                cor[str2] = 1;
            }else{  //WA
                pt[str2]+=20;
            }
        }
        else{   //exist
            if(!cor[str2] == 1){
                if(str3=="CORRECT"){
                    cout << "penalty += " << pt[str2] + time << "\n";
                    corTol++;
                    ptTol += pt[str2] + time;
                    cor[str2] = 1;
                }else{  //WA
                    pt[str2]+=20;
                }
            }
        }

    }

    cout<<"Total corrects are "<<corTol<<"\n";
    cout<<"Total penalties are "<<ptTol<<"\n";

    return 0;
}
