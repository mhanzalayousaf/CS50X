pizzas = {
    "cheese": 9,
    "pepperoni": 10,
    "vegetable": 11,
    "buffalo chicken": 12,
}

for pie, price in pizzas.items():
    print("A whole {} pizza costs ${}".format(pie, price))
