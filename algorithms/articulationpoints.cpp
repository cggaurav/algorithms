#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
int m,n;
vector<int> adjacent[10001];
bool visited[10001];
int DFSno[10001],f[10001],parent[10001],q,inf=200000000,countnbr1=0;
/* Define f[i] as the vertex with the minimum DFS no that you can visit from the subtree of i including i*/
int dfs(int i)
{

	int j,next;
	visited[i]=1;
	f[i]=DFSno[i];
	cout<<" i "<<i<<endl;cin>>q;
	for(j=0;j<adjacent[i].size();j++)
	{
		next=adjacent[i][j];
		cout<<" next "<<next<<endl;cin>>q;
		if(visited[next]==0)
		{	cout<<" Path1 "<<endl;cin>>q;	
			DFSno[next]=DFSno[i]+1;
			parent[next]=i;
			dfs(next);
			f[i]=min(f[i],f[next]);
		}
		else if(next!=parent[i])
		{	cout<<" Path2 "<<endl;cin>>q;
			f[i]=min(f[i],DFSno[next]);
		}
	}
	cout<<" Computed for "<<i<<endl;
	cout<<" DFS "<<DFSno[i]<<"  F[i] "<<f[i]<<endl;cin>>q;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j,a,b;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		adjacent[a].push_back(b);
		adjacent[b].push_back(a);
		if(a==1 || b==1)
		countnbr1++;
	}
	DFSno[1]=1;
	dfs(1);
	cout<< " Articulation Points "<<endl;
	if(countnbr1>=2)
	printf("1\n");
	i=2;
	while(i<=n)
	{	
		for(j=0;j<adjacent[i].size();j++)
		{
			if(f[adjacent[i][j]]>=DFSno[i] && adjacent[i][j]!=parent[i])
			{	printf("%d\n",i);
				i++;
			}	
			
		}
		
	}
	return 0;
}
