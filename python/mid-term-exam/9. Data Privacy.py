class Library:
    book_list = []

    @classmethod
    def entry_book(cls, book):
        cls.book_list.append(book)


class Book:
    def __init__(self, book_id, title, author, availability):
        self.__book_id = book_id
        self.__title = title
        self.__author = author
        self.__availability = availability
        Library.entry_book(self)

    def borrow_book(self):
        if self.__availability:
            self.__availability = False
            print(f"The book '{self.__title}' has been borrowed.")
        else:
            print(f"Sorry, the book '{self.__title}' is currently unavailable.")

    def return_book(self):
        if not self.__availability:
            self.__availability = True
            print(f"The book '{self.__title}' has been returned.")
        else:
            print(f"The book '{self.__title}' was not borrowed.")

    def view_book_info(self):
        print(f"\nBook ID: {self.__book_id}")
        print(f"Title: {self.__title}")
        print(f"Author: {self.__author}")
        print(f"Availability: {self.__availability}")

    def get_book_id(self):
        return self.__book_id

    def get_title(self):
        return self.__title

    def get_author(self):
        return self.__author

    def get_availability(self):
        return self.__availability


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
                if book.get_book_id() == book_id:
                    found = True
                    book.borrow_book()
                    break
            if not found:
                print(f"Error: Book with ID {book_id} not found.")

        elif choice == "3":
            book_id = input("Enter the Book ID to return: ")
            found = False
            for book in Library.book_list:
                if book.get_book_id() == book_id:
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