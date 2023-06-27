# Joshua Bernard U92651625 - Navigator - 50% work
# Raiyan Ali U24491765 - Driver - 50% work

# This program will take the price and the tip in percent and give back the tip amount and the total amount.

# Subtotal
print('How much you have to pay: $', end='')
subtotal = float(input())

# Tip amount
print('How much do you want to tip (as a percent)?: ', end='')
tipPercent = float(input())/100

# Display subtotal
print('Subtotal: ${:.2f}'.format(subtotal))

# Display tip
tip = tipPercent * subtotal
print('Tip: ${:.2f}'.format(tip))

# Total
total = tip+subtotal
print('Your total is: ${:.2f}'.format(total))