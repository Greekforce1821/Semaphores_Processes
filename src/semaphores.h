#ifndef SEMAPHORES_H // Ελέγχει αν το αρχείο κεφαλίδας δεν έχει ήδη περιληφθεί
#define SEMAPHORES_H

#include <stdio.h>
#include <semaphore.h>

// Ορισμός σημαφόρων
extern sem_t *sem_P1, *sem_P2, *sem_P3;

// Αρχείο για την έξοδο
extern FILE *logFile;

// Πρότυπα συναρτήσεων που υπάρχουν στο πρόγραμμα
void P1_process();
void P2_process();
void P3_process();

#endif /* SEMAPHORES_H */ // Τέλος του "συμβολαίου" για την αποφυγή διπλής ενσωμάτωσης του αρχείου κεφαλίδας
