# python3

from collections import namedtuple

Bracket = namedtuple("Bracket", ["char", "position"])


def are_matching(left, right):
    return (left + right) in ["()", "[]", "{}"]


def find_mismatch(text):
    opening_brackets_stack = []
    for i, next in enumerate(text):
        if next in "([{":
            opening_brackets_stack.append(Bracket(next,i))
            # Process opening bracket, write your code here

        if next in ")]}":
            if(len(opening_brackets_stack) == 0 or not are_matching(opening_brackets_stack[-1][0],next)):
                return i+1
            else:
                opening_brackets_stack.pop()
            # Process closing bracket, write your code here
    if(len(opening_brackets_stack) != 0):
        return opening_brackets_stack[0][1]+1
    else:
        return "Success"

def main():
    text = input()
    mismatch = find_mismatch(text)
    # Printing answer, write your code here
    print(mismatch)

if __name__ == "__main__":
    main()
