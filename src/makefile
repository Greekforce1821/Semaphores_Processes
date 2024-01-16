# Ορισμός μεταβλητών
CC = gcc
CFLAGS = -Wall -g -lrt

# Λίστα των source αρχείων
SRCS = main.c semaphores.c functions.c

# Λίστα των object αρχείων
OBJS = $(SRCS:.c=.o)

# Ο στόχος που θα εκτελεστεί για την παραγωγή του εκτελέσιμου
TARGET = Semaphores_Processes

# Στόχος "all": δημιουργεί το εκτελέσιμο
all: $(TARGET)

# Στόχος για τη δημιουργία του εκτελέσιμου από τα object αρχεία
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lpthread

# Στόχος για τη μεταγλώττιση των source αρχείων σε object αρχεία
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
# Στόχος για τον καθαρισμό: διαγράφει τα αρχεία .o και το εκτελέσιμο
clean:
	rm -f $(OBJS) $(TARGET)
	
################################################################
#               Μήνυμα στο τέλος του Makefile                  #
# -------------------------------------------------------------#
#         You reached the end of the following file :D         #
#  CHRISTOS - SPYRIDON KARYDIS & SPYRIDON - EFTYCHIOS KOKOTOS  #
# -------------------------------------------------------------#
################################################################
