from collections import defaultdict

class Solution:
    def sumOfDistancesInTree(self, n, arestas):
        grafo = defaultdict(list)
        for a, b in arestas:
            grafo[a].append(b)
            grafo[b].append(a)

        resposta = [0] * n
        tamanho_subarvore = [1] * n  # Cada nó começa contando só ele mesmo na sua contagem

        # Primeiro DFS: de baixo para cima
        def dfs1(no, pai):
            for vizinho in grafo[no]:
                if vizinho == pai:
                    continue
                dfs1(vizinho, no)
                tamanho_subarvore[no] += tamanho_subarvore[vizinho]
                resposta[no] += resposta[vizinho] + tamanho_subarvore[vizinho]

        # Segundo DFS: de cima para baixo
        def dfs2(no, pai):
            for vizinho in grafo[no]:
                if vizinho == pai:
                    continue
                resposta[vizinho] = resposta[no] - tamanho_subarvore[vizinho] + (n - tamanho_subarvore[vizinho])
                dfs2(vizinho, no)

        # Executa as duas passagens DFS
        dfs1(0, -1)
        dfs2(0, -1)

        return resposta
