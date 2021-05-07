import math 
import random
def sigmoid(z):
    return 1/(1 + math.exp(-z))
#Part 1:
def net(x, w, b):
    hidden = []
    h_1 = sigmoid((w[0] * x[0]) + (w[1] * x[1]) + b[0])
    hidden.append(h_1)
    h_2 = sigmoid((w[2] * x[0]) + (w[3] * x[1]) + b[1])
    hidden.append(h_2)
    h_3 = sigmoid((h_1 * w[4]) + (h_2 * w[5]) + b[4])
    hidden.append(h_3)
    h_4 = sigmoid((h_1 * w[6]) + (h_2 * w[7]) + b[3])
    hidden.append(h_4)
    y = sigmoid((h_3 * w[8]) + (h_4 * w[9]) + b[4])
    return y
#Part 2:
def cost(x, y, w, b):
    pred_y = net(x, w, b)
    cost = (pred_y - y) ** 2
    return cost
#Part 3:
#Part 4:
weights = []
biases = []
for i in range(10):
    weights.append(random.uniform(-1, 1))
    if i < 5:
        biases.append(random.uniform(-1, 1))
#print (weights)
#print (biases)
total_cost_sum = 0
for j in range(10):
    x_1 = random.randint(1, 10)
    x_2 = random.randint(1, 10)
    x = [x_1, x_2]
    y = random.randint(1, 5)
    total_cost_sum += cost(x, y, weights, biases)
avg_cost = total_cost_sum / 10
print (avg_cost)
#Part 5:
