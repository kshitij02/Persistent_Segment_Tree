import random

# n = number of integers you want to generate, x ** y denotes x^y
n =10**4
u = 5*(10**3)
# minimum and maximum possible value of random number generated
minn = 1
maxx = 10 ** 7

# first line containing the value of n
# print "n,q"
print(n)
l=n
choices = list(range(maxx))
random.shuffle(choices)
# print(choices.pop())
while l:
    print(choices.pop())
    l=l-1

print "max"
# print "q value"
for i in range(u):
	print "u "+str(i)+" "+str(random.randint(0, n-1))+" "+ str(random.randint(minn, maxx))

# for i in range(t):
# 	print "t "+str(i)
# for i in range(q):
# 	x=(random.randint(0,n-2))
# 	y=(random.randint(x+1,n-1))
# 	print "q "+str(i)+" "+str(x)+" "+str(y)

print "e"