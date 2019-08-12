with open("input.txt", "r") as f, open("output.txt", "w") as q:
    odd = 0
    arr = f.read().split()
    for a in arr[1:]:
        if int(a) & 1:
            q.write(a + ' ')
            odd += 1
    q.write('\n')
    for a in arr[1:]:
        if not int(a) & 1:
            q.write(a + ' ')
    if 2 * odd > int(arr[0]):
        q.write("\nNO")
    else:
        q.write("\nYES")
