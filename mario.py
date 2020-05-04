rows = int(input("Height: "))
# Check valid or invalid value
while True:
    #rows = int(input("Height: "))
    if rows >= 0 and rows < 24:
        break

rows = rows + 1
for row in range(1, rows):
    num = 1
    for j in range(rows, 0, -1):
        if j > row:
            print(" ", end=' ')
        else:
            print("#", end=' ')
            num += 1
    print("")


