def targetSumPair(arr, targetSum):
    pairs=[]
    p1 = 0
    p2 = len(arr)-1
    while p1< p2:
        currentSum = arr[p1]+arr[p2]
        if currentSum == targetSum:
            pairs.append(arr[p1])
            pairs.append(arr[p2])
            p1+=1
            p2-=1
        elif currentSum >targetSum:
            p2-=1
        else: p1+=1
    return pairs

a2 = [0,1,2,4,5,9,11]
a1 = targetSumPair(a2, 11)
print("[", end="")
for i in a1:
    print(i, end=" ")
print("]")