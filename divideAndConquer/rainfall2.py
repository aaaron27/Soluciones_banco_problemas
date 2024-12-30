from math import sqrt

L, K, T1, T2, H = map(float, input().split())

if H < L:
    print(f"{H} {H}")
else:
    # ax^2 + bx + c
    a = T1
    b = -(T1 * K + T2 * K + H)
    c = L * K

    # formula general
    x_1 = (-b + sqrt(b * b - 4 * a * c)) / 2
    x_2 = (-b - sqrt(b * b - 4 * a * c)) / 2

    if x_2 < H:
        x_2 = x_1

    minimo = min(x_1, x_2)
    if H == L:
        minimo = H
    maximo = max(x_1, x_2)
    print(f"{minimo} {maximo}")
