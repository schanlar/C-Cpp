/*
    Παράδειγμα 6:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει έξι ακεραίούς τους οποίους να αποθηκεύει 
    σε έναν διδιάστατο πίνακα 2 x 3 (π.χ. a). 
    Στη συνέχεια, να διαβάζει άλλους έξι ακεραίούς και να τους αποθηκεύει σε έναν δεύτερο διδιάστατο πίνακα 
    3 x 2 (π.χ. b). 
    Το πρόγραμμα να υπολογίζει και να εμφανίζει τα στοιχεία ενός τρίτον πίνακα (π.χ. c), 
    που προκύπτει από τον αλγεβρικό πολλαπλασιασμό των δύο πινάκων, δηλαδή: c = a x b.
*/

#include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

#define M 2
#define N 3
int main(void){
    // srand(time(NULL)); // for debugging

    int a[M][N], b[N][M], c[M][M], sum;

    printf ("Array a (%d x %d)\n", M, N);
    printf("------------------\n");
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
            // a[i][j] = (rand() % 10) + 1; // for debugging
            // printf("%5d ", a[i][j]);
        }
        // printf("\n");
    }
    printf("------------------\n");

    printf ("\nArray b (%d x %d)\n", N, M);
    printf("------------------\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
            // b[i][j] = (rand() % 10) + 1; // for debugging
            // printf("%5d ", b[i][j]);
        }
        // printf("\n");
    }
    printf("------------------\n");


    // The inner most loop calculate the sum of elements
    // The two outer loops populate the c array
    for (int i = 0; i < M; i++){
            for (int j = 0; j < M; j++){
                sum = 0; // reset sum after each iteration
                for (int k = 0; k < N; k++){
                    sum += a[i][k] * b[k][j];
                }
                c[i][j] = sum;
            }
        }

    printf ("\nArray c = a x b (%d x %d)", M, M); 
	printf("\n------------------\n");	
    for (int i = 0; i < M; i++){
        for (int j = 0; j < M; j++){
            printf("%5d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}