#include<bits/stdc++.h>
using namespace std;
vector<char> symbol;
vector<int> num;
void print(vector<int> &num,vector<char> &symbol,string result);
int main(){
    string input,result;
    int i,op=0;
    while(getline(cin,input)){
        op=0;
        i=0;
        while(i<input.size()){
            while(input[i]==' ')    i++;
            int temp=0;
            if(input[i]=='-' && op==0){ //負值
                temp=0;
                i++;
                while(input[i]==' ')    i++;
                while(input[i]>='0' && input[i]<='9'){
                    temp=temp*10+input[i]-'0';
                    i++;
                }
                temp=-temp;
                //cout<<temp<<endl;
                op=1;
                num.push_back(temp);
            }
            else if(input[i]=='+' && op==0){//正值
                temp=0;
                i++;
                while(input[i]==' ')    i++;
                while(input[i]>='0' && input[i]<='9'){
                    temp=temp*10+input[i]-'0';
                    i++;
                }
                //cout<<temp<<endl;
                op=1;
                num.push_back(temp);
            }
            else if( (input[i]=='+' || input[i]=='-' || input[i]=='*' ||input[i]=='/'  ) &&   op==1){
                symbol.push_back(input[i]);
                op=0;       
                i++;
            }
            else if(input[i]=='='){
                string targetstring = "=";
                int position = input.find(targetstring);
                result= input.substr(position + targetstring.length());
                break;
            }
            else{
                while(input[i]==' ')    i++;
                temp=0;
                while(input[i]>='0' && input[i]<='9'){
                    temp=temp*10+input[i]-'0';
                    i++;
                }
                op=1;
                num.push_back(temp);
            }  
        }
    print(num,symbol,result); 
    int size=symbol.size();
    int pos;
    while(symbol.size()!=0){
        auto mul=find(symbol.begin(),symbol.end(),'*');
        auto div=find(symbol.begin(),symbol.end(),'/');
        if(mul!=symbol.end() && div!=symbol.end()){ //  * /都沒有
            if(mul-div<0){
                pos=mul-symbol.begin();
                num[pos]=num[pos]*num[pos+1];  
            }
            else{
                pos=div-symbol.begin();
                num[pos]=num[pos]/num[pos+1];
            }
            num.erase(num.begin()+pos+1);
            symbol.erase(symbol.begin()+pos);
            print(num,symbol,result);
        }
        else if(mul==symbol.end() && div==symbol.end()){    // *沒有和/都沒有
                if(symbol[0]=='+')
                    num[0]=num[0]+num[1];
                else    
                    num[0]=num[0]-num[1];
                num.erase(num.begin()+1);
                symbol.erase(symbol.begin());
                print(num,symbol,result);
             
        } 
        else if(mul==symbol.end() || div==symbol.end()) {
            if(mul==symbol.end()){      //只有*
                pos=div-symbol.begin();
                num[pos]=num[pos]/num[pos+1];
            }
            else{                       //只有/   
                pos=mul-symbol.begin();
                num[pos]=num[pos]*num[pos+1];

            }
            num.erase(num.begin()+pos+1);
            symbol.erase(symbol.begin()+pos);
            print(num,symbol,result);
        } 
    }
    num.clear();
    symbol.clear();
    cout<<endl;
    }
}
void print(vector<int> &num,vector<char> &symbol,string result){
    int i=0;
    if(symbol.size()==0){
        cout<<num[0]<<"="<<result<<endl;
    }
    else{
        while(symbol.size()!=0 && i<symbol.size()){
            cout<<num[i]<<" "<<symbol[i]<<" ";
            i++;
        }   
        cout<<num[i]<<"="<<result<<endl;
    }
        
    

 
}