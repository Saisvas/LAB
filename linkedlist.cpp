#include<iostream>
using namespace std;
class list{
private:
    struct node
    {
        int data;
        node *next;

    }*head;
    int number;
    node *pnew;
    node *curnode,*prevnode;
public:
    list()
    {
        number=0;
        head=NULL;
    }
    void insertbeg()
    {
        int val;
        cout<<"Enter to insert at the beginning\n";
        cin>>val;
        pnew=new struct node;
        pnew->data=val;
        pnew->next=NULL;
        if(head==NULL)
        {
            head=pnew;
        }
        else{
            pnew->next=head;
            head=pnew;
        }
        number++;
    }
    void display()
    {

        for(int i=number;i>0;i--)
        {
            cout<<head->data<<"\t";
            head=head->next;

        }
    }
    void deleteatn()
    {
        curnode=new struct node;
        prevnode=new struct node;
        int n;
        cout<<"Enter position to delete\n";
        cin>>n;
if(n==0)
{
    curnode=head;
    delete head;

}
else{
        for(int i=1;i<n;i++)
        {
            prevnode=head->next;
            prevnode=prevnode->next;
            if(i==(n-1))
            {
                prevnode->next=curnode;
                curnode->next=prevnode;
             delete curnode;

            }

        }

    }

    }
};
int main()
{
    int s=0;
    list l1;
    while(s<3)
    {
    cout<<"1.Insertbeg 2.Display 3.Delete at nth 4.Exit\n";
    cin>>s;
    switch(s)
    {
    case 1:
        l1.insertbeg();
        break;
    case 2:
        l1.display();
        break;
    case 3:
        l1.deleteatn();
        break;
    default:
        cout<<"--Exit succesfull--";
        break;
    }
    }
    return 0;
}
