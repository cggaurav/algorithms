#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/* 	Binary Index Tree in one dimensions
	to find the prefix sum is the aim!
	
	Let BIT[i] denote the sum of a[i],a[i-1],a[i-1].......,a[i-2^k+1] where k is the number of trailing zeroes in the binary 
	representation of i.
	i&(-i) gives the 2^k! 
*/
int n,m,start,end;
vector<int> BIT;

void updateBIT(int i,int value)
{	cout<<" Update "<<endl;		
	
	while(i<=n)
	{	cout<<" i "<<i<<endl;
		BIT[i]+=value;
		i+=(i&(-i));
	}
}
int findsum(int i)
{	int sum=0;
	while(i>=1)
	{	sum+=BIT[i];
		i-=(i&(-i));
	}
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i;
	BIT.reserve(n+1);
	for(i=1;i<=n;i++)BIT[i]=0;
	for(i=1;i<=n;i++)
	{	
        int j;
		scanf("%d",&j);
		updateBIT(i,j);
	}
	cout<<" BIT "<<endl;
	for(i=1;i<=n;i++)
	cout<<BIT[i]<<" ";
	cout<<endl;
    		
	for(i=1;i<=m;i++)
	{	cout<<" Start and end"<<endl;
		scanf("%d%d",&start,&end);
		printf("%d",findsum(end)-findsum(start-1));
	}
	
	system("PAUSE");
	return 0;
}
