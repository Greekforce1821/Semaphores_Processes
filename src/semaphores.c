#include "semaphores.h" // Συμπερίληψη του αρχείου κεφαλίδας του προγράμματος

// Ορισμός σημαφόρων
sem_t *sem_P1, *sem_P2, *sem_P3;

// Αρχείο για την έξοδο
FILE *logFile;

// Συναρτήσεις για τις διεργασίες παιδιά

void P1_process() {
    while (1) {
        sem_wait(sem_P1);
        printf("Process P1: Department of Informatics\n");
        fprintf(logFile, "Process P1: Department of Informatics\n");
        fflush(logFile); // Εκκαθάριση του buffer για να διασφαλιστεί άμεση εγγραφή στο αρχείο.
        sem_post(sem_P3);
    }
}

void P2_process() {
    while (1) {
        sem_wait(sem_P2);
        printf("Process P2: Ionian University\n");
        fprintf(logFile, "Process P2: Ionian University\n");
        fflush(logFile); // Εκκαθάριση του buffer για να διασφαλιστεί άμεση εγγραφή στο αρχείο.
        sem_post(sem_P1);
    }
}

void P3_process() {
    while (1) {
        sem_wait(sem_P3);
        printf("Process P3: C. KARYDIS, S. KOKOTOS\n");
        fprintf(logFile, "Process P3: C. KARYDIS, S. KOKOTOS\n");
        fflush(logFile); // Εκκαθάριση του buffer για να διασφαλιστεί άμεση εγγραφή στο αρχείο.
        sem_post(sem_P2);
    }
}
