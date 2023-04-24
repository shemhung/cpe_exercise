#include<bits/stdc++.h>
using namespace std;

void setprime();
void determine();
typedef unsigned long long big;
vector<big> prime(1000001,1);
vector<big>ans;
int main(){
    setprime();
    determine();
    int testcase;
    big low,high;
    cin>>testcase;
    while(testcase--){
        cin>>low>>high;
        unsigned long long int index=0,count=0;
        auto upper = upper_bound(ans.begin(),ans.end(),high);
        auto lower = lower_bound(ans.begin(),upper,low);
        cout<<upper-lower<<endl;
        // while(ans[index]<low){
        //     index++;
        // }
        // while(ans[index]<high){
        //     count++;
        //     index++;
        // }
        // cout<<count<<endl;
    }
    return 0;
}
void setprime(){
    prime[0]=0;
    prime[1]=0;
    for ( unsigned long long int i=2; i<1000001; i++)
		if (prime[i]==1)
		    for (unsigned long long int j=i+i; j<1000001; j+=i){
                prime[j] = 0;
            }
}
void determine(){
    for(unsigned long long int i=0;i<=1000001;i++){
        if(prime[i]==1)
            for(unsigned long long int j=i*i;j<1000000000001;j=j*i){
                ans.push_back(j);
            }
    }
    sort(ans.begin(),ans.end());
    //cout<<ans.size()<<endl;
    //cout<<ans[80069];
    // for(long long int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<endl;
    // }
}