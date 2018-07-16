#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
    //write your code here
    int s = 0;
    queue<int> q;
    vector<int> dist(adj.size(),(int)999999);
    vector<bool> visited(adj.size(),false);
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int n = q.front(); q.pop();
        for (int i = 0; i < adj[n].size(); ++i) {
            int m = adj[n][i];
            //check if edge is allowed
            if(visited[m] == true){
                int diff = dist[m] - dist[n];
                if( diff % 2 == 0){
                    return 0;
                }
                continue;
            }
            //explore
            visited[m] = true;
            q.push(m);
            dist[m] = dist[n] + 1;
        }
    }
    return 1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    std::cout << bipartite(adj);
}
