# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program will run the actual trivia game

import trivia

def main():
    # score of the game
    score = [0,0]

    # decides which player is going; 0 is player1 and 1 is player2 to go with list order of score
    turn = 0

    # new instance of trivia
    questions = trivia.trivia()

    # for loop to ask each question
    for x in questions:

        # decides whos turn it is
        if turn == 1:
            print('Question for the first player:')
        else:
            print('Question for the second player:')

        # prints the question
        print(str(x))

        # receives the answer
        answer = int(input('Enter your solution(a number between 1 and 4): '))

        # decides whether answer is correct
        if answer == x.correct:
            print('This is the  correct answer.')
            score[turn] += 1
        else:
            print('This is incorrect. The correct answer is {}'.format(x.correct))

        # changes the turn
        if turn == 0:
            turn = 1
        else:
            turn = 0

    # prints score of each player
    print('The first player earned {} points.'.format(score[0]))
    print('The second player earned {} points.'.format(score[1]))

    # prints winner of game
    if score[0] > score[1]:
        winner = 'first'
    else:
        winner = 'second'

    print('The {} player wins the game!'.format(winner))

# runs the program
main()