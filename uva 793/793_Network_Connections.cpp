#include<bits/stdc++.h>
using namespace std;
int parent[999999];
//int rank[800];
int findroot(int x);
void unionset(int a, int b);
int main(){
    int testcase,right,wrong,num1,num2,count;
    string trash,temp,c,input;
    
    stringstream ss;
    cin>>testcase; 

    for(int i=0;i<testcase;i++){
        if(i==0)
            cin>>count;
        else
            count = stoi(input);            //input(string)會吃掉count，所以要把input(string)轉為數字。
        count++;

        right=0;
        wrong=0;
        for(int i=1;i<=count;i++){
            parent[i]=i;
            //rank[i]=0;
        }   
        
        while(cin>>input && !isdigit(input[0])){
            cin>>num1>>num2;
            // num1=input[2]-'0';
            // num2=input[4]-'0';
            if(input[0]=='c')
                unionset(num1,num2);
            else if(input[0]=='q'){
                if(findroot(num1)==findroot(num2)){
                    right++;
                }
                    
                else    
                    wrong++;
            }
        }
        if(i==testcase-1)
            cout<<right<<","<<wrong<<endl;  
        else 
            cout<<right<<","<<wrong<<endl<<endl;
       
    
    }
    return 0;
    // for(int i=0;i<count;i++){
    //     cout<<parent[i]<<" ";
    // }
}
int findroot(int x){
    int root;
    if(x==parent[x]){
        return x;
    }
    else{
        
       // cout<<parent[x];
        return parent[x]=findroot(parent[x]);;      //一直往上找源頭，找到跟自己一樣就是源頭
    }    
       
}
void unionset(int a, int b) {       //disjoint set的方法，因為相同電腦連一起，所以我將a,b電腦都設定為a是b的源頭
    int roota = findroot(a);
    int rootb = findroot(b);
    if (roota != rootb) {
         parent[rootb] = roota;
    }
}