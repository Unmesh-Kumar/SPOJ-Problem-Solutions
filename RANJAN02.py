arr=[0]*40
for i in range(1,37):
    arr[i]=3*arr[i-1]+2

for _ in range(int(input())):
    print(arr[int(input())])
