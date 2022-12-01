from constraint import *

problem = Problem()

dests = {'to', 'sg', 'sa', 'pa'}

k = 3

vars = set()
for d in dests:
    for i in range(1, k+1):
        vars.add((d, i))
        problem.addVariable((d, i), [True, False])

for d in dests:
    problem.addConstraint(lambda x, y, z: x or y or z, ((d, 1), (d, 2), (d, 3)))

for d in dests:
    for i in range(1, k):
        for j in range(i+1, k+1):
            problem.addConstraint(lambda x, y: not x or not y, ((d, i), (d, j)))

for i in range(1, k + 1):
    problem.addConstraint(lambda x, y: not x or not y, (('sa', i), ('pa', i)))
    problem.addConstraint(lambda x, y: not x or not y, (('sa', i), ('to', i)))
    problem.addConstraint(lambda x, y: not x or not y, (('sg', i), ('to', i)))

solutions = problem.getSolutions()

for s in solutions:
    for p in s:
        if s[p]:
            print(p, end=' ')
    print()

