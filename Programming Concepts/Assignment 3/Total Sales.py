# Raiyan Ali - U24491765 - Driver - 50% work
# Joshua Bernard - U92651625 - Navigator - 50% work

# this program asks the user to enter the weekly sales amount for each day of the week
# and return the total sales, the minimum amount, and the maximum amount

import math

# stored days of the week
week = ('Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday')

weekSales = [week[0], week[1], week[2], week[3], week[4], week[5], week[6]]

print()

# Input for weekly sales, makes sure value is positive
weekSales[0] = float(input('Enter the sales for Sunday: '))
while weekSales[0] <= 0:
    weekSales[0] = float(input('Incorrect sales for Sunday. Try again: '))

weekSales[1] = float(input('Enter the sales for Monday: '))
while weekSales[1] <= 0:
    weekSales[1] = float(input('Incorrect sales for Monday. Try again: '))

weekSales[2] = float(input('Enter the sales for Tuesday: '))
while weekSales[2] <= 0:
    weekSales[2] = float(input('Incorrect sales for Tuesday. Try again: '))

weekSales[3] = float(input('Enter the sales for Wednesday: '))
while weekSales[3] <= 0:
    weekSales[3] = float(input('Incorrect sales for Wednesday. Try again: '))

weekSales[4] = float(input('Enter the sales for Thursday: '))
while weekSales[4] <= 0:
    weekSales[4] = float(input('Incorrect sales for Thursday. Try again: '))

weekSales[5] = float(input('Enter the sales for Friday: '))
while weekSales[5] <= 0:
    weekSales[5] = float(input('Incorrect sales for Friday. Try again: '))

weekSales[6] = float(input('Enter the sales for Saturday: '))
while weekSales[6] <= 0:
    weekSales[6] = float(input('Incorrect sales for Saturday. Try again: '))


# Calculates total sales and min. and max. values
totalSale = math.fsum(weekSales)
print('\nThe total sales is: $', '{:,.2f}' .format(totalSale), sep='')
print('The minimum sale amount for the week was: $', '{:,.2f}' .format(min(weekSales)), sep='')
print('The maximum sale amount for the week was: $', '{:,.2f}' .format(max(weekSales)), sep='')