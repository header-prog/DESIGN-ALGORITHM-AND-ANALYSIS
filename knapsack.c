#include <stdio.h>


void sortItems(int n, int value[], int weight[]) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            double r1 = (double)value[j] / weight[j];
            double r2 = (double)value[j + 1] / weight[j + 1];
            if (r1 < r2) { 
                int temp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
            }
        }
    }
}


void fractionalKnapsack(int n, int capacity, int value[], int weight[]) {
    sortItems(n, value, weight); 

    double totalValue = 0.0;
    double solution[n]; // Stores the fraction of items taken
    int i;

    for (i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            solution[i] = 1.0;  // Take the whole item
            totalValue += value[i];
            capacity -= weight[i];
        } else {
            solution[i] = (double)capacity / weight[i]; // Take fraction
            totalValue += solution[i] * value[i];
            break; // Knapsack is full
        }
    }

 
    printf("The solution vectors are ");
    for (i = 0; i < n; i++) {
        printf("%.2lf ", solution[i]);
    }
    printf("\nThe max. value is %.2lf\n", totalValue);
}

int main() {
    int n, capacity, i;

    
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    int value[n], weight[n];
    printf("Enter the value and weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &value[i], &weight[i]);
    }

  
    fractionalKnapsack(n, capacity, value, weight);

    return 0;
}
