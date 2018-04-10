
#include <bits/stdc++.h>
using namespace std;

pair<vector<int>,bool> bfs(vector<vector<int> > Graph,int st,int tt){

    queue<int> qq;
    qq.push(st);
    vector<bool> visited(Graph.size(),false);
    vector<int> parent(Graph.size(),-1);
    visited[st] = true;
    
    while(!qq.empty())
    {
        int i = qq.front();
        //cout<<i<<": ";
        qq.pop();
        for(int j=1;j<Graph.size();j++){
            if(Graph[i][j]!=0 && visited[j]!=true) 
            {
                qq.push(j);
                //cout<<j<<" ";
                visited[j] = true;
                parent[j] = i; 
            }
        }
        //cout<<endl;
    }
    if(visited[tt]==true) {return make_pair(parent,true);}
    return make_pair(parent,false);

} 

int max_flow(vector<vector<int> > Graph,int s,int t){
    int size = Graph.size();
    int max_flow = 0;
    vector<vector<int> > residual_graph = Graph;
    // for(int i=1;i<Graph.size();i++){
    //     for(int j=1;j<Graph.size();j++){
    //         cout<<residual_graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(bfs(residual_graph,s,t).second){
        
        pair<vector<int>,bool> res = bfs(residual_graph,s,t);
        vector<int> parent = res.first;
        int p_flow = INT_MAX;
        int u,v = t;
        while(v!=s) // find bottleneck
        {
            u=parent[v];
            p_flow = min(p_flow,residual_graph[u][v]);
            v=parent[v];

        }
        v = t;
        while(v!=s) 
        {
            u=parent[v];
            residual_graph[u][v] -= p_flow;
            residual_graph[v][u] += p_flow;
            v=parent[v];

        }
        max_flow += p_flow;
    }
    return max_flow;
}
 
int main()
{
    int V,s=1,t=6;
    cin>>V;
    vector<vector<int> > Graph(V+1,vector<int>(V+1,0));
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            cin>>Graph[i][j];
        }
    }
    cin>>s>>t;
    //cout<<s<<" "<<t<<endl;
    cout<<max_flow(Graph,s,t)<<endl;

    return 0;
}