
#include <vector>
#include <unordered_map>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};





class Solution {
    // mapa para ter a correspondencia entre os nós originais e seus clones
    // chave: ponteiro para o nó original
    // valor: ponteiro para o nó clonado
    std::unordered_map<Node*, Node*> clonadoEvisitado;

    Node* clone_dfs(Node* node_original) {

        // caso base: nó original nulo
        if (!node_original) {
            return nullptr;
        }

        // caso base: nó visitado e clonado já está no map
        if (clonadoEvisitado.count(node_original)){
            return clonadoEvisitado[node_original];
        }

        Node* node_clone = new Node(node_original->val);

        clonadoEvisitado[node_original] = node_clone;

        for (Node* vizinho_original : node_original->neighbors){
            Node* vizinho_clonado = clone_dfs(vizinho_original);

            node_clone->neighbors.push_back(vizinho_clonado);
        }

        // retorna o clone do nó atual, com vizinhos também clonados e conectados.
        return node_clone;
    }

    public:
        Node* cloneGraph(Node* node) {
            return clone_dfs(node);
        }
};