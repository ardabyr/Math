from string import ascii_lowercase as asc
from itertools import product as pr
def printt(m, r):
    print(' ', *asc[:r].strip())
    for i in range(r):
        print(asc[i], *(m[i]))


razmer = int(input("Введите размер матрицы: "))
matrica = [[]]*razmer
for element in range(len(matrica)):
    vvod = input("Введите элементы: ").split()
    matrica[element] = [int(i) for i in vvod]
# bukv = [asc[i] for i in range(razmer) ]
yravn = []
yravn_1 = []
zn = {}
for i in range(razmer):
    zn[asc[i]] = 0
for i in range(razmer):
    for j in range(razmer):
        if asc[i] == asc[j]:
            continue
        else:
            if matrica[i][j] == 1:
                v = [asc[i], asc[j]]
                kk = 0
                for k in range(len(yravn)):
                    if yravn[k] == v[::-1]:
                        kk = 1
                        break
                    else:
                        continue
                if kk == 0:
                    yravn.append(v)
                    yravn_1.append(f"({asc[i]} + {asc[j]})")
                zn[asc[i]] += 1

print("Ваша булева матрица графа: ")
printt(matrica, razmer)
print("Подставим в F ")
print(*yravn_1, sep='*', end=' = 1\n')
sp = []
k = ''
for i in range(len(yravn)-1):
    k += yravn[i][1]
    if yravn[i][0] == yravn[i+1][0]:
        if i + 2 == len(yravn):
            k += yravn[-1][1]
            sp.append([yravn[i][0], k])
        continue
    else:
        sp.append([yravn[i][0], k])
        if i + 2 == len(yravn):
            sp.append([yravn[i+1][0], yravn[-1][1]])
        k = ''
sp_1 = []
for si in sp:
    sp_1.append(f"({si[0]} + {si[1]})")
print("Упрощая, получим: ")
print(*sp_1, sep='*', end=" = 1\n")
fn = []

dd = "01"
for i in pr(dd, repeat=len(sp)):
    i = list(i)
    kk = set()
    l = ''
    n = 0
    for j in i:
        l += (sp[n][int(j)])
        n += 1
    for sim in l:
        kk.add(sim)

    fn.append(sorted(list(kk)))
fn_1 = fn[:]
for sin in fn_1:
    if fn.count(sin) == 1:
        continue
    else:
        fn.remove(sin)

fn = [set(i) for i in fn]
fn_1 = fn[:]
for i in range(len(fn_1)):
    for j in range(len(fn_1)):
        if j == i:
            continue
        else:
            if fn_1[i] <= fn_1[j]:
                if fn_1[j] in fn:
                    fn.remove(fn_1[j])

fn = [sorted(list(i)) for i in fn]

std = {asc[i] for i in range(razmer)}
pfn = []
for i in range(len(fn)):
    k = '('
    for j in range(len(fn[i])):
        k += fn[i][j]
    k += ')'
    fn[i] = k
    pfn.append(set(list(std.difference(set(fn[i])))))
print("Или \n")
print(*fn, sep="+", end=" = 1\n")

print(f"Таким образом, граф обладает {len(pfn)} максимальными внутренне устойчивыми подмножествами: \n")
print(*pfn, sep=', ')



