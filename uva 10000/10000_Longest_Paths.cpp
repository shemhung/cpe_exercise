//2022/2/14
//UVA 10000
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include <queue>
#include <cstring>
using namespace std;
void bfs(int start, vector<int> &d,vector<vector<int>> &map);
int main(){
    int p,start,d1,d2,testcase=1;
    
    while(cin>>p && p!=0){
        vector<vector<int>> map(p,vector<int>(p,0));
        vector<int> d(p,0);
        int max=0,endpoint;
        cin>>start;
        while(cin>>d1>>d2){
            if(d1==0 && d2==0){
                break;
            }
            map[d1-1][d2-1]=1;
        }
        bfs(start-1,d,map);
        for(int i=0;i<d.size();i++){
            if(max<d[i])
                max=d[i];
        }
        for(int i=0;i<d.size();i++){
            if(max==d[i]){
                endpoint=i;
                break;
            }
        }
        cout<<"Case "<<testcase<<": The longest path from "<<start<<" has length "<<max<<", finishing at "<<endpoint+1<<"."<<endl<<endl;
        testcase++;
    }

}
void bfs(int start, vector<int> &d,vector<vector<int>> &map){
    queue<int> q;
    vector<int> visit(d.size(),0);
    q.push(start);
    while(!q.empty()){
        start=q.front();
        visit[start]=0;
        q.pop();
        for(int i=0;i<d.size();i++){
            if(map[start][i]==1 && d[start]+1>d[i]){
                d[i]=d[start]+1;
                if(!visit[i]){
                    q.push(i);
                    visit[i]=1;
                }             
            }   
        }
        // for(int i=0;i<d.size();i++){
        //     cout<<d[i];
        // }
        // cout<<endl;
        
    }
}