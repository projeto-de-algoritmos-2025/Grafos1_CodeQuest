from collections import deque

class Solution:
    def levelOrder(self, raiz):
        if not raiz:
            return []  # Caso a árvore esteja vazia

        resultado = []
        fila = deque([raiz])  # Iniciar a fila com o nó raiz

        while fila:
            nivel = []
            tamanho = len(fila)  # O número de elementos no nível atual

            for _ in range(tamanho):
                no_atual = fila.popleft()  # Remover o nó da frente da fila
                nivel.append(no_atual.val)  # Adicionar o valor do nó no nível

                # Se o nó atual tem filhos, adicionar à fila
                if no_atual.left:
                    fila.append(no_atual.left)
                if no_atual.right:
                    fila.append(no_atual.right)

            resultado.append(nivel)  # Adiciona o nível à lista de resultados

        return resultado
