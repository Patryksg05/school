import random

lower_case = 'abcdefgihijklmnoprstwuxyz'
upper_case = 'ABCDEFGHIJKLMNOPRSTWUXYZ'
numbers = '0123456789'
symbols = '!@#$%&?'

sum = lower_case + upper_case + numbers + symbols
lenght = int(input("Lenght of password: "))

password = "".join(random.sample(sum, lenght))
print("Your password: " + password)
