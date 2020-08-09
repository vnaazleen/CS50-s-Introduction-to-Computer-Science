from cs50 import get_float

# Take input until it is valid
while True:
    cash = get_float("Change owed: ")
    if cash > 0:
        break

# Coins we have
coins = [25, 10, 5, 1]

# Dollars to cents
cash = int(cash * 100)

# Vars for count the coins
count = 0
each_coin = 0

# Main loop to count no of coins requried
for coin in coins:
    each_coin = cash // coin
    cash -= each_coin * coin
    count += each_coin

# Print the answer
print(count)