#include<bits/stdc++.h>
using namespace std;
bool prime[20000000];
vector<int> primelist;
int main(){
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for (int i=2; i<20000000; i++)
		if (prime[i]==true)
		    for (int j=i+i; j<20000000; j+=i){
                prime[j] = false;
            }
    for(int i=2;i<20000000;i++){
        if(prime[i]==true && prime[i+2]==true) 
            primelist.push_back(i);
    }
    // for(int i=0;i<primelist.size();i++){
    //     cout<<primelist[i]<<endl;
    // }
    int input,start=0;
    while(cin>>input){
                cout<<"("<<primelist[input-1]<<", "<<primelist[input-1]+2<<")"<<endl;
    }
        
    
				 
            
}