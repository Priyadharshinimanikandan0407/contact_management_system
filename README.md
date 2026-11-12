# contact_management_system
A C-based Contact Management System comparing BST, AVL Tree, and Hashing using Linear Probing for efficient contact storage and searching.
📞 Contact Management System

📌 Project Overview

The Contact Management System is a C programming project developed using three different data structures: Binary Search Tree (BST), AVL Tree, and Hashing with Linear Probing.

This project is designed to store, manage, and search contact details efficiently. It compares the performance of three data structures to identify which one is more suitable for contact management.

🎯 Objectives

- To develop a Contact Management System using C.
- To understand different data structures.
- To implement insertion and searching operations.
- To compare BST, AVL Tree, and Hashing.
- To analyze searching performance and efficiency.
- To identify the best data structure for contact management.

🛠️ Technologies Used

- Programming Language: C
- Compiler: GCC
- Platform: Code::Blocks / VS Code
- Version Control: GitHub

📂 Project Structure

Contact-Management-System/
│
├── bst.c
├── avl.c
├── hashing.c
└── README.md

📚 Data Structures Implemented

1. Binary Search Tree (BST)

A Binary Search Tree stores contact records based on Contact ID.

Features:

- Insertion of contacts.
- Searching for contacts.
- Displaying contacts using inorder traversal.
- Displaying tree height.

2. AVL Tree

An AVL Tree is a self-balancing Binary Search Tree that maintains balance after insertion.

Features:

- Insertion of contacts.
- Searching for contacts.
- Automatic tree balancing.
- LL, RR, LR, and RL rotations.
- Displaying tree height.

3. Hashing Using Linear Probing

Hashing stores contact records using a hash function to calculate their storage positions.

Hash Function:

"h(key) = key % TABLE_SIZE"

Features:

- Insertion of contacts.
- Searching for contacts.
- Collision handling using Linear Probing.
- Displaying stored contacts.
- Counting total collisions.

📋 Contact Details Stored

Each contact contains:

- Contact ID
- Contact Name
- Phone Number
- Email Address

⚙️ Operations Performed

1. Insert a new contact.
2. Search for an existing contact.
3. Display all contacts.
4. Measure searching comparisons.
5. Calculate tree height.
6. Count hash collisions.

▶️ How to Run the Project

Step 1: Clone the Repository

git clone YOUR_GITHUB_REPOSITORY_URL

Step 2: Open the Project Folder

cd Contact-Management-System

Step 3: Compile the Programs

BST:

gcc bst.c -o bst

AVL Tree:

gcc avl.c -o avl

Hashing:

gcc hashing.c -o hashing

Step 4: Execute the Programs

BST:

./bst

AVL Tree:

./avl

Hashing:

./hashing

Note: On Windows, use "bst.exe", "avl.exe", and "hashing.exe" to execute the compiled programs.

📊 Performance Comparison

Parameter| BST| AVL Tree| Hashing
Insertion| O(log n) average| O(log n)| O(1) average
Searching| O(log n) average| O(log n)| O(1) average
Worst-case searching| O(n)| O(log n)| O(n)
Self-balancing| No| Yes| Not applicable
Collision handling| Not required| Not required| Linear Probing
Sorted traversal| Yes| Yes| No

🧪 Experimental Analysis

The following experiments are performed using the same contact dataset:

- Successful Search
- Unsuccessful Search
- Contact Insertion
- Tree Height Calculation
- Collision Counting

The performance of all three data structures is compared using experimental observations.

🏆 Final Verdict

Hashing with Linear Probing is expected to provide better average searching performance for a Contact Management System because it offers O(1) average-time searching.

AVL Tree provides guaranteed O(log n) searching and maintains balanced structure.

BST is simple to implement but may become unbalanced depending on the insertion order.

Therefore, Hashing is recommended when fast contact retrieval is the main requirement.

🚀 Future Enhancements

- Add contact deletion.
- Update existing contact details.
- Search contacts by name.
- Add a graphical user interface.
- Store contact details permanently using a database.
- Add sorting and filtering options.

📖 Conclusion

This project demonstrates the practical application of BST, AVL Tree, and Hashing in a Contact Management System. By implementing and comparing these data structures, we understand their performance, advantages, and limitations in real-world applications.

👩‍💻 Project Information

Project Name: Contact Management System

Programming Language: C

Domain: Data Structures

Project Type: Academic Assignment

Submitted By: Priyadharshini M

Repository: Contact-Management-System
