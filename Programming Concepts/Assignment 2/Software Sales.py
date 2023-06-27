# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program will take the amount of packages bought and give back the % of discount, how much discounted,
# and the total after the discount.

# gets the number of packages purchased
numberOfPackages = int(input('Enter the number of packages purchased:'))

# total cost of packages before discounts
packageCost = 99 * numberOfPackages


# finds amount of discount and total after discounts
if numberOfPackages >= 100:
    print('Discount Amount @ 40%: $', .4 * packageCost)
    print('Total Amount: $', .6 * packageCost)
elif numberOfPackages >= 50:
    print('Discount Amount @ 30%: ', .3 * packageCost)
    print('Total Amount: $', .7 * packageCost)
elif numberOfPackages >= 20:
    print('Discount Amount @ 20%: ', .2 * packageCost)
    print('Total Amount: $', .8 * packageCost)
elif numberOfPackages >= 10:
    print('Discount Amount @ 10%: ', .1 * packageCost)
    print('Total Amount: $', .9 * packageCost)
else:
    print('Discount Amount @ 0%: ',0 * packageCost)
    print('Total Amount: $',1 * packageCost)