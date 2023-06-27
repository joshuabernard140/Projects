# Joshua Bernard U92651625 - Navigator - 50% work
# Raiyan Ali U24491765 - Driver - 50% work

# This program will take the coordinates of 2 points and give back the slope between them.

# Requests coordinates
print('Enter the x-coordinate for point1: ')
x1 = int(input()) # variable for first x coordinate

print('Enter the y-coordinate for point1: ')
y1 = int(input())

print('Enter the x-coordinate for point2: ')
x2 = int(input()) # variable for second x coordinate

print('Enter the y-coordinate for point2: ')
y2 = int(input())

# Variable consisting of slope equations
slope = (y2 - y1) / (x2 - x1)

# prints the slope of the given coordinates
print('The slope for the line that connects two points, (', x1, ',', y1, ') and (', x2, ',', y2, ') is {:.5f}.'.format(slope))

