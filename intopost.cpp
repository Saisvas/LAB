#include<iostream>
#include<string>
using namespace std;
class stacks
{
public:
    char *st;
    int top;
    int n;
    stacks()
    {
        top=-1;
        st=new char[n];
    }
    int enter()
    {
        cin>>n;
        return n;
    }
    bool isfull()
    {
        if(top==(n-1))
         return true;
         else
            return false;
    }
    bool isempty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
    void push(char x)
    {
        if(isfull())
        {
            cout<<"stackoverflow\n";
            return;
        }
        top++;
        st[top]=x;
    }
    void pop()
    {
        if(isempty())
        {
            cout<<"stackunderflow\n";
            return;
        }
        else
        {
            top--;
        }
    }
    void display()
    {
        if(isempty())
        {
            cout<<"Nothing to display\n";
            return;
        }
        int k;
        k=top;
        while(k!=-1)
        {
            cout<<st[k]<<"\n";
            k--;
        }
    }
    char peek()
    {
        if(top<0)
        {
            cout<<"Stack is empty\n";
        }
        else
        {
            return st[top];
        }
    }

};
int weight(char ch)
{
    switch(ch)
    {
    case '/':
    case '*':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}
string intopost(string exp,string res)
{
    int i;
    stacks t;
    for(i=0;i<exp.length();i++)
    {
        if(exp[i]<=122 && exp[i]>=97)
        {
            res=res+exp[i];
        }
        else if(exp[i]=='+' || exp[i]=='-'|| exp[i]=='/' || exp[i]=='*')
        {
            while(!t.isempty() && (weight(exp[i])<=weight(t.peek())))
                                   {
                                       res=res+t.peek();
                                       t.pop();
                                   }
                        t.push(exp[i]);
        }
    }
    while(!t.isempty())
    {
        res=res+t.peek();
        t.pop();
    }
    return res;
}


int main()
{
    int num,n;
    string exp,res=" ";
    stacks t;
    cout<<"Enter stacks size\n";
    t.enter();
    cout<<"Enter Infix expression\n";
    cin>>exp;
    cout<<"\n"<<intopost(exp,res);
    return 0;
}
