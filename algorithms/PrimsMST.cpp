#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

#define INF 2000000000
 
//PRIMS Minimum Spanning Tree:
using namespace std;

int n,m,mw=0,q;
vector< pair <int,int> > E[10001];
vector<int> sd(10001);
bool visited[10001];
struct compare
{
    bool operator()(int a,int b)
    {
        if((sd[a]<sd[b])|| (sd[a]==sd[b] && a<b))
            return true;      
        else
            return false;
    }
};
set<int,compare> S;
int main()
{
            cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                int a,b,c;
                scanf("%d%d%d",&a,&b,&c);
                E[a].push_back(make_pair(b,c));
                E[b].push_back(make_pair(a,c));       
            }
            
            S.insert(1);
            for(int i=1;i<=n;i++)
                {sd[i]=INF;
                 visited[i]=false;
                }   
            sd[1]=0;

            while(S.size()!=0)
            {
                int now=*S.begin();
                visited[now]=true;
                mw+=sd[now];
                //cout<<"Now is "<<now<<endl;cin>>q;
                S.erase(now);
                for(int i=0;i<E[now].size();i++)
                {
                    int nbr=E[now][i].first;
                    int wt=E[now][i].second;
                    //cout<<"nbr is "<<nbr<<endl;cin>>q;
                    //cout<<"wt is "<<wt<<endl;cin>>q;
                    if(sd[nbr]>wt)
                    {   //cout<<" Updating ! "<<endl;cin>>q;
                        S.erase(nbr);
                        sd[nbr]=wt;
                        S.insert(nbr);
                    }
                }
            } 
    printf("Minimum Weight %d \n",mw);
    system("PAUSE");
    return 0;
}
