import csv
import sys
import re


n = len(sys.argv)
if n < 3 :
    print("not enough arg")
    exit()

#main_file = "databases/large.csv"
#seq_file_path = "sequences/5.txt"

# python dna.py databases/large.csv sequences/1.txt
main_file = sys.argv[1]
seq_file_path = sys.argv[2]

# -- File opened
csv_file = open(main_file, "r")
str_file = open(seq_file_path, "r")

heading = csv_file.readline()
heading = heading.replace("\n", "")
sequence_list = list(heading.split(","))

col_index_map = {}
txt_file = str_file.read()

for i in range(1, len(sequence_list)):
    key = sequence_list[i]
    # https://stackoverflow.com/a/61131908
    # https://stackoverflow.com/questions/6930982/how-to-use-a-variable-inside-a-regular-expression
    groups = re.findall(rf'(?:{key})+', txt_file)
    if len(groups) ==0:
        longest_count =0
    else:
        largest = max(groups, key=len)
        longest_count = len(largest) // len(key)
    col_index_map[i] = longest_count


def is_dna_match(col_map, row_val):
    for i in range(1, len(row_val)):
        if int(col_map[i]) == int(row_val[i]):
            continue
        else:
            return False
    return True

for row in csv_file:
    row = row.replace("\n","")
    row_value = row.split(",")
    status = is_dna_match(col_index_map, row_value)
    if(status is True):
        print(row_value[0])
        exit()
print("No match")

