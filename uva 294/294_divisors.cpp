#include<bits/stdc++.h>
using namespace std;
bool prime[20000000];
bool is_prime( int num);
void setprime();
int factor(int num);
vector<int> primelist;
int main(){
    vector<int> divisor;
    int testcase,start,end,max=0,temp,index;
    setprime();
    cin>>testcase;
    while(testcase--){
        cin>>start>>end;
        divisor.clear();
        max=0;
        for(int i=start;i<=end;i++){
            temp=factor(i);
            //cout<<temp<<" ";
            divisor.push_back(temp);
            if(temp>max){
              max=temp;
            }
        }
        //cout<<max<<" max";
        auto it=find(divisor.begin(),divisor.end(),max);
        index=it-divisor.begin();
        cout<<"Between "<<start<<" and "<<end<<", "<<index+start<<" has a maximum of " <<max<<" divisors."<<endl;
        
    }
    
}
void setprime(){
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for ( int i=2; i<20000000; i++)
		if (prime[i]==true)
		    for (int j=i+i; j<20000000; j+=i){
                prime[j] = false;
            }
    for(int i=2;i<20000000;i++){
        if(prime[i]==true) 
            primelist.push_back(i);
    }
}
int factor(int num){
    int i=0,count=0,answer=1;
    if(num==1){
        return 1;
    }
    if(is_prime(num)==true){
        return 2;
    }     
    for(int i=2;i<=int(sqrt(num));i++){
        if(is_prime(i)==true){
            count=0;
            if(num%i==0){
                while(num%i==0){
                    num=num/i;
                    count++;
                }
                answer=answer*(count+1);
                //cout<<answer<<endl;
            }
        }    
    }
    if(num!=1){
        answer=answer*2;
    }
    return answer;
   
}
bool is_prime( int num){  
    int n=int(sqrt(num));
    for(int i=0;primelist[i]<=n;i++){
        if(num % primelist[i]==0)
            return false;
    }
    return true;
}