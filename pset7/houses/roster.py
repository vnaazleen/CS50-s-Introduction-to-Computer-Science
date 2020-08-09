# TODO

from sys import argv, exit
from cs50 import SQL

# Validate the number of argumnets given in commnad line
if (len(argv) != 2):
    exit(1)

hname = argv[1]
# Creating a way to interact with database
db = SQL("sqlite:///students.db")

# Selecting the students accodring to house name given
students = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", hname)

# print each person showing their information and their middle name if they have one
for student in students:
    if student['middle'] != None:
        print(student['first'].strip() + " " + student['middle'] + " " +
              student['last'].strip() + ", born " + str(student['birth']))
    else:
        print(student['first'].strip() + " " + student['last'].strip() + " " + ", born " + str(student['birth']))