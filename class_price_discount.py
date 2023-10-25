class Product:
    def __init__(self, name, price):
        self.name = name
        self.price = price

    def __str__(self):
        return f"Product: {self.name}, Price: {self.price}"

    def apply_discount(self, discount):
        self.price = self.price * (1 - discount)


class ThirdClass(Product):
    def __init__(self, name, price, category):
        super().__init__(name, price)
        self.category = category

    def __str__(self):
        return f"{super().__str__()}, Category: {self.category}"


product1 = ThirdClass("Phone", 1000, "Electronics")
print(product1)

product1.apply_discount(0.2)
print(product1)
