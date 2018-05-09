import os
import random

NR_PROBLEMS = 145

if __name__ == "__main__":
    values = list(range(1, NR_PROBLEMS + 1))

    # exclude all the problems we have already made folders for
    created_projects = []
    for d in os.listdir(os.getcwd()):
        if os.path.isdir(d) and d != ".git":
            created_projects += [int(d)]

    for d in created_projects:
        if values.count(d) > 0:
            values.remove(d)

    print(random.choice(values))
