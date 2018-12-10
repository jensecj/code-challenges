import sys
import os
import time
import datetime as dt
from itertools import *

from typing import List, Dict, Tuple

def panic(msg: str) -> None:
    print(msg)
    sys.exit(1)

def get_timestamp(line: str) -> dt.datetime:
    "Returns the timestamp of a command input."
    (TIMESTAMP_START, TIMESTAMP_END) = (1, 17)
    return dt.datetime.strptime(line[TIMESTAMP_START:TIMESTAMP_END], '%Y-%m-%d %H:%M')

def get_cmd(line: str) -> str:
    "Returns the command from a command input."
    (CMD_START, CMD_END) = (19, 24)
    return line[CMD_START:CMD_END].lower()

def get_guard_id(line: str) -> int:
    "Returns the guards id, from a guard command input."
    # from character 26 to first whitespace
    id = line[26:].split()[0]
    return int(id)

def minute_diff(ts1: dt.datetime, ts2: dt.datetime) -> int:
    "Returns the difference between two timestamps in minutes."
    t1 = time.mktime(ts1.timetuple())
    t2 = time.mktime(ts2.timetuple())
    return int ((t1 - t2) / 60)

def solve(input: List[str]) -> Tuple[int, int]:
    # sort input by the datetime of the log entries
    lines = sorted(input, key = lambda x: get_timestamp(x))

    current_guard_id = -1
    current_guard_started_shift_time = dt.datetime.now()
    current_guard_fell_asleep_time = dt.datetime.now()
    current_guard_minutes_awake_before_sleep = -1

    # each guard has an hour where we can fall asleep / wake up, we just keep a
    # list of 60 ints, representing each minute of the hour 00:00 - 00:59 where
    # the guard can fall asleep. if he falls asleep at 00:01 and wakes up at
    # 00:05, we increment each index of our list between the two times,
    # including the minute he fell asleep, and excluding the minute he wakes up,
    # as per the description.
    guards_log: Dict[int, List[int]] = {}

    # precondition: a guard is never replaced while he is asleep, i.e. for each
    # time we receive a log message about a guard falling asleep, there exists
    # one where he wakes up.
    for l in lines:
        timestamp = get_timestamp(l)
        cmd = get_cmd(l)

        if cmd == "guard":
            current_guard_id = int(get_guard_id(l))
            current_guard_started_shift_time = timestamp

            if current_guard_id not in guards_log:
                guards_log[current_guard_id] = [0] * 60

            print("guard #%s begins shift at %s" % (current_guard_id, timestamp))
        elif cmd == "falls":
            current_guard_fell_asleep_time = timestamp
            current_guard_minutes_awake_before_sleep = minute_diff(current_guard_fell_asleep_time, current_guard_started_shift_time)
            print("guard #%d falls asleep %d minutes after starting shift" % (current_guard_id, current_guard_minutes_awake_before_sleep))
        elif cmd == "wakes":
            slept_minutes = minute_diff(timestamp, current_guard_fell_asleep_time)
            print("guard #%d wakes up, was asleep for %i minutes" % (current_guard_id, slept_minutes))

            for i in range(slept_minutes):
                idx = (current_guard_fell_asleep_time.minute + i) % 60
                guards_log[current_guard_id][idx] = guards_log[current_guard_id][idx] + 1


    for k in guards_log.keys():
        print("%s: %s" % (k, guards_log[k]))

    all_guards_total_sleep = [ (k, sum(guards_log[k])) for k in guards_log.keys() ]
    print("totals: %s" % all_guards_total_sleep)

    worst_guard = max(all_guards_total_sleep, key=lambda x: x[1])
    worst_guard_id = worst_guard[0]
    worst_guard_minutes_slept = worst_guard[1]
    print("worst guard: %s, with %d minutes slept" % (worst_guard_id, worst_guard_minutes_slept))

    worst_minute_misses = max(guards_log[worst_guard_id])
    worst_minute = guards_log[worst_guard_id].index(worst_minute_misses)
    print("worst minute: %s, with %s times missed" % (worst_minute, worst_minute_misses))

    part1 = worst_guard_id * worst_minute # 85296

    guards_and_worst_minutes = [ (k, max(guards_log[k])) for k in guards_log.keys() ]
    worst_same_minute_guard = max(guards_and_worst_minutes, key=lambda x: x[1])
    worst_same_minute_guard_id = worst_same_minute_guard[0]
    worst_same_minute_guard_misses = worst_same_minute_guard[1]
    worst_same_minute_guard_minute = guards_log[worst_same_minute_guard_id].index(worst_same_minute_guard_misses)

    print("guard who sleeps most at the same minute: %s, with minute %s having %s misses"
          % (worst_same_minute_guard_id,
             worst_same_minute_guard_minute,
             worst_same_minute_guard_misses))

    part2 = worst_same_minute_guard_id * worst_same_minute_guard_minute # 58559

    return (part1, part2)


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

    (part1, part2) = solve(input_data)

    print("Part 1: %s" % part1)
    print("Part 2: %s" % part2)


if  __name__ =='__main__':
    main()
