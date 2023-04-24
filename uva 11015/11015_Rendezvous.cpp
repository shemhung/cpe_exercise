#include<bits/stdc++.h>
#include <limits>
using namespace std;
vector<vector<int>> dist(25,vector<int>(25,0));
vector<string> namelist;
void Floyd_Warshall(int n);
int main(){
    int n,r,x,y,d,sum,casenum=1;
    string nstr;
    vector<int> sumlist;
    while(cin>>n>>r ){
        if(n==0 && r==0) break;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==j)
                    dist[i][j]=0;
                else    
                    dist[i][j]=1e9;
            }
        }

        for(int i=0;i<n;i++){
            cin>>nstr;
            namelist.push_back(nstr);
        }
        for(int i=0;i<r;i++){
            cin>>x>>y>>d;
            dist[x][y]=d;
            dist[y][x]=d;
        }
        Floyd_Warshall(n);

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++)
        //         cout<<dist[i][j]<< " ";
        //     cout<<endl;
        // }

        for(int i=1;i<=n;i++){
            sum=0;
            for(int j=1;j<=n;j++){
                sum+=dist[i][j];
            }
            //cout<<sum<<endl;
            sumlist.push_back(sum);
        }
        int  min=*min_element(sumlist.begin(),sumlist.end());
        auto it =find(sumlist.begin(),sumlist.end(),min);
        int index=it-sumlist.begin();
        cout<<"Case #"<<casenum<<" : "<<namelist[index]<<endl;
        casenum++;
         namelist.clear();sumlist.clear();
    }
}
void Floyd_Warshall(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dist[j][i]+dist[i][k]<dist[j][k]){
                    dist[j][k]=dist[j][i]+dist[i][k];
                }
            }
        }
    }
}