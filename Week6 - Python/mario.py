# Print a double half-pyramid of a specified height.
# $ python mario.py
# Height: 4
#    #  #
#   ##  ##
#  ###  ###
# ####  ####
from cs50 import get_int

def main():
    height = get_height()
    for i in range(height):
        print("#")

    print("?" * height)

    for i in range(3):
        for j in range(3):
            print("#", end="")
        print()

def get_height():
    while True:
        try:
            x = int(input("Height: "))
            if x > 0:
                return x
        except ValueError:
            print("Not an integer")

main()