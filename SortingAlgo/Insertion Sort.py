for i in range(1,n):
    curr = arr[i]
    j = i - 1;
    
    while(j > -1 and curr < arr[j]):
        arr[j+1] = arr[j]
        j -= 1
        
    arr[j+1] = curr
