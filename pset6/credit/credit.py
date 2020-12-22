from cs50 import get_string

def main():
    credit_card = get_string("Number: ")
    check_valid(credit_card)


def check_valid(credit_card):
    counter = 0

    for i in range(0, len(credit_card), 2):
        multiplier = str(int(credit_card[i]) * 2)
        if len(multiplier) == 2:
            counter += (int(multiplier[0]) + int(multiplier[1]))
        else:
            counter += int(multiplier[0])

    for j in range(1, len(credit_card),2):
        counter += int(credit_card[j])

    if(counter%2 == 0):
        card_type(credit_card)
    else:
        print("INVALID\n")

def card_type(credit_card):
    if (len(credit_card)==15 and (credit_card[0] =='3') and ((credit_card[1] == '4') or (credit_card[1] == '7'))):
        print("AMEX\n")
    elif (len(credit_card)==16 and (credit_card[0] =='5') and (credit_card[1] in ('1', '2', '3', '4', '5'))):
        print("MASTERCARD\n")
    elif ((len(credit_card) in (13,16)) and (credit_card[0] == '4')):
        print("VISA\n")
    else:
        print("INVALID\n")

main()
