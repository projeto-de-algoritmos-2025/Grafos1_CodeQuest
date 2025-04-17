from collections import deque

class Solution:
    def shortestPathLength(self, graph):
        quantidade_nos = len(graph)
        objetivo = (1 << quantidade_nos) - 1
        visitados = set()
        fila = deque()

        # Começa a BFS a partir de todos os nós
        for no_inicial in range(quantidade_nos):
            mascara_inicial = 1 << no_inicial  # Só o nó atual está marcado como visitado
            fila.append((no_inicial, mascara_inicial, 0))  # (nó atual, máscara de visitados, passos)
            visitados.add((no_inicial, mascara_inicial))

        # Busca em largura
        while fila:
            no_atual, mascara_visitados, passos = fila.popleft()

            # Se já visitou todos os nós, retorna o número de passos
            if mascara_visitados == objetivo:
                return passos

            # Para cada vizinho do nó atual
            for vizinho in graph[no_atual]:
                nova_mascara = mascara_visitados | (1 << vizinho)  # Marca o vizinho como visitado

                if (vizinho, nova_mascara) not in visitados:
                    visitados.add((vizinho, nova_mascara))
                    fila.append((vizinho, nova_mascara, passos + 1))

        return -1
