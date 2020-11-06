#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(i=0;i<n;i++)
#define loop1(i,k,n) for(i=k;i<n;i++)
#define pb push_back
typedef long long int ll;
void BFS(int G[][7],int start,int n){
    int visited[7]={0};
    cout<<start<<" ";
    visited[start]=1;
    queue<int> q;
    q.push(start);
    int i=start;
    while(!q.empty()){
        i=q.front();
        q.pop();
        for(int j=1;j<n;j++){
            if(G[i][j]==1&&visited[j]==0){ 
                cout<<j<<" ";
                visited[j]=1;
                q.push(j);
            }
        }   
    }
    cout<<endl;
}
void DFS(int G[][7],int start,int n){
    static int visited[7]={0};
    if(visited[start]==0){
        cout<<start<<" ";
        visited[start]=1;
        for(int i=1;i<n;i++){
            if(G[start][i]==1&&visited[i]==0) DFS(G,i,n);
        }
    }
}
int main(){
    int G[7][7]={{0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,1,0,0,1,0,0},
    {0,1,0,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}};
    BFS(G,3,7);
    DFS(G,1,7);
    return 0;
}