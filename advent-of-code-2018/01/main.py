import sys
import os
from itertools import *

from typing import List

def panic(msg: str) -> None:
    print(msg)
    sys.exit(1)

def part1(input_data: List[int]) -> int:
    return sum(input_data)

def part2(input_data: List[int]) -> int:
    seen: set = set()
    state: int = 0

    for x in cycle(input_data):
        state += x

        if state in seen:
            break
        else:
            seen.add(state)

    return state

def main():
    if len(sys.argv) <= 1:
        panic("usage: python main.py <input file>")

    input_file_path = str(sys.argv[1])

    if not os.path.isfile(input_file_path):
        panic("Cannot find input file: " + input_file_path)

    with open(input_file_path, 'r') as input_file:
        input_data = input_file.read()

    input_data = input_data.split('\n')
    input_data = [ s for s in input_data if s ] # remove empty entries

    input_data = [ s.replace('+', '') for s in input_data ] # remove surplofuous + signs
    input_data = [ int(s) for s in input_data ] # convert to a list of ints

    print(part1(input_data))
    print(part2(input_data))

if  __name__ =='__main__':
    main()
