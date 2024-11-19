#include <stdio.h>

void fcfsScheduling(int n, int arrivalTime[], int burstTime[]) {
    int waitingTime[n], turnaroundTime[n];
    int completionTime[n];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Calcular tiempos de finalización
    completionTime[0] = arrivalTime[0] + burstTime[0];
    for (int i = 1; i < n; i++) {
        if (completionTime[i - 1] > arrivalTime[i]) {
            completionTime[i] = completionTime[i - 1] + burstTime[i];
        } else {
            completionTime[i] = arrivalTime[i] + burstTime[i];
        }
    }

    // Calcular tiempos de turnaround y tiempos de espera
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Mostrar resultados
    printf("Proceso\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTime[i], burstTime[i], 
               completionTime[i], turnaroundTime[i], waitingTime[i]);
    }

    // Calcular y mostrar promedios
    printf("\nPromedio de tiempo de espera: %.2f\n", (float)totalWaitingTime / n);
    printf("Promedio de turnaround time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    int n;

    printf("Ingrese el número de procesos: ");
    scanf("%d", &n);

    int arrivalTime[n], burstTime[n];

    printf("Ingrese los tiempos de llegada y ráfaga para cada proceso:\n");
    for (int i = 0; i < n; i++) {
        printf("Proceso %d - Tiempo de llegada: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Proceso %d - Tiempo de ráfaga: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    fcfsScheduling(n, arrivalTime, burstTime);

    return 0;
}
