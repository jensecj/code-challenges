# tags: bruteforce, analysis, fingerprinting

import itertools as it
from collections import defaultdict

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        signals = []
        outputs = []
        for line in f.read().split("\n"):
            pattern, output = line.split(" | ")
            signals.append([p for p in pattern.split(" ") if p])
            outputs.append([o for o in output.split(" ") if o])
    return signals, outputs


SIGNALS = "abcdefg"
SEGMAP = {
    "abcefg": 0,
    "cf": 1,
    "acdeg": 2,
    "acdfg": 3,
    "bcdf": 4,
    "abdfg": 5,
    "abdefg": 6,
    "acf": 7,
    "abcdefg": 8,
    "abcdfg": 9,
}
SEGSET = set(SEGMAP.keys())


def part1(data):
    signals, outputs = data

    bag = defaultdict(int)
    for v in SEGSET:
        bag[len(v)] += 1

    uniq = set(len(v) for v in SEGSET if bag[len(v)] == 1)

    uniques = 0
    for output in outputs:
        for segment in output:
            if len(segment) in uniq:
                uniques += 1

    return uniques


def part2_bruteforce(data):
    """
    there are 7 elements, which means there are 7! = 5040 permutations
    so it's likely possible to bruteforce the problem in reasonable time
    """

    def translate(translation, segment):
        return "".join(sorted(translation[p] for p in segment))

    count = 0

    signals, outputs = data
    for signals, outputs in zip(signals, outputs):
        for perm in it.permutations(SIGNALS):
            # create a translation map from the permutation -> original alphabet
            t = dict(zip("abcdefg", perm))

            # test to see if all translated segments match up to our original segments
            if all(translate(t, segment) in SEGSET for segment in signals):
                # if they do, we have found a permutation that matches,
                # translate outputs and increment our count
                c = (translate(t, pattern) for pattern in outputs)
                c = (SEGMAP[p] for p in c)
                c = "".join(str(n) for n in c)
                count += int(c)
                break
            # if some the the translated segments did not match, try the next permutation

    return count


def part2(data):
    def fingerprint(signal, patterns):
        """
        segments only care about which signals are "on".
        in the input, signals arrive as characters in a segment, in no particular order.
        whats more, the signals can be jumbled in the input,
        so we cannot trust that a signal in one input, is the same as in another,
        so only the distribution of the signals in the segment, and the length of the segment matter.

        we need to create a fingerprint which will match for different signals,
        that match the same segment.

        we generate the fingerprint of SIGNAL by creating a sorted list
        of the lengths of the patterns in PATTERNS which include the signal.

        e.g. in our original data, the signal 'e' occurs in 4 segments,
        [acdeg,abcefg,abdefg,abcdefg], with sizes [5,6,6,7], which will be the fingerprint.

        since each 7-segment number uses a different set of signals,
        (by the nature of 7-segment displays), this means that our fingerprint
        will be unique for each signal
        """
        return sorted(len(pattern) for pattern in patterns if signal in pattern)

    # fingerprint all the known segments (0-9), so we can compare them
    segment_fingerprints = {s: fingerprint(s, SEGSET) for s in SIGNALS}

    count = 0
    signals, outputs = data
    for signals, outputs in zip(signals, outputs):
        # fingerprint signals so we can compare them to our fingerprinted segments
        signal_fingerprints = {s: fingerprint(s, signals) for s in SIGNALS}

        # create a mapping from the local signals, to our known segments,
        # based on comparing the local fingerprints to our segments fingerprints
        mapping = {}
        for sig, fp in segment_fingerprints.items():
            for local_sig, local_fp in signal_fingerprints.items():
                if fp == local_fp:
                    mapping[local_sig] = sig

        # now we have a mapping from the current signals, to our original alphabet,
        # all we need to do now is translate each segment,
        # look up the numbers they represent, and sum them
        digits = []
        for output in outputs:
            translation = sorted(mapping[o] for o in output)
            translated_signal = "".join(translation)
            for signal, num in SEGMAP.items():
                if signal == translated_signal:
                    digits.append(num)
                    break

        count += int("".join(str(o) for o in digits))
    return count


def main():
    test_input = read_input("test.in")
    real_input = read_input("input.in")

    assert part1(test_input) == 26
    assert part1(real_input) == 318
    print(benchmark(part1, 50)(real_input))

    assert part2_bruteforce(test_input) == 61229
    assert part2_bruteforce(real_input) == 996280
    print(benchmark(part2_bruteforce)(real_input))

    assert part2(test_input) == 61229
    assert part2(real_input) == 996280
    print(benchmark(part2)(real_input))


if __name__ == "__main__":
    main()
