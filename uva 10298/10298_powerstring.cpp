#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,next_token,token,delimiter;
    bool flag;
    int  pos;
    while(cin>>s && s[0]!='.'){
        for(int i=1;i<=s.size();i++){
            if(s.size()%i==0){
                flag=true;
                delimiter=s.substr(0,i);
                pos=i;
                while(pos<s.size()){
                    next_token=s.substr(pos,i);
                    if(delimiter!=next_token){
                        flag=false;
                        break;  
                    }
                    pos+=i;
                }
                if(flag){
                    cout<<s.size()/delimiter.size()<<endl;
                    break;
                }    
            }
        }
    
    }
 
   
}
