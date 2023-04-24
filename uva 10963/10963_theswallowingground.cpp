#include<bits/stdc++.h>
using namespace std;
int main(){
    int testcase,num,n,s,base,last_base;
    bool flag=true;
    cin>>testcase;
    while(testcase--){
        flag=true;
        cin>>num;
        cin>>n>>s;
        last_base=n-s;
        for(int i=1;i<num;i++){
            cin>>n>>s;
            base=n-s;
            if(base!=last_base)
                flag=false;
            last_base=base;
        }
        if(flag)
            cout<<"yes"<<endl;
        else   
            cout<<"no"<<endl;   
        if(testcase)
            cout<<endl;
    }
        
    
}