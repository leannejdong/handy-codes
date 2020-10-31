/*Time Complexity: O(|V|+|E|), where |V| is the number of vertices and |E| the number of edges
Space Complexity: O(|V|)*/

//PSEUDOCODE

// Calculate the number of connected components using DFS in an undirected graph

#include <iostream>
#include <vector>
#include <array>
#include <bitset>

constexpr int nMax = 100005;

// prefer not to use vector of raws
void dfs(int nod, std::bitset<nMax>& vis, std::array<std::vector<int>, nMax >& G)
// void dfs(int nod, std::bitset<nMax>& vis, std::vector<std::vector<int> > G)

{
    vis[nod]=1;
    for(auto i:G[nod])
        if(!vis[i])
            dfs(i, vis, G);  /// Recursive call for node's neighbour
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;

    std::array<std::vector<int>, nMax > G;
    while(m--)
    {
        int x, y;
        std::cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int connected = 0;
    std::bitset<nMax> vis;
    for(int i=1; i<=n; i++)
        if(!vis[i])
        {
            connected++;  /// Another connected component is detected 
            dfs(i, vis, G);
        }

    std::cout << connected;
    return 0;
}


/*Python

n = 6
m = 3
edges = [[1, 2], [1, 4], [3, 5]]

G = {}  # Represent the graph as an adjacency list (dictionary)
for i in range(1, n+1):
    G.update({i: []})

for i in range(len(edges)):
    G[edges[i][0]].append(edges[i][1])
    G[edges[i][1]].append(edges[i][0])

def dfs(node, G, vis):
    vis[node] = 1;
    for i in range(len(G[node])):
        if vis[G[node][i]]==0:
            dfs(G[node][i], G, vis)  # Recursive call for node's neighbour

connected = 0  # Solution / number of connected components
vis = []
for i in range(1, n+2):
    vis.append(0)

for i in range(1, n+1):
    if vis[i]==0:
        connected += 1
        dfs(i, G, vis)

print(connected)
*/
