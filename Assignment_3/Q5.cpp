#include<bits/stdc++.h>
using namespace std;

class Compare
{
 public: 
 	bool operator()(const pair<int,int> lhs, const pair<int,int> rhs) const
  {
     return lhs.second > rhs.second;
  }
};

/*

Vertex    Distance from Source
1          0
2          4
3          12
4          19
5          21
6          11
7          9
8          8
9          14

*/

int main(){

	priority_queue<pair<int,int>,vector<pair<int,int> >, Compare> pq;
	int V,E,u,v,w;
	cin>>V>>E;
	vector<vector<pair<int,int> > > adj(V+1);
	vector<int> parent(V+1);
	vector<int> dist(V+1);

	for(int i=0;i<E;i++){
		cin>>u>>v>>w;
    	adj[u].push_back(make_pair(v,w));
    	adj[v].push_back(make_pair(u,w));
	}

	for(int i=1;i<=V;i++){
		parent[i]=-1;
		dist[i]=INT_MAX;			
	}

	int s,d;
	cin>>s;
	dist[s]=0;

	for(int i=1;i<=V;i++)
	{
		pq.push(make_pair(i,dist[i]));			
	}

	while(!pq.empty())
	{
		
		pair<int,int> smallest = pq.top();
		if(smallest.second == INT_MAX)	 
			break;
		pq.pop();

		for(int i=0;i<adj[smallest.first].size();i++){
			int v = adj[smallest.first][i].first;
			int w = adj[smallest.first][i].second;
			int new_dist = smallest.second + w;

			if(new_dist<dist[v]){
				dist[v] = new_dist;
				parent[v]=smallest.first;
				pq.push(make_pair(v,new_dist));
			}

		}
	}
	
	 for(int i=1;i<=V;i++){
	 	if(i==s) continue;
	 	cout<<endl;
	 	cout<<"Vertex : "<<i<<endl<<"Distance - "<<dist[i]<<endl;
	 	int new_d = i;
	 	vector<int> v;
		v.clear();
		v.push_back(new_d);
		cout<<"Path - "<<new_d<<" <-- ";
		while(parent[new_d]!=-1){
			v.push_back(parent[new_d]);
			if(parent[parent[new_d]]!=-1)cout<<parent[new_d]<<" <-- ";
			else cout<<parent[new_d];
			new_d = parent[new_d];		 
		}
		cout<<endl;
	 }

	return 0;

}