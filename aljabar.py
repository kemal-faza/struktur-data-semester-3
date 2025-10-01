import math


def diskriminan(a: int, b: int, c: int) -> int:
    return b**2 - 4 * a * c


def akar_plus(a: int, b: int, c: int) -> float:
    return abs((-b + math.sqrt(diskriminan(a, b, c))) / (2 * a))


def akar_minus(a: int, b: int, c: int) -> float:
    return abs((-b - math.sqrt(diskriminan(a, b, c))) / (2 * a))


def angka_terkecil(a: int, b: int, c: int) -> float:
    return min(akar_plus(a, b, c), akar_minus(a, b, c))


def angka_terbesar(a: int, b: int, c: int) -> float:
    return max(akar_plus(a, b, c), akar_minus(a, b, c))


def Aljabar(a: int, b: int, c: int) -> float:
    if diskriminan(a, b, c) < 0:  # imajiner
        return -999
    elif angka_terbesar(a, b, c) == 0:
        return 0.0
    else:
        return round(angka_terkecil(a, b, c) / angka_terbesar(a, b, c), 5)
