from sys import argv
script, filename = argv
#要注明文件后缀名
txt = open(filename)
#open()该函数表示打开文件函数，参数为文件名称
print(f"Here`s your file {filename}:")
print(txt.read())

print(f"Type the filename again:")
file_again = input("> ")

txt_again = open(file_again)

print(txt_again.read())
