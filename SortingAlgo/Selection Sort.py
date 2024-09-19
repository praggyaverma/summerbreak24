for i in range(n):
    mini = i
    for j in range(i+1,n):
        if (arr[j] < arr[mini]):
            mini = j
            
    if (mini != i):
        arr[mini], arr[i] = arr[i], arr[mini]
