# tags: calculator, precendence

from typing import Deque
from dataclasses import dataclass

from collections import deque

from compytetive.util import benchmark


def read_input(filename):
    with open(filename) as f:
        data = f.readlines()
        data = [d.strip() for d in data]
    return data


@dataclass
class Token:
    pass


@dataclass
class Num(Token):
    value: int


@dataclass
class Op(Token):
    value: str


@dataclass
class LParen(Token):
    pass


@dataclass
class RParen(Token):
    pass


def tokenize(expr: str) -> Deque[Token]:
    tokens: Deque[Token] = deque()
    pc = 0

    while pc < len(expr):
        if (e := expr[pc]).isdigit():
            tokens.append(Num(int(e)))

        elif (e := expr[pc]) in ["+", "*"]:
            tokens.append(Op(e))

        elif (e := expr[pc]) == "(":
            tokens.append(LParen())

        elif (e := expr[pc]) == ")":
            tokens.append(RParen())

        pc += 1

    return tokens


assert list(tokenize("1+2")) == [Num(1), Op("+"), Num(2)]
assert list(tokenize("1+(2*3)")) == [
    Num(1),
    Op("+"),
    LParen(),
    Num(2),
    Op("*"),
    Num(3),
    RParen(),
]

assert list(tokenize("1+(2*3)+(4*(5+6))")) == [
    Num(1),
    Op("+"),
    LParen(),
    Num(2),
    Op("*"),
    Num(3),
    RParen(),
    Op("+"),
    LParen(),
    Num(4),
    Op("*"),
    LParen(),
    Num(5),
    Op("+"),
    Num(6),
    RParen(),
    RParen(),
]


def shunt(tokens: Deque[Token], precedence={"*": 1, "+": 1}) -> Deque[Token]:
    """
    We can use Dijkstra's shunting-yard algorithm to turn an arithmatic
    expression with some precedences into RPN, which is simple to evaluate.

    (in this case we ignore associativity, because we only deal with unary +/*)

    See: https://en.wikipedia.org/wiki/Shunting-yard_algorithm#The_algorithm_in_detail
    """
    operators_stack = deque()
    output_queue = deque()

    while tokens:
        t = tokens.popleft()

        # if token is a number, push it to the output queue
        if isinstance(t, Num):
            output_queue.append(t)

        # if the token is an operator
        elif isinstance(t, Op):
            while (
                # while there is an op on top of operator stack
                operators_stack
                and (top := operators_stack[0])
                # and that op is not a left paren
                and not isinstance(top, LParen)
                # and that ops precedence is higher than our token
                # here, we use >= because we treat + and * as left associative
                and precedence[top.value] >= precedence[t.value]
            ):
                # push from operators stack -> output queue
                output_queue.append(operators_stack.popleft())

            # push token to operator stack
            operators_stack.appendleft(t)

        # if token is a left paren
        elif isinstance(t, LParen):
            # push to operator stack
            operators_stack.appendleft(t)

        # if token is right paren
        elif isinstance(t, RParen):
            # while the top token in operator stack is not a left paren
            while (
                operators_stack
                and (top := operators_stack[0])
                and not isinstance(top, LParen)
            ):
                # pop from operator stack -> output queue
                output_queue.append(operators_stack.popleft())

            # if there is a left parenthesis at the top of the operator stack
            if (
                operators_stack
                and (top := operators_stack[0])
                and isinstance(top, LParen)
            ):
                # discard it
                operators_stack.popleft()

    # pop the remaining operators_stack to the output queue
    while operators_stack:
        output_queue.append(operators_stack.popleft())

    return output_queue


assert list(shunt(tokenize("1+2*3"), {"+": 1, "*": 1})) == [
    Num(1),
    Num(2),
    Op("+"),
    Num(3),
    Op("*"),
]

assert list(shunt(tokenize("1+2*3"), {"+": 2, "*": 1})) == [
    Num(1),
    Num(2),
    Op("+"),
    Num(3),
    Op("*"),
]


