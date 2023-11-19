import heapq


class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        
        skyline = []
        
        mudancaAltura = []
        # Loop para guardar quando comeca uma mudanca de altura
        # 0 = inicio mudanca
        # 1 = fim da mudanca
        for left, rigth, height in buildings:
            mudancaAltura.append((left, height, 0))     
            mudancaAltura.append((rigth, height, 1))
        mudancaAltura.sort()

        maxHeap = [] # Guarda as altura utilizadas
        heapq.heappush((maxHeap, 0))

        # Loop para comparar as alturas
        for i in range(len(mudancaAltura)):
            auxAltura = mudancaAltura[i][0]

            # Caso os edificio tenham mesma coordenadas iniciais
            while j < len(mudancaAltura) and mudancaAltura[j][0] == auxAltura:
                x, y, f = mudancaAltura[i]

                if f == 0:
                    heapq.heappush((maxHeap, y))
                else:
                    heapq.heappop(maxHeap)

                j += 1

            # Verificando se a altura modificou
            if not skyline or skyline[-1][1] != mudancaAltura[-1]:
                skyline.append((auxAltura, mudancaAltura[-1]))

        return skyline

            