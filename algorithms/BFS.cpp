#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;


int visited[1001],parent[1001];
int sdistance[1001];
int n,m,startbfs,q,now;
queue<int> bfs;
vector<int> adjacent[1001];

int main()
{
	scanf("%d%d%d",&n,&m,&startbfs);
	int i,j,a,b;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		adjacent[a].push_back(b);
		adjacent[b].push_back(a); 
	}	
	cout<<"Adacency List"<<endl;
	for(i=1;i<=n;i++)
	 {
	 	for(j=0;j<adjacent[i].size();j++)
		 cout<<adjacent[i][j]<<"  ";
		 cout<<endl;	 
	 }
	cin>>q;
	visited[startbfs]=1;
	sdistance[startbfs]=0;
	bfs.push(startbfs);
	while(!bfs.empty())
	{	
		now=bfs.front();
		cout<<"Processing "<<now<<endl;
		cin>>q;
		bfs.pop();
		for(j=0;j<adjacent[now].size();j++)
		 if(visited[adjacent[now][j]]==0)
		 {
		 	bfs.push(adjacent[now][j]);
			cout<<"Inserting "<<adjacent[now][j]<<" into Q"<<endl;
			cin>>q;
			visited[adjacent[now][j]]=1;
			sdistance[adjacent[now][j]]=sdistance[now]+1;
			cout<<"sdistance of "<<adjacent[now][j]<<" is "<<sdistance[adjacent[now][j]]<<endl;
			cin>>q;
			parent[adjacent[now][j]]=now;
			cout<<"Parent of "<<adjacent[now][j]<<" is "<<parent[adjacent[now][j]]<<endl;
			cin>>q;
			
		 
		 }
	
	}	 	 
	for(i=1;i<=n;i++)
		cout<<i<<" ";
		cout<<endl;
	cout<<"Visited"<<endl;
	for(i=1;i<=n;i++)
	cout<<visited[i]<<" ";
	cout<<endl;
	cin>>q;
	cout<<"sdistance"<<endl;
	for(i=1;i<=n;i++)
	cout<<sdistance[i]<<" ";
	cout<<endl;
	cin>>q;
	cout<<"Parent"<<endl;
	for(i=1;i<=n;i++)
	cout<<parent[i]<<" ";
	cout<<endl;
	cin>>q;

	return 0;

}

