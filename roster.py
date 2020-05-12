# TODO
from cs50 import SQL
from sys import argv

# if_passing_arguments_are < 2 then_exit
if len(argv) < 2:
    print("usage error, roster.py houseName")
    exit()

# open_database_in_a_variable_to_reuse_later
db = SQL("sqlite:///students.db")
students = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last", argv[1])

# print_persons_name
for student in students:
    if student['middle'] != None:
        print(f"{student['first']} {student['middle']} {student['last']}, born {student['birth']}")
    else:
        print(f"{student['first']} {student['last']}, born {student['birth']}")