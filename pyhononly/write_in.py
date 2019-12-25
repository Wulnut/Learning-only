from sys import argv

#script, first, second = argv
# script表示文件名后面 first second只有两个值可以出入
#print("The script is called:", script)
#print("Your first variable is:", first)
#print("Your second variable is:", second)

#filename = argv
#print("Filename:", filename)

script, filename = argv

print("We`re going to erase {filename}.")
print("If you don`t want that, hit CTRL-C (^C).")
print("If you do want that, hit RETURN.")

input("?")

print("Open the file...")
target = open(filename, 'w')

print("Truncation the file. Goodbye!")
target.truncate()

print("Now I`m going to ask you for three lines.")
line1 = input("line 1:")
line2 = input("line 2:")
line3 = input("line 3:")

print("I`m going to write these to the file.")

target.write(line1)
target.write("\n")
target.write(line2)
target.write("\n")
target.write(line3)
target.write("\n")

print("And finally, we close it.")
target.close()