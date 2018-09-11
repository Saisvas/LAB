#include<iostream>
using namespace std;
class list
{
 private:
 struct node
{ 
int data;
struct node *next;
}*head;
int count;
 struct node *pnew;
public:
 list()
{
 head=NULL;
 count=0;
}
int insertbeg()
{
 int val;
 cout<<"Enter number\n";
 cin>>val;
 pnew=new struct node;
 pnew->data=val;
 pnew->next=NULL;
if(head==NULL)
{
 head=pnew;
}
else
{
 pnew->next=head;
 head=pnew;
}
count++;

 return head->data;
}                           //End of insertbeg

int insertend()
{
 node *temp;
// temp=new struct node;(Not necessary for "temp" variables)
 int val;
 cout<<"Enter number\n";
 cin>>val;
 pnew=new struct node;
 pnew->data=val;
 pnew->next=NULL;
 if(head==NULL)
{
 head=pnew;
}
else
{
 
 temp=head;
 while(temp->next!=NULL)
{
 temp=temp->next;
}
 temp->next=pnew;
}
count++;
return pnew->data;
}                       //End of insertend           


int insertspecific()
{
 int loc,val;
 cout<<"Enter number\n";
 cin>>val;
 cout<<"Enter specific location to insert\n";
 cin>>loc;
if(loc>=count)
{
 cout<<"Enter a correct location\n";
}
else
{
 node *temp;
 temp=head;
 for(int i=0;i<loc;i++)
{
 temp=temp->next;
}
count++;
pnew->next=temp->next;
temp->next=pnew;
return pnew->data;
}
}                    //End of insertspecific

void retrieve()
{
 int nod;
 int total=0;
 node *temp;
 temp=head;
 cout<<"Enter the index(starts at zero) to get its value\n";
 cin>>nod;
 while(temp!=NULL)
{ 
 if(nod==total)
{ 
 cout<<"Value at index "<<nod<<" is "<<temp->data<<"\n";
 return;
}

temp=temp->next;
total++;
}
cout<<"Invalid location\n";

}                   //End of retrieve


void remove(int val)
{
 
 node *tmp,*temp,*t;

 tmp=head;
 temp=head->next;

if(head==NULL)
{
	cout<<"Empty";
	return;
}

node *p,*c;

c=head;
p=NULL;

while(c!=NULL)
{

	if(val==c->data)
	{
		if(p==NULL)
			head=c->next;
		else
			p->next=c->next;
		delete(c);
		count--;
		return;
	}

	p=c;
	c=c->next;
}

cout<<"Not found";

/*while(tmp->next!=NULL)
{
 temp=head;
 temp=temp->next;
 t=head;
 t=t->next;
 if(temp->data=val)
{
 node *tep;
 temp->next=tep;
 t->next=tep;
 delete temp;
 count--;
} 
else 
{
 cout<<"Number not found\n";
}        
} */ 
}                  //End of remove

void display()
{
 if(head==NULL)
 cout<<"Empty\n";
 else
{
//Alternate code:
/* 
node *t;
t=head;
while(t!=NULL)
{
 cout<<t->data<<"\t";
 t=t->next;
}
*/

node *t=head;
 for(int i=count;i>0;i--)
{
 cout<<t->data<<"\t";
 t=t->next;
}
cout<<"\n";
}
}                       //End of display

int dispcount()
{
 return count;
}                     //End of dispcount

};                 //End of class



int main()
{
 list l1;
int val;
 int k;
 
while(k<8)
{
cout<<"1.Insertbeg 2.Insertend 3.Insert after a node 4.Retrieve"<<"\n"<<" 5.Delete 6.Display 7.Total nodes 8.Exit\n";
 cin>>k;
 
switch(k)
{
 case 1:
   l1.insertbeg();
   break;
 case 2:
   l1.insertend();
   break;
 case 3:
   l1.insertspecific();
   break;
 case 4:
   l1.retrieve();
   break;
 case 5:
   cout<<"Enter Val:";
   cin>>val;
   l1.remove(val);
   break;
 case 6:
   l1.display();
   break;
 case 7:
   cout<<"Total nodes are "<<l1.dispcount()<<"\n";
   break;
 default:
   cout<<"--Finished--\n";
   break;
}
}

 return 0;
}
