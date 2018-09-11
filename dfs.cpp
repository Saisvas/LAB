#include<iostream>
#include<stack>
using namespace std;


int main()
{
    stack<int> st;
    int *visited,adj[100][100],*vertex;
    int i,j,n=4,k,s;
    cout<<"Enter no. of vertices\n";
    cin>>n;
    visited=new int[n];
    vertex=new int[n];
    cout<<"Enter all the vertices\n";
    for(i=0;i<n;i++)
    {
        cin>>vertex[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<"Enter no. of edges connected to "<<vertex[i]<<"\n";
        cin>>k;
        cout<<"Enter the names of edges that "<<vertex[i]<<" is connected to..\n";
        for(j=0;j<k;j++)
        {
            cin>>s;
            adj[i][s]=1;
        }
    }
    cout<<"This is the adjacency matrix representation..\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<adj[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\n";
    int start;
    cout<<"Enter starting vertex\n";
    cin>>start;
    visited[start]=1;
    st.push(start);
    cout<<start<<"\n";
    while(st.size()>=0)
    {
    i=st.top();
    for(j=0;j<n;j++)
    {
        if(visited[j]==0 && adj[i][j]==1)
        {
            visited[j]=1;
            st.push(j);
            cout<<j<<"\n";
            break;
        }
    }
    }
    return 0;
}
