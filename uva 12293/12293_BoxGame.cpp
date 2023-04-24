#include<bits/stdc++.h>
using namespace std;
int main(){
    int input;
    while(cin>>input && input!=0){      //2alice贏，3必輸4必贏5必贏6必贏，7不管怎麼分會把456
        input=input+1;
        while(input!=1 ){
            if(input%2!=0)
                break;
            input=input/2;
        }
        if(input==1){
            cout<<"Bob"<<endl;
        }
        else    
            cout<<"Alice"<<endl;
    }
}
