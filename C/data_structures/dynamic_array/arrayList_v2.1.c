#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

#define DELETED NAN  // Marker for deleted elements
#define EPSILON 1e-6 // Tolerance for floating-point comparison

// Struct definition for the dynamic list
typedef struct list_properties {
    double* array;          // Pointer to the array holding list elements
    size_t length;    // Number of active elements in the list
    size_t capacity;  // Total capacity of the array
    size_t deletions; // Number of deleted elements
    size_t occupied;  // Number of occupied slots (active + deleted)
} LIST;

// Function to safely allocate memory, exits on failure
void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Function to safely reallocate memory, exits on failure
void* safe_realloc(void* ptr, size_t new_size) {
    void* new_ptr = realloc(ptr, new_size);
    if (!new_ptr) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}

// Function to initialize a list with a given initial capacity
LIST init_list(size_t initial_capacity) {
    LIST l;
    l.array = (double*)safe_malloc(sizeof(double) * initial_capacity);
    l.length = 0;
    l.capacity = initial_capacity;
    l.deletions = 0;
    l.occupied = 0;
    return l;
}

// Function to check if a list exists and is initialized
int list_exists(const LIST* pl) {
    if (pl && pl->array) return 1;
    printf("List is not initialized!\n");
    return 0;
}

// Function to free memory allocated to a list
void free_list(LIST* pl) {
    if (list_exists(pl)) {
        free(pl->array);
        pl->array = NULL;
        pl->length = 0;
        pl->capacity = 0;
        pl->deletions = 0;
        pl->occupied = 0;
    }
}

// Function to print the status of the list
void status(const LIST* pl) {
    if (!list_exists(pl)) return;

    const int bar_length = 100;
    printf("LENGTH: %zu; CAPACITY: %zu; DELETIONS: %zu; OCCUPIED: %zu\n", pl->length,
        pl->capacity, pl->deletions, pl->occupied);
    for (int i = 0; i < bar_length; i++) {
        printf("-");
        if (i == bar_length - 1) {
            printf("\n");
        }
    }
}

// Function to display the active elements of the list
void display(const LIST* pl) {
    if (!list_exists(pl)) return;

    size_t print_count = 0;
    printf("[");
    for (size_t i = 0; i < pl->occupied; i++) {
        if (!isnan(pl->array[i])) {
            if (print_count > 0) {
                printf(", ");
            }
            printf("%.1f", pl->array[i]);
            print_count++;
        }
    }
    printf("]\n");
}

// Function to resize the list's capacity
void resize_list(LIST* pl, size_t new_capacity) {
    if (!list_exists(pl)) return;

    pl->array = (double*)safe_realloc(pl->array, sizeof(double) * new_capacity);
    pl->capacity = new_capacity;
}

// Function to append an element to the list
void append(LIST* pl, double num) {
    if (!list_exists(pl)) return;

    if (isnan(num)) {
        printf("Cannot append nan!\n");
        return;
    }

    if (pl->occupied == pl->capacity) {
        resize_list(pl, pl->capacity * 2);
    }
    pl->array[pl->occupied++] = num;
    pl->length++;
}

// Function to compare two doubles with a tolerance
int compare_doubles(const void* a, const void* b) {
    double arg1 = *(const double*)a;
    double arg2 = *(const double*)b;
    double diff = fabs(arg1 - arg2);
    if (diff <= EPSILON) return 0;
    if (arg1 > arg2) return 1;
    return -1;
}

// Function to check if a list contains a given element
int contains(const LIST* pl, double num) {
    if (!list_exists(pl)) return -1;

    // Serial search
    for (size_t i = 0; i < pl->occupied; i++) {
        if (!isnan(pl->array[i])) {
            if (compare_doubles(&pl->array[i], &num) == 0) {
                return i;
            }
        }
    }
    return -1;
}

// Function to compactify the list by removing deleted elements
void compactify(LIST* pl) {
    if (!list_exists(pl)) return;

    size_t idx = 0;
    for (size_t i = 0; i < pl->occupied; i++) {
        if (!isnan(pl->array[i])) {
            pl->array[idx++] = pl->array[i];
        }
    }
    pl->length = idx;
    pl->deletions = 0;
    pl->occupied = pl->length;
    resize_list(pl, pl->occupied);
}

