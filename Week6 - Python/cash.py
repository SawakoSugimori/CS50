# Calculate the minimum number of coins required to give a user change
from cs50 import get_float
import math


def main():
    input = get_input()
    num = input * 100
    # Count a change
    coins = 0

    while num > 0:
        # 25 cent
        if num >= 25:
            coin = math.floor(num / 25)
            num = num - (coin * 25)
            coins += coin
        # 10 cent
        elif num >= 10:
            coin = math.floor(num / 10)
            num = num - (coin * 10)
            coins += coin
        # 5 cent
        elif num >= 5:
            coin = math.floor(num / 5)
            num = num - (coin * 5)
            coins += coin
        # 1 cent
        elif num >= 1:
            coin = math.floor(num / 1)
            num = num - coin
            coins += coin

    print(coins)

# Get user input


def get_input():
    while True:
        try:
            # If the input is more than 0, return
            input = get_float("Change owed: ")
            if input > 0:
                return input
        except:
            get_input()


main()
