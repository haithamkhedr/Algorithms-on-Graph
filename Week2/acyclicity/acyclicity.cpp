#include <iostream>
#include <vector>

using std::vector;
using std::pair;


template class std::vector<std::vector<int>>;
template class std::vector<bool>;
bool dfs(int n, const vector<vector<int> > &adj,vector<bool> &visited,vector<bool> &recurStack){
    
    if(visited[n] == false){
        visited[n] = true;
        recurStack[n] = true;
        for (int i=0; i < adj[n].size(); ++i) {
            if(recurStack[adj[n][i]] == true){
                return true;
            }
            else if(!visited[adj[n][i]]){
                if(dfs(adj[n][i],adj,visited,recurStack))
                    return true;
            }
        }
        recurStack[n] = false;

    }
    return false;
}

int acyclic(vector<vector<int> > &adj) {
    //write your code here
    vector<bool> visited(adj.size(),false);
    for (int i = 0; i < adj.size(); ++i) {
        vector<bool> recurStack(adj.size(),false);
        if(dfs(i,adj,visited,recurStack)){
            return true;
        }
    }
    return false;

}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    std::cout << acyclic(adj);
}
