#include <iostream>

using namespace std;

int rolumn[2][100] = {};

void getArr(int arr[][100], int row, int column);

bool subMatrixx(const int arr1[][100], const int row1, const int column1,
                const int arr2[][100], const int row2, const int column2,
                int column, int counter1, int counter2);

bool subMatrixy(const int arr1[][100], const int row1, const int column1,
                const int arr2[][100], const int row2, const int column2,
                int row, int counter1, int counter2);

bool subMatrix(const int arr1[][100], const int row1, const int column1,
               const int arr2[][100], const int row2, const int column2); // should be fix

int main()
{
    int row1, column1, row2, column2;

    int arr1[100][100], arr2[100][100];

    //cout << "row1 :";
    cin >> row1;
    //cout << "column1 :";
    cin >> column1;
    //cout << "row2 :";
    cin >> row2;
    //cout << "column2 :";
    cin >> column2;

    getArr(arr1, row1, column1);
    getArr(arr2, row2, column2);

    for (int i = 0; (i + row2 - 1) < row1; i++)
    {
        if (subMatrixx(arr1, row1, column1, arr2, row2, column2, 0, i, 0))
        {
            cout << "yes";
            return 0;
        }
    }
    cout << "no";

    return 0;
}

void getArr(int arr[][100], int row, int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            cin >> arr[i][j];
}

// row and column move in arr2
// counter1 and counter 2 move in arr1

// use subMatrixx in : for (int i = counter1; (i + (row2 - row - 1)) < row1 ; i++)

bool subMatrixx(const int arr1[][100], const int row1, const int column1,
                const int arr2[][100], const int row2, const int column2,
                int column, int counter1, int counter2)
{
    for (int j = counter2; (j + column2 - column - 1) < column1; j++)
    {
        if (arr1[counter1][j] == arr2[0][column])
        {
            rolumn[1][column] = j;
            if (column == (column2 - 1))
            {
                if(subMatrixy(arr1, row1, column1, arr2, row2, column2, 0, counter1, rolumn[1][0]))
                    return true;
            }
            else
                if(subMatrixx(arr1, row1, column1, arr2, row2, column2, column + 1, counter1, j + 1))
                    return true;
        }
    }

    return false;
}

bool subMatrixy(const int arr1[][100], const int row1, const int column1,
                const int arr2[][100], const int row2, const int column2,
                int row, int counter1, int counter2)
{
    for(int i = counter1; (i + row2 - row - 1) < row1; i++)
    {
        if(arr1[i][counter2] == arr2[row][0])
        {
            rolumn[0][row] = i;
            if(row == (row2 - 1))
            {
                if(subMatrix(arr1, row1, column1, arr2, row2, column2))
                    return true;
            }
            else 
                if(subMatrixy(arr1, row1, column1, arr2, row2, column2, row + 1, i, counter2))
                    return true;
        }
    }
    return false;
}

bool subMatrix(const int arr1[][100], const int row1, const int column1,
               const int arr2[][100], const int row2, const int column2) // should be fix
{
    for(int i = 0; i < row2; i++)
    {
        for(int j = 0; j < column2; j++)
        {
            if(arr2[i][j] != arr1[rolumn[0][i]][rolumn[1][j]])
                return false;
        }
    }
    return true;
}
