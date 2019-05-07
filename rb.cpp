#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left, *right, *parent;
    char color;         //0=red 1=black
};
int maxx=898989;
node *create_node(int key)
{
    struct node *leaf=new struct node;
    leaf->data=key;
    leaf->left=NULL;
    leaf->right=NULL;
    leaf->parent=NULL;
    leaf->color='r';
    return leaf;
}
node *check(struct node *root, struct node *tmp)
{
    if(tmp==root)
    {
        root->color='b';
        return tmp;
    }
    else
    {
        if(tmp->parent->color=='r')
        {
            if(tmp->parent==tmp->parent->parent->left)
            {
                if(tmp->parent->parent->right->color=='r')
                {
                    tmp->parent->parent->right->color='b';
                    tmp->parent->parent->left->color='b';
                }


            }
            else
            {
                if(tmp->parent->parent->left->color=='r' && tmp->parent->parent->left!=NULL)
                {
                    tmp->parent->parent->right->color='b';
                    tmp->parent->parent->left->color='b';
                }
                else
                {
                    if(tmp->parent->right==tmp)
                    {
                        tmp->parent->left=tmp->parent->parent;
                        tmp->parent->parent=tmp->parent->left->parent;
                        tmp->parent->left->parent=tmp->parent;
                        tmp->color='b';
                    }
                }
            }
        }
    }
    return root;
}
node *bst(struct node *root,struct node *tmp)
{
    if(root==NULL)
    {
        return tmp;
    }
    else if(tmp->data<root->data)
    {
        root->left=bst(root->left,tmp);
        root->left->parent=root;
    }
    else
    {
        root->right=bst(root->right,tmp);
        root->right->parent=root;
    }
    return root;

}
node *rbinsert(struct node *root,int key)
{
    node *tmp=new node;
    tmp=create_node(key);
    root=bst(root,tmp);
    root=check(root,tmp);
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {

            inorder(root->left);
            cout<<root->data<<" "<<root->color<<" , ";
            inorder(root->right);
    }
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" "<<root->color<<" , ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" "<<root->color<<" , ";
    }
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

int main()
{
    int a[]={2,1,4,5,9,3,6,7};
    int i;
    struct node *head;
    head=NULL;
    for(i=0;i<5;i++)
    {
        head=rbinsert(head,a[i]);
    };
  //  postorder(head);
    cout<<'\n';
    inorder(head);
    cout<<'\n'<<height(head);

}

