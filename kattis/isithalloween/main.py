import sys

for line in sys.stdin:
    date = line.strip()
    if date == "OCT 31" or date == "DEC 25":
        print("yup")
    else:
        print("nope")
