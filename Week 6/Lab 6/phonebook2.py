people = [
    {"name": "Carter", "number": "+1-234-235-9872"},
    {"name": "David", "number": "+1-245-125-9332"},
    {"name": "John", "number": "+1-235-335-9892"},
]

name = input("Name: ").title()

for person in people:
    if person["name"] == name:
        print(f"Found {person['number']}")
        break
else:
    print("Not Found")
