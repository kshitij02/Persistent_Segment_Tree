import random

# n = number of integers you want to generate, x ** y denotes x^y
n =10**2
q=10**1
# minimum and maximum possible value of random number generated
minn = 1
maxx = 10 ** 7

# first line containing the value of n
# print "n,q"
print(n)
print(q)
l=n
choices = list(range(maxx))
random.shuffle(choices)
# print(choices.pop())
while l:
    print(choices.pop())
    l=l-1

# print "q value"
for i in range(q):
	x=(random.randint(0,n-1))
	y=(random.randint(x+1,n-1))
	z=(random.randint(1,y-x))
	print str(x)+" "+str(y)+" "+str(z)
