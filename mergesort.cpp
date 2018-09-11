#include<iostream>
using namespace std;
void merge(int *left,int *right,int *a,int nl,int nr)
{
  //  int nl=sizeof(left)/sizeof(left[0]);
    //int nr=sizeof(right)/sizeof(right[0]);
    int i=0,j=0,k=0;
    while(i<nl && j<nr)
    {
        if(left[i]<right[j])
        {
            a[k]=left[i];
            i++;
            k++;
        }
        else
        {
            a[k]=right[j];
            j++;
            k++;
        }
    }
        while(i<nl)
        {
            a[k]=left[i];
            i++;
            k++;
        }
        while(j<nr)
        {
            a[k]=right[j];
            j++;
            k++;
        }
    }
void mergesort(int *a,int n)
{
    int mid,*left,*right,i;
    if(n<2)
        return;
    mid=n/2;
    left=new int[mid];
    right=new int[n-mid];
    for(i=0;i<mid;i++)
        left[i]=a[i];
    for(i=mid;i<n;i++)
        right[i-mid]=a[i];
    mergesort(left,mid);
    mergesort(right,n-mid);
    merge(left,right,a,mid,n-mid);
}

int main()
{
    int n,*a,i;
    cout<<"Enter no. of elements"<<endl;
    cin>>n;
    a=new int[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    mergesort(a,n);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
