lis1 = []
for i in range(5):
    temp = int(input("enter the elements of list"))
    lis1.append(temp)

set1 = set(lis1)
lis2 = list(set1)

print("original list : ",lis1)
print("duplicates removed ",lis2)

#even list
even_list = [x for x in range(10) if x%2 == 0]
print("even numbers list ",even_list)

even_list.reverse()
print("revrsed even list is : ",even_list)