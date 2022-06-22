# WAP to convert all vowels in a string to alphabet
# 'g'(for lower case)/'G'(for upper case)
from gettext import translation


def translator(phrase):
    translation = ""  # empty string
    # looping through every letter in phrase
    for letter in phrase:
        if letter.lower() in "aeiou":  # checking if letter is present in "AEIOUaeiou".If it is uppercase,it is converted to lowercase by letter.lower()
            if letter.islower() :
              translation = translation + "g"
            else : #if vowel is upperCase
                translation=translation +"G"
        else:
            translation = translation + letter

    return translation


a = input("Enter phrase : ")  # taking input
print(translator(a))  # calling and printing function
