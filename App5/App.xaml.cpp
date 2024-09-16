#include <iostream>  
#include <windows.h>  
#include <ctime>  
using namespace std;

void level1(int M, int N) {
    int array[M][N];
    for (int mm = 0; mm < M; ++mm) {
        for (int nn = 0; nn < N; ++nn) {
            array[mm][nn] = rand() % 21; // do 20  
        }
    }
    cout << "Масив:\n";
    for (int mm = 0; mm < M; ++mm) {
        for (int nn = 0; nn < N; ++nn) {
            cout << array[mm][nn] << " ";
        }
        cout << "\n";
    }
}

void level2(int M, int N) {
    int array[M][N];
    int countpluss = 0, countminuss = 0, countnolikk = 0;
    for (int mm = 0; mm < M; ++mm) {
        for (int nn = 0; nn < N; ++nn) {
            array[mm][nn] = rand() % 21 - 10; // -10 do 20  
            countpluss += (array[mm][nn] > 0);
            countminuss += (array[mm][nn] < 0);
            countnolikk += (array[mm][nn] == 0);
        }
    }
    cout << "Положительных: " << countpluss << ", Отрицательных: " << countminuss << ", Нулей: " << countnolikk << "\n";
}
void level3(int M, int N) {
    int array[M][N];

    for (int mm = 0; mm < M; ++mm) {
        for (int nn = 0; nn < N; ++nn) {
            array[mm][nn] = rand() % 21;
        }
    }

    for (int mm = 0; mm < M - 1; mm += 2) {
        for (int nn = 0; nn < N; ++nn) {
            int timeres = array[mm][nn];
            array[mm][nn] = array[mm + 1][nn];
            array[mm + 1][nn] = timeres;
        }
    }

    cout << "масив после замени четных и не четных строк:\n";
    for (int mm = 0; mm < M; ++mm) {
        for (int nn = 0; nn < N; ++nn) {
            cout << array[mm][nn] << " ";
        }
        cout << "\n";
    }
}

void level4(int M, int N) {
    int array[M][N];

    int minim = 101, maxim = -101;
    int sumaa = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            array[i][j] = rand() % 201 - 100; 
            if (array[i][j] < minim) minim = array[i][j];
            if (array[i][j] > maxim) maxim = array[i][j];
        }
    }

    bool falseANDtrue = false;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (array[i][j] == minim) falseANDtrue = true;
            if (falseANDtrue) sumaa += array[i][j];
            if (array[i][j] == maxim) falseANDtrue = false;
        }
    }

    cout << "Сума елементов между мин и макс: " << sumaa << "\n";
}

void level5(int M, int N) {
    int array[M][N];
    int arrayy[M * N];
    int mainen = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            array[i][j] = rand() % 21;
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            arrayy[mainen++] = array[i][j];
        }
    }

    cout << "Одинмерный массив:\n";
    for (int i = 0; i < M * N; ++i) {
        cout << arrayy[i] << " ";
    }
    cout << "\n";

    mainen = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            array[i][j] = arrayy[mainen++];
        }
    }

    cout << "Двуйхмерный масив:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}
void level6(int M, int N) {
    int array[M][N];
    int mainee = 1;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            array[i][j] = mainee++;
        }
    }

    cout << "Масив по диоганолям:\n";
    for (int d = 0; d < M + N - 1; ++d) {
        for (int i = 0; i < M; ++i) {
            int j = d - i;
            if (j >= 0 && j < N) {
                cout << array[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    int M = 3, N = 4;

    level1(M, N);
    level2(M, N);
    level3(M, N);
    level4(M, N);
    level5(M, N);
    level6(M, N);

    return 0;
}