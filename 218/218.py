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

        alturas = [] # Guarda as altura utilizadas
        alturas.append(0)

        # Loop para comparar as alturas
        i = 0
        while i in range(len(mudancaAltura)):
            xAtual = mudancaAltura[i][0]

            # Caso os edificio tenham as mesmas coordenadas x
            while i < len(mudancaAltura) and mudancaAltura[i][0] == xAtual:
                x, y, f = mudancaAltura[i]

                if f == 0:
                    alturas.append(y)
                    alturas.sort()
                else:
                    alturas.remove(y)
                    alturas.sort()

                i += 1

            # Verificando se a altura modificou
            if not skyline or skyline[-1][1] != alturas[-1]:
                skyline.append((xAtual, alturas[-1]))

        return skyline
