# Calculates the sum of digits of a number
def sum_of_digits(n):
    sum = 0
    for c in str(n):
        sum += int(c)
    return sum


def isvalid(n):
    multiplied_no, werent_multiplied_no = [], []
    total_sum = 0

    # List all the every other digits multiplied by 2
    for i in range(0, len(n), 2):
        multiplied_no.append(int(str(n)[i]) * 2)

    # Add those products digis together
    sum_of_mul = sum([sum_of_digits(i) for i in multiplied_no])

    # Digits that werent multiplied
    for i in range(1, len(n), 2):
        werent_multiplied_no.append(int(str(n)[i]))

    total_sum = sum(werent_multiplied_no) + sum_of_mul
    print(total_sum)

    return str(total_sum)[-1] == '0'


# Prompt user for input until its vaild
card_no = input("Number: ")
try:
    card_no = int(card_no)
except:
    while len(str(card_no)) > 17 or len(str(card_no)) < 12:
        try:
            card_no = int(input("Number: "))
        except:
            pass

# Covert card no to string and find length
card_no = str(card_no)
card_no_len = len(card_no)

# If valid go ahead and print type
if isvalid(card_no):
    if card_no_len == 16 and card_no[0] == '5' and card_no[1] in ['1', '2', '3', '4', '5']:
        print("MASTERCARD")
    elif (card_no_len in [16, 13] and card_no[0] == '4'):
        print("VISA")
elif card_no_len == 15 and card_no[0] == '3' and card_no[1] in ['4', '7']:
    print("AMEX")
else:
    print("INVALID")

