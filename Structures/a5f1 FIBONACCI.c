// * Filename: a5f1.c DOMES Kritsimi Dimitra

/*Στα μαθηματικά, η ακολουθία Fibonacci ορίζεται ως το σύνολο των αριθμών που προκύπτουν από το
άθροισμα των δύο προηγούμενων αριθμών του συνόλου. Εξ ορισμού, οι 2 πρώτοι αριθμοί του συνόλου είναι
οι 0,1. Να γραφεί πρόγραμμα το οποίο θα υλοποιεί τις παρακάτω συναρτήσεις:
a. Συνάρτηση isFibonacci, η οποία δέχεται έναν θετικό ακέραιο n και μία ακολουθία Fibonacci
(typos_synolou) και επιστρέφει την τιμή TRUE ή FALSE ανάλογα εάν ο αριθμός ανήκει ή όχι
αντίστοιχα στην ακολουθία Fibonacci
b. Διαδικασία createFibonacciSet η οποία θα δέχεται έναν θετικό ακέραιο threshold και θα δημιουργεί
και επιστρέφει το σύνολο Fibonacci, μέχρι και τον αριθμό που είναι μικρότερος ή ίσος από τον
δοσμένο ακέραιο.
Στη συνέχεια, γράψτε κυρίως πρόγραμμα το οποίο θα ζητάει από τον χρήστη έναν ακέραιο αριθμό max, ο
οποίος ανήκει στο διάστημα [2…1000] και θα δημιουργεί και θα εμφανίζει την ακολουθία Fibonacci, όπου
το μεγαλύτερο στοιχείο της θα είναι μικρότερο ή ίσο του max. Χρησιμοποιείστε την υλοποίηση ΑΔΤ
σύνολο με πίνακα και τη διαδικασία displaySet από το TestSetADT.c για την εμφάνιση του συνόλου.
Τέλος, μετά την εμφάνιση του συνόλου, ο χρήστης θα μπορεί να εισάγει αριθμούς επανηληπτικά, τους
οποίους το πρόγραμμα θα ελέγχει για το εάν ανήκουν στην τρέχουσα ακολουθία Fibonacci και θα εκτυπώνει
αντίστοιχο μήνυμα Το πρόγραμμα θα τερματίζει όταν λάβει αρνητικό αριθμό.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 1001          //μέγιστο πλήθος στοιχείων συνόλου

//ΟΡΙΣΜΟΣ ΔΟΜΩΝ
typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

//ΟΡΙΣΜΟΣ ΣΥΝΑΡΤΗΣΕΩΝ
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void displayset(typos_synolou set);

boolean isFibonacci(stoixeio_synolou candidate, typos_synolou synolo);
void createFibonacciSet(stoixeio_synolou threshold,typos_synolou synolo);

//ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ
int main()
{
     typos_synolou Fibonacci;
     stoixeio_synolou max;
     stoixeio_synolou tmp;

     printf("Dwse to megistoarithmo.");
     scanf("%d", &max);
     while (max<2 || max>1000){
          printf("o arithmos then einai egkyros\n");
          printf("Dwse to megistoarithmo.");
          scanf("%d", &max);
      }

     createFibonacciSet(max,Fibonacci);

     displayset(Fibonacci);


     printf("Enter number to check:");
     scanf("%d", &tmp);
     while(tmp>=0){
         while (tmp>1000){
             printf("o arithmos then einai egkyros\n");
             printf("Enter number to check:");
             scanf("%d", &tmp);
         }
         if(isFibonacci(tmp,Fibonacci))
             printf("Fibonacci! \n");
         else
             printf("Not Fibonacci...\n");
         printf("Enter number to check:");
         scanf("%d", &tmp);


    }
    return 0;

 }


 //ΣΥΝΑΡΤΗΣΕΙΣ

void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}

void createFibonacciSet(stoixeio_synolou threshold,typos_synolou synolo ){

     //ΔΗΜΙΟΥΡΓΙΑ ΣΥΝΟΛΟΥ
     Dimiourgia(synolo);

    stoixeio_synolou f,g,i;
    f=0;
    g=1;
    i=0;
    Eisagogi(f,synolo);
    do{
        Eisagogi(g,synolo);
        i=f+g;
        f=g;
        g=i;
    }while(g<=threshold);
}

void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i<megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}

boolean isFibonacci(stoixeio_synolou candidate, typos_synolou synolo){

      return synolo[candidate];

}
