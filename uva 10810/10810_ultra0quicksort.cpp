#include<bits/stdc++.h>
using namespace std;
void mergesort(vector<int> &num,int left,int right);
void merge(vector<int> &num,int left,int mid,int right);
long long int c=0;

int main(){
    int input;
    while(cin>>input && input!=0){
        c=0;
        vector<int> num;
        int temp;
        for(int i=0;i<input;i++){
            cin>>temp;
            num.push_back(temp);
        }
        mergesort(num,0,input-1);
        cout<<c<<endl;
    }
    
}
void merge(vector<int> &num,int left,int mid,int right) {
    vector<int> temp(right-left+1);
    int L=left,R=mid+1,k=0;
    while(L<=mid && R<=right){
        if(num[L]<num[R]){
            temp[k++]=num[L++];
        }
        else{//右邊比較小的時候
            c+=mid-L+1;
            temp[k++]=num[R++];
        }
    }
    while(L<=mid){
        temp[k++]=num[L++];
    }
    while(R<=right){
        temp[k++]=num[R++];
    }
    for(int i=0;i<temp.size();i++){
        num[left+i]=temp[i];
    }
}
void mergesort(vector<int> &num,int left,int right){
    if (left<right){
        int mid=(left+right)/2;
        mergesort(num,left,mid);
        mergesort(num,mid+1,right);
        merge(num,left,mid,right);
    }
}