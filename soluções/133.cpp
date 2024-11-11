class Solution {
public:
    Node* clonarGraph(Node* node) {
        if (node == nullptr) return nullptr;

        // Mapa para armazenar os nós clonados
        unordered_map<Node*, Node*> clonedNodes;

        // Pilha para a travessia iterativa (DFS)
        stack<Node*> toVisit;
        toVisit.push(node);

        // Clona o nó inicial e armazena no mapa
        clonedNodes[node] = new Node(node->val);

        // Executa DFS usando a pilha
        while (!toVisit.empty()) {
            Node* current = toVisit.top();
            toVisit.pop();

            // Processa cada vizinho do nó atual
            for (Node* neighbor : current->neighbors) {
                // Se o vizinho ainda não foi clonado
                if (clonedNodes.find(neighbor) == clonedNodes.end()) {
                    // Cria o clone do vizinho e armazena no mapa
                    clonedNodes[neighbor] = new Node(neighbor->val);
                    toVisit.push(neighbor); // Adiciona o vizinho na pilha para processá-lo depois
                }
                // Adiciona o vizinho clonado à lista de vizinhos do nó clonado atual
                clonedNodes[current]->neighbors.push_back(clonedNodes[neighbor]);
            }
        }

        // Retorna o clone do nó inicial
        return clonedNodes[node];
    }
};