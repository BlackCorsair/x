def reverseNumber(number):
    """
        base case
        reverseNumber(1) = 1
    """
    if number < 10:
        return number

    """
        general case
        reverseNumber(123) == 321

        general case closer to base case
        reverseNumber(12) = 21

        general case closer to base
        reverseNumber(1) = 1
    """
    return concatenate(number % 10, reverseNumber(int(number / 10)))


def concatenate(x, y):
    upow = 10
    while y >= upow:
        upow *= 10
    return x * upow + y
