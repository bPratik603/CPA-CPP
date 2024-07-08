import sys 

def merge(L, p, q, r): 
    """p <= p <= q < r < len(L)"""
    n1 = q - p + 1 
    n2 = r - q 
    L1 = [0 for i in range(n1)]
    L2 = [0 for i in range(n2)]
    for i in range(n1): 
        L1[i] = L[p+i] 
    for i in range(n2): 
        L2[i] = L[q+1+i] 
    i, j, k = 0, 0, 0 
    while True: 
        if L1[i] <= L2[j]: 
            L[p+k] = L1[i] 
            i += 1
            k += 1 
            if i == n1: 
                while j < n2: 
                    L[p+k] = L2[j]
                    j += 1 
                    k += 1 
                break 
        else: 
            L[p+k] = L2[j] 
            j += 1 
            k += 1 
            if j == n2: 
                while i < n1: 
                    L[p+k] = L1[i]
                    i += 1 
                    k += 1 
                break 
     
def merge_sort(L, p, r): 
    q = None 
    if p < r: 
        q = (p+r)//2
        merge_sort(L, p, q)
        merge_sort(L, q+1, r) 
        merge(L, p, q, r)

#--------------------------------------------------------
import random, time
print("USER DEFINED MERGE SORT")
L = [random.randint(0, 10000000) for i in range(1000000)]
print("LENGTH:", len(L))
#print("Before sort:", L)
t_start = time.time()
merge_sort(L, 0, len(L)-1)
t_end = time.time()
print(t_end-t_start)
#print("After sort:L:", L)
#--------------------------------------------------------
print("BUILT IN SORT")
L = [random.randint(0, 10000000) for i in range(1000000)]
print("LENGTH:", len(L))
#print("Before sort:", L)
t_start = time.time()
L.sort() 
t_end = time.time()
print(t_end-t_start)

"""
[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
0             p           q          r                           N-1

0 <= p <= q < r < N 
L[p...q] -> sorted 
L[q+1...r] -> sorted 
L[p...r]

10 20 30 40 50 
  15 25 35 45 55 
                    Nothing to do   if p = r 
M_sort(L, p, r) =   
                    q = (p+r//2)    

                    M_sort(L, p, q)

                    M_sort(L, q+1, r)

                    Merge(L, p, q, r)
[][][][][][][][] : M_sort 

[][][][]  [][][][] 

[][] [][]  [][] [][]

[] [] [] [] [] [] [] []
S   S

[][] [] [] [] [] [] []
S     S  S

[][]  [][]  [] [] [] []
S     S 

[][][][]  [] [] [] []
S         S  S

[][][][] [][] [] []
S         S    S S

[][][][]  [][]  [][]
S           S   S 

[][][][]    [][][][]
S           S 

[][][][][][][][]
S 
"""

""" 
import sys 
import random

def main(argc, argv): 
    if argc != 2: 
        print("Usage Error : %s number_of_elements" % argv[0])
        sys.exit(-1)

    n = int(argv[1])
    L = [random.randint(0, 10000000000) for i in range(n)]

    print("Before sort:")
    for i in range(len(L)): 
        print("L[%d]:%d" % (i, L[i]))
    
    merge_sort(L, 0, len(L)-1)
    
    print("After sort:")
    for i in range(len(L)): 
        print("L[%d]:%d" % (i, L[i]))

    sys.exit(-1)

main(len(sys.argv), sys.argv)
"""