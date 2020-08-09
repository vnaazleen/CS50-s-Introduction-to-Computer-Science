from cs50 import get_string

nwords, nletters, nsentences, L, S = 0, 0, 0, 0, 0

s = get_string("Text: ")

# Loop through the string and Calculate no of chars, sentences and words
for c in s:
    if c == '!' or c == '.' or c == '?':
        nsentences += 1
    elif c == ' ':
        nwords += 1
    elif c.isalpha():
        nletters += 1

nwords += 1

# Calculating L and S
L = (nletters / nwords) * 100
S = (nsentences / nwords) * 100

# Coleman-Liau index formula
index = int((0.0588 * L - 0.296 * S - 15.8) + 0.5)

if index < 1:
    print("Before Grade 1")
elif index >= 1 and index <= 16:
    print(f"Grade {index}")
else:
    print("Grade 16+")