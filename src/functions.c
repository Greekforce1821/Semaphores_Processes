#include "functions.h" // Συμπερίληψη του αρχείου κεφαλίδας του προγράμματος

#include <stdio.h>

// Συνάρτηση που εμφανίζει μήνυμα σφάλματος και εξάγει το πρόγραμμα με κατάσταση σφάλματος
void displayErrorMessage(const char *message, int code) {
    fprintf(stderr, "%s\nProgram exits with code %d!\n", message, code);
}