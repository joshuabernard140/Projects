# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program will simulate the race between the tortoise and the hare based on randomly generated actions. The first
# animal to reach the 50th position wins the race! If they both land on the same spot, the tortoise will bite the hare.
# If they tie at the finish, the tortoise will take the win.

# allows for the random number generator
import random

randTortoiseValue = int() # variable for random tortoise action
randHareValue = int() # variable for random hare action
hareScore = int() # position of hare in race
tortoiseScore = int() # position of tortoise in race
win = int() # handles the winner of the race


# handles the random action of the tortoise
def tortoise():
    global randTortoiseValue
    global tortoiseScore
    randTortoiseValue = random.randint(1, 11)
    if randTortoiseValue <= 5: # fast plod
        tortoiseScore += 3
    elif randTortoiseValue <= 7: # slip
        tortoiseScore -= 5
    else: # slow plod
        tortoiseScore += 1
    if tortoiseScore < 0:
        tortoiseScore = 0
    if tortoiseScore > 50:
        tortoiseScore = 50

# handles the random action of the hare
def hare():
    global randHareValue
    global hareScore
    randHareValue = random.randint(1, 11)
    if randHareValue <= 2: # sleep
        hareScore += 0
    elif randHareValue <= 4: # big hop
        hareScore += 7
    elif randHareValue <= 5: # big slip
        hareScore -= 10
    elif randHareValue <= 8: # small hop
        hareScore += 1
    else: # small slip
        hareScore -= 2
    if hareScore < 0:
        hareScore = 0
    if hareScore > 50:
        hareScore = 50

# prints out the race itself
def race():
    global hareScore
    global tortoiseScore
    global win
    for position in range(0, 51):
        if position == hareScore:
            print('H', end='')
        if position == tortoiseScore:
            print('T', end='')
        else:
            print(' ', end='')
    print()
    if hareScore == tortoiseScore: # prints 'OW!!' if they land on each other
        print('OW!!')
    if hareScore >= 50 and tortoiseScore >= 50: # 1 = tortoise win   /   2 = hare win
        win = 1
    elif tortoiseScore >= 50:
        win = 1
    elif hareScore >= 50:
        win = 2

# puts the whole game together and finds out if there was a winner yet
def main():
    print('ON YOUR MARK... GET SET...\nGO!!!!!!\nAND THEY\'RE OFF!\n')
    for sec in range(1000):
        tortoise()
        hare()
        race()
        if win == 1:
            print('\nTortoise wins!! Yay!')
            print('The race was {} seconds.'.format(sec + 1))
            break
        elif win == 2:
            print('\nHare wins!! Yay!')
            print('The race was {} seconds.'.format(sec + 1))
            break

# runs the game
main()