assert list(shunt(tokenize("1+2*3"), {"+": 1, "*": 2})) == [
    Num(1),
    Num(2),
    Num(3),
    Op("*"),
    Op("+"),
]

assert list(shunt(tokenize("1+(2*3)"))) == [
    Num(1),
    Num(2),
    Num(3),
    Op("*"),
    Op("+"),
]


assert list(shunt(tokenize("1+2*3+4*5+6"))) == [
    Num(1),
    Num(2),
    Op("+"),
    Num(3),
    Op("*"),
    Num(4),
    Op("+"),
    Num(5),
    Op("*"),
    Num(6),
    Op("+"),
]


def eval_rpn(tokens: Deque[Token]) -> int:
    """Evaluate an arithmetic expression in Reverse Polish Notation"""
    stack = deque()

    while tokens:
        t = tokens.popleft()

        if isinstance(t, Num):
            stack.appendleft(t)

        elif isinstance(t, Op):
            assert len(stack) >= 2

            lhs = stack.popleft()
            rhs = stack.popleft()

            if t.value == "+":
                val = lhs.value + rhs.value
            elif t.value == "*":
                val = lhs.value * rhs.value

            stack.appendleft(Num(val))

    return stack[0].value


# (1+2)*3
assert eval_rpn(shunt(tokenize("1+2*3"))) == 9

# 1+(2*3)
assert eval_rpn(shunt(tokenize("1+2*3"), {"+": 1, "*": 2})) == 7
assert eval_rpn(shunt(tokenize("1+(2*3)"))) == 7


# ((((1+2) * 3) + 4) * 5) + 6
assert eval_rpn(shunt(tokenize("1+2*3+4*5+6"))) == 71
assert eval_rpn(shunt(tokenize("1+(2*3)+(4*(5+6))"))) == 51
assert eval_rpn(shunt(tokenize("2*3+(4*5)"))) == 26
assert eval_rpn(shunt(tokenize("5+(8*3+9+3*4*3)"))) == 437
assert eval_rpn(shunt(tokenize("5*9*(7*3*3+9*3+(8+6*4))"))) == 12240
assert eval_rpn(shunt(tokenize("((2+4*9)*(6+9*8+6)+6)+2+4*2"))) == 13632


assert eval_rpn(shunt(tokenize("1+2*3+4*5+6"), {"+": 2, "*": 1})) == 231
assert eval_rpn(shunt(tokenize("1+(2*3)+(4*(5+6))"), {"+": 2, "*": 1})) == 51
assert eval_rpn(shunt(tokenize("2*3+(4*5)"), {"+": 2, "*": 1})) == 46
assert eval_rpn(shunt(tokenize("5+(8*3+9+3*4*3)"), {"+": 2, "*": 1})) == 1445
assert eval_rpn(shunt(tokenize("5*9*(7*3*3+9*3+(8+6*4))"), {"+": 2, "*": 1})) == 669060
assert (
    eval_rpn(shunt(tokenize("((2+4*9)*(6+9*8+6)+6)+2+4*2"), {"+": 2, "*": 1})) == 23340
)


def part1(data):
    values = []

    for line in data:
        tokens = tokenize(line)
        rpn = shunt(tokens, {"+": 1, "*": 1})
        ret = eval_rpn(rpn)
        values.append(ret)

    return sum(values)


def part2(data):
    values = []

    for line in data:
        tokens = tokenize(line)
        rpn = shunt(tokens, {"+": 2, "*": 1})
        ret = eval_rpn(rpn)
        values.append(ret)

    return sum(values)


def main():
    data = read_input("input.in")
    print(benchmark(part1)(data))
    print(benchmark(part2)(data))


if __name__ == "__main__":
    main()


real_input = read_input("input.in")
assert part1(real_input) == 75592527415659
assert part2(real_input) == 360029542265462
