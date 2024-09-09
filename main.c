#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8
int diff = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffleRows(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        int randomRow = rand() % size;
        for (int j = 0; j < size; j++) {
            swap(&grid[i][j], &grid[randomRow][j]);
        }
    }
}

void shuffleColumns(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        int randomCol = rand() % size;
        for (int j = 0; j < size; j++) {
            swap(&grid[j][i], &grid[j][randomCol]);
        }
    }
}

void printGrid(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printClues(int *top, int *bottom, int *left, int *right, int size) {
    printf(" ");
    for (int i = 0; i < size; i++) {
        printf("%d ", top[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", left[i]);  
        for (int j = 0; j < size-1; j++) {
            printf("  ");  
        }
        printf("%d\n", right[i]);  
    }

    printf(" ");
    for (int i = 0; i < size; i++) {
        printf("%d ", bottom[i]);
    }
    printf("\n");
}

void generateSolvedGrid(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = (i + j) % size + 1;
        }
    }
}

void generateClues(int **grid, int size, int *top, int *bottom, int *left, int *right) {
    for (int i = 0; i < size; i++) {
        int maxHeight = 0;
        int visibleCount = 0;

        maxHeight = 0;
        visibleCount = 0;
        for (int j = 0; j < size; j++) {
            if (grid[j][i] > maxHeight) {
                maxHeight = grid[j][i];
                visibleCount++;
            }
        }
        top[i] = visibleCount;

        maxHeight = 0;
        visibleCount = 0;
        for (int j = size - 1; j >= 0; j--) {
            if (grid[j][i] > maxHeight) {
                maxHeight = grid[j][i];
                visibleCount++;
            }
        }
        bottom[i] = visibleCount;

        maxHeight = 0;
        visibleCount = 0;
        for (int j = 0; j < size; j++) {
            if (grid[i][j] > maxHeight) {
                maxHeight = grid[i][j];
                visibleCount++;
            }
        }
        left[i] = visibleCount;

        maxHeight = 0;
        visibleCount = 0;
        for (int j = size - 1; j >= 0; j--) {
            if (grid[i][j] > maxHeight) {
                maxHeight = grid[i][j];
                visibleCount++;
            }
        }
        right[i] = visibleCount;
    }
}

int main() {
    int size;
    srand(time(NULL));


    while (1) {
        printf("Enter the size of the grid (0 for quit): ");
        scanf("%d", &size);
        
        if (size == 0) {
            break;
        }

        if (size < 2 || size > MAX_SIZE) {
            printf("Invalid grid size. Please enter a number between 4 and %d.\n", MAX_SIZE);
            continue;
        }

        printf("Enter scramble amount: ");
        scanf("%d", &diff);

        int **grid = (int **)malloc(size * sizeof(int *));
        for (int i = 0; i < size; i++) {
            grid[i] = (int *)malloc(size * sizeof(int));
        }

        int *topClues = (int *)malloc(size * sizeof(int));
        int *bottomClues = (int *)malloc(size * sizeof(int));
        int *leftClues = (int *)malloc(size * sizeof(int));
        int *rightClues = (int *)malloc(size * sizeof(int));

        generateSolvedGrid(grid, size); 
        for (int i = 0; i <= diff; i++) {
            int r = rand() % 100;
            if (r >= 50) {
                shuffleRows(grid, size);
            } else {
            shuffleColumns(grid, size);
            }
        }

        generateClues(grid, size, topClues, bottomClues, leftClues, rightClues);
        
        printf("\n   skyscrapers generated: \n\n");
        printGrid(grid, size);

        printf("   visibilty clues: \n\n");
        printClues(topClues, bottomClues, leftClues, rightClues, size);
        printf("\n");
        for (int i = 0; i < size; i++) {
            free(grid[i]);
        }
        free(grid);
        free(topClues);
        free(bottomClues);
        free(leftClues);
        free(rightClues);
    }

    return 0;
}
