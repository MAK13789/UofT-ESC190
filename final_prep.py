def change(coins, amount):
    M = [0] * (amount + 1)
    for i in range(1, amount + 1):
        minimum = 99999
        for j in range(len(coins)):
            if i >= coins[j]:
                minimum = min(minimum, 1 + M[i-coins[j]])
        M[i] = minimum
    return M[amount]
coins = [1, 5, 10, 25, 100, 200]
amount = 154
print(change(coins, amount))
#other dynamic programming stuff:
'''
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
'''
def climbStairs(n):
    arr = [0 for i in range(n+1)]
    arr[0] = 0
    arr[1] = 1
    if (len(arr) > 2):
        arr[2] = 2
    for j in range(3, n+1):
        arr[j] = arr[j-2] + arr[j-1]
    return arr[n]
'''
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
'''
def minCostClimbingStairs(cost):
    arr = [0] * len(cost)
    arr[0] = cost[0]
    arr[1] = cost[1]
    for i in range(2, len(cost)):
        arr[i] = min(arr[i-1], arr[i-2]) + cost[i]
    return min(arr[len(cost)-2], arr[len(cost)-1])        
'''
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
'''
def tribonacci(n):
    if (n == 0):
        return 0
    elif (n <= 2):
        return 1
    arr = [0] * (n+1)
    arr[0] = 0
    arr[1] = 1
    arr[2] = 1
    for j in range(3, n+1):
        arr[j] = arr[j-3] + arr[j-2] + arr[j-1]
    return arr[n]