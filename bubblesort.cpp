
#include<iostream>
using namespace std;
void swap(int a,int b)
{
   int temp;
    temp=a;
    a=b;
    b=temp;
}
int main()
{
    long *a,n,i,k;//flag;
    cin>>n;
    a=new long[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(k=1;k<n;k++)
    {
        //flag=0;
        for(i=0;i<n-k;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a[i],a[i+1]);
                //flag=1;
            }
        }
       // if(flag==1)
         //   break;
    }
    if(n%2==1)
        cout<<a[n/2];
    else
        cout<<(a[n/2]+a[(n/2)+1])/2;
    return 0;
}
