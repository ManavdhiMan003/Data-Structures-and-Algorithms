#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(i=0;i<n;i++)
#define loop1(i,k,n) for(i=k;i<n;i++)
#define pb push_back
#define bug() 1;//cout<<__LINE__<<endl;
typedef long long int ll;
struct node{
    int data;
    node* left;
    node* right;
    int ht;
    node(int x){
        data=x;
        left=right=NULL;
        ht=1;
    }
};
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
int height(node* root){
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}
int balancefactor(node* root){
    if(root==NULL) return 0;
    int hl=root->left?root->left->ht:0;
    int hr=root->right?root->right->ht:0;
    return hl-hr; 
}
void LLrotation(node** root){
    bug();
    // node *temp2=*root;
    node* p=(*root)->left;
    node* temp=p->right;
    p->right=*root;
    (*root)->left=temp;
    (*root)->ht=height(*root);
    p->ht=height(p);
    *root=p;
    return;
}
void LRrotation(node** root){
    node *temp=(*root)->left;
    node* temp2=temp->right;
    temp->right=temp2->left;
    (*root)->left=temp2->right;
    temp2->left=temp;
    temp2->right=*root;
    temp2->ht=height(temp2);
    temp->ht=height(temp);
    (*root)->ht=height(*root);
    *root=temp2;
    return;
}
void RRrotation(node** root){
    node* temp=(*root)->right;
    node* temp2=temp->left;
    temp->left=*root;
    (*root)->right=temp2;
    temp->ht=height(temp);
    (*root)->ht=height(*root);
    *root=temp;
    return;
}
void RLrotation(node** root){
    node* temp=(*root)->right;
    node* temp2=temp->left;
    (*root)->right=temp2->left;
    temp->left=temp2->right;
    temp2->left=*root;
    temp2->right=temp;
    temp->ht=height(temp);
    temp2->ht=height(temp2);
    (*root)->ht=height(*root);
    *root=temp2;
    return;
}
void insert(node** root,int x){
    node* temp=new node(x);
    if(*root==NULL){
        *root=temp;
        return;
    }
    else if((*root)->data>x) insert(&((*root)->left),x);
    else insert(&((*root)->right),x);
    (*root)->ht=height(*root);
    if(balancefactor(*root)>1&&x<(*root)->left->data){
        bug();
        LLrotation(&(*root));
        bug();
    }
    else if(balancefactor(*root)>1&&x>(*root)->left->data){
        LRrotation(&(*root));
    }
    else if(balancefactor(*root)<-1&&x>(*root)->right->data){
        RRrotation(&(*root));
    }
    else if(balancefactor(*root)<-1&&x<(*root)->right->data){
        RLrotation(&(*root));
    }
}

int main(){
    // ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    node* head=NULL;
    insert(&head,5);
    // cout<<head->data<<"\n";
    insert(&head,7);
    // cout<<head->data<<"\n";
    insert(&head,6);
    preorder(head);
    return 0;
}