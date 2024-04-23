books = []

# Add three books to shelf
for _ in range(3):
    book = dict()
    book["author"] = input("Enter an author: ")
    book["title"] = input("Enter a title: ")
    books.append(book)

# Print list of books
for book in books:
    print(f"{book['author']} wrote {book['title']}.")
