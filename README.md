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
Peer review report
In the peer review report, you will be covering the challenges you faced to finish the project including
the approaches you followed to address these challenges. This will also include your comments on group
member’s participation and cooperation.
Each student will evaluate their group members using the criteria below:
• On a scale of 1 to 4, rate your teammate on the effort she/he put into researching and developing
the project.
1. The student did not collect any information that relates to the research topic following the
rubrics presented earlier.
2. The student collected very little information relating to the research topic following the rubrics
presented earlier.
3. The student collected a reasonable amount of information and most of it is related to the
research topic following the rubrics presented earlier.
4. The student collected a great deal of information and all of it is related to the research topic
following the rubrics presented earlier.
• On a scale of 1 to 4, rate your teammate on how well he/she shares information and code with the
group.
1. The student did not relay any information to other teammates.
2. The student relayed very little information that related to the research topic to other
teammates.
3. The student relayed some information and most of it was related to the research topic.
4. The student relayed a great deal of information and all of it related to the research topic.
• On a scale of 1 to 4, rate your teammate on how well he/she performs their duties relating to the
project.
1. Did not perform any duties of the assigned team role.
2. Performed very few duties.
3. Perform nearly all duties.
4. Performed all the duties assigned.
• On a scale of 1 to 4, rate your teammate on how well he/she shared the workload.
1. Always relied on others to do the work.
2. Rarely did the assigned work – often needed reminding.
3. Usually did the assigned work – rarely needed reminding.
4. Always did the assigned work without having to be reminded.
• On a scale of 1 to 4, rate your teammate on how well he/she attended meetings or communicated
with group members.
1. Missed most group meetings. Did not respond to any communications.
2. Frequently missed group meetings and frequently responded to team members.
3. Attended most of the meetings. Responded in a couple of days to any communication.
4. Attended all group meetings. Responded to emails in a reasonable time.
Besides these grading, please include any comments and reviews you may have on group work and
group members.
