# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program creates a tuple and 3 dictionaries for 5 different course numbers and all of the designated inforamtion
# that goes with them. It then asks the user for a course number and if the given course exists in the tuple, it gives
# back the designated information but if not in tuple, says course number is invalid.

# tuple of all course numbers
courseNumbers = ('COP 2510', 'EGN 3000L', 'MAC 2281', 'MUH 3016', 'PHY 2048')

# dictionary for the course names
courseNames = {courseNumbers[0] : ['Programming Concepts'],
               courseNumbers[1] : ['Foundations of Engineering Lab'],
               courseNumbers[2] : ['Calculus 1'],
               courseNumbers[3] : ['Survey of Jazz'],
               courseNumbers[4] : ['General Physics 1']}

# dictionary for the course instructors
courseInstructors = {courseNumbers[0] : ['Z. Beasley'],
                     courseNumbers[1] : ['J. Anderson'],
                     courseNumbers[2] : ['A. Makaryus'],
                     courseNumbers[3] : ['A. Wilkins'],
                     courseNumbers[4] : ['G. Pradhan']}

# dictionary for the course times
courseTimes = {courseNumbers[0] : ['MW 12:30pm –1:45pm'],
               courseNumbers[1] : ['TR 11:00am –12:15pm'],
               courseNumbers[2] : ['MW 9:30am –10:45am '],
               courseNumbers[3] : ['online asynchronous'],
               courseNumbers[4] : ['TR 5:00pm –6:15pm']}

# asks for the course number from user
userInput = input('Enter a course number:')

# shows class information if class is in tuple courseNumbers
if userInput in courseNumbers:
    print('Course Name:', courseNames[userInput])
    print('Instructor:', courseInstructors[userInput])
    print('Class times:', courseTimes[userInput])

# says invalid course number if class is not in tuple courseNumbers
else:
    print('{:} is an invalid course number.'.format(userInput))

