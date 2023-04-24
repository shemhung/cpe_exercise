#include<bits/stdc++.h>
using namespace std;
bool prime[20000000];
vector<int> primelist;
void setprime();
int digit_sum(int num);
int break_down(int testnum);
bool is_prime( int num);
int main(){
   int input,testcase;
   setprime() ;
   cin>>testcase;
   while(testcase--){
        cin>>input;
        input++;
        while(1){
            //cout<<"digit_sum"<<digit_sum(input)<<"break_down"<<break_down(input)<<endl;
            if(is_prime(input) ==true){
                input++;
                continue;
            }
            if(digit_sum(input)==break_down(input)){
                break;
            }
            input++;
        }
        cout<<input<<endl;
   }
   

}
bool is_prime( int num){  
    int n=int(sqrt(num));
    for(int i=0;primelist[i]<=n;i++){
        if(num % primelist[i]==0)
            return false;
    }
    return true;
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
int digit_sum(int num){
     int sum=0;
    while(num!=0){
        sum+=num%10;
        num/=10;
    }
    return sum;
}
int break_down(int testnum){
    int i=0;
    int sum=0;
    while(testnum!=1){
        if(testnum % primelist[i]==0){
            sum+=digit_sum(primelist[i]);
            testnum/=primelist[i];
        }
        else{
            if(is_prime(testnum)==true){
                sum+=digit_sum(testnum); 
                break;
            }
            i++;
        }
            
    }
    return sum;
}