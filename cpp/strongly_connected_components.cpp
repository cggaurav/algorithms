 #include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

typedef unsigned long UL;
typedef signed long SL;
typedef unsigned short US;
typedef signed short SS;

const UL max_N=1000;

vector<UL> adjl[max_N];
vector<UL> radjl[max_N];

vector<UL> cadjl[max_N];
vector<UL> comp_ver[max_N];

UL tmp;
UL z[max_N];
bool visited[max_N];

UL comp[max_N];
UL n_comp=0;

void DFS(UL v)
{
    if(visited[v])
        return;
    visited[v]=true;
    for(UL i=0; i<adjl[v].size(); ++i)
        DFS(adjl[v][i]);
    z[--tmp]=v;//calculates finishing time;
}

void rDFS(UL v)
{
    //cerr<<"Begin rDFS "<<v<<endl;
    visited[v]=true;
    comp[v]=n_comp;
    comp_ver[n_comp].push_back(v);
    
    for(UL i=0; i<radjl[v].size(); ++i)
    {
        const UL u=radjl[v][i];
        //if(v==1)
            //cerr<<"u: "<<u<<endl;
        if(!visited[u])
            rDFS(u);
        else
            if(comp[u]!=comp[v] && (cadjl[comp[u]].empty() || cadjl[comp[u]].back()!=comp[v]))// make sure you do not draw parallel component edges.!
                cadjl[comp[u]].push_back(comp[v]);
    }
    //cerr<<"End rDFS "<<v<<endl;
}

int main()
{
    UL N, M;
    scanf("%lu %lu", &N, &M);
    for(UL i=0; i<M; ++i)
    {
        UL a,b;
        scanf("%lu %lu", &a, &b);
        adjl[a].push_back(b);
        radjl[b].push_back(a);
    }
    tmp=N;
    fill(visited, visited+N, false);
    for(UL i=0; i<N; ++i)
        DFS(i);
    fill(visited, visited+N, false);
    for(UL i=0; i<N; ++i)
    {
        const UL v=z[i];
        if(!visited[v]) //new component
        {
            rDFS(v);
            ++n_comp;
        }
    }
    printf("Number of components: %lu\n", n_comp);
    for(UL i=0; i<n_comp; ++i)
    {
        printf("\nComponent %lu :\nVertices :", i);
        for(UL j=0; j<comp_ver[i].size(); ++j)
            printf(" %lu", comp_ver[i][j]);
        printf("\nOutgoing edges to components : ");
        for(UL j=0; j<cadjl[i].size(); ++j)
            printf(" %lu", cadjl[i][j]);
        printf("\n");
    }
system("PAUSE");
return 0;
}
