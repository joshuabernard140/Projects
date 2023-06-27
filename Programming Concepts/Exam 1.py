# Joshua Bernard - U92651625
# This program will take the numerator and denominator and give back if its a proper or improper fraction, whether
# or not it can be reduced, and the mixed or whole number.

import math

# Gets the numerator (greater than 0)
numerator = float(input('Enter a numerator: Value must be greater than 0:'))
while numerator < 0:
    numerator = float(input('Please re-enter the numerator. Value must be greater than 0:'))


# Gets the denominator (greater than 0)
denominator = float(input('Enter a denominator: Value must be greater than 0:'))
while denominator < 0:
    denominator = float(input("Please re-enter the denominator. Value must be greater than 0:"))


# gets the greatest common denominator
gcd = math.gcd(int(numerator),int(denominator))


# gets the whole number and the remaining fraction of an improper fraction
whole_number = numerator // denominator
new_numerator = numerator % denominator


# finds and prints whether or not the fraction is proper or improper
if numerator < denominator: # for proper fractions
     print('{0:}/{1:} is a proper fraction.'.format(numerator,denominator))
     if gcd > 1:
         print('This proper fraction can be reduced to',(numerator/gcd),'/',(denominator/gcd),'.')
     else:
         print('This proper fraction cannot be reduced further.')
else: # for improper fractions
     print('{0:}/{1:} is an improper fraction.'.format(numerator,denominator))
     if gcd > 1:
         print('This improper fraction can be reduced to', (numerator / gcd), '/', (denominator / gcd), '.')
     else:
         print('This improper fraction cannot be reduced further.')
     if new_numerator <= 0:
         print('The whole number is {:}.'.format(whole_number))
     else:
         print('The mixed number is {0:} and {1:}/{2:}.'.format(whole_number, new_numerator / gcd, denominator / gcd))

