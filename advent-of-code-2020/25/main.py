# tags: modulo

from compytetive.util import benchmark


def calc_loop_size(public_key):
    subject = 7
    loop_size = 0
    val = 1

    while val != public_key:
        val *= subject
        val %= 20201227
        loop_size += 1

    return loop_size


def break_encryption(loop_size, public_key):
    subject = public_key
    encryption_key = 1

    for _ in range(loop_size):
        encryption_key *= subject
        encryption_key %= 20201227

    return encryption_key


def part1(data):
    card_public, door_public = data

    card_loop_size = calc_loop_size(card_public)
    door_loop_size = calc_loop_size(door_public)

    card_private = break_encryption(door_loop_size, card_public)
    door_private = break_encryption(card_loop_size, door_public)
    assert card_private == door_private

    return card_private


def part1_faster(data):
    card_public, door_public = data

    subject = 7
    val = key = 1

    while val != card_public:
        # we don't need to know the actual loop size,
        # because we know that the loop terminates when val == public_key.
        # so we can just calculate val and the encryption key simultaneously
        val = (val * subject) % 20201227
        key = (key * door_public) % 20201227

    return key


def main():
    print(benchmark(part1)((1965712, 19072108)))
    print(benchmark(part1_faster)((1965712, 19072108)))


if __name__ == "__main__":
    main()


# test input
assert part1((5764801, 17807724)) == 14897079

# real input
assert part1((1965712, 19072108)) == 16881444
