# Computes the approximate grade level needed to comprehend some text
from cs50 import get_string
import numpy as np


def main():
    text = get_string("Text: ")

    word_num = 0
    letter_num = 0
    sentence_num = 0
    # Count words
    words = text.split()
    word_num = len(words)

    # define letter list
    letter = []

    for i in range(word_num):
        letter = letter + list(words[i])
        nletters = len(letter)

    for i in range(nletters):
        # Count words
        if letter[i].isalpha() == True:
            letter_num += 1
        # Count sentences
        if letter[i] == '.' or letter[i] == '!' or letter[i] == '?':
            sentence_num += 1

    # The average number of letters per 100 words in the text
    L = letter_num / word_num * 100
    # The aberage number of sentences per 100 words in the text
    S = sentence_num / word_num * 100
    # Calculate grade
    grade = np.round(0.0588 * L - 0.296 * S - 15.8)

    # Print Grade X
    # print(word_num, letter_num, sentence_num)
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


# Call main
main()