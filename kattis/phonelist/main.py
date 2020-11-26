import sys


def eprint(*args, **kwargs):
    print(*args, **kwargs, file=sys.stderr)


input = sys.stdin.readlines()
input = [l.strip() for l in input]

# c = int(input[0])
pc = 1
while pc < len(input):
    c = int(input[pc])
    nums = input[pc + 1 : pc + 1 + c]

    nums = sorted(nums)
    eprint(nums)

    found = False
    eprint(f"{c=}")
    for i in range(0, c):
        eprint(f"{i=}")
        eprint(f"{nums[i]=}")
        if (i + 1) < c:
            eprint(f"{nums[i+1]=}")
            if nums[i + 1].startswith(nums[i]):
                found = True
                break

    print("YES") if not found else print("NO")

    pc += c + 1
