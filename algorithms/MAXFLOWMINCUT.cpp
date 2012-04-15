/* Gaurav Chandrashekar */
//Max Flow - Ford Fulkerson's algorithm using Max Flow Min Cut Theorem.WORST CASE RUNNING TIME OF O(N*M^2)
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

/* traversing macros */
#define FOR(i, a, b)       for(int i=int(a); i<=int(b); i++)
#define FORN(i, n)         FOR(i, 1, int(n))
#define RFOR(i, a, b)      for(int i=int(a); i>=int(b); i--)
#define TR(c, it)          for(typeof((c).begin()) it = (c).begin(); it!=(c).end(); it++)

/* shortform macros */
#define PB                 push_back
#define MP                 make_pair
#define SIZE(c)            (int((c).size()))

/* debug and printing macros */
#define _DEBUG(x) cerr<<#x<<" = "<<x<<endl;

/* typedefs */
typedef         long long       LL;
typedef         long double     LD;
typedef         vector<int>     VI;
typedef         vector<bool>    VB;
typedef         pair<int, int>  PII;
typedef         vector< PII >    VPII;
typedef         set<int>        SI;

/* infinity */
#define OO 200000000

/* MAX FLOW*/
#define MAXN  50
int ntt;
int n,m;//NOV,NOE
int AP[MAXN+1];//augmenting path queue
int visited[MAXN+1];
int from[MAXN+1];//from[i] stores where i was reached from
int rc[MAXN+1][MAXN+1];//residual capacity: stores c-f at any point of time
int pc;//path capacity of the augmenting path
VPII AL[MAXN+1];//adjacency list 
bool bfs(int source,int sink)
{
    //initialize 
    fill(visited+1,visited+n+1,0);
    fill(from+1,from+n+1,-1);
    visited[source]=1;
    int head=1,tail=1,now,next;
    pc=OO;
    AP[head]=source;int flag=0;
    while(head<=tail && flag==0)
    {
        now=AP[head];  
        head++;
        for(int j=0;j<AL[now].size();j++)
        {
            next=AL[now][j].first;  
            if(visited[next]==0 && rc[now][next]>0) // augmenting path must not include full forward edges and empty backward edges.
            {
                tail++;
                AP[tail]=next;
                from[next]=now;
                visited[next]=1;
                if(next==sink) flag=1;//break while
            }
        }
    } 
    now=sink;//path capacity is the minimum capacity of the augmenting path
    while(from[now]>-1)
    {
        next=from[now];
        pc=min(pc,rc[next][now]);
        now=next;
    }
    now=sink;
    while(from[now]>-1)
    {
        next=from[now];
        rc[next][now]-=pc;
        rc[now][next]+=pc;
        now=next;
    }
    if(pc==OO)
        return 0;
    else 
        return 1;
}
int maxflow(int source,int sink)
{
    int mincut=0;//actually max flow in the graph= value of min cut : minimum sum of 
    //weight of edges that disconnects the source from the sink   
    
    while(bfs(source,sink))//Augmenting path found:Increase maxflow by path capacity!
    {
        mincut+=pc;
    }
    return mincut;
}
int main()
{
    scanf("%d",&ntt);
    int source,sink;
    while(ntt--)
    {
        scanf("%d %d",&n,&m);     
        int i,j;// vertices marked 1----n;
        memset(rc,sizeof(rc),0);
        for(i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            AL[a].PB(MP(b,c));// do not insert b->a again!
            AL[b].PB(MP(a,c));
            rc[a][b]=c;
        }
        scanf("%d %d",&source,&sink);
        cout<<"source "<<source<<"sink "<<sink<<endl;
        printf("%d\n",maxflow(source,sink));
        /*to find the minimum cut edges
        for(i=1;i<=n;i++)
        {
            for(j=0;j<SIZE(AL[i]);j++)
            {
                if(visited[i]==true && visited[AL[i][j]]==false)
                {
                    printf("Edge from %d to %d is a part of the min cut\n",i,j);  
                }
            }   
    
        }*/
    }
system("PAUSE");
return 0;
}
