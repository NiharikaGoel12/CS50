from cs50 import get_float

def main():
    change = get_float("Change owed: ")
    if change >0:
        calculate_change(change)

def calculate_change(change):
    change = int(100 * change)
    counter = 0

    if(change % 25 != change):
        counter += (change // 25)
        change = change - (25* (change // 25))

    if(change % 10 != change):
        counter += (change // 10)
        change = change - (10* (change // 10))

    if(change % 5 != change):
        counter += (change // 5)
        change = change - (5* (change // 5))

    if(change % 1 != change):
        counter += (change // 1)
        change = change - (1* (change // 1))

    print(counter)

main()