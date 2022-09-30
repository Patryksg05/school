import time
from random import randint

for i in range(1,45):
    print('')

z = ''

for i in range(1,1000):
    licznik = randint(1,100)
    while (licznik > 0):
        z += ' '
        licznik -= 1

    if (i % 10 ==0):
        print(z + 'Happy New Year :)')
    else:
        print(z + '*')

    z = ''
    time.sleep(0.3)