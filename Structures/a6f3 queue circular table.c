
                 //a6f3 DOMES Kritsimi Dimitra

/*Μια εναλλακτική υλοποίηση μιας ουράς που χρησιμοποιεί ένα
κυκλικό πίνακα και δεν απαιτεί να διατηρούμε μία κενή θέση μεταξύ
της εμπρός και της πίσω άκρη της για να ξεχωρίζει μια κενή ουρά από
μια γεμάτη χρειάζεται απλά την προσθήκη ενός ακέραιου πεδίου
Count στην εγγραφή τύπου QueueType, στο οποίο αποθηκεύεται ο
τρέχων αριθμός στοιχείων της ουράς. Να κάνετε τις απαραίτητες
αλλαγές στη δήλωση του τύπου της εγγραφής και στις βασικές
λειτουργίες του ΑΤΔ ουρά με πίνακες, έτσι ώστε να χρησιμοποιείται
αυτό το επιπλέον πεδίο και να μην διατηρείται κενή θέση στον πίνακα
όπου αποθηκεύονται τα στοιχεία της ουράς. Η TraverseQ που σας
δίνεται στο TestQueue θα πρέπει επίσης να τροποποιηθεί. Για να
ελέγξετε την ορθότητα του προγράμματος σας
*/
#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 10  //το όριο μεγέθους της ουράς

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear, Count;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;
//ΟΡΙΣΜΟΣ ΣΥΝΑΡΤΗΣΕΩΝ
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void TraverseQ(QueueType Queue);
//ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ
main()
{
   QueueType Queue;
   QueueElementType AnItem;

   int i;
 /* (a) Δημιουργήστε μια ουρά (QueueLimit=10) που περιλαμβάνει
        όλους τους ακέραιους αριθμούς στο διάστημα [0..9].
         Εμφανίστε την ουρά (με βοηθητική διαδικασία TraverseQ)
         την τιμή της Front, Rear και του μετρητή των στοιχείων της ουράς.*/
   CreateQ(&Queue);
   for(i=0; i<10; i++){
      AddQ(&Queue,i);
    }
   printf("---a---\n");
   TraverseQ(Queue);
   printf("Front=%d Rear=%d Count=%d \n",Queue.Front, Queue.Rear,Queue.Count);

/*(b) Στη συνέχεια επιχειρήστε να προσθέσετε ένα οποιοδήποτε στοιχείο.
      Εμφανίστε την ουρά (με βοηθητική διαδικασία TraverseQ)*/
   printf("---b---\n");
   AddQ(&Queue,25);
   printf("\n");
   TraverseQ(Queue);
   printf("Front=%d Rear=%d Count=%d \n",Queue.Front, Queue.Rear,Queue.Count);

/*(c) Αφαιρέστε τη κεφαλή της ουράς και εμφανίστε την ουρά (με
βοηθητική διαδικασία TraverseQ), το στοιχείο που αφαιρέσατε,
την τιμή της Front, Rear και του μετρητή των στοιχείων της ουράς*/
   printf("---c---\n");
   RemoveQ(&Queue,&AnItem);
   TraverseQ(Queue);
   printf("Removed item=%d ",AnItem);
   printf("Front=%d Rear=%d Count=%d\n",Queue.Front, Queue.Rear,Queue.Count);

/*(d) Προσθέσετε ένα οποιοδήποτε στοιχείο και εμφανίστε την ουρά
(με βοηθητική διαδικασία TraverseQ), την τιμή της Front, Rear
και του μετρητή των στοιχείων της ουράς*/
   printf("---d---\n");
   AddQ(&Queue,25);
   TraverseQ(Queue);
   printf("Front=%d Rear=%d Count=%d \n",Queue.Front, Queue.Rear,Queue.Count);

/*(e) Στη συνέχεια επιχειρήστε να προσθέσετε ένα οποιοδήποτε
στοιχείο. Εμφανίστε την ουρά (με βοηθητική διαδικασία
TraverseQ), την τιμή της Front, Rear και του μετρητή των
στοιχείων της ουράς.*/
   printf("---e---\n");
   AddQ(&Queue,25);
   printf("\n");
   TraverseQ(Queue);
   printf("Front=%d Rear=%d Count=%d\n",Queue.Front, Queue.Rear,Queue.Count);

/*(f) Αδειάστε την ουρά. Μετά την αφαίρεση κάθε φορά της κεφαλής
της ουράς εμφανίστε την ουρά (με βοηθητική διαδικασία
TraverseQ), το στοιχείο που αφαιρέσατε, την τιμή της Front, Rear
και του μετρητή των στοιχείων της ουράς.*/
   printf("---f---\n");
   while(!EmptyQ(Queue)){
         RemoveQ(&Queue,&AnItem);
         TraverseQ(Queue);
         printf("Removed item=%d ",AnItem);
         printf("Front=%d Rear=%d Count=%d\n",Queue.Front, Queue.Rear,Queue.Count);
        }
   return 0;
}

  //ΣΥΝΑΡΤΗΣΕΙΣ

void TraverseQ(QueueType Queue) {
     int i;
     int current;
	 current = Queue.Front;
	 printf("Queue: ");
	 if(!EmptyQ(Queue)){
         for(i=0; i<Queue.Count; i++) {
              printf("%d ", Queue.Element[current]);
		      current = (current + 1) % QueueLimit;
         }
	 }
     else
         printf("Empty Queue");
     printf("\n");

}

//void TraverseQ(QueueType Queue) {
/*	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}*/

void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count = 0;
}
//void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
/*{
	Queue->Front = 0;
	Queue->Rear = 0;
}
*/

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Count == 0);
}
//boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
/*{
	return (Queue.Front == Queue.Rear);
}
*/
boolean FullQ(QueueType Queue)
{
	return (Queue.Count == QueueLimit);
}
//boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
/*{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}
*/

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front+1 ) % QueueLimit;
		Queue ->Count--;
	}
	else
		printf("Empty Queue");
}
//void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
/*{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}
*/

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
		{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
        Queue ->Count++;
	    }
	else
		printf("Full Queue");
}
//void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
/*{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue");
}
*/
                           //ΤΕΛΟΣ
