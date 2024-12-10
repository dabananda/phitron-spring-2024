class Library:
    book_list = []

    @classmethod
    def entry_book(cls, book):
        cls.book_list.append(book)


class Book:
    def __init__(self, book_id, title, author, availability):
        self.book_id = book_id
        self.title = title
        self.author = author
        self.availability = availability
        Library.entry_book(self)

    def borrow_book(self):
        if self.availability:
            self.availability = False
            print(f"The book '{self.title}' has been borrowed.")
        else:
            print(f"Sorry, the book '{self.title}' is currently unavailable.")

    def return_book(self):
        if not self.availability:
            self.availability = True
            print(f"The book '{self.title}' has been returned.")
        else:
            print(f"The book '{self.title}' was not borrowed.")

    def view_book_info(self):
        print(f"\nBook ID: {self.book_id}")
        print(f"Title: {self.title}")
        print(f"Author: {self.author}")
        print(f"Availability: {self.availability}")


def menu():
    while True:
        print("\n1. View All Books")
        print("2. Borrow Book")
        print("3. Return Book")
        print("4. Exit")

        choice = input("Choose an option: ")

        if choice == "1":
            if Library.book_list:
                print("\nList of Books:")
                for book in Library.book_list:
                    book.view_book_info()
            else:
                print("No books available.")

        elif choice == "2":
            book_id = input("Enter the Book ID to borrow: ")
            found = False
            for book in Library.book_list:
                if book.book_id == book_id:
                    found = True
                    book.borrow_book()
                    break
            if not found:
                print(f"Error: Book with ID {book_id} not found.")

        elif choice == "3":
            book_id = input("Enter the Book ID to return: ")
            found = False
            for book in Library.book_list:
                if book.book_id == book_id:
                    found = True
                    book.return_book()
                    break
            if not found:
                print(f"Error: Book with ID {book_id} not found.")

        elif choice == "4":
            print("Successfully exited.")
            break

        else:
            print("Invalid choice! Please enter a number between 1 and 4.")


book1 = Book("101", "Book 01", "Author 01", True)
book2 = Book("102", "Book 02", "Author 02", True)
book3 = Book("103", "Book 03", "Author 03", True)
book4 = Book("104", "Book 04", "Author 04", True)
book5 = Book("105", "Book 05", "Author 05", True)

menu()
