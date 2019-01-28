import sys
import time
import sys
import random
sys.setrecursionlimit(100000) # 10000 is an example, try with different values
ALGLOOPNUM = 50;

def Helper(algNum, x, y):

   timeList = []
   timeAv = 0

   for i in range(0,algNum): 

      start = time.clock()

      ackermann(x, y)

      timeList.append(time.clock() - start)
      timeAv += timeList[i]
      
      print("Algorithm Time: %f" %timeList[i])


   timeAv /= algNum
   print("\nAverage Algorithm Time: %f" %timeAv)
   #print(listBuff)


def ackermann(x, y):
  if(x<0 or y<0):
    return -1;
  if(x==0):
    return y+1;
  if(y==0):
    return ackermann(x-1,1);
  else:
    return ackermann(x-1, ackermann(x,y-1));

if len(sys.argv) != 3:
   print("ERROR: Include two integers")
   sys.exit(1)

Helper(ALGLOOPNUM, int(sys.argv[1]), int(sys.argv[2]))
