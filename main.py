
# A Python program to print all
# permutations using library function
from itertools import permutations
 
arr = [i for i in range(1, 1000)]
#print(arr)
perm = permutations(arr)
 
for i in list(perm):
   print (i)

              