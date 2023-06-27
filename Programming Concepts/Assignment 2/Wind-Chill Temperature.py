# Joshua Bernard U92651625 - Navigator - 50% work
# Raiyan Ali U24491765 - Driver - 50% work

# This program will determine the wind chill given the outside temperature and wind speed

# temperature
t = float(input('Enter the temperature in Fahrenheit (between -58 and 41): '))
while t > 41:
    t = float(input("Equation won't work, please enter a value within the range: "))

# wind speed
ws = float(input('Enter the wind speed (must eb at least greater than 2 mph): '))
while ws < 2:
    ws = float(input("Equation won't work, please enter a value within the range: "))

# solve for windchill
windChill = 35.74 + (0.6215*t) - (35.75*(ws**0.16)) + (0.4275*t*(ws**0.16))
print('{:.3f}'.format(windChill))