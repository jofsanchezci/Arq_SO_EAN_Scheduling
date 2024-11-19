
# Algoritmo First-Come, First-Served (FCFS) en C

## Descripción

El algoritmo **First-Come, First-Served (FCFS)** es uno de los métodos más simples de planificación de procesos en sistemas operativos. Su principio básico es que los procesos se ejecutan en el orden en que llegan al sistema, utilizando una cola FIFO (First In, First Out). Este enfoque es **no expropiativo**, lo que significa que un proceso, una vez iniciado, se ejecuta hasta completarse antes de que otro tome su lugar.

---

## Características del Algoritmo FCFS

1. **Orden de llegada**:
   - Los procesos se ejecutan según el orden en que llegan al sistema.

2. **No expropiativo**:
   - Un proceso no puede ser interrumpido una vez que comienza su ejecución.

3. **Similitud con una cola**:
   - El primer proceso que entra es el primero que se ejecuta.

---

## Funcionamiento

### Pasos del Algoritmo:
1. Ordenar los procesos según sus tiempos de llegada.
2. Calcular los tiempos de finalización (Completion Time, CT):
   - CT de cada proceso es el tiempo acumulado después de ejecutar los procesos anteriores.
3. Calcular los tiempos de turnaround (Turnaround Time, TAT):
   - TAT[i] = CT[i] - Tiempo de llegada[i]
4. Calcular los tiempos de espera (Waiting Time, WT):
   - WT[i] = TAT[i] - Tiempo de ráfaga[i]

---

## Fórmulas

- **Tiempo de Turnaround (TAT)**:
  \[
  TAT[i] = CT[i] - AT[i]
  \]

- **Tiempo de Espera (WT)**:
  \[
  WT[i] = TAT[i] - BT[i]
  \]

---

## Implementación en C

El programa simula la planificación de procesos utilizando el algoritmo FCFS y calcula:
- Tiempos de espera (WT)
- Turnaround Times (TAT)
- Tiempos de finalización (CT)
- Promedios de los tiempos calculados

### Archivos del Proyecto
- `fcfs.c`: Código fuente de la implementación en C.
- `README.md`: Archivo explicativo.

---

## Cómo Usar

### Requisitos
- Compilador de C (por ejemplo, GCC).
- Sistema operativo con soporte para compilación de C.

### Instrucciones

1. **Compilar el programa**:
   ```bash
   gcc fcfs.c -o fcfs
   ```

2. **Ejecutar el programa**:
   ```bash
   ./fcfs
   ```

3. **Ingresar los datos requeridos**:
   - Número de procesos.
   - Tiempo de llegada y tiempo de ráfaga para cada proceso.

4. **Revisar los resultados en pantalla**:
   - Tabla con los tiempos de espera, turnaround y finalización.

---

## Ejemplo

### Entrada:
```plaintext
Ingrese el número de procesos: 3
Ingrese los tiempos de llegada y ráfaga para cada proceso:
Proceso 1 - Tiempo de llegada: 0
Proceso 1 - Tiempo de ráfaga: 5
Proceso 2 - Tiempo de llegada: 1
Proceso 2 - Tiempo de ráfaga: 3
Proceso 3 - Tiempo de llegada: 2
Proceso 3 - Tiempo de ráfaga: 8
```

### Salida:
```plaintext
Proceso	AT	BT	CT	TAT	WT
P1	0	5	5	5	0
P2	1	3	8	7	4
P3	2	8	16	14	6

Promedio de tiempo de espera: 3.33
Promedio de turnaround time: 8.67
```

---

## Ventajas

1. **Simplicidad**:
   - Fácil de implementar y comprender.
   
2. **Justicia**:
   - Los procesos se ejecutan en el orden en que llegan.

---

## Desventajas

1. **Convoy Effect**:
   - Si un proceso largo llega primero, los demás deben esperar, aumentando los tiempos de espera.

2. **No óptimo para sistemas interactivos**:
   - Procesos cortos pueden quedar bloqueados detrás de procesos largos.

---

## Contribuciones

Si deseas mejorar este proyecto o añadir nuevas características, siéntete libre de hacer un fork del repositorio y enviar un pull request.

---

## Licencia

Este proyecto es de dominio público. Puedes usarlo, modificarlo y distribuirlo libremente.
