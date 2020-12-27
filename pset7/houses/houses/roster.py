from cs50 import SQL
import sys

db = SQL("sqlite:///students.db")

n = len(sys.argv)

if n<2:
    print("not enough arguments passed")
    exit()

main_file = sys.argv[1]

query_result = db.execute("SELECT first, middle, last, birth from students WHERE house=? order by last, first", (main_file,))
for i in query_result:
    first_name = i['first']
    middle_name = i['middle']
    last_name = i['last']
    birth_year = i['birth']
    if(middle_name == ""):
        print("{} {}, born {}".format(first_name, last_name, birth_year))
    else:
        print("{} {} {}, born {}".format(first_name, middle_name, last_name, birth_year))
