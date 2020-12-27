# TODO
from cs50 import SQL
import sys
import csv

db = SQL("sqlite:///students.db")

n = len(sys.argv)

if n<2:
    print("not enough arguments passed")
    exit()

main_file = sys.argv[1]


def student_name(name):
    student_full_name = name.split(" ")
    first_name = student_full_name[0]

    if(len(student_full_name) == 2):
        middle_name = ""
        last_name = student_full_name[1]
    else:
        middle_name = student_full_name[1]
        last_name = student_full_name[2]

    return(first_name, middle_name, last_name)

def main():
    with open(main_file,"r") as f:
        reader = csv.reader(f,delimiter = ",")
        data = list(reader)
        row_count = len(data)

        for i in range(1, row_count):
            name = student_name(data[i][0])
            house = data[i][1]
            birth_year = int(data[i][2])

            first_sname = name[0]
            middle_sname = name[1]
            last_sname = name[2]

            sql = "INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)"
            db.execute(sql, first_sname, middle_sname, last_sname, house, birth_year)

main()
