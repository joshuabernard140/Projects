# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program will take a given string and convert it into Morse code.

# tuple includes all required Morse code characters, consisting of 40 total characters
morseCode = (' ', '--..--', '.-.-.-', '..--..', '-----', # space, comma, period, question mark, 0
             '.----', '..---', '...--', '....-', '.....', # 1, 2, 3, 4, 5
             '-....', '--....', '---..', '----.', # 6, 7, 8, 9 (given morse code for 7 is incorrect but we left it)
             '.-', '-...', '-.-.', '-..', '.', # a, b, c, d, e
             '..-.', '--.', '. ...', '. .', '.---', # f, g, h, i, j (given morse code for i and h are also incorrect)
             '-.-', '.-..', '--', '-.', '---', # k, l, m, n, o
             '.---.', '--.-', '.-.', '...', '-', # p, q, r, s, t
             '..-', '...-', '.--', '-..-', '-.--', '--..') # u, v, w, x, y, z

# requests a string that will be converted to Morse code
userInput = input('Enter the string to be converted to Morse code:')

# takes the inputted string and makes all letter upper case
userInput = str.upper(userInput)

# variable that will hold the converted string in Morse code
inputInMorse = ''

# takes each letter and converts it into Morse code
for ch in userInput:
    if ch == ' ':
        inputInMorse += morseCode[0]
    elif ch == ',':
        inputInMorse += morseCode[1]
    elif ch == '.':
        inputInMorse += morseCode[2]
    elif ch == '?':
        inputInMorse += morseCode[3]
    elif ch == '0':
        inputInMorse += morseCode[4]
    elif ch == '1':
        inputInMorse += morseCode[5]
    elif ch == '2':
        inputInMorse += morseCode[6]
    elif ch == '3':
        inputInMorse += morseCode[7]
    elif ch == '4':
        inputInMorse += morseCode[8]
    elif ch == '5':
        inputInMorse += morseCode[9]
    elif ch == '6':
        inputInMorse += morseCode[10]
    elif ch == '7':
        inputInMorse += morseCode[11]
    elif ch == '8':
        inputInMorse += morseCode[12]
    elif ch == '9':
        inputInMorse += morseCode[13]
    elif ch == 'A':
        inputInMorse += morseCode[14]
    elif ch == 'B':
        inputInMorse += morseCode[15]
    elif ch == 'C':
        inputInMorse += morseCode[16]
    elif ch == 'D':
        inputInMorse += morseCode[17]
    elif ch == 'E':
        inputInMorse += morseCode[18]
    elif ch == 'F':
        inputInMorse += morseCode[19]
    elif ch == 'G':
        inputInMorse += morseCode[20]
    elif ch == 'H':
        inputInMorse += morseCode[21]
    elif ch == 'I':
        inputInMorse += morseCode[22]
    elif ch == 'J':
        inputInMorse += morseCode[23]
    elif ch == 'K':
        inputInMorse += morseCode[24]
    elif ch == 'L':
        inputInMorse += morseCode[25]
    elif ch == 'M':
        inputInMorse += morseCode[26]
    elif ch == 'N':
        inputInMorse += morseCode[27]
    elif ch == 'O':
        inputInMorse += morseCode[28]
    elif ch == 'P':
        inputInMorse += morseCode[29]
    elif ch == 'Q':
        inputInMorse += morseCode[30]
    elif ch == 'R':
        inputInMorse += morseCode[31]
    elif ch == 'S':
        inputInMorse += morseCode[32]
    elif ch == 'T':
        inputInMorse += morseCode[33]
    elif ch == 'U':
        inputInMorse += morseCode[34]
    elif ch == 'V':
        inputInMorse += morseCode[35]
    elif ch == 'W':
        inputInMorse += morseCode[36]
    elif ch == 'X':
        inputInMorse += morseCode[37]
    elif ch == 'Y':
        inputInMorse += morseCode[38]
    else:
        inputInMorse += morseCode[39]

# prints given string in Morse code
print(inputInMorse)