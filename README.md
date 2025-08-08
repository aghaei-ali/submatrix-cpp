# submatrix_cpp

This C++ program checks if a smaller matrix B can be obtained from a larger matrix A by selecting rows and columns in order (they do not have to be adjacent).

## Input
rowA colA
rowB colB
<rowA * colA integers for A (row-major)>
<rowB * colB integers for B (row-major)>


## Output
```Prints exactly:
yes or no

Example:
Input:

6 6
3 3
1 2 3 4 5 6
7 8 9 1 2 3
4 5 6 7 8 9
9 8 7 6 5 4
3 2 1 4 3 8
9 5 4 7 2 3
8 1 3
8 6 4
5 7 3

Output:
yes

![Demo](images/demo.png)
