class greeter:
    def greet(self, toBeGreeted):
        print("Hello {}".format(toBeGreeted))


class worldGreeter(greeter):
    def __init__(self):
        self.toBeGreeted = "World"

    def greet(self):
        super().greet(self.toBeGreeted)


if __name__ == '__main__':
    worldGreeter().greet()
