#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int data;
    vector<node *>child;
};
node * create(int key)
{
    struct node* ptr;
    ptr= new struct node;
    ptr->data=key;
    return ptr;
}
node *insertele(struct node *root,int key)
{
    if(root==NULL)
    {
        root=create(key);
        return root;
    }
    else
    {
        char op;
        cout<<"child of "<<root->data<<":- ";
        cin>>op;
        if(op=='y')
        {
            root->child.push_back(create(key));
        }
        else
        {
            for(i=0;i<root->child.size();i++)
            {

            }
        }

    }
}


