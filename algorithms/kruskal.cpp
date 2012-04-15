
#include<iostream>
#include<algorithm>

#define FOR(i,l,r) for (int i=l; i<=r; ++i)
#define FORD(i,l,r) for (int i=l; i>=r; --i)
#define inf 2000000000
#define MAXM 50
#define MAXN 50
using namespace std;

struct Edge
{
    int u, v, c;
    //edge between u and v of weight c     
    bool operator < (Edge a) const 
    {return c < a.c;} 
};

Edge edge[MAXM];
int Parent[MAXN];
int n,m,MST=0,q;

int findRoot(int u)
{
    if (Parent[u]==u) return u;
    Parent[u]=findRoot(Parent[u]);
    return Parent[u];
}
//path compression for Union/Find rank
int main()
{   
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].c);
    }
    
    sort(edge+1, edge+m+1);
    /*cout<<"Sorted Edge weights"<<endl;
    for(int i=1;i<=m;i++)
        cout<<edge[i].c<<endl;
        cin>>q;*/    
    FOR(i, 1, n)
        Parent[i]=i;
        
    FOR(i, 1, m)
    {   
        int ru=findRoot(edge[i].u);
        int rv=findRoot(edge[i].v);
        //cout<<" u "<<edge[i].u<<endl;cout<<" v "<<edge[i].v<<endl;
        //cout<<" ru "<<ru<<endl;cout<<" rv "<<rv<<endl;
        //cin>>q;
        if (ru!=rv)        
        {   //cout<<"Union"<<endl;cin>>q;
            Parent[ru]=rv;                
            MST+=edge[i].c;
        }
    }
    cout<<"MST weight "<<MST<<endl;
    //int q;cin>>q;
    return 0;
}
