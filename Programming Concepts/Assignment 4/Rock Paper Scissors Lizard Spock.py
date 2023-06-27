# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program is a rock paper scissors spin off with 5 options. it will let the player choose any of the 5
# options and determine whether the player won or the computer won. If the player wants to play again, they
# select yes and play again. If the player is done playing, select no and it will let you know the details
# of the play session, including total games, player wins, computer wins, and ties.

# used for random generator functions used for the computer
import random

# lists used for possible choices for the game and replaying
options = ['rock', 'paper', 'scissors', 'lizard', 'spock']
replayOptions = ['yes', 'no']

# variable for the user's game choice
userInput = ()

# variables for the play session details
gamesPlayed = 0
playerWins = 0
computerWins = 0
gamesTied = 0

# creates a random game choice for the computer and compares it to the player's game choice
def randomOption():

    # accesses the variables from outside of the function
    global options
    global userInput
    global playerWins
    global computerWins
    global gamesTied

    # takes a random choice from the list options
    for computerOption in range(1):
        computerOption = random.choice(options)
    if userInput == 'rock': # possible outcomes if user chooses rock
        if computerOption == 'rock':
            print('Computer chose rock!')
            print("It's a draw!")
            gamesTied += 1 # tracks that the game was tied
        elif computerOption == 'paper':
            print('Computer chose paper!')
            print("Paper covers rock! Computer wins!")
            computerWins += 1 # tracks that the computer won
        elif computerOption == 'scissors':
            print('Computer chose scissors!')
            print('Rock crushes scissors! Player wins!')
            playerWins += 1 # tracks that the player won
        elif computerOption == 'lizard':
            print('Computer chose lizard!')
            print('Rock crushes lizard! Player wins!')
            playerWins += 1
        else:
            print('Computer chose spock!')
            print('Spock vaporizes rock! Computer wins!')
            computerWins += 1
    elif userInput == 'paper': # possible outcomes if user chooses paper
        if computerOption == 'rock':
            print('Computer chose rock!')
            print('Paper covers rock! Player wins!')
            playerWins += 1
        elif computerOption == 'paper':
            print('Computer chose paper!')
            print("It's a draw!")
            gamesTied += 1
        elif computerOption == 'scissors':
            print('Computer chose scissors!')
            print('Scissors cuts paper! Computer wins!')
            computerWins += 1
        elif computerOption == 'lizard':
            print('Computer chose lizard!')
            print('Lizard eats paper! Computer wins!')
            computerWins += 1
        else :
            print('Computer chose spock!')
            print('Paper disproves spock! Player wins!')
            playerWins += 1
    elif userInput == 'scissors': # possible outcomes if user chooses scissors
        if computerOption == 'rock':
            print('Computer chose rock!')
            print('Rock crushes scissors! Computer wins!')
            computerWins += 1
        elif computerOption == 'paper':
            print('Computer chose paper!')
            print('Scissors cuts paper! Player wins!')
            playerWins += 1
        elif computerOption == 'scissors':
            print('Computer chose scissors!')
            print("It's a draw!")
            gamesTied += 1
        elif computerOption == 'lizard':
            print('Computer chose lizard!')
            print('Scissors decapitates lizard! Player wins!')
            playerWins += 1
        else :
            print('Computer chose spock!')
            print('Spock smashes scissors! Computer wins!')
            computerWins += 1
    elif userInput == 'lizard': # possible outcomes if user chooses lizard
        if computerOption == 'rock':
            print('Computer chose rock!')
            print('Rock crushes lizard! Computer wins!')
            computerWins += 1
        elif computerOption == 'paper':
            print('Computer chose paper!')
            print('Lizard eats paper! Player wins!')
            playerWins += 1
        elif computerOption == 'scissors':
            print('Computer chose scissors!')
            print('Scissors decapitates lizard! Computer wins!')
            computerWins += 1
        elif computerOption == 'lizard':
            print('Computer chose lizard!')
            print("It's a draw!")
            gamesTied += 1
        else :
            print('Computer chose spock!')
            print('Lizard poisons spock! Player wins!')
            playerWins += 1
    else: # possible outcomes if user chooses spock
        if computerOption == 'rock':
            print('Computer chose rock!')
            print('Spock vaporizes rock! Player wins!')
            playerWins += 1
        elif computerOption == 'paper':
            print('Computer chose paper!')
            print('Paper disproves spock! Computer wins!')
            computerWins += 1
        elif computerOption == 'scissors':
            print('Computer chose scissors!')
            print('Spock smashes scissors! Player wins!')
            playerWins += 1
        elif computerOption == 'lizard':
            print('Computer chose lizard!')
            print('Lizard poisons spock! Computer wins!')
            computerWins += 1
        else :
            print('Computer chose spock!')
            print("It's a draw!")
            gamesTied += 1

# asks player if they want to play again
def replay():

    # accesses the variables from outside of the function
    global replayOptions
    global gamesPlayed
    global playerWins
    global gamesTied

    # requests from player if they want to play again
    replayAnswer = str.lower(input('Play again? (yes/no):')) # makes string lowercase to match list options
    while replayAnswer != replayOptions:
        if replayAnswer == 'yes':
            game()
            break
        elif replayAnswer == 'no':
            print('Number of games played: {}'.format(gamesPlayed)) # shows total games played
            print('Games you won: {}'.format(playerWins)) # shows player wins
            print('Games the computer won: {}'.format(computerWins)) # shows computer wins
            print('Tie games: {}'.format(gamesTied)) # shows games tied
            print('Thanks for playing!')
            break
        else:
            replayAnswer = str.lower(input('Invalid response. Play again? Yes or no only:')) # prevents invalid inputs

# handles the game itself
def game():

    # accesses the variables from outside of the function
    global options
    global userInput
    global gamesPlayed
    gamesPlayed += 1 # counts how many times the game is played

    print("Let's play Rock, Paper, Scissors, Lizard, Spock!")

    # requests game choice from player
    userInput = str.lower(input("Enter your choice:")) # makes string lowercase to match list options

    # determines if user input is valid
    while userInput != options:
        if userInput == 'rock':
            randomOption()
            replay()
            break
        elif userInput == 'paper':
            randomOption()
            replay()
            break
        elif userInput == 'scissors':
            randomOption()
            replay()
            break
        elif userInput == 'lizard':
            randomOption()
            replay()
            break
        elif userInput == 'spock':
            randomOption()
            replay()
            break
        else:
            # prevents invalid inputs
            userInput = str.lower(input("That's invalid. Please enter rock, paper, scissors, lizard or spock:"))

# runs the games
game()

