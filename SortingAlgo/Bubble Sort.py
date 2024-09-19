for i in range(11):
    for j in range(11-i-1):
        if (arr[j] > arr[j+1]):
            temp = arr[j]
            arr[j] = arr[j+1]
            arr[j+1] = temp
