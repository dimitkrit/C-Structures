
                     //ENDGAME

/*Το αρχείο transactions.txt περιλαμβάνει ύποπτες συναλλαγές
 και θέλουμε να εντοπίσουμε τις m μεγαλύτερες συναλλαγές.
  Η διαθέσιμη μνήμη δεν επαρκεί για να διαβάσουμε όλες τις συναλλαγές
  από το αρχείο και να τις αποθηκεύσουμε σε μια δομή δεδομένων στη μνήμη.
Επιλέξτε την κατάλληλη δομή δεδομένων ώστε να βρίσκει τις m μεγαλύτερες συναλλαγές.
 Μετά την εύρεση των m μεγαλύτερων συναλλαγών θα εμφανίζει το μέγεθος
 και τα στοιχεία της δομής δεδομένων (προσαρμόστε κατάλληλα την PrintHeap)
  και στη συνέχεια θα εμφανίσει σε αύξουσα διάταξη τις m μεγαλύτερες συναλλαγές.
  Την τιμή της m θα τη δίνει ο χρήστης, και θεωρήστε ότι δίνεται τιμή πολύ
  μικρότερη του μεγέθους του αρχείου χωρίς να γίνεται σχετικός έλεγχος.
   Ως δομή δεδομένων θα πρέπει να χρησιμοποιηθεί σωρός (μέγιστος ή ελάχιστος σωρός;).
    Δίνεται ένα στιγμιότυπο εκτέλεσης:
Give m: 5
Data Structure size =5
4121.85 4409.74 4381.21 4747.08 4732.35
Transactions
4121.85 4381.21 4409.74 4732.35 4747.08*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define  MaxElements 10         //το μέγιστο πλήθος των στοιχείων του σωρού

typedef float  HeapElementType;    //ο τύπος δεδομένων των στοιχείων του σωρού
typedef  struct {
     HeapElementType key;
    // int Data;                // οποισδήποτε τύπος για τα παρελκόμενα δεδομένα κάθε κόμβου
} HeapNode;


typedef struct {
        int Size;
        HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;
//----------ΔΗΛΩΣΗ ΣΥΝΑΡΤΗΣΕΩΝ---------------
//---------------ΜΙΝ-------------------------
void CreateMinHeap(HeapType *Heap);
void InsertMinHeap(HeapType *Heap, HeapNode Item);
void DeleteMinHeap(HeapType *Heap, HeapNode *Item);
//---------------ΜΑΧ-------------------------
void InsertMaxHeap(HeapType *Heap, HeapNode Item);
void CreateMaxHeap(HeapType *Heap);
void DeleteMaxHeap(HeapType *Heap, HeapNode *Item);
//--------------------------------------------
void PrintHeap(HeapType Heap);
boolean FullHeap(HeapType Heap);
boolean EmptyHeap(HeapType Heap);

//----------ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ
int main()
{
   HeapType Heap;
   FILE *fp;
   HeapNode TRANSACTION;
   CreateMinHeap(&Heap);
   int m;
   printf("Give m:");
   scanf("%d", &m);
   fp = fopen("transactions.txt", "r");
    if (fp == NULL)
        printf("Cannot open fp file\n");
    else
    {
        while(!feof(fp)) {
             fscanf(fp, "%f", &TRANSACTION.key);
             InsertMinHeap(&Heap, TRANSACTION);
             if (Heap.Size > m)
                DeleteMinHeap(&Heap, &TRANSACTION);
            }
    }
    PrintHeap(Heap);
    printf("Transactions\n");
    while(!EmptyHeap(Heap)){
        DeleteMinHeap(&Heap, &TRANSACTION);
        printf("%.2f ",TRANSACTION.key);
    }
    fclose(fp);
   return 0;
}
 //-----------------------------------------------------------
          //ΣΥΝΑΡΤΗΣΕΙΣ
//------------------------------------------------------------


void PrintHeap(HeapType Heap)
{
    int i,l,r,n;
    printf("Data Structure size =%d \n",Heap.Size);
    /* printf("N   L   R\n");
     n=Heap.Size/2;
     for (i=1; i<=n;i++)
     {
         l=2*i;
         r=2*i+1;
         printf("%.2f, ",Heap.Element[i].key);
         if (l<=Heap.Size)
            printf("%.2f, ",Heap.Element[l].key);
         else printf(",   ");
         if (r<=Heap.Size)
            printf("%.2f \n",Heap.Element[r].key);
         else printf("\n");
     }
     printf("Heap array\n");*/
     for (i=1; i<=Heap.Size;i++)
        printf("%.2f ",Heap.Element[i].key);
    printf(" \n");
}

