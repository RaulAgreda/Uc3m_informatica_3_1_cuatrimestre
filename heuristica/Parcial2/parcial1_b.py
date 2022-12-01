from constraint import *

k = 2

problem = Problem()

dests = {'to', 'sg', 'sa', 'pa'}

vars = {}
for d in dests:
    vars[d] = list(range(1, k+1))
    problem.addVariable(d, vars[d])

problem.addConstraint(lambda x, y: x != y, ('sa', 'pa'))
problem.addConstraint(lambda x, y: x != y, ('sa', 'to'))
problem.addConstraint(lambda x, y: x != y, ('sg', 'to'))

solutions = problem.getSolutions()

for s in solutions:
    print(s)

