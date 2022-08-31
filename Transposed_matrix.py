def koord(i, g):
    return (i // g)*g + i % g

def t_koord(i,j):
    return (i%j)*j + (i // j)
f = open("1.txt")
n, m = map(int, f.readline().split())
ind, znach = [], []
fff = []
ff = [ i.split() for i in f.readlines()]
for i in ff:
    fff += i
k = 0
for i in range(len(fff)):
    c = int(fff[i])
    k += 1
    if c != 0:
        ind.append(i)
        znach.append(c)
l = len(znach)
und = []
for i in range(l):
    h = ind[i]
    f, ff = h % m, h // m
    und.append(f*n + ff)

xnach = []
for i in znach:
    xnach.append(i)

for i in range(l):  # Создаем функцию range для всех чисел списка
    ma = float("inf")  # Создаем бесконечно большое число
    na = 0
    for s in range(i, l):  # Перебираем список от i до конца списка, сдвигая границу проверки
        if ma > und[s]:  # Ищем минимум в заданном промежутке, уменьшая m, если x[s] меньше
            ma = und[s]  # Отбираем минимум
            na = s  # Запоминаем индекс минимума
    p = und[i]
    und[i] = und[na]  # Меняем местами левую границу с минимальным элементом из промежутка
    und[na] = p
    pp = xnach[i]
    xnach[i] = xnach[na]
    xnach[na] = pp


k = 0
for i in range(m*n):
    if k < l and i == ind[k]:
        print(znach[k], '\t', end='')
        k += 1
    else:
        print(0, '\t', end='')
    if (m + i) % m == (m-1):
            print('\n')
print('_________________________________________________\n')


k = 0
for i in range(m*n):
    if k < l and i == und[k]:
        print(xnach[k], '\t', end='')
        k += 1
    else:
        print(0, '\t', end='')
    if (n + i) % n == (n-1):
            print('\n')

