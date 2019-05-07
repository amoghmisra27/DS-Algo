#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
    char color;         //0=red 1=black
};
node *create(int key)
{
    node *tmp=new node;
    tmp->data=key;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
int height(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l,r;
    l=height(root->left);
    r=height(root->right);
    if(l<r)
    {
        return r+1;
    }
    else
    {
        return l+1;
    }
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
node *rotatel(node *root)
{
   node *r=root->right;
   node *rl=r->left;
   r->left=root;
  root->right=rl;
   root=r;
   return root;
}
node *rotater(node *root)
{
    node *l=root->left;
    node *lr=l->right;
    l->right=root;
    root->left=lr;
    root=l;
    return root;
}
node *rotaterl(node *root)
{
    root->right=rotater(root->right);
    root=rotatel(root);
    return root;
}
node *rotatelr(node *root)
{
    root->left=rotatel(root->left);
    root=rotater(root);
    return root;
}
node *avlinsert(node *root,int key)
{
    if(root==NULL)
    {
        return create(key);
    }
    if(key<root->data)
    {
        root->left=avlinsert(root->left,key);
    }
    else
    {
        root->right=avlinsert(root->right,key);
    }
    int l=height(root->left);
    int r=height(root->right);
    if(l-r<-1 && key>root->right->data)
    {
        root=rotatel(root);
    }
    if(l-r>1 && key<root->left->data)
    {
        root=rotater(root);
    }
    if(l-r<-1 && key<root->right->data)
    {
        root=rotaterl(root);
    }
    if(l-r>1 && key>root->left->data)
    {
        root=rotatelr(root);
    }
    return root;
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {

            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
    }
}
int main()
{
    node *head;
    head=NULL;
    int a[]={30,10,20,40,50,25};
    int i;
    for(i=0;i<3/*(sizeof(a)/sizeof(a[0]))*/;i++)
    {
        head=avlinsert(head,a[i]);
    }
    preorder(head);
    cout<<'\n'<<height(head);
    cout<<'\n';
    inorder(head);
}
