from sys import argv, exit
import csv

# Validate the no of args and type of args
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)
elif not((argv[1]).endswith('.csv') and (argv[2]).endswith('.txt')):
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

data = []
STR = []

try:
    # Reading a csv file
    with open(argv[1], mode="r") as csv_file:
        csv_file = csv.reader(csv_file)

        for line in csv_file:
            data.append(line)

        for s in data[0][1:]:
            STR.append(s)

        data = data[1:]

    # Reading a text file
    text_file = open(argv[2])
    sequence = text_file.read().rstrip('\n')
except:
    print("Invalid csv or text file")
    exit(1)


def find_repeats(sequence, STR):
    # Number of bases in Short Tandem Repeat
    L = len(STR)

    max_repeats = 0
    for i in range(len(sequence)):
        # Initialise and reset repeat counter
        repeats = 0

        if sequence[i: i + L] == STR:
            # Account for first match
            repeats += 1
            # Keep adding to count for consecutive repeats
            while sequence[i: i + L] == sequence[i + L: i + (2 * L)]:
                repeats += 1
                # Shift reading frame (value of i resets in for loop so we can update it here)
                i += L

        # Update max count if current repeat steak is greater than max
        if repeats > max_repeats:
            max_repeats = repeats

    return max_repeats


# To count stas
count = []
for str in STR:
    count.append(find_repeats(sequence, str))

# Check if the count of str matches for any person
for d in data:
    flag = True
    for i in range(len(STR)):
        # Doesnt match break out of loop
        if (count[i] != int(d[i + 1])):
            flag = False
            break
    # If matched print their name and break
    if flag:
        print(d[0])
        break

else:
    print("No match")