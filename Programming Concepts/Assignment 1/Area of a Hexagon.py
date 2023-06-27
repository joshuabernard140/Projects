# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program will take the side length of the hexagon and give back the area.

import math # used for square root in the equation

# requests the side length
print('Enter the side length of the hexagon:')
sideLength = float(input())

# variable consisting of equation for the area of a hexagon
areaOfHexagon = ((3*math.sqrt(3)/2)*(sideLength**2))

# prints the area of the heaxagon
print('The area of a hexagon with side {0:.2f} is {1:.2f}'.format(sideLength, areaOfHexagon))
