# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program will take the 3 edges and give back the perimeter. If any of the 3 pairs doesn't add up to be greater
# than the 3rd edge, it will give and error message.

# edge variables request the edge lengths
edge1 = float(input('Enter length of edge1:'))
edge2 = float(input('Enter length of edge2:'))
edge3 = float(input('Enter length of edge3:'))

# equation of the perimeter
perimeter = edge1 + edge2 + edge3

# finds out whether any of the 3 pairs don't add up to be greater than the 3rd edge
if edge1 + edge2 < edge3:
    print('The perimeter cannot be calculated: the input is invalid')
elif edge2 + edge3 < edge1:
    print('The perimeter cannot be calculated: the input is invalid')
elif edge3 + edge1 < edge2:
    print('The perimeter cannot be calculated: the input is invalid')
else:
    print('The perimeter is {:.2f}'.format(perimeter))