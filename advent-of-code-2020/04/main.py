import sys
import string


def read_input():
    input = sys.stdin.read()
    batches = input.split("\n\n")
    raw_passport = [b.split() for b in batches]

    passports = []
    for raw in raw_passport:
        passport = {}
        for p in raw:
            k, v = p.split(":")
            passport.update({f"{k}": v})

        passports.append(passport)

    return passports


def validate(passport):
    """
    A passport is valid if it has all the following fields:
    byr (Birth Year)
    iyr (Issue Year)
    eyr (Expiration Year)
    hgt (Height)
    hcl (Hair Color)
    ecl (Eye Color)
    pid (Passport ID)
    (optional) cid (Country ID)
    """
    fields = passport.keys()
    required = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"]
    return all(i in fields for i in required)


def more_validate(passport):
    """
    byr (Birth Year) - four digits; at least 1920 and at most 2002.
    iyr (Issue Year) - four digits; at least 2010 and at most 2020.
    eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
    hgt (Height) - a number followed by either cm or in:
        If cm, the number must be at least 150 and at most 193.
        If in, the number must be at least 59 and at most 76.
    hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
    ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
    pid (Passport ID) - a nine-digit number, including leading zeroes.
    cid (Country ID) - ignored, missing or not.
    """
    byr = 1920 <= int(passport["byr"]) <= 2002
    iyr = 2010 <= int(passport["iyr"]) <= 2020
    eyr = 2020 <= int(passport["eyr"]) <= 2030

    hgt_raw = passport["hgt"]
    hgt_val = hgt_raw[:-2]
    hgt_val = int(hgt_val) if hgt_val.isdigit() else False

    hgt = False
    if hgt_raw.endswith("cm"):
        hgt = 150 <= hgt_val <= 193
    elif hgt_raw.endswith("in"):
        hgt = 59 <= hgt_val <= 76

    hcl = False
    if (hcl_val := passport["hcl"]) and hcl_val.startswith("#"):
        hcl = all(c in string.hexdigits for c in hcl_val[1:])

    ecl = passport["ecl"] in ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"]

    pid = False
    if (pid_val := passport["pid"]) and len(pid_val) == 9:
        pid = pid_val.isdigit()

    return all([byr, iyr, eyr, hgt, hcl, ecl, pid])


def part1(passports):
    valid = 0
    for p in passports:
        if validate(p):
            valid += 1

    return valid


def part2(passports):
    valid = 0
    for p in passports:
        if validate(p) and more_validate(p):
            valid += 1

    return valid


def main():
    input = read_input()
    print(part1(input))
    print(part2(input))


if __name__ == "__main__":
    main()

assert (
    validate(
        {
            "ecl": "gry",
            "pid": "860033327",
            "eyr": "2020",
            "hcl": "#fffffd",
            "byr": "1937",
            "iyr": "2017",
            "cid": "147",
            "hgt": "183cm",
        }
    )
    == True
)

assert (
    validate(
        {
            "iyr": "2013",
            "ecl": "amb",
            "cid": "350",
            "eyr": "2023",
            "pid": "028048884",
            "hcl": "#cfa07d",
            "byr": "1929",
        }
    )
    == False
)
assert (
    validate(
        {
            "hcl": "#ae17e1",
            "iyr": "2013",
            "eyr": "2024",
            "ecl": "brn",
            "pid": "760753108",
            "byr": "1931",
            "hgt": "179cm",
        }
    )
    == True
)
assert (
    validate(
        {
            "hcl": "#cfa07d",
            "eyr": "2025",
            "pid": "166559648",
            "iyr": "2011",
            "ecl": "brn",
            "hgt": "59in",
        }
    )
    == False
)


assert (
    more_validate(
        {
            "eyr": "1972",
            "cid": "100",
            "hcl": "#18171d",
            "ecl": "amb",
            "hgt": "170",
            "pid": "186cm",
            "iyr": "2018",
            "byr": "1926",
        }
    )
    == False
)
assert (
    more_validate(
        {
            "iyr": "2019",
            "hcl": "#602927",
            "eyr": "1967",
            "hgt": "170cm",
            "ecl": "grn",
            "pid": "012533040",
            "byr": "1946",
        }
    )
    == False
)
assert (
    more_validate(
        {
            "hcl": "dab227",
            "iyr": "2012",
            "ecl": "brn",
            "hgt": "182cm",
            "pid": "021572410",
            "eyr": "2020",
            "byr": "1992",
            "cid": "277",
        }
    )
    == False
)
assert (
    more_validate(
        {
            "hgt": "59cm",
            "ecl": "zzz",
            "eyr": "2038",
            "hcl": "74454a",
            "iyr": "2023",
            "pid": "3556412378",
            "byr": "2007",
        }
    )
    == False
)


assert (
    more_validate(
        {
            "pid": "087499704",
            "hgt": "74in",
            "ecl": "grn",
            "iyr": "2012",
            "eyr": "2030",
            "byr": "1980",
            "hcl": "#623a2f",
        }
    )
    == True
)
assert (
    more_validate(
        {
            "eyr": "2029",
            "ecl": "blu",
            "cid": "129",
            "byr": "1989",
            "iyr": "2014",
            "pid": "896056539",
            "hcl": "#a97842",
            "hgt": "165cm",
        }
    )
    == True
)
assert (
    more_validate(
        {
            "hcl": "#888785",
            "hgt": "164cm",
            "byr": "2001",
            "iyr": "2015",
            "cid": "88",
            "pid": "545766238",
            "ecl": "hzl",
            "eyr": "2022",
        }
    )
    == True
)
assert (
    more_validate(
        {
            "iyr": "2010",
            "hgt": "158cm",
            "hcl": "#b6652a",
            "ecl": "blu",
            "byr": "1944",
            "eyr": "2021",
            "pid": "093154719",
        }
    )
    == True
)
