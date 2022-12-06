
                //a2jf4 DOMES Kritsimi Dimitra

/*Για τις παρακάτω λειτουργίες που αφορούν σε απλή συνδετική λίστα (Α.Σ.Λ.) με δείκτες να γραφούν διαφορετικά
προγράμματα για καθεμιά από αυτές. Γνωρίζουμε τα εξής:
 Κάθε κόμβος της ΑΣΛ ή των ΑΣΛ περιέχει έναν ακέραιο αριθμό.
 Η είσοδος των δεδομένων θα γίνεται ως εξής: Πρώτα θα διαβάζεται για κάθε ΑΣΛ το πλήθος των κόμβων της Α.Σ.Λ.
και στη συνέχεια τα στοιχεία της.
 Σε όλες τις παρακάτω ασκήσεις η εισαγωγή στοιχείου, για την κατασκευή της υπάρχουσας λίστας γίνεται στην
αρχή της λίστας.
 Σε κάθε πρόγραμμα θα εμφανίζονται οι κόμβοι της αρχικής ή των αρχικών λιστών και στη συνέχεια αυτών που
δημιουργούνται κατά την εκτέλεση του προγράμματος.
 Η εμφάνιση των δεδομένων θα γίνεται ως εξής: Τα στοιχεία των κόμβων της Α.Σ.Λ. θα εμφανίζονται σε μια γραμμή
με ένα κενό χαρακτήρα μεταξύ τους.
 Αν κατά τη διάσχιση της λίστας διαπιστώσετε ότι η Α.Σ.Λ. είναι κενή, τότε να εμφανίζετε το μήνυμα EMPTY LIST.
Σ όλα τα προγράμματα θα πρέπει να κατασκευάσετε την ΑΣΛ ή τις ΑΣΛς διαβάζοντας τα δεδομένα ως εξής: πλήθος
στοιχείων λίστας, στοιχεία λίστας ή αν πρόκειται για 2 λίστες τότε θα τα διαβάζετε ως εξής: πλήθος στοιχείων λίστας1,
στοιχεία λίστας1, πλήθος στοιχείων λίστας2, στοιχεία λίστας2
Η καθεμία από τις παρακάτω λειτουργίες να υλοποιηθεί με τη χρήση συνάρτησης*/

/*Να γραφεί συνάρτηση για την εισαγωγή m στοιχείων μετά το n-οστό στοιχείο της Α.Σ.Λ.
Το πρωτότυπο της συνάρτησης είναι void insert_list_m_elements(ListPointer *List, int n);
Το διάβασμα των δεδομένων θα γίνεται ως εξής: η Σ.Λ. (πλήθος στοιχείων λίστας, στοιχεία λίστας), στη συνέχεια ο
αριθμός n, το πλήθος m και τέλος τα m στοιχεία. Το πλήθος m και τα m στοιχεία θα διαβάζονται μέσα στη
insert_list_m_elements(). Ο έλεγχος της τιμής της n θα γίνεται μέσα στη συνάρτηση insert_list_m_elements() και
αν n > πλήθος των κόμβων της Σ.Λ., τότε θα εμφανίζεται το μήνυμα ERROR.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef int ListElementType;           /* ο τύπος των στοιχείων της συνδεδεμένης λίστας
                                        ενδεικτικά τύπου int */
typedef struct ListNode *ListPointer;   //ο τύπος των δεικτών για τους κόμβους
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);

void menu(int *choice);
void list_insertion(ListPointer *List, int choice1);


void insert_list_m_elements(ListPointer *List, int n);

int main()
{

    ListElementType i,n,plithos,number,PredPtr;

    ListPointer AList;
    PredPtr=NULL;

    CreateList(&AList);

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS:");
    scanf("%d", &plithos);
    for(i=0; i<plithos; i++){
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS:");
        scanf("%d", &number);
        LinkedInsert(&AList,number,PredPtr);
    }
    printf("*********Arxiki lista************\n");
    LinkedTraverse(AList);
    printf("DWSE TI THESI, META APO TIN OPOIA THA EISAXTHOUN TA STOIXEIA:");
    scanf("%d", &n);
    insert_list_m_elements(&AList,n);
    printf("*********Teliki lista************\n");
    LinkedTraverse(AList);
	return 0;
}

  //ΣΥΝΑΡΤΗΣΕΙΣ

