#include <deque>
#include <utility>
#include <limits>
#include <vector>

using celula = std::pair<int,int>;
class Solution {
public:
    int minimumObstacles(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int INF = std::numeric_limits<int>::max();
        // vetor de distancias, de tamanho m (vetor externo), tamanho interno m e valor interno "infinito"  
        std::vector<std::vector<int>> dist (m, std::vector<int>(n, INF));

        dist[0][0] = 0;

        std::deque<celula> dq;

        dq.push_front({0, 0});


        // sistema de navegação na matriz m x n
        int dirLinha[] = {-1, 1, 0, 0};
        int dirColuna[] = {0, 0, -1, 1};

        while(!dq.empty()) {
            celula atual = dq.front();
            dq.pop_front();

            int linhaCel = atual.first;
            int colunaCel = atual.second;
            
            // retorna a distancia minima caso o valor atual a ser processado já seja o da ultima posicao
            if (linhaCel == m-1 && colunaCel == n-1){
                return dist[linhaCel][colunaCel];
            }


            // iteração nas 4 direções possiveis
            for(int i = 0; i < 4; i++) {
                int proxLinha = linhaCel + dirLinha[i];
                int proxColuna = colunaCel + dirColuna[i];

                // checa se os vizinhos estão dentro do grid
                if(proxLinha >= 0 && proxLinha < m && proxColuna >= 0 && proxColuna < n) {
                    int custoAresta = grid[proxLinha][proxColuna];
                    int novoCusto = dist[linhaCel][colunaCel] + custoAresta;

                    // se um caminho mais curto para o vizinho for encontrado
                    if (novoCusto < dist[proxLinha][proxColuna]) {
                        dist[proxLinha][proxColuna] = novoCusto;

                        if(custoAresta == 0){
                            dq.push_front({proxLinha, proxColuna});
                        } else {
                            dq.push_back({proxLinha, proxColuna});
                        }
                    }
                }
            }

        }

        int custoFinal = dist[m-1][n-1];
        return custoFinal;
        
    }
};