

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 indica que o nó não foi visitado ainda
        
        for (int i = 0; i < n; i++) {
            // Se o nó ainda não foi visitado, começamos uma BFS a partir dele
            if (color[i] == -1) {
                if (!bfs(graph, color, i)) {
                    return false; // Se a BFS retornar falso, o grafo não é bipartido
                }
            }
        }
        
        return true; // Se todas as componentes foram visitados corretamente
    }

    bool bfs(const vector<vector<int>>& graph, vector<int>& color, int start) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Para cada vizinho do nó atual
            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) { //se nao foi visitado
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    // Se o vizinho já foi visitado 
                    return false;
                }
            }
        }
        
        return true; // A BFS terminou sem encontrar conflitos de cores é biprtido
    }
};

