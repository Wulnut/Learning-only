class Animal():
    def getInfo(self):
        return "I am an animal"

class Lion(Animal):
    def getInfo(self):
        return "I am a lion"

class Tiger(Animal):
    def getInfo(self):
        return "I am a Tiger"

if __name__ == '__main__':
    objectList = [item() for item in (Animal, Lion, Tiger)]
    for object in objectList:
        print(object.getInfo())