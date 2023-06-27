# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program will takes 2 given items' details and returns it with a nice format.

# class for the items
class retail_item():
    def __init__(self,t1,a1,p1,t2,a2,p2):
        self.__type1 = t1
        self.__amount1 = a1
        self.__price1 = p1
        self.__type2 = t2
        self.__amount2 = a2
        self.__price2 = p2

    # formats the print to look nice
    def __str__(self):
        print('Here is a summary of the items you added:')
        print('Item               Amount           Price')
        print('-----------------------------------------')
        print('{}                   {}             {}   '.format(self.__type1,self.__amount1,self.__price1))
        print('{}                   {}             {}   '.format(self.__type2,self.__amount2,self.__price2))
        return ' '

# main function
def main():
    # information for item 1
    name1 = str(input('Name of item 1: '))
    amount1 = int(input('Amount of item 1: '))
    price1 = float(input('Price of item 1: '))

    # information for item 2
    name2 = str(input('Name of item 2: '))
    amount2 = int(input('Amount of item 2: '))
    price2 = float(input('Price of item 2: '))

    # creates the items' object
    retail = retail_item(name1,amount1,price1,name2,amount2,price2)

    # prints out the __str__
    print(retail)

# runs the program
main()