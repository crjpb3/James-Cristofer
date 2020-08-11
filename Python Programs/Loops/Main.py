#Cristofer James
#August 11, 2020
#Working with loops in Python

for x in range(10):
    print(x + 1, end=" ")
print()

y = int(input("Enter a number between 1 and 100: "))

for x in range(y):
    print(x + 1, end=" ")
print()
print("Finished counting to", y)

print()
correct_num = 47
guess_num = int(input("Guess the number between 1 and 50: "))

while not guess_num == correct_num:
    print("Incorrect guess")
    print()
    guess_num = int(input("Guess the number between 1 and 50: "))
print("Correct! The number was ", correct_num)
print()

cont_num = 1
user_input = int(input("Enter '1' to continue or any other key to quit: "))

while user_input == 1:
    user_input = int(input("Enter '1' to continue or any other key to quit: "))

print("The loop has ended.")
print()