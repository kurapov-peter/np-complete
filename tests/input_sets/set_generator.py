import sys
import random

if len(sys.argv) > 1:
	setlen = int(sys.argv[1])
	lowborder = int(sys.argv[2])
	upborder = int(sys.argv[3])
else:
	setlen = random.randint(0, 100)
	lowborder = random.randint(-1000, 1000)
	upborder = random.randint(lowborder, 1000)

print(setlen)
for i in range(setlen):
	print(random.randint(lowborder, upborder))


