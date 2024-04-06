### QUESTION ONE
#### Case Study: MoMo Pin Generation & Cracking
People are using mobile money to receive and send money, the security of their money depends on the PIN (Personal Identification Number). John is interested in finding all possible combinations of PINs that are used by MoMo clients. 

#### Business Rules:
- Each PIN is a five digit number
- Each digit slot has an equal possibility of being occupied by 10 digits [from 0 to 9 all inclusive].

#### Expected Tasks:
##### Part I: Write a program that completes the following tasks:
- You will generate all PINs satisfying the business rules.
- All generated PINs will be recorded in a file named generated_passwords.txt in the same directory as the executing program.

##### Part II: Write a program that completes the following tasks
- John is interested in testing weakness of different PINs in such a way that the PIN is feed to the program and the program compare that PIN against all PINs stored in the generated_passwords.txt.
- The program will generate the probability of finding that PIN in the file. Hint: Consider the number of iterations to access the PIN John feed to the system to test against the total number of all possible iterations in the file.
