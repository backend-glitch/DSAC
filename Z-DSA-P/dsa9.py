# UGLY number
num = 6

if num < 0:
    print("not valid")

for i in [2,3,5]:
    while num%i == 0:
        num = num//i

if num == 1:
    print("yes")
else:
    print("no")

        