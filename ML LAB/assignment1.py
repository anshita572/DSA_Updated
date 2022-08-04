import numpy as np
arr=np.array([1,2,3,6,4,5])
print(arr)
#reverse an array
ans=np.flip(arr)
print(ans)
#flattening any dimension array means it will become a 1D array
A=np.array([[1,2,3],[2,4,5],[1,2,3]])
#M1
B=A.flatten()
print(B)
#M2
C=A.ravel()
print(C)
#comparison
a = np.array([101, 99, 87])
b = np.array([897, 97, 111])
 
print("Array a: ", a)
print("Array b: ", b)
 
print("a > b")
print(np.greater(a, b))
 
print("a >= b")
print(np.greater_equal(a, b))
 
print("a < b")
print(np.less(a, b))
 
print("a <= b")
print(np.less_equal(a, b))
#frequency
x = np.array([1,2,3,4,5,1,2,1,1,1])
freq=np.bincount(x)
print("frequency of each element"+freq)