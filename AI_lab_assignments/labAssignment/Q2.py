#from turtle import pos
import copy
from heapq import heappush, heappop
def enqueue(a):
    global q
    q=q+[a]
def dequeue(g):
    global q
def heuristic(a,g):
    d=0
    for i in range(3):
        for j in range(3):
            if a[i][j]!=g[i][j]:
                d+=1


def down(a,pos)
i,j=pos
if i<2:
    t=copy.deepcopy(a)
    t[i][j]=t[i+1][j]
    t[i+1][j]=0
    return (t)
    else:
        return(a)

