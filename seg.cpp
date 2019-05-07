#include<iostream>
using namespace std;
int const maxx=778;
struct node
{
    int data;
    int start;
    int finish;
    struct node *left;
    struct node *right;
    struct node *parent;
};
node * create(int key,int l,int h)
{
    node *temp=new node;
    temp->data=key;
    temp->start=l;
    temp->finish=h;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=NULL;
    return temp;
}
node *conseg(node *root,int a[],int s,int e)
{
    if(s==e)
    {
        return create(a[s],s,e);
    }
    else
    {
        int l,r;
        int mid=(s+e)/2;
        root=create(maxx,s,e);
        root->left=conseg(root->left,a,s,mid);
        root->right=conseg(root->right,a,mid+1,e);
        root->left->parent=root;
        root->right->parent=root;
        l=root->left->data;
        r=root->right->data;
        if(l<r)
        {
            root->data=l;
        }
        else
        {
            root->data=r;
        }
        return root;
    }
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int findmin(node *root,int q1,int q2)
{
    if(root->finish<q1 || root->start>q2)
    {
        return maxx;
    }
    else if(root->start>=q1 && root->finish<=q2)
    {
        return root->data;
    }
    else
    {
        int l,r;
        l=findmin(root->left,q1,q2);
        r=findmin(root->right,q1,q2);
        if(l<r)
        {
            return l;
        }
        else
        {
            return r;
        }
    }
}
node *findval(node *root,int key)
{
    if(root!=NULL)
    {
        node *tmp=new node;
        tmp=NULL;
        tmp=findval(root->left,key);
        if(tmp==NULL)
        {
            tmp=findval(root->right,key);
            if(root->data==key)
            {
                tmp=root;
                return tmp;
            }
            return tmp;
        }
        return tmp;
    }
    return NULL;
}
node *minseg(node *root,node *tmp)
{
    if(root==tmp)
    {
        return root;
    }
}
node *conminseg(node *root)
{
    if(root->left==NULL)
    {
        return root;
    }
    node *l=new node;
    node *r=new node;
    l=conminseg(root->left);
    r=conminseg(root->right);
    if(l->data<r->data)
    {
        root->data=l->data;
    }
    else
    {
        root->data=r->data;
    }
    return root;
}
node *update(node *root,int val)
{
    node *cv=new node;
    int tmp;
    cv=findval(root,val);
    if(cv==NULL)
    {
        cout<<"\nNosuch given value was found\n";
        return root;
    }
    cout<<"enter changed value:- ";
    cin>>tmp;
    cv->data=tmp;
    root=conminseg(root);
    cout<<"value successfully changed:\n";
    return root;
}
int main()
{
    int a[]={-1,3,4,0,2,1};
    node *head;
    head=NULL;
    int val;
    int n=sizeof(a)/sizeof(a[0])-1;
    head=conseg(head,a,0,n);
    int q1,q2;
    cout<<"enter the value you want to replace:- ";
    cin>>val;
    head=update(head,val);
    inorder(head);
    /*cout<<"enter range to find minimum\nstart:- ";
    cin>>q1;
    cout<<"finish:- ";
    cin>>q2;
    cout<<"minimum in given range is:- "<<findmin(head,q1,q2);*/
    return 0;
}
