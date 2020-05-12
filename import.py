# TODO
from cs50 import SQL
from csv import reader
from sys import argv

# open_database_in_a_variable_to_reuse_later
db = SQL("sqlite:///students.db")

# if_passing_arguments_are < 2 then_exit
if len(argv) < 2:
    print("usage error, import.py characters.csv")
    exit()

# open_csv_&_copy_into_list
with open(argv[1], newline='') as charactersFile:
    characters = reader(charactersFile)
    for character in characters:
        if character[0] == 'name':
            continue

        # split_into_(first),(last),_(middle)_name if present
        fullName = character[0].split()
        # insert_into_database
        if len(fullName) < 3:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullName[0], None, fullName[1], character[1], character[2])

        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullName[0], fullName[1], fullName[2], character[1], character[2])