import numpy as np
import random 
def cost(v, u1, u2, u3):
    cost = 0
    for i in range(len(u1)):
        cost += (v[i] - u1[i]) ** 2 + (v[i] - u2[i]) ** 2 + (v[i] - u3[i]) ** 2  
    return cost
def min_dist(u1, u2, u3):
    v = []
    for i in range(len(u1)):
        v.append(random.uniform(-1, 1))
    v = np.asarray(v, dtype='float64')
    epsilon = 0.01
    alpha = 0.001
    print (v)
    while cost(v, u1, u2, u3) > epsilon:
        v -= alpha * np.gradient(v)
        print (v)
        print ("\n")
        print (cost(v, u1, u2, u3))
        print ("\n")
        print ("\n")
        print ("\n")
        print ("\n")
        print ("\n")
    return v
#testing:
u1 = []
u2 = []
u3 = []
for i in range(5):
    u1.append(random.uniform(-5, 5))
    u2.append(random.uniform(-5, 5))
    u3.append(random.uniform(-5, 5))
v = [0] * 5
og_cost = cost(v, u1, u2, u3)
'''
print (og_cost)
v = min_dist(u1, u2, u3)
new_cost = cost(v, u1, u2, u3)
print (v)
print (new_cost)
'''