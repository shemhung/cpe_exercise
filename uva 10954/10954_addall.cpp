#include<bits/stdc++.h>
using namespace std;
vector<long long int > numlist;
int main(){
    long long int number,n,sum=0,temp;
    while(cin>>number && number!=0){
        sum=0;
        for(long long int i=0;i<number;i++){
            cin>>n;
            numlist.push_back(n);
        }
        sort(numlist.begin(),numlist.end());
        while(numlist.size()!=2){
            temp=numlist[0]+numlist[1];
            sum+=temp;
            numlist.erase(numlist.begin());
            numlist.erase(numlist.begin());
            numlist.push_back(temp);
            sort(numlist.begin(),numlist.end());
        }
        sum+=numlist[0]+numlist[1];
        cout<<sum<<endl;
        numlist.clear();
    }
}