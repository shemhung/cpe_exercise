#include<bits/stdc++.h>
using namespace std;
vector<vector<unsigned long long>> dp(101,vector<unsigned long long>(64,0)); 
void throwballon(vector<vector<unsigned long long>> &dp);
int main(){
    int  k;
    unsigned long long  n;
    throwballon(dp);
    while(cin>>k>>n &&k&&n){   //k顆球，n層樓
        int solution,check=1;
        for(int i=1;i<=63;i++){
            if(dp[k][i]>=n){
                check=0;
                solution=i;
                break;
            }
        }
        if(check==1){
            cout<<"More than 63 trials needed."<<endl;
        }
        else  
            cout<<solution<<endl;

    }
    
}
void throwballon(vector<vector<unsigned long long>> &dp){
    for(int i=1;i<=100;i++){
        for(int j=1;j<=63;j++){
            dp[i][j]=dp[i][j-1]+1+dp[i-1][j-1];
            //球分兩種
        }
    }
}