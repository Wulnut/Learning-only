the_count = [1, 2, 3, 4, 5]
fruits =['apple', 'banana', 'pears', 'apricots']
change = [1, 'pennies', 2, 'dimes', 3, 'quarters']

for number in the_count:
    print(f"This is count {number}")

#print(f"{number}") init a var-number number:5

for fruit in fruits:
    print(f"This is fruit {fruit}")

for i in change:
    print(f"I got {i}")

elements = []
#range(,)range function to do 0 to 5 counts
#range(,) first var is start second is all numbers
for i in range(0,6):
    print(f"Adding {i} to the list")
    elements.append(i)
#append() is a function that lists enter in;

for i in elements:
    print(f"Element was: {i}")

list2d = [[1,2,3],[4,5]]
sum = 0
for i in list2d:
    for j in i:
        print(f"j:{j}")