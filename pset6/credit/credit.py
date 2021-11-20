# Prompt for credit card number
while(True):
    number = input("Number: ").strip()
    if number.isnumeric():
        break

# credit card num count
count = len(number)
sum = 0
tmp_count = count - 1
i = 1

while tmp_count >= 0:
    n = number[tmp_count]
    if(i % 2 == 0 ):
        s = int(n) * 2
        
        if s > 9:
            sum += s - 9
        else:
            sum += s
            
    else:
        sum += int(n)
    i += 1
    tmp_count -= 1

valid = sum % 10 == 0

p = number[:2]

# Check if the card is American Express
if count == 15 and (p in ["34","37"]) and valid:
    print("AMEX")
# Check if the card is MasterCard
elif count == 16 and (p in ["51","52","53","54","55"]) and valid:
    print("MASTERCARD")
# Check if the card is Visa
elif (count == 13 or count == 16) and (p[0] == "4") and valid:
    print("VISA")
# Print Invalid if it's not one of the above
else:
    print("invalid")