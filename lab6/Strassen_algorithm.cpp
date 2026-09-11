#include <iostream>
#include <vector>
using namespace std;
using Matrix = vector<vector<int>>;
Matrix addMatrix(const Matrix& A, const Matrix& B)
{
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}
Matrix subtractMatrix(const Matrix& A, const Matrix& B)
{
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}
Matrix strassen(const Matrix& A, const Matrix& B)
{
    int n = A.size();
   if (n == 1)
        return {{A[0][0] * B[0][0]}};

    int k = n / 2;
    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k));
    Matrix A21(k, vector<int>(k)), A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k));
    Matrix B21(k, vector<int>(k)), B22(k, vector<int>(k));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }
    Matrix M1 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    Matrix M2 = strassen(addMatrix(A21, A22), B11);
    Matrix M3 = strassen(A11, subtractMatrix(B12, B22));
    Matrix M4 = strassen(A22, subtractMatrix(B21, B11));
    Matrix M5 = strassen(addMatrix(A11, A12), B22);
    Matrix M6 = strassen(subtractMatrix(A21, A11), addMatrix(B11, B12));
    Matrix M7 = strassen(subtractMatrix(A12, A22), addMatrix(B21, B22));
    Matrix C11 = addMatrix(subtractMatrix(addMatrix(M1, M4), M5), M7);
    Matrix C12 = addMatrix(M3, M5);
    Matrix C21 = addMatrix(M2, M4);
    Matrix C22 = addMatrix(subtractMatrix(addMatrix(M1, M3), M2), M6);
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
    return C;
}
int nextPowerOfTwo(int n)
{
    int power = 1;
    while (power < n)
        power *= 2;
    return power;
}
void printMatrix(const Matrix& A)
{
    for (const auto& row : A)
    {
        for (int value : row)
            cout << value << " ";
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;
    Matrix A(n, vector<int>(n));
    Matrix B(n, vector<int>(n));
    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    int size = nextPowerOfTwo(n);
    Matrix Ap(size, vector<int>(size, 0));
    Matrix Bp(size, vector<int>(size, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Ap[i][j] = A[i][j];
            Bp[i][j] = B[i][j];
        }
    }
    Matrix Cp = strassen(Ap, Bp);
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = Cp[i][j];

    cout << "\nResult Matrix:\n";
    printMatrix(C);
    return 0;
}