#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#define INFINITY 2000000000
/* Dijkstra with set....MLOGV solution */
using namespace std;
vector<int> sd;
struct compare
{   
    bool operator ()(int a,int b)
    {
        if(sd[a]<sd[b])
            return true;
        else if(sd[a]==sd[b] && a<b)
            return true;
        else
            return false;
    }
};
set<int,compare> S;
vector<pair<int,int> > E[10001];
int m,n,start,destination,q;
int main()
{   
    cin>>n>>m;
    sd.reserve(n+1);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        E[a].push_back(make_pair(b,c));  
        E[b].push_back(make_pair(a,c));
    }
    for(int i=1;i<=n;i++)
        sd[i]=INFINITY;
    sd[1]=0;
    S.insert(1);
    while(1)
    {   //cout<<" SIZE OF SET"<<S.size()<<endl;cin>>q;
        int now=*S.begin();
        S.erase(now);
        //cout<<" NOW IS "<<now<<endl;cin>>q;
        if(now==destination)  
        break;
        for(int i=0;i<E[now].size();i++)
        {
            int nbr=E[now][i].first;
            int weight=E[now][i].second;
            //cout<<nbr<<" is the neighbour of "<<now<<" and the weight is "<<weight<<endl;cin>>q;
            if(sd[nbr]> sd[now]+weight)
            {   //cout<<" Path to "<<nbr<<" is shorter through "<<now<<endl;
                S.erase(nbr);
                sd[nbr]=sd[now]+weight;
                S.insert(nbr);   
            }   
        }
    }
    cout<<"Shortest Distance "<<endl;
    for(int i=1;i<=n;i++)
        cout<<sd[i]<<" ";
        cin>>q;
}
