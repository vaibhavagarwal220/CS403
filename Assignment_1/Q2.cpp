#include <bits/stdc++.h>
using namespace std;

bool dfs_util(vector<vector<int> > &adj,vector<bool> &visited,vector<int> &parent,int N,int v,int parent_of_v)
{
    visited[v] = true;
    parent[v] = parent_of_v;
    for(int i=0;i<adj[v].size();i++){
            if(!visited[adj[v][i]]) 
            {
                if(dfs_util(adj,visited,parent,N,adj[v][i],v)) 
                    return true;  // v is parent of all next explored nodes

            }
            else if(parent_of_v!=adj[v][i])
            {
                vector<int> path;
                path.push_back(adj[v][i]);
                path.push_back(v);
                int parent_on_path=parent[v];
                while(parent_on_path!=adj[v][i]){
                    path.push_back(parent_on_path);
                    parent_on_path = parent[parent_on_path];
                }
                for(int j = 0;j < path.size();j++){
                    cout<<path[j]<<" "; 
                }
                cout<<adj[v][i]<<endl;
                return true;
            }
        }
    return false;
}


void dfs(vector<vector<int> > &adj,int N){

    vector<bool> visited(N+1,false);
    vector<int> parent(N+1,-1);

    for(int i=1;i<=N;i++)
    {
        if(!visited[i])
        {
            bool ans = dfs_util(adj,visited,parent,N,i,-1);
            if(ans)
            {
                cout<<"Cycle"<<endl;
                return;
            }         
        }
    }
    cout<<"No Cycle"<<endl;
    return;

}

int main()
{
    int N,M,u,v;
    
    //stack<int> dfs_stack;
    cin>>N>>M;
    vector<vector<int> > adj(N+1);
       
    for(int i=0;i<M;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);        
    }

    dfs(adj,N);
    return 0;
}