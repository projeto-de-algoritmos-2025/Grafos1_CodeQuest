#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 class Solution {
    private:
        TreeNode* construtorArvore(const std::string& travessia, int& indiceSTR, int profundidadeEsperada){
            // caso base, fim da string
            if (indiceSTR >= travessia.length()) {
                return nullptr;
            }
    
            int posicaoOriginal = indiceSTR;
            int profundidadeAtual = 0;
    
            // conta os traços para achar a profundidade atual
            while(indiceSTR < travessia.length() && travessia[indiceSTR] == '-'){
                profundidadeAtual++;
                indiceSTR++;
            }
    
            // checa se o nó encontrado é filho direto do nó que chamou a função ou se pertence a um nível acima
            if (profundidadeAtual != profundidadeEsperada){
                indiceSTR = posicaoOriginal;
                return nullptr;
            }
    
            // nó encontrado é de fato o nó que precisamos nesse nível
            std::string valSTR = "";
            while (indiceSTR < travessia.length() && std::isdigit(travessia[indiceSTR])){
                valSTR += travessia[indiceSTR];
                indiceSTR++;
            }
    
    
            int valorAtual = std::stoi(valSTR);
    
            TreeNode* node = new TreeNode(valorAtual);
    
    
            node->left = construtorArvore(travessia, indiceSTR, profundidadeEsperada + 1);
            node->right = construtorArvore(travessia, indiceSTR, profundidadeEsperada + 1);
    
            return node;
    
        }
    
    
    public:
        TreeNode* recoverFromPreorder(std::string traversal) {
            int indexSTR = 0;
            return construtorArvore(traversal, indexSTR, 0);
        }
    };


////////////////////////////////////////////////////////////////////////////////
// para testes durante o desenvolvimento e posteriormente na avaliação por pares:
////////////////////////////////////////////////////////////////////////////////

void printPreOrder(TreeNode* node){
    if (!node){
        return;
    }

    std::cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

int main() {
    Solution sol;
    std::string teste = "1-2--3--4-5--6--7";
    TreeNode* raiz = sol.recoverFromPreorder(teste);
    printPreOrder(raiz);
}

////////////////////////////////////////////////////////////////////////////////