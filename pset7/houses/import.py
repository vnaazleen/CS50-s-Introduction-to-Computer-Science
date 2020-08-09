# TODO
import csv
from sys import argv, exit
from cs50 import SQL

# Validate the number of argumnets given in commnad line
if (len(argv) != 2):
    exit(1)

fname = argv[1]

# Creating a way to interact with database
open(f"students.db", "w").close()
db = SQL("sqlite:///students.db")

# Create table 'students', and specify the cols we want
db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")
f = open(fname, "r")
students = f.readlines()

for student in students[1:]:
    name, house, year = student.strip().split(',')
    name = name.split()

    # Checking if the student has miidle name
    if len(name) == 3:
        fname = name[0]
        mname = name[1]
        lname = name[2]
    elif len(name) == 2:
        fname = name[0]
        lname = name[1]
        mname = None
    else:
        fname = name[0]
        lname = None
        mname = None

    # Insert the student info into db
    db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", fname, mname, lname, house, year)