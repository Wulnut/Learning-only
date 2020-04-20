# list = [1, 2, 3, 3, 2, 4]
#
# # 通过遍历，这种写法可以排除相同的数值
# arr = {item for item in list}
#
# print(arr)


# #推导式 创建字典
# dir = {i: i % 3 == 0 for i in range(1, 11)}
#
# print(dir)
#
# clist = ["运动", "饮食", "营养"]
# elist = ["motion", "diet", "nutrition"]
#
# dir1 = {clist[i]:elist[i] for i in range(len(elist))}
#
# print(dir1)

#推导式 创建元组

questionList = ['name', 'profession', 'favorites']
answerList = ['Linda', 'programmer', 'music']

t = tuple(zip(questionList, answerList))

for i in t:
    print(t, end = ' ')