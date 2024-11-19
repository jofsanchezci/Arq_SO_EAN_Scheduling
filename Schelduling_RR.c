#include <stdio.h>

void roundRobin(int n, int burstTimes[], int quantum) {
    int remainingTime[n];
    int waitingTime[n], turnaroundTime[n];
    int time = 0; // Tiempo actual
    int completed = 0;

    // Inicializar tiempos restantes con los tiempos de ráfaga
    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTimes[i];
        waitingTime[i] = 0;
    }

    // Mientras haya procesos por ejecutar
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                if (remainingTime[i] > quantum) {
                    // Ejecutar el proceso durante el quantum
                    time += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    // Ejecutar el proceso hasta completarlo
                    time += remainingTime[i];
                    waitingTime[i] = time - burstTimes[i];
                    remainingTime[i] = 0;
                    completed++;
                }
            }
        }
    }

    // Calcular turnaround time
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = burstTimes[i] + waitingTime[i];
    }

    // Mostrar resultados
    printf("Proceso\tTiempo de ráfaga\tTiempo de espera\tTurnaround time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t\t%d\n", i + 1, burstTimes[i], waitingTime[i], turnaroundTime[i]);
    }

    // Calcular promedios
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    printf("\nPromedio de tiempo de espera: %.2f\n", totalWaitingTime / n);
    printf("Promedio de turnaround time: %.2f\n", totalTurnaroundTime / n);
}

int main() {
    int n, quantum;

    printf("Ingrese el número de procesos: ");
    scanf("%d", &n);

    int burstTimes[n];
    printf("Ingrese los tiempos de ráfaga para cada proceso:\n");
    for (int i = 0; i < n; i++) {
        printf("Proceso %d: ", i + 1);
        scanf("%d", &burstTimes[i]);
    }

    printf("Ingrese el tiempo de quantum: ");
    scanf("%d", &quantum);

    roundRobin(n, burstTimes, quantum);

    return 0;
}
