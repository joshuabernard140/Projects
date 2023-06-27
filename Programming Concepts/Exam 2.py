# Joshua Bernard - U92651625
# This program will solve for the selected shape and how many numbers there are based on the given order number.
# It will repeat until told to stop by the user.

# Handles the options menu
def display_menu():
    print('Welcome to the Centered Polygonal Number program!')
    print('Here are your choices:')
    print('1. Centered Triangular Number')
    print('2. Centered Pentagonal Number')
    print('3. Centered Heptagonal Number')
    print('4. Centered Hendecagonal Number')


# Handles the centered triangular number
def triangular(num):
    ret = ((3* num**2) + (3*num) + 2)/2
    return int(ret)


# Handles the centered pentagonal number
def pentagonal(num):
    ret = ((5* num**2) + (5*num) + 2)/2
    return int(ret)


# Handles the centered heptagonal number
def heptagonal(num):
    ret = ((7* num**2) + (7*num) + 2)/2
    return int(ret)


# Handles the centered hendecagonal number
def hendecagonal(num):
    ret = ((11* num**2) + (11*num) + 2)/2
    return int(ret)


quit = False
while not quit: # while loop that keeps looping until user wants to stop the program
    display_menu()
    choice = int(input('Enter your choice (1-4): ')) # chooses which shape
    while choice < 1 or choice > 4: # makes sure number is between 1 and 4
        choice = int(input('Invalid entry. Re-enter your choice (1-4): '))
    order = int(input('Enter an order number (>= 1): '))
    while order <= 1: # number must be great or equal to 1
        order = int(input('Invalid entry. Re-enter your order number (>= 1): '))
    if choice == 1: # triangular
        print('The number in position {} of the triangular series is: {}'.format(order, triangular(order)))
    elif choice == 2: # pentagonal
        print('The number in position {} of the pentagonal series is: {}'.format(order, pentagonal(order)))
    elif choice == 3: # heptagonal
        print('The number in position {} of the heptagonal series is: {}'.format(order, heptagonal(order)))
    else: # hendecagonal
        print('The number in position {} of the hendecagonal series is: {}'.format(order, hendecagonal(order)))
    replay = input('Would you like to run the program again? Enter yes or no: ') # asks if user wants to use again
    replay = str.lower(replay)
    if replay == 'yes': # replays program
        continue
    else: # ends program
        quit = True
        print('Thanks for using the program! Goodbye!')


