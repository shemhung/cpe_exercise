#include<bits/stdc++.h>
using namespace std;
int findk(long long int input);

int main() {
    long long int k,num;
    
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> k;
        long long int answer =findk(abs(k));
        if(i==num-1)
            cout << answer<< endl;
        else
            cout << answer<< endl<<endl;  // print a blank line between outputs
    }
    return 0;
}
int findk(long long int k){
    long long int n=ceil((-1+sqrt(1+8*k))/2);
    if(k==0)
        return 3;
    while(1){
        long long int temp=(n+1)*n/2;
        if((temp-k)%2==0)
            break;
        n++;
    }   
    return n;
       
}
