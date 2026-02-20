#include <iostream>
using namespace std;

int main() {
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2;

    cout<<"Enter row and column size for matrix 1"<<endl;
    cin >> r1 >> c1;
    
       cout<<"Enter row and column size for matrix 2"<<endl;
    cin >> r2 >> c2;


    if (c1 != r2) {
        cout << " multiplication is not possible";
        return 0;
    }

    cout<<"Enter elements of first Matrix"<<endl;

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> a[i][j];
        }
    }
 cout<<"Enter elements of second Matrix"<<endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            c[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                c[i][j] += a[i][k] + b[k][j];
            }
        }
    }

    cout<<"Final matrix :"<<endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//////////////////////////////////////////////////////////////

// determinant
#include <iostream>
using namespace std;

// Function to calculate determinant
int determinant(int matrix[][10], int n) {
    int det = 0;
    
    // Base case: 1x1 matrix
    if (n == 1) {
        return matrix[0][0];
    }
    
    // Base case: 2x2 matrix
    if (n == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    
    // For larger matrices (3x3 and above)
    int submatrix[10][10];
    int sign = 1;
    
    // Expand along first row
    for (int f = 0; f < n; f++) {
        // Create submatrix by removing first row and f-th column
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == f) continue;
                submatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        
        // Recursive call
        det += sign * matrix[0][f] * determinant(submatrix, n - 1);
        sign = -sign;  // Alternate signs
    }
    
    return det;
}

int main() {
    int n;
    int matrix[10][10];
    
    // Input matrix size
    cout << "Enter the size of square matrix (n x n): ";
    cin >> n;
    
    // Input matrix elements
    cout << "\nEnter elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    // Display the matrix
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Calculate and display determinant
    int det = determinant(matrix, n);
    cout << "\nDeterminant of the matrix: " << det << endl;
    
    return 0;
}


///////////////////////////////

int main() {
    int n;
    int matrix[10][10];
    
    // Input matrix size (must be square)
    cout << "Enter the size of square matrix (n x n): ";
    cin >> n;
    
    // Input matrix elements
    cout << "\nEnter elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    // Display the matrix
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Calculate Primary Diagonal Sum
    int primarySum = 0;
    for (int i = 0; i < n; i++) {
        primarySum += matrix[i][i];
    }
    
    // Calculate Secondary Diagonal Sum
    int secondarySum = 0;
    for (int i = 0; i < n; i++) {
        secondarySum += matrix[i][n - 1 - i];
    }
    
    // Calculate Total Diagonal Sum
    int totalSum = primarySum + secondarySum;
    
    // If odd-sized matrix, subtract the center element (counted twice)
    if (n % 2 != 0) {
        totalSum -= matrix[n/2][n/2];
    }
    
    // Display results
    cout << "\nPrimary Diagonal Sum: " << primarySum << endl;
    cout << "Secondary Diagonal Sum: " << secondarySum << endl;
    cout << "Total Diagonal Sum: " << totalSum << endl;
    
    return 0;
}
