class Person:
    def __init__(self, name, surname):
        self.name = name
        self.surname = surname

def main(p):
    full_name = lambda name, surname: f'Full name: {p.name}, {p.surname}'


if '__name__' == '__main__':
    main(Person("jo", "rge")

