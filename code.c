#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    char status[10];
    int progress;
} Process;

Process processes[] = {
    {1, "Process A", "Running", 75},
    {2, "Process B", "Pending", 20},
    {3, "Process C", "Completed", 100},
};
int num_processes = sizeof(processes) / sizeof(processes[0]);

void* update_progress(void* arg) {
    while (1) {
        sleep(2);
        int running = 0;
        for (int i = 0; i < num_processes; i++) {
            if (strcmp(processes[i].status, "Running") == 0) {
                processes[i].progress += (rand() % 5) + 1;
                if (processes[i].progress >= 100) {
                    processes[i].progress = 100;
                    strcpy(processes[i].status, "Completed");
                }
                running = 1;
            }
        }
        if (!running) break;
    }
    return NULL;
}

void* display_processes(void* arg) {
    while (1) {
        sleep(2);
        int running = 0;
        printf("\nCurrent Process Status:\n");
        for (int i = 0; i < num_processes; i++) {
            printf("ID: %d, Name: %s, Status: %s, Progress: %d%%\n", 
                   processes[i].id, processes[i].name, processes[i].status, processes[i].progress);
            if (strcmp(processes[i].status, "Running") == 0) {
                running = 1;
            }
        }
        if (!running) break;
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t progress_thread, display_thread;
    
    pthread_create(&progress_thread, NULL, update_progress, NULL);
    pthread_create(&display_thread, NULL, display_processes, NULL);
    
    pthread_join(progress_thread, NULL);
    pthread_join(display_thread, NULL);
    
    return 0;
}
