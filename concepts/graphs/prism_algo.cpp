#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i, n) for (i = 0; i < n; i++)
#define loop1(i, k, n) for (i = k; i < n; i++)
#define pb push_back
#define MAX INT_MAX
typedef long long int ll;
int cost[][8] =
    {{MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX},
     {MAX, MAX, 25, MAX, MAX, MAX, 5, MAX},
     {MAX, 25, MAX, 12, MAX, MAX, MAX, 10},
     {MAX, MAX, 12, MAX, 8, MAX, MAX, MAX},
     {MAX, MAX, MAX, 8, MAX, 16, MAX, 14},
     {MAX, MAX, MAX, MAX, 16, MAX, 20, 18},
     {MAX, 5, MAX, MAX, MAX, 20, MAX, MAX},
     {MAX, MAX, 10, MAX, 14, 18, MAX, MAX}};
int near[8] = {MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX};
int t[2][6];
int main()
{
    int m=MAX,v,u,n=7;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(cost[i][j]<m){
                m=cost[i][j];
                v=i;
                u=j;
            }
        }
    }
    t[0][0]=v;
    t[1][0]=u;
    near[u]=near[v]=0;
    for(int i=1;i<=n;i++){
        if(near[i]!=0){
            if(cost[i][v]<cost[i][u]) near[i]=v;
            else near[i]=u;
        }
    }
    int k;
    for(int i=1;i<n-1;i++){
        m=MAX;
        for(int j=1;j<=n;j++){
            if(near[j]!=0&&cost[j][near[j]]<m){
                k=j;
                m=cost[j][near[j]];
            }
        }
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;
        for(int j=1;j<=n;j++){
            if(near[j]!=0&&cost[j][k]<cost[j][near[j]]) near[j]=k;
        }
    }
    for(int i=0;i<n-1;i++){
        cout<<t[0][i]<<" "<<t[1][i]<<endl;
    }
    return 0;
}