//2022/2/14
//UVA 10003
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include <cstring>
using namespace std;

int main(){
    int l,j,num;
    while(cin>>l){
        if(l==0)
            break;
        cin>>num;
        vector<vector<int>> dp(52,vector<int>(52,99999));
        int cut[52];
        cut[0]=0;
        for(int i=1;i<=num;i++){
            cin>>cut[i];
        }
        cut[num+1]=l;
        for(int i=0;i<=num;i++){
            dp[i][i+1]=0;
        }                               //num個切割點，有num+1個range  
        for (int r=2;r<=num+1;r++){      //range
            for(int i=0;i+r<=num+1;i++){       //起點+range |--|--|--| 
                j=i+r;
                for(int k=i+1;k<j;k++){           //k點從i+1跑，|--|--k--|，0到k，k到j
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+cut[j]-cut[i]);
                    //cout<<" dp i j "<<i<<" "<<j<<"　"<<dp[i][j];
                   
                }
            }
            
        }
        cout<<"The minimum cutting is "<<dp[0][num+1]<<"."<<endl;
       
    }

}
