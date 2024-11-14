# C++ final 
Jonah Marchi, Joseph Pipia, Paul Allen

Comp Sci 371: Advanced Object-oriented Design
Group Project
Full Mark: 100
Code Submission Deadline: 10 December, 2024
Advanced Bank Management System
Objective: To develop a C++ object-oriented program to implement a bank management
system.
Project Overview:
Your task is to develop a Bank Management System in C++ that encompasses
user accounts, manager accounts, transactions, and a login system. The system
involves three main classes: User, Transaction, and BankAccount. Additionally,
there is a special class for bank managers.
The following are the main requirements of this project. You are allowed to
implement as many classes as you want to fulfill the following
requirements.
Requirements:
• Implement a class to manage user bank accounts, including methods to create
and delete users, load user's information from a file, and handle user logins. A
typical bank account should have attributes such as account number, account
type, balance, and customer information. This class will include a static data
member to keep track of the number of active accounts currently held by the
bank.
• User login information and account information should be stored in the users.txt
file.
• Create a class to manage banking accounts, allowing users to perform actions
like withdrawal, deposit, and printing account summaries.
o The Withdraw function verifies the availability of funds and deducts a
specified amount from the user's account. If there are insufficient funds,
the user is promptly notified with an error message.
o Deposit enables the user to inject a specified amount of money into their
account.
o PrintAccountSummary exhibits the user's comprehensive transaction
history along with their present account balance.
• Develop a specialized class for bank managers, providing login functionality and
access to all user data.
• The login data for managers is stored in managers.txt. No class will have the
capability to create a manager account; instead, the manager's name and
password must be manually inserted into the managers.txt file. Initially, the first
names of you and your group members, along with their corresponding
passwords, will be stored inside managers.txt.
Your program should start with the following options:
1. User Login
2. Create Account
3. Manager Login
4. Exit
For any further clarification, please contact your instructor.
Your code and its functionality will be evaluated according to the following criteria
✓ Use of an Abstract Class 5 marks
✓ Use of classes, objects, constructors (default, parametric, copy) 10 marks
✓ Use of a static member to the account class 5 marks
✓ Use of Encapsulation, Polymorphism, Inheritance 10 marks
✓ Use of pointers 5 marks
✓ File, memory management 5 marks
✓ Correctly working program 10 marks
Rubrics
Your code and its correct functionalities 50
Report 20
Presentation 25
Peer Review 5
Functionalities
You need to implement the topics, concepts, and syntax that we covered in class. Examples include
pointers, class definitions, header files, encapsulation, polymorphism, inheritance, File I/O, and strings.
Report
You are required to submit a comprehensive report detailing your project implementation,
methodology, inputs/outputs, and any insights gained throughout the development process. The report
should be structured and formatted in a professional manner. You can follow the guidelines provided
below:
1. Introduction
2. Methodology
o Describe the approach you took to design and implement your project.
o Explain the data structures, and programming techniques used.
3. Implementation Details:
o Provide a detailed explanation of how you implemented the project.
o You can use UML, detailed class design, attributes, and class behaviors here to
describe your project.
o Discuss any challenges encountered and how you addressed them.
o Include code snippets or pseudocode to illustrate key components of your
implementation.
4. Input/Output
o Provides inputs and outputs of your project which help to test all features of your
project.
5. Conclusion:
o Summarize the project, key findings, and insights gained from your project.
6. References:
7. Appendices (Code):
o Add the entire code of your project.
Presentation
In Weeks 13-14, you will present your project during the class hour. Each group will have approximately
15-20 minutes for their presentation. This will consist of 12-15 minutes for the presentation itself and 5
minutes for answering questions. Your presentation slides should include information on how you fulfill
the project requirements, such as the utilization of pointers or inheritance in your project, along with
the corresponding code implementation. You should clearly indicate which group member wrote which
specific parts of the code in your program. During the presentation, you'll be asked to run your code and
conduct a code walk-through, with each member presenting the sections they implemented.
