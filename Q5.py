def construct_D_arr(L1, L2):
    D = [[100 for i in range(len(L1) + 1)] for j in range(len(L2)+1)]
    for i in range(len(D)):
        D[0][i] = i
    for j in range(len(D)):
        D[i][0] = j
    '''
    subproblem relation:
    D[i][j] = min{1+D[i-1][j], 1+D[i][j-1], 2+D[i-1][j-1]}
    '''
    for a in range(1, len(D)):
        for b in range(1, len(D[0])):
            D[a][b] = min(1+D[a-1][b], 1+D[a][b-1], 2+D[a-1][b-1])
    return D
#print (construct_D_arr([1, 2], [1, 3]))        
def min_dist(L1, L2):
    if len(L2) == len(L1):
        diff = 0
        for i in range(len(L1)):
            if L1[i] != L2[i]:
                diff += 1
        return diff
    elif len(L2) > len(L1):
        transformations_1 = 0
        transformations_2 = 0
        temp_L2 = L2[:len(L1)]
        for k in range(len(L1)):
            if L1[k] != temp_L2[k]:
                transformations_1 += 1
        len_diff = len(L2) - len(L1)
        temp2_L2 = L2[len_diff:]
        for i in range(len(L1)):
            if L1[i] != temp2_L2[i]:
                transformations_2 +=1
        return min(transformations_2 + len(L2) - len(L1), transformations_1 + len(L2) - len(L1))
    elif len(L1) > len(L2):
        transformations_1 = 0
        transformations_2 = 0
        temp_L1 = L1[:len(L2)]
        for k in range(len(L2)):
            if L2[k] != temp_L1[k]:
                transformations_1 += 1
        len_diff = len(L1) - len(L2)
        temp2_L1 = L1[len_diff:]
        for i in range(len(L2)):
            if L2[i] != temp2_L1[i]:
                transformations_2 +=1
        return min(transformations_2 + len(L1)-len(L2), transformations_1 + len(L1) - len(L2))
#print (min_dist([1, 1, 2, 3], [2, 2, 3]))       
def recover_path(L1, L2):
    None