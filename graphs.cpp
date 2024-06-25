#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;
class graph
{
	public:
	void addedge(unordered_map<int,list<int>>&m,int n,int v,int direction)
	{
		for(int i=0;i<n;i++)
		{
		int u,v;
		cin>>u>>v;	
		m[u].push_back(v);
		if (direction==1)
		{
			m[v].push_back(u);
		}
	}
	}
	void print(unordered_map<int,list<int>>m)
	{
		for(auto i:m)
		{
			cout<<i.first<< ":";
			for(auto j:i. second)
			{
				cout<<j<<",";
			}
			cout<<endl;
		}
	}
	void bfs(unordered_map<int,list<int>>&m,unordered_map<int ,bool>&vis,vector<int>&ans,int nd)
	{
		queue<int>q;
		q.push(nd);
		vis[nd]=1;
		while(!q.empty())
		{
			int front=q.front();
			q.pop();
			ans.push_back(front);
			for(auto i:m[front])
			{
				if(!vis[i])
				{
					q.push(i);
					vis[i]=1;
				}
			}
		}
	}
};
/*
1 2
1 3
2 5
3 4
4 5
*/
int main()
{
	unordered_map<int,list<int>>m;
	int n,v;
	cout<<"enter number of node"<<endl;
	cin>>n;
	cout<<"enter number of vertices"<<endl;
	cin>>v;
	graph g;
	g.addedge(m,n,v,1);
	g.print(m);
	unordered_map<int,bool>vis;
	vector<int>ans;
	for(int i=1;i<n;i++)
	{
		if(!vis[i])
		{
			g.bfs(m,vis,ans,i);
		}
	}
	int size=ans.size();
	for(int i=0;i<size;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
