# Raiyan Ali U24491765 - Driver - 50% work
# Joshua Bernard U92651625 - Navigator - 50% work

# This program will create a list of all the questions and answer choices

import questions

def trivia():

    # list that will hold the questions and answers
    question = []

    # adds the first question and answers
    question.append(questions.question('How many days are in a lunar year?','354','365','243','379',1))


    question.append(questions.question('What is the largest planet?','Mars','Jupiter','Earth','Pluto',2))


    question.append(questions.question('What is the largest kind of whale?','Orca whale','Humpback whale','Beluga whale','Blue whale',4))


    question.append(questions.question('Which dinosaur could fly?','Triceratops','Tyrannosaurus Rex','Pteranodon','Diplodocus',3))


    question.append(questions.question('Which of these Winnie the Pooh characters is a donkey?','Pooh','Eeyore','Piglet','Kanga',2))


    question.append(questions.question('What is the hottest planet?','Mars','Pluto','Earth','Venus',4))


    question.append(questions.question('Which dinosaur had the largest brain compared to body size?','Troodon','Stegosaurus','chthyosaurus','Gigantoraptor',1))


    question.append(questions.question('What is the largest type of penguins?','Chinstrap penguins','Macaroni penguins','Emperor penguins','White-flippered penguins',3))


    question.append(questions.question('Which children\'s story character is a monkey?','Winnie the Pooh','Curious George','Horton','Goofy',2))


    question.append(questions.question('How long is a year on Mars?','550 Earth days','498 Earth days','126 Earth days','687 Earth days',4))

    # returns the list for later
    return question

