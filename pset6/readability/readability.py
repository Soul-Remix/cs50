import re


def main():
    # Prompt user for text input
    text = input("Text: ")

    # text length
    length = len(text)
    letters = 0
    words = 1
    sentences = 0

    # Check for letters in text
    for i in range(length):
        # Check if char is an alphabet character
        if text[i].isalpha():
            letters += 1

    # Check for words in text
    for i in range(length):
        # Check if char is space
        if text[i].isspace():
            words += 1

    regex = re.compile('[.!?]')
    # Check for sentences in text
    for i in range(length):
        # Check if char is is the regex
        if (regex.search(text[i]) != None):
            sentences += 1

    # Compute the grade using Coleman-Liau algo
    L = 100 * (letters / words)
    S = 100 * (sentences / words)
    grade = round(0.0588 * L - 0.296 * S - 15.8)

    # Check the grade and print the appropriate message
    if grade < 1:
        print("Before Grade 1")
    
    elif grade > 16:
        print("Grade 16+")
    
    else:
        print(f"Grade {grade}")
    

main()