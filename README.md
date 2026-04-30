# 📚 Library Management System

## 📖 Overview

The **Library Management System** is a simple **console-based application** developed in **C++** that helps manage books and students in a library.
It allows the librarian to:

* ➕ Add new books
* 📋 View all books
* 👨‍🎓 Add students
* 📕 Issue books to students
* 📗 Return books

The system stores data in text files, making it easy to save and retrieve records.

---

## ✨ Features

### 1️⃣ Add Book

Allows the user to enter:

* 🆔 Book ID
* 📘 Book Title
* ✍️ Author Name

The book information is stored in **`books.txt`**.

---

### 2️⃣ View Books

Displays the list of all books with:

* 🆔 Book ID
* 📘 Title
* ✍️ Author
* 📌 Availability Status

Status values:

* ✅ **Available** → Book can be issued
* ❌ **Issued** → Book is already issued

---

### 3️⃣ Add Student

Allows the user to register a student by entering:

* 🆔 Student ID
* 👤 Student Name

The student information is stored in **`student.txt`**.

---

### 4️⃣ Issue Book

Issues a book to a student by:

* 🔍 Checking if the book is available
* ❌ Marking the book as issued
* 📝 Updating the student's issued books list

---

### 5️⃣ Return Book

Returns a previously issued book by:

* 🔄 Updating the book status back to available

---

## 🛠️ Technologies Used

* 💻 **Language:** C++
* 📂 **File Handling:** `fstream`
* 📦 **Data Structures:** `vector`
* 🔤 **String Processing:** `stringstream`

---

## 📁 Files Used

### 📘 `books.txt`

Stores book records in the format:

```bash id="a1"
BookID,Title,Author,Availability
```

Example:

```bash id="a2"
101,C++ Basics,Bjarne,1
```

Where:

* `1` = ✅ Available
* `0` = ❌ Issued

---

### 👨‍🎓 `student.txt`

Stores student records in the format:

```bash id="a3"
StudentID,StudentName,IssuedBooks
```

Example:

```bash id="a4"
201,John,101
```

---

## 🏗️ Class Structure

### 📘 `book` Class

Stores:

* 🆔 Book ID
* 📘 Title
* ✍️ Author
* 📌 Availability

Provides:

* 🔄 `tostring()` method to convert book details into file format

---

### 👨‍🎓 `student` Class

Stores:

* 🆔 Student ID
* 👤 Name
* 📚 Issued Books

Provides:

* 🔄 `tostring()` method to convert student details into file format

---

### 🏛️ `library` Class

Handles all library operations:

* ➕ `addbook()`
* 📋 `viewbooks()`
* 👨‍🎓 `addstudent()`
* 📕 `issuebook()`
* 📗 `returnbook()`

---

## ▶️ How to Run

### 1️⃣ Compile the Code

```bash id="a5"
g++ library.cpp -o library
```

### 2️⃣ Run the Program

```bash id="a6"
./library
```

---

## 📜 Menu Options

```bash id="a7"
==== LIBRARY MENU ====
1. Add Book
2. View Books
3. Issue Book
4. Return Book
5. Exit
```

---

## ⚠️ Limitations

This is a basic implementation and has some limitations:

* ❌ No delete book/student feature
* 🔍 No search functionality
* 🔄 Student issued books are not updated on return
* ⚠️ Minimal error handling
* 🗄️ Uses plain text files instead of a database

---

## 🚀 Future Enhancements

Possible improvements:

* 🔍 Add search book feature
* ✏️ Add delete/update records
* 📝 Maintain return records
* 🗄️ Use database integration (MySQL/SQLite)
* 🔐 Add login authentication
* 🎨 Improve user interface

---

## 🎯 Conclusion

This project demonstrates the basic concepts of:

* 💡 **Object-Oriented Programming**
* 📂 **File Handling**
* 📊 **Data Management using C++**

It is useful as a beginner-level mini project for understanding how a simple **Library Management System** works.

---
