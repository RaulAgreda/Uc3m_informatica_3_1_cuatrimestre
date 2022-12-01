
def generate_posibilities(all, k):
    _generate_posibilities(all, [None] * k, 0)

def _generate_posibilities(all, var_list , i):
    for val in (False, True):
        var_list[i] = val
        if i < len(var_list) - 1:
            _generate_posibilities(all, var_list, i + 1)
        else:
            all.append(var_list[:])


vars = {'p', 'q', 'r', 's'}
vars = {v: None for v in vars}

test = []
generate_posibilities(test, len(vars))

C1 = lambda p: p
C2 = lambda x, y: x or y
C3 = lambda x, y, z: x or y or z
C4 = lambda x, y, z, w: x or y or z or w

propositions = {}

for posib in test:
    print(posib)
# print(test)