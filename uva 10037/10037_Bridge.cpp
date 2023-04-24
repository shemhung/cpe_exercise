#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int testcase;
    cin>>testcase;
    while(testcase--){
        long long int num,temp,sum=0;
        cin>>num;
        vector<long long int> time;
        for(int i=0;i<num;i++){
            cin>>temp;
            time.push_back(temp);
        }
        sort(time.begin(),time.end());
        vector<long long int> path;
        int plana=0,planb=0;
        while(time.size()!=0){  
            long long int people =time.size();
            if(people>=4){
                plana=time[1]+time[0]+time.back()+time[1];//01過去，0回來，最後兩個過去，1回來
                planb=time[time.size()-2]+time[0]+time.back()+time[0];//0最後一個過去，0回來，0倒數第二個過去，0回來
                if(plana<planb){
                    sum+=plana;
                    path.push_back(time[0]);path.push_back(time[1]);
                    path.push_back(time[0]);
                    path.push_back(time[time.size()-2]);path.push_back(time[time.size()-1]);
                    path.push_back(time[1]);
                }
                else{
                    sum+=planb;
                    path.push_back(time[0]);path.push_back(time[time.size()-2]);
                    path.push_back(time[0]);
                    path.push_back(time[0]);path.push_back(time[time.size()-1]);
                    path.push_back(time[0]);    
                }
                time.pop_back();
                time.pop_back();
            }
            if(people==3){
                path.push_back(time[0]);path.push_back(time[1]);
                path.push_back(time[0]);
                path.push_back(time[0]);path.push_back(time[2]);
                plana=time[0]+time[1]+time[2];//01過去，0回來，02過去，0回來
                sum+=plana;
                time.pop_back();
                time.pop_back();
                time.pop_back();
            }
            else if(people==2){
                path.push_back(time[0]);path.push_back(time[1]);
                plana=time[1];
                sum+=plana;
                time.pop_back();
                time.pop_back();
            }
            else if(people==1){
                path.push_back(time[0]);
                sum+=time[0];
                time.pop_back();
                break; 
            }
        }
        cout<<sum<<endl;
        if(path.size()==1)
            cout<<path[0]<<endl;
        else if(path.size()==2)
            cout<<path[0]<<" "<<path[1]<<endl;
        else    
            for(int i=0;i<path.size();i=i+3){
                cout<<path[i]<<" "<<path[i+1]<<endl;
                if(i+1==path.size()-1)
                    break;
                cout<<path[i+2]<<endl;
            }
        if(testcase)
            cout<<endl;
            
        // for(int i=0;i<path.size();i++){
        //     cout<<path[i]<<endl;
           
        // }
        
    }
}