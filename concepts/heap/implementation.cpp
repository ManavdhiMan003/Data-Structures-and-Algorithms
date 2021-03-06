#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(i=0;i<n;i++)
#define loop1(i,k,n) for(i=k;i<n;i++)
#define pb push_back
typedef long long int ll;
void insert(int *a,int n){
    int temp=a[n],i=n;
    while(i>1&&temp>a[i/2]){
        a[i]=a[i/2];
        i/=2;
    }
    a[i]=temp;
}
int del(int a[],int n){
    int i=1,j=2*i,temp=a[1],t;
    a[1]=a[n];
    while(j<n-1){
        if(a[j+1]>a[j]){
            j++;
        }
        if(a[i]<a[j]){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i=j;
            j=2*i;
        }
        else break;
    }
    a[n]=temp;
    return temp;
}
void heapify(int a[],int n){
    int s=n/2;
    for(int i=s;i>0;i--){
        int l=2*i,r=2*i+1,c=i,k=i;
        while(l<n||r<n){
            if(a[l]>a[c]&&r<n){
                c=l;
            }
            if(a[r]>a[c]&&r<n){
                c=r;
            }
            if(c!=k){
                swap(a[c],a[k]);
                k=c;
            }
            l=2*k;
            r=2*k+1;
            c=k;
        }
    }
}
int main(){
    int a[8]={0,10,50,75,95,32,56,78};
    heapify(a,8);
    for(int i=1;i<8;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=2;i<8;i++){
        insert(a,i);
    }
    for(int i=1;i<8;i++) cout<<a[i]<<" ";
    cout<<endl; 
    for(int i=7;i>0;i--) del(a,i);
    cout<<"sorted order\n";
    for(int i=7;i>0;i--) cout<<a[i]<<" ";
    return 0;   
}