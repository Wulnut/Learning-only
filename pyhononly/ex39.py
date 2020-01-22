def deco(func):
    def modify_text(str):
        return "<strong>" + func(str) + "</strong>"
    return modify_text

@deco
def textFunc(str):
    return str

print(textFunc("text"))