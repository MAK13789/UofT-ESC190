def find_lowest(L, e):
    if e > L[len(L)-1] or e < L[0]:
        return -1
    if L[len(L)//2] < e:
        return len(L)//2 + find_lowest(L[len(L)//2:], e)   
    if L[len(L)//2] > e:
        return find_lowest(L[:len(L)//2], e)
    if L[len(L)//2] == e:
        if find_lowest(L[:len(L)//2], e) != -1:
            return find_lowest(L[:len(L)//2], e)
        else:
            return len(L)//2
    return -1
def find_highest(L, e):
    if e > L[len(L)-1] or e < L[0]:
        return -1
    if L[len(L)//2] < e:
        return len(L)//2 + find_highest(L[len(L)//2:], e)   
    if L[len(L)//2] > e:
        return find_highest(L[:len(L)//2], e)
    if L[len(L)//2] == e:
        if find_highest(L[len(L)//2 + 1:], e) != -1:
            return find_highest(L[len(L)//2 + 1:], e)
        else:
            return len(L)//2
    return -1    
temp = [1, 2, 2, 3, 3]
temp_1 = 2
print(find_lowest(temp, temp_1))
print(find_highest(temp, temp_1))
