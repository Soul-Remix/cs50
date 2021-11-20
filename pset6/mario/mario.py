while(True):
    try:
        # Prompt the user for pyramid height
        height = int(input("Height: "))
        # check if height between 1 and 8
        if height in range(1, 9):
            break
    except:
        # print the error message if the inputted value is not a number
        print("value should be a number betwen 1 and 9")

# Print the pyramid
for i in range(height):
    print(" " * (height - i - 1), end='')
    print("#" * (i + 1), end='')
    print("  ", end='')
    print("#" * (i + 1))