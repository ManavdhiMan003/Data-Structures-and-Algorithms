#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(i=0;i<n;i++)
#define loop1(i,k,n) for(i=k;i<n;i++)
#define pb push_back
typedef long long int ll;
struct node{
    char data;
    node* left;
    node* right;
    node(char x){
        data=x;
        left=right=NULL;
    }
};
void preorder2(node* root){
    if(root==NULL) return;
    stack<node* > s;
    s.push(root);
    node* temp=NULL;
    while(!s.empty()){
        temp=s.top();
        cout<<temp->data<<" ";
        s.pop();
        if(temp->right!=NULL) s.push(temp->right);
        if(temp->left!=NULL) s.push(temp->left);
    }
    // cout<<endl;
}
void inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
void preorder(node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void postorder(node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}
void levelorder(node* root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        cout<<curr->data<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
        q.pop();
    }
    cout<<endl;
}
int nodes(node* root){
    if(root==NULL) return 0;
    return 1+nodes(root->left)+nodes(root->right); 
}
int finddepth(node* root){
    if(root==NULL) return 0;
    return max(finddepth(root->left),finddepth(root->right))+1;
}
void topview(node* head){
    if(head==NULL) return;
    map<int,int> m;
    queue<pair<node*,int>> q;
    q.push({head,0});
    int temp;
    node *temp2=NULL;
    while(!q.empty()){
        temp=q.front().second;
        temp2=q.front().first;
        q.pop();
        if(m.find(temp)==m.end()){
            cout<<temp2->data<<" "; 
            m[temp]=temp2->data;    
        }
        if(temp2->left) q.push({temp2->left,temp-1});
        if(temp2->right) q.push({temp2->right,temp+1});

    }
    cout<<endl;
}
// void leftview(node* root){
//     if(root==NULL) return;
    
// }
int main(){
    node* head=new node('A');
    head->left = new node('B');
    head->right = new node('C');
    head->right->right = new node('G');
    head->right->left = new node('F');
    head->right->left->left = new node('I');
    head->right->left->right = new node('J');
    head->left->left = new node('D');
    head->left->right = new node('E');
    head->left->left->right = new node('H');
    inorder(head);
    cout<<endl;
    preorder(head);
    cout<<endl;
    preorder2(head);
    cout<<endl;
    postorder(head);
    cout<<endl;
    levelorder(head);
    cout<<nodes(head)<<endl;
    cout<<finddepth(head)<<endl;
    topview(head);
    return 0;
}