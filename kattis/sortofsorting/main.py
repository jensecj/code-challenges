import sys


input = sys.stdin.readlines()
input = [l.strip() for l in input]

pc = 0
while pc < len(input):
    c = int(input[pc])
    if c == 0:
        break

    if pc > 0:
        print()

    names = input[pc + 1 : pc + c + 1]
    sorted_names = sorted(names, key=lambda a: a[:2])

    for n in sorted_names:
        print(n)

    pc += c + 1
