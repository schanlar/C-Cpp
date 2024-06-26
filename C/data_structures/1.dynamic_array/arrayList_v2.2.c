#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

#define DELETED NAN  // Marker for deleted elements
#define EPSILON 1e-6 // Tolerance for floating-point comparison

/* Define some status codes */
#define LIST_SUCCESS 0
#define LIST_ERROR_NOT_INITIALIZED -1
#define LIST_ERROR_NAN_VALUE -2
#define LIST_ERROR_NOT_FOUND -3

/**
 * @struct list_properties
 * @brief Structure to represent the properties of a dynamic list
 * 
 * @var list_properties::array
 * Pointer to the array holding list elements
 * 
 * @var list_properties::length
 * Number of active elements in the list
 * 
 * @var list_properties::capacity
 * Total capacity of the array
 * 
 * @var list_properties::deletions
 * Number of deleted elements
 * 
 * @var list_properties::occupied
 * Number of occupied slots (active + deleted)
 */
typedef struct list_properties {
    double* array;
    size_t length;
    size_t capacity;
    size_t deletions;
    size_t occupied;
} LIST;

/**
 * @brief Safely allocate memory, exits on failure
 * 
 * @param size Size of memory to allocate
 * @return void* Pointer to the allocated memory
 */
void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

/**
 * @brief Safely reallocate memory, exits on failure
 * 
 * @param ptr Pointer to the existing memory
 * @param new_size New size of memory to allocate
 * @return void* Pointer to the reallocated memory
 */
void* safe_realloc(void* ptr, size_t new_size) {
    void* new_ptr = realloc(ptr, new_size);
    if (!new_ptr) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}

/**
 * @brief Initialize a list with a given initial capacity
 * 
 * @param initial_capacity Initial capacity of the list
 * @return LIST Initialized list
 */
LIST init_list(size_t initial_capacity) {
    LIST l;
    l.array = (double*)safe_malloc(sizeof(double) * initial_capacity);
    l.length = 0;
    l.capacity = initial_capacity;
    l.deletions = 0;
    l.occupied = 0;
    return l;
}

/**
 * @brief Check if a list exists and is initialized
 * 
 * @param pl Pointer to the list
 * @return int 1 if the list exists, 0 otherwise
 */
int list_exists(const LIST* pl) {
    if (pl && pl->array) return 1;
    printf("List is not initialized!\n");
    return 0;
}

/**
 * @brief Free memory allocated to a list
 * 
 * @param pl Pointer to the list
 */
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

/**
 * @brief Print the status of the list
 * 
 * @param pl Pointer to the list
 */
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

/**
 * @brief Display the active elements of the list
 * 
 * @param pl Pointer to the list
 */
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

/**
 * @brief Resize the list's capacity
 * 
 * @param pl Pointer to the list
 * @param new_capacity New capacity of the list
 */
void resize_list(LIST* pl, size_t new_capacity) {
    if (!list_exists(pl)) return;

    pl->array = (double*)safe_realloc(pl->array, sizeof(double) * new_capacity);
    pl->capacity = new_capacity;
}

/**
 * @brief Append an element to the list
 * 
 * @param pl Pointer to the list
 * @param num Element to append to the list
 */
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

/**
 * @brief Compare two doubles with a tolerance
 * 
 * @param a Pointer to the first double
 * @param b Pointer to the second double
 * @return int 0 if the doubles are equal within the tolerance, 1 if the first double is greater, -1 if the second double is greater
 */
int compare_doubles(const void* a, const void* b) {
    double arg1 = *(const double*)a;
    double arg2 = *(const double*)b;
    double diff = fabs(arg1 - arg2);
    if (diff <= EPSILON) return 0;
    if (arg1 > arg2) return 1;
    return -1;
}

/**
 * @brief Check if a list contains a given element
 * 
 * @param pl Pointer to the list
 * @param num Element to search for
 * @param index Pointer to store the index of the found element
 * @return int LIST_SUCCESS if the element is found, LIST_ERROR_NOT_INITIALIZED if the list is not initialized, LIST_ERROR_NOT_FOUND if the element is not found
 */
int contains(const LIST* pl, double num, size_t* index) {
    if (!list_exists(pl)) return LIST_ERROR_NOT_INITIALIZED;

    // Serial search
    for (size_t i = 0; i < pl->occupied; i++) {
        if (!isnan(pl->array[i])) {
            if (compare_doubles(&pl->array[i], &num) == 0) {
                if (index) {
                    *index = i;
                }
                return LIST_SUCCESS;
            }
        }
    }
    return LIST_ERROR_NOT_FOUND;
}

/**
 * @brief Compactify the list by removing deleted elements
 * 
 * @param pl Pointer to the list
 */
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

/**
 * @brief Remove (and return) a specific element from the list
 * 
 * @param pl Pointer to the list
 * @param num Element to remove
 * @param out Pointer to store the removed element
 * @return int LIST_SUCCESS if the element is removed, LIST_ERROR_NOT_INITIALIZED if the list is not initialized, LIST_ERROR_NAN_VALUE if the element is NaN, LIST_ERROR_NOT_FOUND if the element is not found
 */
