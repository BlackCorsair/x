class Pata:
    def __init__(self, largo, ancho, material):
        self.largo = largo
        self.ancho = ancho
        self.material = material

    def describe_me(self):
        print("tengo un ancho: {}, y largo: {}"
              .format(self.ancho, self.largo))

    def saludar(self):
        print("hola, soy una pata!")

    def ancho_por_largo(self):
        return self.ancho * self.largo


pata_derecha = Pata(3.0, 4, "madera")
pata_izquierda = Pata(9, 6.6, pata_derecha)


pata_derecha.describe_me()
pata_izquierda.describe_me()

print("ancho x largo: {}".format(pata_izquierda.ancho_por_largo()))
print("Hello world")
