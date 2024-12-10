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

    def return_book(self):
        if not self.availability:
            self.availability = True

    def view_book_info(self):
        print(f"Book id: {self.book_id}")
        print(f"Title: {self.title}")
        print(f"Author: {self.author}")
        print(f"Availability: {self.availability}")