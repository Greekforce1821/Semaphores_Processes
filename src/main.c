/* Λειτουργικά Συστήματα | Επεισόδιο ΙV | Ομάδα Χρηστών ΙΙΙ | Σημαφόροι  */

/* -------------------------------------------------------------- */

#include "functions.h"
#include "semaphores.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    // Ανοίγω το αρχείο καταγραφής για εγγραφή.
    logFile = fopen("logfile.txt", "w");
    if (logFile == NULL) {
        displayErrorMessage("Error opening log file.", ERROR_OPENING_FILE);
        return ERROR_OPENING_FILE;
    }

    // Αρχικοποίηση σημαφόρων
    sem_P1 = sem_open("sem_P1", O_CREAT, 0644, 0);
    sem_P2 = sem_open("sem_P2", O_CREAT, 0644, 1);
    sem_P3 = sem_open("sem_P3", O_CREAT, 0644, 0);

    // Δημιουργία διεργασιών παιδιών
    pid_t pid_P1, pid_P2, pid_P3;

    pid_P1 = fork();
    if (pid_P1 == 0) {
        P1_process();
        exit(0);
    } else if (pid_P1 < 0) {
        displayErrorMessage("Error opening log file.", ERROR_CREATING_PROCESS_1);
        return ERROR_CREATING_PROCESS_1;
    }

    pid_P2 = fork();
    if (pid_P2 == 0) {
        P2_process();
        exit(0);
    } else if (pid_P2 < 0) {
        displayErrorMessage("Error opening log file.", ERROR_CREATING_PROCESS_2);
        return ERROR_CREATING_PROCESS_2;
    }

    pid_P3 = fork();
    if (pid_P3 == 0) {
        P3_process();
        exit(0);
    } else if (pid_P3 < 0) {
        displayErrorMessage("Error opening log file.", ERROR_CREATING_PROCESS_3);
        return ERROR_CREATING_PROCESS_3;
    }

    // Αναμονή των παιδιών
    waitpid(pid_P1, NULL, 0);
    waitpid(pid_P2, NULL, 0);
    waitpid(pid_P3, NULL, 0);

    // Κλείσιμο και καταστροφή των σημαφόρων
    sem_close(sem_P1);
    sem_close(sem_P2);
    sem_close(sem_P3);
    sem_unlink("sem_P1");
    sem_unlink("sem_P2");
    sem_unlink("sem_P3");
    
    // Κλείνω το αρχείο καταγραφής.
    fclose(logFile);

    return SUCCESS;
}

/* -------------------------------------------------------------- */

/* You reached the end of the following file :D 
   CHRISTOS - SPYRIDON KARYDIS & SPYRIDON - EFTYCHIOS KOKOTOS */
