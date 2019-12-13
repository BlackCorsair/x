def digitAt(number, position):
    """
        first the base condition
        if the position is 1, we return the
        first number at the left
    """
    if position == 1:
        return number % 10

    """
        general case: position 4
        digitAt(123456, 4) should return 3

        general case: position 3
        digitAt(12345, 3) should return 3

        general case: position 2
        digitAt(1234, 2) should return 3

        ...
    """
    return digitAt(int(number / 10), position - 1)

