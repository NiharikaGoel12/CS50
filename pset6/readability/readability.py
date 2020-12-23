from cs50 import get_string
import re

def main():
    sentence = get_string("Text: ")
    result = grade(sentence)
    if (result >= 16):
        print("Grade 16+")
    elif (result < 1):
        print("Before Grade 1")
    else:
        print("Grade ", result)


def grade(sentence):
    count_s =0
    count_w =1
    count_l =0
    for i in range(len(sentence)):
        if((sentence[i] == '!') or (sentence[i] == '.') or (sentence[i] == '?')):
            count_s +=1
        elif (sentence[i]== " "):
            count_w +=1
        elif(sentence[i].isalpha()):
            count_l +=1

    L = (count_l * 100.0)/count_w
    S = (count_s * 100.0)/count_w
    index = round( (0.0588 * L) - (0.296 * S) - 15.8)
    return index


main()

