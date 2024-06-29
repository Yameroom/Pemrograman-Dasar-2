#include <iostream>
using namespace std;

void menghitungkovarianmatrix(float A[2][3], float kovarianmatrix[2][2]) {
   
    float mean[3] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            mean[i] += A[j][i];
        }
        mean[i] /= 2;
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            kovarianmatrix[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                kovarianmatrix[i][j] += (A[i][k] - mean[k]) * (A[j][k] - mean[k]);
            }
            kovarianmatrix[i][j] /= (2 - 1);
        }
    }
}

int main() {
   
    float A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    float kovarianmatrix[2][2];

    
    menghitungkovarianmatrix(A, kovarianmatrix);

   
    cout << "matriks Kovarian:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << kovarianmatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

