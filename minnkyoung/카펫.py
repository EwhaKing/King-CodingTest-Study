def solution(brown, red):
    for row in range(1, int(red**0.5) + 1):
        if red%row == 0:
            col = red//row
            if 2 * row + 2 * col + 4 == brown:
                return [col + 2, row + 2]