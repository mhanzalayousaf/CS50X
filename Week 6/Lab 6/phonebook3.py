people = {
    "Carter" : "+1-234-235-9872",
    "David" : "+1-245-125-9332",
    "John" : "+1-235-335-9892",
}

name = input("Name: ").title()

if name in people:
    print(f"Found {people[name]}")
else:
    print("Not Found")
