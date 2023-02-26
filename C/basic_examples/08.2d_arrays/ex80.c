/*
    Παράδειγμα 3:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει οκτώ ακεραίους, να τους αποθηκεύει σε έναν 
    πίνακα 2 x 4 και να εμφανίζει το άθροισμα όλων των στοιχείων του καθώς και το άθροισμα 
    των στοιχείων της κάθε γραμμής και κάθε στήλης του.
*/

#include <stdio.h>

int main(void){

    int arr[2][4] = {0}, sum = 0, rowSum, colSum;

    // Initialize array
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 4; j++){
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        rowSum = 0; // Re-initialize after each iteration
        for (int j = 0; j < 4; j++){
            sum += arr[i][j];
            rowSum += arr[i][j];
            if (i == 0){
                colSum = arr[i][j] + arr[i+1][j];
                printf("Sum of col %d: %d\n", j, colSum);
            }
            
        }
        printf("Sum of row %d: %d\n", i, rowSum);
    }
    printf("Sum of numbers: %d\n", sum);
} 