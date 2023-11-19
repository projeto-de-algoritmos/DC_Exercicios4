# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:            
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # Verificando se  lista esta vazia
        if not lists or len(lists) == 0:
            return None
          
        while len(lists) > 1:
            listaMergada = []

            for i in range(0, len(lists), 2):
                lista1 = lists[i]
                if (i+1) < len(lists):
                    lista2 = lists[i+1]

                listaMergada.append(self.merge(lista1, lista2))
            
            lists = listaMergada
    
        return lists[0]
    
    def merge(self, lista1, lista2):
        cabeca = ListNode()
        ultimo = cabeca

        while lista1 and lista2:
            if lista1.val < lista2.val:
                ultimo.next = lista1
                lista1 = lista1.next
            else:
                ultimo.next = lista2
                lista2 = lista2.next
            ultimo = ultimo.next

        if lista1:
            ultimo.next = lista1
        if lista2:
            ultimo.next = lista2

        return cabeca.next