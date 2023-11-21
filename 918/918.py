class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:

        soma = 0
        auxMax = 0
        auxMin = 0

        maximoGlobal = nums[0]
        minimoGlobal = nums[0]

        for numero in nums:
            auxMax = max(auxMax + numero, numero)
            auxMin = min(auxMin + numero, numero)

            maximoGlobal = max(maximoGlobal, auxMax)
            minimoGlobal = min(minimoGlobal, auxMin)

            soma += numero

        if maximoGlobal > 0:
            return max(maximoGlobal, soma - minimoGlobal)
        else:
            return maximoGlobal
