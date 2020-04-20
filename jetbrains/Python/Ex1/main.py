import random

str = "0123456789abcdefghijklmnopqrstuvwxyz"

len = str.__len__()

code = ""

for i in range(4):

    for j in range(4):
        code = code + str[random.randint(0, len - 1)]

    # print(f'')是一种格式化输出
    print(f'当前验证次数{i + 1},当前验证码: {code}')
    codein = input("请输入验证码: ")

    if codein == code:
        print("验证成功!")
    else:
        print(f'验证失败，你还有有{3 - i}次机会')

    code = ""



# for i in range(4):
#     code = code + str[random.randint(0, len - 1)]
#
# print("当前验证码:", code)
#
# codein = input("请输入验证码： ")
#
# if codein == code :
#     print("验证成功")
# else:
#     print("验证失败")
