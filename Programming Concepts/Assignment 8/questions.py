# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program will create a class for the questions. This will be used later.

class question:
    def __init__(self,question,answer1,answer2,answer3,answer4,correct):
        self.__question = question # question that will be asked
        self.__answer1 = answer1 # answer choices
        self.__answer2 = answer2
        self.__answer3 = answer3
        self.__answer4 = answer4
        self.correct = correct # correct answer


    # prints later in the main function
    def __str__(self):
        print(self.__question)
        print('1.',self.__answer1)
        print('2.',self.__answer2)
        print('3.',self.__answer3)
        print('4.',self.__answer4)
        return ' '