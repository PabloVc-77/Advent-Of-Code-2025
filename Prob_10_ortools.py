from ortools.sat.python import cp_model
import sys


def decode(line):
    inibuttons = line.index(']')
    finbuttons = line.index('{')
    text_buttons = line[inibuttons + 1:finbuttons].split()
    buttons = []

    for b in text_buttons:
        values = list(map(int, b[1:-1].split(',')))
        buttons.append(values)

    endstate = list(map(int, line.rstrip()[finbuttons+1:-1].split(',')))

    return endstate, buttons


def star2(endstate, buttons):
    model = cp_model.CpModel()

    enteornoVar = []
    for i in range(len(buttons)):
        # Variables para el entorno (val, max, name)
        enteornoVar.append(model.NewIntVar(0, pow(10, 9), f'x{i}'))

    for i in range(len(endstate)):
        involved = []
        for j in range(len(buttons)):
            if i in buttons[j]:
                involved.append(enteornoVar[j])
        model.Add(sum(involved) == endstate[i])

    model.Minimize(sum(enteornoVar))

    solver = cp_model.CpSolver()

    solver.Solve(model)

    return sum([solver.Value(x) for x in enteornoVar])


def main(lines):
    res = 0
    for i, (ends, buttons) in enumerate(lines):
        print("Line: " + str(i) + " Procesada")
        res += star2(ends, buttons)
    print(str(res))

# Start venv: ./venv/Script/Activate.ps1
# Execute like:  Get-Content input.txt | python program.py
if __name__ == '__main__':
    lines = []
    for line in sys.stdin: 
        if line.strip():
            lines.append(decode(line))

    main(lines)
