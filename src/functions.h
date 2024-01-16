#ifndef FUNCTIONS_H // Ελέγχει αν το αρχείο κεφαλίδας δεν έχει ήδη περιληφθεί
#define FUNCTIONS_H

// Ορισμός σταθερών για κωδικούς σφαλμάτων
#define SUCCESS 0
#define ERROR_CREATING_PROCESS_1 1
#define ERROR_CREATING_PROCESS_2 2
#define ERROR_CREATING_PROCESS_3 3
#define ERROR_OPENING_FILE 4


// Πρότυπα συναρτήσεων που υπάρχουν στο πρόγραμμα
void displayErrorMessage(const char *message, int code);

#endif /* FUNCTIONS_H */ // Τέλος του "συμβολαίου" για την αποφυγή διπλής ενσωμάτωσης του αρχείου κεφαλίδας
