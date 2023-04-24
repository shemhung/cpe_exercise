#include<bits/stdc++.h>
using namespace std;
int bfs(int x1,int y1,int x2,int y2);
int dir[8][2]={{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
int main(){
    string input;
    int x1,x2,y1,y2;
  
    while(getline(cin,input)){
        x1=input[0]-'a';
        y1=input[1]-49;
        x2=input[3]-'a';
        y2=input[4]-49;
        cout<<"To get from "<<input[0]<<input[1]<<" to "<<input[3]<<input[4]<<" takes "<< bfs(x1,y1,x2,y2)<<" knight moves."<<endl;
        //bfs(x1,y1,x2,y2);
    }
}
int bfs(int x1,int y1,int x2,int y2){
    queue<pair<int,int>> q;
    vector<int> p;
    int visit[8][8]={0};
    int dis[8][8]={0};
    q.push(make_pair(x1,y1));
    while(!q.empty()){
        pair<int,int> start=q.front();
        int x=start.first;
        int y=start.second;
        visit[x][y]=1;
        q.pop();
        if(x==x2 && y==y2){        
            break;
        } 
        for(int i=0;i<8;i++){
            if( x+dir[i][0]>=0 && x+dir[i][0]<8 && y+dir[i][1]<8 && y+dir[i][1]>=0 ){
              
                if(!visit[x+dir[i][0]][y+dir[i][1]]){
                    dis[x+dir[i][0]][y+dir[i][1]]=dis[x][y]+1;
                    q.push(make_pair(x+dir[i][0],y+dir[i][1]));
                    visit[x+dir[i][0]][y+dir[i][1]]=1;
                } 
                // cout<<i<<endl;
                // for(int i=0;i<8;i++){
                //     for(int j=0;j<8;j++){
                //         cout<<dis[i][j]<<" ";
                //     }
                //     cout<<endl;
                // } 
                // cout<<endl;            
            }   
        }
        
      
    }
    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dis[x2][y2];
}