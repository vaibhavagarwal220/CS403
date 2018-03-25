#include <bits/stdc++.h>
using namespace std;

/*Input

5 5
1 3
2 3
1 2
3 5
4 5
1 4

Ans - 3 

5 3
1 3
1 2
4 5
1 4

Ans - 0

*/

int main()
{
    int N,M,u,v,start,dest,vert;
    bool visited[3501];
    int min_dist[3501];
    queue<int> bfs_queue;
    cin>>N>>M;
    vector<vector<int> > buildings(N+1);

    for(int i=1;i<=3500;i++){
        visited[i]=false;
    }

    for(int i=0;i<M;i++){
        cin>>u>>v;
        buildings[u].push_back(v);
        buildings[v].push_back(u);        
    }
    cin>>start>>dest;
    
    bfs_queue.push(start);
    visited[start] = true;
    min_dist[start] = 0;
    while(!bfs_queue.empty()){
        vert = bfs_queue.front();
        bfs_queue.pop();
        for(int i=0;i<buildings[vert].size();i++){
            if(visited[buildings[vert][i]]==false) 
            {
                bfs_queue.push(buildings[vert][i]);
                visited[buildings[vert][i]] = true;
                min_dist[buildings[vert][i]] = min_dist[vert]+1;
                if(buildings[vert][i]==dest) {
                    cout<<min_dist[buildings[vert][i]]<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<0<<endl;

    return 0;
}