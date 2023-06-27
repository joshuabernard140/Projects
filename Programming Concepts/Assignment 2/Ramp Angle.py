# Joshua Bernard U92651625 - Navigator - 50% work
# Raiyan Ali U24491765 - Driver - 50% work

# This program will determine the angle of the ramp

import math

# Force and Mass variables
F = float(input('Enter the force used to push the cart (in N): '))
m = float(input('Enter the mass of the cart (in kg): '))

# gravity
g = 9.8

# ramp angle
sin = F/(m * g)
sine = (math.degrees(math.asin(sin)))
print('The angle of the ramp is: {:.1f} degrees'.format(sine))