// Function to remove (and return) a specific element from the list
double pop(LIST* pl, double num) {
    if (!list_exists(pl)) return -DBL_MAX;

    if (isnan(num)) {
        printf("Cannot remove a nan value! Use compactify() instead!\n");
        return -DBL_MAX;
    }

    int idx = contains(pl, num);
    if (idx != -1) {
        double xnum = pl->array[idx];
        pl->array[idx] = DELETED;
        pl->deletions++;
        pl->length--;

        if (pl->deletions > pl->occupied / 4) {
            compactify(pl);
        }

        return xnum;
    }
    printf("Number not found!\n");
    return -DBL_MAX;
}

// Function to check if two lists are equal.
int is_equal(const LIST* pl1, const LIST* pl2) {
    if (!list_exists(pl1) || !list_exists(pl2)) return -1;
    if (pl1->length != pl2->length) {
        printf("Lists do not have the same length!\n");
        return 0;
    }

    size_t last_idx2 = 0;
    for (size_t idx1 = 0; idx1 < pl1->occupied; idx1++) {
        if (isnan(pl1->array[idx1])) continue;
        double num1 = pl1->array[idx1];
        for (size_t idx2 = last_idx2; idx2 < pl2->occupied; idx2++) {
            if (isnan(pl2->array[idx2])) continue;
            double num2 = pl2->array[idx2];
            if (compare_doubles(&num1, &num2) != 0) return 0;
            last_idx2 = idx2 + 1;
            break;
        }
    }
    return 1;
}

// Function to sort the non-NaN elements of the list in ascending order.
void sort(LIST* pl) {
    if (!list_exists(pl)) return;

    if (pl->length == 0) {
        return; // No need to sort if there are no non-NaN elements
    }

    // Compactify the array to remove the NAN values.
    compactify(pl);

    // Use the quicksort algorithm from stdlib to sort the array with active elements
    qsort(pl->array, pl->length, sizeof(double), compare_doubles);
}


int main(void){
    srand(time(NULL));
    
    //Initialize list 
    LIST ml = init_list(4);
    display(&ml);
    status(&ml);
    
    // Add numbers to list without exceeding capacity 
    append(&ml, 1);
    append(&ml, 2);
    display(&ml);
    status(&ml);
    
    // Add more numbers to list to exceed capacity and reallocate memory 
    for (int i=3; i<15; i++){
        append(&ml, i);
    }
    display(&ml);
    status(&ml);
    
    // Try to add a nan 
    append(&ml, NAN);
    display(&ml);
    status(&ml);
    
    // Try to operate on an uninitialized list 
    LIST l;
    append(&l, 1);
    
    // Pop numbers from list 
    printf("Popped: %.1f\n", pop(&ml, 16));
    display(&ml);
    status(&ml);
    
    printf("Popped: %.1f\n", pop(&ml, 5));
    display(&ml);
    status(&ml);
    
    printf("Popped: %.1f\n", pop(&ml, 14));
    display(&ml);
    status(&ml);
    
    printf("Popped: %.1f\n", pop(&ml, 1));
    display(&ml);
    status(&ml);
    
    // Test equality of lists
    LIST ml2 = init_list(11);
    for (int i=2; i<14; i++){
        if (i != 5){
            append(&ml2, i);
        }
    }
    display(&ml2);
    status(&ml2);
    printf("ml1 is equal to ml2: %d\n", is_equal(&ml, &ml2));
    
    append(&ml, 20);
    printf("ml1 is equal to ml2: %d\n", is_equal(&ml, &ml2));
    
    // Remove elements from list to compactify it 
    printf("Popped: %.1f\n", pop(&ml, 20));
    display(&ml);
    status(&ml);
    printf("ml1 is equal to ml2: %d\n", is_equal(&ml, &ml2));
    
    printf("Popped: %.1f\n", pop(&ml, 12));
    display(&ml);
    status(&ml);
    
    printf("Popped: %.1f\n", pop(&ml, 7));
    display(&ml);
    status(&ml);
    
    printf("Popped: %.1f\n", pop(&ml, 4));
    display(&ml);
    status(&ml);
    
    // Test sorting
    LIST ml3 = init_list(10);

    // Append 8 random elements to the list
    for (unsigned int i = 0; i < 8; i++) {
        append(&ml3, rand() % 100 + rand() % 10 / 10.0);
    }

    // Randomly remove some elements from the list
    int num_elements_to_remove = 2;
    for (int i = 0; i < num_elements_to_remove; i++) {
        unsigned int remove_index = rand() % ml3.occupied;
        if (!isnan(ml3.array[remove_index])) {
            pop(&ml3, ml3.array[remove_index]);
        }
    }
    display(&ml3);
    status(&ml3);
    sort(&ml3);
    display(&ml3);
    status(&ml3);
    
    
    
    free_list(&ml);
    free_list(&ml2);
    free_list(&ml3);
    
    return 0;
}