
#include <bits/stdc++.h>
using namespace std;

pair<vector<int>,bool> bfs(vector<vector<int> > Graph,int st,int tt,int del){

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
            if(Graph[i][j]!=0 && visited[j]!=true && Graph[i][j]>=del) 
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
    int delta=INT_MIN;
    vector<vector<int> > residual_graph = Graph;


    for(int j=1;j<Graph.size();j++){
        if(Graph[s][j]>delta) 
        {
            delta = Graph[s][j];
        }
    }

    delta = (int)pow(2,(int)log2(delta));
    


    // for(int i=1;i<Graph.size();i++){
    //     for(int j=1;j<Graph.size();j++){
    //         cout<<residual_graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(delta>=1){
        while(bfs(residual_graph,s,t,delta).second){
            
            pair<vector<int>,bool> res = bfs(residual_graph,s,t,delta);
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
        delta=delta/2;
    }

    int disj_paths=0;
    for(int j=1;j<residual_graph.size();j++){
        disj_paths = residual_graph[j][s]+disj_paths;
    }
    cout<<"The max number of edge disjoint paths is "<<disj_paths<<endl;

    return max_flow;
}
 
int main()
{
    int V,E,s,t,u,v;
    cin>>V>>E;
    vector<vector<int> > Graph(V+1,vector<int>(V+1,0));

    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            Graph[i][j]=0;
        }
    }

    for(int i=1;i<=E;i++){
        cin>>u>>v;
        Graph[u][v]=1;
        
    }
    cin>>s>>t;
    cout<<s<<" "<<t<<endl;
    max_flow(Graph,s,t);

    return 0;
}