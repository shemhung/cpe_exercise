#include<bits/stdc++.h>
using namespace std;
bool mycompare(string a,string b);
int main(){
    int count;
    string input;
    while(cin>>count && count!=0){
        vector<string> stringnum;
        vector<string> output;
        vector<int> number;
    
        string answer;
            for(int i=0;i<count;i++){
            cin>>input;
            stringnum.push_back(input);
        }
        sort(stringnum.begin(),stringnum.end(),mycompare);
        for(int i=0;i<stringnum.size();i++){
            cout<<stringnum[i];
        }
        cout<<endl; 
        stringnum.clear();number.clear();
    }
}
bool mycompare(string a,string b){
    return a+b>b+a;
}