/*Να γραφεί συνάρτηση για την εισαγωγή m στοιχείων μετά το n-οστό στοιχείο της Α.Σ.Λ.
Το πρωτότυπο της συνάρτησης είναι void insert_list_m_elements(ListPointer *List, int n);
Το διάβασμα των δεδομένων θα γίνεται ως εξής: η Σ.Λ. (πλήθος στοιχείων λίστας, στοιχεία λίστας), στη συνέχεια ο
αριθμός n, το πλήθος m και τέλος τα m στοιχεία. Το πλήθος m και τα m στοιχεία θα διαβάζονται μέσα στη
insert_list_m_elements(). Ο έλεγχος της τιμής της n θα γίνεται μέσα στη συνάρτηση insert_list_m_elements() και
αν n > πλήθος των κόμβων της Σ.Λ., τότε θα εμφανίζεται το μήνυμα ERROR. )*/
void insert_list_m_elements(ListPointer *List, int n){
    ListPointer Tempptr,pr;
    ListElementType  number;
    int i,m;
         if(EmptyList(&List))
             printf("EMPTY lIST");
         else{
             Tempptr = *List;
             i = 1;
             while((Tempptr->Next!=NULL) && (Tempptr!=n)){
                 if(i==n)
                    pr=Tempptr;
                 Tempptr = Tempptr->Next;
                 i++;
             }
             if(i<n || n<1)
                 printf("ERROR\n");

             else{
                  printf("DWSE TO PLITHOS TWN STOIXEIWN POU THA EISAXTHOUN:");
                  scanf("%d", &m);
                  for(i=0; i<m; i++){
                        printf("DWSE TON ARI8MO GIA EISAGWGH STH LISTA:");
                        scanf("%d", &number);
                        LinkedInsert(List, number,pr);
                        pr=pr->Next;
                 }
            }
         }
}


void CreateList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
  Επιστρέφει:  Τον μηδενικό δείκτη List
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
  Επιστρέφει: True αν η λίστα είναι κενή και false διαφορετικά
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο,
                ένα στοιχείο δεδομένων Item και έναν δείκτη PredPtr.
   Λειτουργία: Εισάγει έναν κόμβο, που περιέχει το Item, στην συνδεδεμένη λίστα
                μετά από τον κόμβο που δεικτοδοτείται από τον PredPtr
                ή στην αρχή  της συνδεδεμένης λίστας,
                αν ο PredPtr είναι μηδενικός(NULL).
  Επιστρέφει:  Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο της
                να δεικτοδοτείται από τον List.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
 /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
   &List, List,  &(*List), (*List), TempPtr); */
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο της
                 και έναν δείκτη PredPtr.
   Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα τον κόμβο που έχει
                για προηγούμενό του αυτόν στον οποίο δείχνει ο PredPtr
                ή διαγράφει τον πρώτο κόμβο, αν ο PredPtr είναι μηδενικός,
                εκτός και αν η λίστα είναι κενή.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο
                να δεικτοδοτείται από τον List.
   Έξοδος:     Ένα μήνυμα κενής λίστας αν η συνδεδεμένη λίστα ήταν κενή .
*/
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
   Λειτουργία: Διασχίζει τη συνδεδεμένη λίστα και
                επεξεργάζεται κάθε δεδομένο ακριβώς μια φορά.
   Επιστρέφει: Εξαρτάται από το είδος της επεξεργασίας.
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
   	 //   printf("%p\n",CurrPtr);
   	 //   printf("%-16s\t%-4s\t%-16s\n", "CurrPtr","Data","Next");
         while ( CurrPtr!=NULL )
        {
             printf("%d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
           printf("\n");

   }
}


void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Εκτελεί μια γραμμική αναζήτηση στην μη ταξινομημένη συνδεδεμένη
              λίστα για έναν κόμβο που να περιέχει το στοιχείο Item.
  Επιστρέφει: Αν η αναζήτηση είναι επιτυχής η Found είναι true, ο CurrPtr δείχνει
                στον κόμβο που περιέχει το Item και ο PredPtr στον προηγούμενό του
                ή είναι nil αν δεν υπάρχει προηγούμενος.
                Αν η αναζήτηση δεν είναι επιτυχής η Found είναι false.
*/
{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* Δέχεται:    Ένα στοιχείο Item και μια ταξινομημένη συνδεδεμένη λίστα,
                που περιέχει στοιχεία δεδομένων σε αύξουσα διάταξη και στην οποία
                ο δείκτης List δείχνει στον πρώτο  κόμβο.
   Λειτουργία: Εκτελεί γραμμική αναζήτηση της συνδεδεμένης ταξινομημένης λίστας
                για τον πρώτο κόμβο που περιέχει το στοιχείο Item ή για μια θέση
                για να εισάγει ένα νέο κόμβο που να περιέχει το στοιχείο Item.
   Επιστρέφει: Αν η αναζήτηση είναι επιτυχής η Found είναι true,
                ο CurrPtr δείχνει στον κόμβο που περιέχει το Item και
                ο PredPtr στον προηγούμενό του ή είναι nil αν δεν υπάρχει προηγούμενος.
                Αν η αναζήτηση δεν είναι επιτυχής η Found είναι false.
*/
{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}


