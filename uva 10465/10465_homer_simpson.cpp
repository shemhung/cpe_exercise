#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,t,number,new_number,left_time,flag=0;
    while(cin>>m>>n>>t){
        flag=0;
        if(m>n){
            int temp=m;
            m=n;
            n=temp;
        }
        number=t/m;
        left_time=t-number*m;
        if(left_time==0)
            cout<<number<<endl;
        else if(m>t && n>t)
            cout<<number<<" "<<t<<endl;
        else if(n>t){
            cout<<number<<" "<<left_time<<endl;
        }
        else{
            for(int i=number;i>=0;i--){
                int new_left_time=t-i*m;
                new_left_time=new_left_time-new_left_time/n*n;
                if(new_left_time==0){
                    cout<<i+(t-i*m)/n<<endl;
                    flag=1;
                    break;
                }
                if(new_left_time<left_time){
                    number=i+(t-i*m)/n;
                    left_time=new_left_time;
                }   
            }
            if(flag!=1)
                cout<<number<<" "<<left_time<<endl;
        }
    }
}