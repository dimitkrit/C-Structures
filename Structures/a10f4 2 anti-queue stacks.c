
                //FILE a10f4 ENDGAME

/*Να γίνει πρόγραμμα που θα προσομοιώνει μια ουρά με τη βοήθεια δύο στοιβών,
δηλαδή οι λειτουργίες της ουράς θα προσομοιώνονται με τις λειτουργίες της στοίβας.
Αντί να χρησιμοποιήσετε μια ουρά αρκεί να χρησιμοποιήσετε 2 στοίβες.
Κάθε κόμβος περιέχει έναν ακέραιο αριθμό και η εισαγωγή δεδομένων θα γίνεται ως εξής:
 πλήθος στοιχείων, στοιχεία. Το πρόγραμμα θα εμφανίζει τα περιεχόμενα και των 2 στοιβών.
Η 2η στοίβα έχει καταχωρημένα τα στοιχεία όπως θα ήταν αν είχαμε χρησιμοποιήσει μια ουρά.
Δίνεται ένα στιγμιότυπο από τη εκτέλεση του προγράμματος όπου φαίνονται τα δεδομένα εισόδου
 και η εμφάνιση των αποτελεσμάτων.
PLITHOS STOIXEIWN: 5
DWSE TO 1o STOIXEIO: 23
DWSE TO 2o STOIXEIO: 12
DWSE TO 3o STOIXEIO: 7
DWSE TO 4o STOIXEIO: 35
DWSE TO 5o STOIXEIO: 3
*********1i stoiva***********
3 35 7 12 23
*********2i stoiva***********
23 12 7 35 3*/
#include <stdio.h>
#include <stdlib.h>

//__________________________________
typedef enum {
    FALSE, TRUE
} boolean;
//__________________________________

//_________STOIVA____________________
typedef char StackElementType;
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;
void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);

void TraverseStack(StackPointer Stack);
void menu(int *choice);


//ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ
int main()
{
   StackPointer AStack, BStack;
   StackElementType item;
   int i, plithos;
   CreateStack(&AStack);
   CreateStack(&BStack);

   printf("PLITHOS STOIXEIWN: ");
   plithos=GetInteger();
   for(i=1; i<=plithos; i++){
       printf("DWSE TO %d STOIXEIO: ",i);
       scanf("%d",&item);
       Push(&AStack,item);
   }
   printf("*********1i stoiva***********\n");
   TraverseStack(AStack);
   while(!EmptyStack(AStack)){
       Pop(&AStack,&item);
       Push(&BStack,item);
   }
   printf("*********2i stoiva***********\n");
   TraverseStack(BStack);

	return 0;
}

          //ΣΥΝΑΡΤΗΣΕΙΣ ΣΤΟΙΒΑΣ
void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα.
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον
                δείκτη Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack.
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας,
                αν η στοίβα δεν είναι κενή, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item.
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
