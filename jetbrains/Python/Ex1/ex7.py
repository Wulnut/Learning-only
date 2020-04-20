import abc
## abc == abstract base class

class People(metaclass = abc.ABCMeta):

    @abc.abstractmethod
    def working(self):
        pass


class Chinese(People):

    def working(self):

        print("中国")

c = Chinese()
c.working()