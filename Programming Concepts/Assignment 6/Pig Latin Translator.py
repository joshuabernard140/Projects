# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program will take a string and convert it into pig latin. It moves the first letter to the
# end and adds 'ay' to it. If string is 1 letter, it just adds 'ay'.


def main():
    # given text file named 'desiderata.txt'
    file = open(input('Input text file to be converted to pig latin: '), 'r') # opens the file that will be translated to pig latin
    newFileName = input('Input new file name (txt file is preferred): ') # name of file for translation to be written on
    contents = file.read() # reads the file
    contents = contents.split(' ') # seperates all the words
    pig_latin = ''
    for x in contents:
        if len(x) == 1: # just adds 'ay' if only 1 letter
            x = x + 'ay'
        else: # moves first letter to the end and adds 'ay'
            x = x[1:] + x[0] + 'ay'
        pig_latin += ' ' + x
    newFile = open(newFileName, 'w') # creates new file
    newFile.write(pig_latin) # writes translation to new file
    newFile.close()


# runs program
main()