int erase(LIST* pl, double num, double* out) {
    if (!list_exists(pl)) return LIST_ERROR_NOT_INITIALIZED;

    if (isnan(num)) {
        printf("Cannot remove a nan value! Use compactify() instead!\n");
        return LIST_ERROR_NAN_VALUE;
    }

    size_t idx;
    int contains_result = contains(pl, num, &idx);
    if (contains_result == LIST_SUCCESS) {
        double xnum = pl->array[idx];
        pl->array[idx] = DELETED;
        pl->deletions++;
        pl->length--;

        if (pl->deletions > pl->occupied / 4) {
            compactify(pl);
        }

        if (out) {
            *out = xnum;
        }
        return LIST_SUCCESS;
    }
    printf("Number not found!\n");
    return LIST_ERROR_NOT_FOUND;
}

/**
 * @brief Check if two lists are equal
 * 
 * @param pl1 Pointer to the first list
 * @param pl2 Pointer to the second list
 * @return int 1 if the lists are equal, LIST_ERROR_NOT_INITIALIZED if either list is not initialized, 0 otherwise
 */
int is_equal(const LIST* pl1, const LIST* pl2) {
    if (!list_exists(pl1) || !list_exists(pl2)) return LIST_ERROR_NOT_INITIALIZED;
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

/**
 * @brief Sort the non-NaN elements of the list in ascending order
 * 
 * @param pl Pointer to the list
 */
void sort(LIST* pl) {
    if (!list_exists(pl)) return;

    if (pl->length == 0) {
        return; // No need to sort if there are no non-NaN elements
    }

    // Compactify the array to remove the NaN values
    compactify(pl);

    // Use the quicksort algorithm from stdlib to sort the array with active elements
    qsort(pl->array, pl->length, sizeof(double), compare_doubles);
}




// Example usage
int main(void) {
    srand(time(NULL));
    
    // Initialize list 
    LIST ml = init_list(4);
    display(&ml);
    status(&ml);
    
    // Add numbers to list without exceeding capacity 
    append(&ml, 1);
    append(&ml, 2);
    display(&ml);
    status(&ml);
    
    // Add more numbers to list to exceed capacity and reallocate memory 
    for (int i = 3; i < 15; i++) {
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
    
    // Erase numbers from list 
    double erased_value;
    if (erase(&ml, 16, &erased_value) == LIST_SUCCESS) {
        printf("Erased: %.1f\n", erased_value);
    } else {
        printf("Failed to erase\n");
    }
    display(&ml);
    status(&ml);
    
    if (erase(&ml, 5, &erased_value) == LIST_SUCCESS) {
        printf("Erased: %.1f\n", erased_value);
    } else {
        printf("Failed to erase\n");
    }
    display(&ml);
    status(&ml);
    
    if (erase(&ml, 14, &erased_value) == LIST_SUCCESS) {
        printf("Erased: %.1f\n", erased_value);
    } else {
        printf("Failed to erase\n");
    }
    display(&ml);
    status(&ml);
    
    if (erase(&ml, 1, &erased_value) == LIST_SUCCESS) {
        printf("Erased: %.1f\n", erased_value);
    } else {
        printf("Failed to erase\n");
    }
    display(&ml);
    status(&ml);
    
    // Test equality of lists
    LIST ml2 = init_list(11);
    for (int i = 2; i < 14; i++) {
        if (i != 5) {
            append(&ml2, i);
        }
    }
    display(&ml2);
    status(&ml2);
    printf("ml1 is equal to ml2: %d\n", is_equal(&ml, &ml2));
    
    append(&ml, 20);
    printf("ml1 is equal to ml2: %d\n", is_equal(&ml, &ml2));
    
    // Remove elements from list to compactify it 
    if (erase(&ml, 20, &erased_value) == LIST_SUCCESS) {
        printf("Erased: %.1f\n", erased_value);
    } else {
        printf("Failed to erase\n");
    }
    display(&ml);
    status(&ml);
    printf("ml1 is equal to ml2: %d\n", is_equal(&ml, &ml2));
    
    if (erase(&ml, 12, &erased_value) == LIST_SUCCESS) {
        printf("Erased: %.1f\n", erased_value);
    } else {
        printf("Failed to erase\n");
    }
    display(&ml);
    status(&ml);
    
    if (erase(&ml, 7, &erased_value) == LIST_SUCCESS) {
        printf("Erased: %.1f\n", erased_value);
    } else {
        printf("Failed to erase\n");
    }
    display(&ml);
    status(&ml);
    
    if (erase(&ml, 4, &erased_value) == LIST_SUCCESS) {
        printf("Erased: %.1f\n", erased_value);
    } else {
        printf("Failed to erase\n");
    }
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
            erase(&ml3, ml3.array[remove_index], NULL);
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