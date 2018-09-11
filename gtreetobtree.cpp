#include<iostream>
using namespace std;
class gtb
{
    int top;
public:
    gtb()
    {
        top=-1;
    }
    struct node
    {
        char name;
        struct node*left,*right;
    }*root;
    struct stack
    {
        int level;
        struct node *ptr;
    }s[50];
    void push(struct node *pnew,int l)
    {
        top++;
        s[top].ptr=pnew;
        s[top].level=l;
    }
    int pop()
    {
        struct node *x;
        x=s[top].ptr;
        top--;
    }
    void convert(char ch,int l)
    {
        struct node *pnew;
        pnew=new struct node;
        pnew->name=ch;
        pnew->left=NULL;
        pnew->right=NULL;
        if(l==0)
        {
            root=pnew;
            push(pnew,l);
        }
        else
        {
            if(s[top].level<l)
            {
                s[top].ptr->left=pnew;
                push(pnew,l);
            }
            else if(s[top].level==l)
            {
                s[top].ptr->right=pnew;
                push(pnew,l);
            }
            else
            {
                while(s[top].level!=l)
                {
                    pop();
                }
                s[top].ptr->right=pnew;
                push(pnew,l);
            }
        }
    }
    int preorder(struct node *root)
    {
        if(root!=NULL)
        {
            cout<<root->name<<"->";
            preorder(root->left);
            preorder(root->right);
        }
    }
};
int main()
{
    gtb g;
    int m,l;
    char ch;
    cout<<"Enter size\n";
    cin>>m;
    cout<<"Enter ch and level in pre-order\n";
    cin>>ch>>l;
    for(int i=0;i<m;i++)
    {
        g.convert(ch,l);
    }
    g.preorder(g.root);
    return 0;
}
