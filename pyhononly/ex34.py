
key = input("请输入加密密匙：")
enc = input("请输入要加密的字符: ")

dec = ord(key) ^ ord(enc)
print("加密结果:",chr(dec))

enc = ord(key) ^ dec
print("解密结果:",chr(enc))


#ord()函数主要是将传入的参数转换成ASCII码
#chr()函数主要是将传入的ASCII转换成其对应的字符，同样也可以使用十进制和十六进制
"""
help(pow)
"""
#help()函数可以快速查询内置函数的使用方法

"""
a = 20
print("a是整型么？", isinstance(a, int))
"""