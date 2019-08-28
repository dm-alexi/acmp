with open("input.txt", "r") as f, open("output.txt", "w") as q:
    arr = [int(x) for x in f.read().split()]
    a = [x for x in arr[1:] if x & 1]
    q.write(' '.join((str(x) for x in a)) + '\n' + ' '.join((str(x) for x in arr[1:] if not x & 1)) + '\n')
    q.write("NO" if 2 * len(a) > arr[0] else "YES")
