#include <bits/stdc++.h>
using namespace std;

bool sort_by_w(const pair< pair<int,int>, int > &a,
              const pair< pair<int,int> ,int > &b)
{
    return (a.second < b.second);
}

int find_set(int u,vector<int> parent){
	if(u==parent[u])
		return u;
	else return find_set(parent[u],parent);

}
 
void union_set(int u,int v,vector<int> &parent){
	parent[u]=parent[v];
}

void kruskal(vector<pair< pair<int,int> ,int > > edges,vector<int> &parent){

	int m = edges.size();
	int n = parent.size(),x,y;

	for(int i=0;i<m;i++){
		x = find_set(edges[i].first.first, parent);
		y = find_set(edges[i].first.second, parent);
		if(x!=y){
			union_set(x,y,parent);
			cout<<edges[i].first.first<<"-------"<<edges[i].first.second<<" : "<<edges[i].second<<endl;
		}
	}

}

int main(){

	int n,u,v,w,m;
	cin>>n>>m;
	vector<pair< pair<int,int> ,int > > edges,edges_squared;
	vector<int> parent(n+1);
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		edges.push_back(make_pair(make_pair(u,v),w));
		edges_squared.push_back(make_pair(make_pair(u,v),w*w));
	}
	sort(edges.begin(),edges.end(),sort_by_w);
	sort(edges_squared.begin(),edges_squared.end(),sort_by_w);
	for(int i=1;i<=n;i++){
		parent[i]=i;
	}
	cout<<"MST for normal edge weight"<<endl;
	kruskal(edges,parent);
	for(int i=1;i<=n;i++){
		parent[i]=i;
	}
	cout<<"MST for squared edge weights"<<endl;
	kruskal(edges_squared,parent);

	return 0;
}