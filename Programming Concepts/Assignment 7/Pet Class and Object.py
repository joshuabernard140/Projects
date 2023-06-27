# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program will take the given pet information and store it in the object.

# class for animal information
class Pet():
    # initial information
    def __init__(self,n='Not provided',t='Not provided',a=0):
        self.__name = n
        self.__type = t
        self.__age = a

    # sets information
    def setName(self,n):
        self.__name = n

    def setType(self,t):
        self.__type = t

    def setAge(self,a):
        self.__age = a

    # returns the information
    def getName(self):
        return self.__name

    def getType(self):
        return self.__type

    def getAge(self):
        return self.__age

# main function
def main():

    # creates an object of the pet class
    newPet = Pet()

    # prints defualt information
    print('A pet object has been created. Here is the initial information about the pet:')
    print('Name of pet: {}'.format(newPet.getName()))
    print('Type of pet: {}'.format(newPet.getType()))
    print('Age of pet: {}'.format(newPet.getAge()))

    # gets information from user
    n = str(input('Enter the pet\'s name: '))
    t = str(input('Enter the type of animal: '))
    a = int(input('Enter the pet\'s age: '))

    # sets new information
    newPet.setName(n)
    newPet.setType(t)
    newPet.setAge(a)

    # prints new information
    print('Here is the updated information about the pet:')
    print('Name of pet: {}'.format(newPet.getName()))
    print('Type of pet: {}'.format(newPet.getType()))
    print('Age of pet: {}'.format(newPet.getAge()))

# runs the program
main()