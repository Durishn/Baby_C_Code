import sys
import time
import sys
import random
sys.setrecursionlimit(100000) # 10000 is an example, try with different values
ALGLOOPNUM = 50;

def quickSortHelper(algNum, alist):

   timeList = []
   timeAv = 0

   for i in range(0,algNum): 

      listBuff = list(alist)

      start = time.clock()

      quickSort(listBuff,0,len(listBuff)-1)

      timeList.append(time.clock() - start)
      timeAv += timeList[i]
      
      print("Algorithm Time: %f" %timeList[i])


   timeAv /= algNum
   print("\nAverage Algorithm Time: %f" %timeAv)
   #print(listBuff)


def quickSort(alist,first,last):
   if first<last:
       splitpoint = partition(alist,first,last)
       quickSort(alist,first,splitpoint-1)
       quickSort(alist,splitpoint+1,last)


def partition(alist, first, last):
   pivotvalue = alist[last]
   leftmark = first - 1

   for rightmark in range( first, last ):
      if alist[rightmark] <= pivotvalue:
         leftmark = leftmark + 1
         temp = alist[leftmark]
         alist[leftmark] = alist[rightmark]
         alist[rightmark] = temp
 
   temp = alist[last]
   alist[last] = alist[leftmark+1]
   alist[leftmark+1] = temp
   return leftmark+1

if len(sys.argv) != 2:
   print("ERROR: Include a filename")
   sys.exit(1)

f = open(sys.argv[1])
intList = []
with open(sys.argv[1]) as f:
   for line in f:
      data = line.split()
      intList.append(int(data[0]))

quickSortHelper(ALGLOOPNUM, intList)
