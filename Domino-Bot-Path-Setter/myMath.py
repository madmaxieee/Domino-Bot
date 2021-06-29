def cross(O: list, A: list, B: list):
    return (A[0] - O[0]) * (B[1] - O[1]) - (A[1] - O[1]) * (B[0] - O[0])


def intersect(A1: list, A2: list, B1: list, B2: list):
    c1 = cross(A1, A2, B1)
    c2 = cross(A1, A2, B2)
    c3 = cross(B1, B2, A1)
    c4 = cross(B1, B2, A2)

    if c1 * c2 < 0 and c3 * c4 < 0:
        return True

    if c1 == 0 and intersect(A1, A2, B1):
        return True
    if c2 == 0 and intersect(A1, A2, B2):
        return True
    if c3 == 0 and intersect(B1, B2, A1):
        return True
    if c4 == 0 and intersect(B1, B2, A2):
        return True

    return False
