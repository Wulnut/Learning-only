from sys import argv
from os.path import exists
#可以使用exists

script, from_file, to_file = argv;

print(f"Copying from {from_file} to {to_file}")

in_file = open(from_file)
indata = in_file.read()
#indata不需要数据类型

print(f"The input file is {len(indata)} bytes long")

print(f"Dose the output file exist? {exists(to_file)}")
#判断文件路径是否存在
print(f"Ready, hit RETURN to continue, CTRL ^C to abort. ")

input()

out_file = open(to_file, 'w')
out_file.write(indata)

print("Alright, all done! ")

out_file.close()
in_file.close()