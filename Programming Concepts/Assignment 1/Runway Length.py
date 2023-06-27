# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program will take the take off speed and acceleration of the plane and give back the minimum runway length.

# Requests the plane take off speed
print("Enter the plane's take off speed in m/s:")
v = int(input()) # variable for take off speed

# Requests the plane acceleration
print("Enter the plane's acceleration in m/s**2:")
a = int(input()) # variable for acceleration

# Variable consisting of the equation for the runway length
minimumRunwayLength = (v**2)/(2*a)

# Prints the minimum runway length
print('The minimum runway length needed for this airplane is {:.4f} meters.'.format(minimumRunwayLength))