boolean EmptyHeap(HeapType Heap)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ελέγχει αν ο σωρός είναι κενός.
   Επιστρέφει: TRUE αν ο σωρός είναι κενός, FALSE διαφορετικά
*/
{
  return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap)
/* Δέχεται:    Ένα σωρό.
   Λειτουργία: Ελέγχει αν ο σωρός είναι γεμάτος.
   Επιστρέφει: TRUE αν ο σωρός είναι γεμάτος, FALSE διαφορετικά
*/
{
  return (Heap.Size==MaxElements);
}
//----------------------------------------------------------
                     //MIN
//----------------------------------------------------------
void CreateMinHeap(HeapType *Heap)
/* Λειτουργία: Δημιουργεί ένα κενό σωρό.
   Επιστρέφει: Ένα κενό σωρό
*/
{
  (*Heap).Size=0;
}

void InsertMinHeap(HeapType *Heap, HeapNode Item)
{
   int hole;

   if (!FullHeap(*Heap))
   {
          (*Heap).Size++;

          hole=(*Heap).Size;
          while (hole>1 && Item.key < Heap->Element[hole/2].key)
          {
            (*Heap).Element[hole]=(*Heap).Element[hole/2];
                      hole=hole/2;
          }
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}


void DeleteMinHeap(HeapType *Heap, HeapNode *Item)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ανακτά και διαγράφει το μεγαλύτερο στοιχείο του σωρού.
   Επιστρέφει: Το μεγαλύτερο στοιχείο Item του σωρού και τον τροποποιημένο σωρό
*/
{
   int parent, child;
   HeapNode last;
   boolean done;

   if (!EmptyHeap(*Heap))
   {
        done=FALSE;
        *Item=(*Heap).Element[1];
        last=(*Heap).Element[(*Heap).Size];
        (*Heap).Size--;

        parent=1; child=2;

        while (child<=(*Heap).Size && !done)
        {
            if (child<(*Heap).Size)
                if ((*Heap).Element[child].key > (*Heap).Element[child+1].key)
                    child++;
            if (last.key <= (*Heap).Element[child].key)
                done=TRUE;
            else
            {
               (*Heap).Element[parent]=(*Heap).Element[child];
               parent=child;
               child=2*child;
            }
        }
        (*Heap).Element[parent]=last;
    }
   else
       printf("Empty heap...\n");
}

//----------------------------------------------------------
                   //MAX
//-----------------------------------------------------------
void CreateMaxHeap(HeapType *Heap)
/* Λειτουργία: Δημιουργεί ένα κενό σωρό.
   Επιστρέφει: Ένα κενό σωρό
*/
{
  (*Heap).Size=0;
}
void InsertMaxHeap(HeapType *Heap, HeapNode Item)
/*  Δέχεται:    Ένα σωρό Heap και ένα στοιχείο δεδομένου Item .
    Λειτουργία: Εισάγει το στοιχείο Item στο σωρό, αν ο σωρός δεν είναι γεμάτος.
    Επιστρέφει: Τον τροποποιημένο σωρό.
    Έξοδος:     Μήνυμα γεμάτου σωρού αν ο σωρός είναι γεμάτος
*/
{
   int hole;

   if (!FullHeap(*Heap))
   {
          (*Heap).Size++;

          hole=(*Heap).Size;
          while (hole>1 && Item.key > Heap->Element[hole/2].key)
          {
            (*Heap).Element[hole]=(*Heap).Element[hole/2];
                      hole=hole/2;
          }
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}
void DeleteMaxHeap(HeapType *Heap, HeapNode *Item)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ανακτά και διαγράφει το μεγαλύτερο στοιχείο του σωρού.
   Επιστρέφει: Το μεγαλύτερο στοιχείο Item του σωρού και τον τροποποιημένο σωρό
*/
{
   int parent, child;
   HeapNode last;
   boolean done;

   if (!EmptyHeap(*Heap))
   {
        done=FALSE;
        *Item=(*Heap).Element[1];
        last=(*Heap).Element[(*Heap).Size];
        (*Heap).Size--;

        parent=1; child=2;

        while (child<=(*Heap).Size && !done)
        {
            if (child<(*Heap).Size)
                if ((*Heap).Element[child].key < (*Heap).Element[child+1].key)
                    child++;
            if (last.key >= (*Heap).Element[child].key)
                done=TRUE;
            else
            {
               (*Heap).Element[parent]=(*Heap).Element[child];
               parent=child;
               child=2*child;
            }
        }
        (*Heap).Element[parent]=last;
    }
   else
       printf("Empty heap...\n");
}



