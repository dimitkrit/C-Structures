
                   //a9f4 DOMES ENDGAME

/* Να γραφεί πρόγραμμα που να διαβάζει ένα αλφαριθμητικό και στη συνέχεια να προσθέτει
 έναν-ένα τους χαρακτήρες του σε μια στοίβα και σε μια ουρά ταυτόχρονα.
 Μετά το τέλος της εισαγωγής των χαρακτήρων του αλφαριθμητικού στη στοίβα και στην ουρά
 θα εμφανίζετε τα στοιχεία της στοίβας και της ουράς.
 Η εμφάνιση των στοιχείων της στοίβας και ουράς θα γίνεται όπως περιγράφεται
 στις Παρατηρήσεις στο σημείο 2i. Στη συνέχεια θα ελέγχετε αν το αλφαριθμητικό
 είναι καρκινικό, οπότε κι θα εμφανίζετε το μήνυμα ‘ACCEPTED’, ή όχι,
 οπότε θα εμφανίζετε το μήνυμα ‘REJECTED’ (χρησιμοποιήστε τις διαδικασίες:
 εισαγωγή στοιχείου σε στοίβα,
 εισαγωγή στοιχείου σε ουρά,
 εξαγωγή στοιχείου από στοίβα,
 εξαγωγή στοιχείου από ουρά με δυναμική υλοποίηση).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//__________OURA_____________________
typedef char QueueElementType;
typedef struct QueueNode *QueuePointer;
typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;
typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;
//__________________________________
typedef enum {
    FALSE, TRUE
} boolean;
//__________________________________
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);

void menu(int *choice);
void TraverseQ(QueueType Queue);
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



int main()
{
   StackPointer AStack;
   char str[20];
   StackElementType Item;
   int i=0;
   QueueType AQueue;
   QueueElementType AnItem;
   boolean result;

   CreateStack(&AStack);
   CreateQ(&AQueue);
   printf("DWSE TO ALFARITHMITIKO:");
   gets(str);
  // fgets(str,20,stdin);
   for(i=0; i<strlen(str); i++){
       Push(&AStack,str[i]);
       AddQ(&AQueue,str[i]);
   }
   printf("-------Stack of characters-------\n");
   TraverseStack(AStack);
   printf("-------Queue of characters-------\n");
   TraverseQ(AQueue);
   while(!EmptyStack(AStack) && !EmptyQ(AQueue)){
         Pop(&AStack,&Item);
         RemoveQ(&AQueue,&AnItem);
         if(Item==AnItem)
              result=TRUE;
         else
              result=FALSE;
              break;
   }

   if(result==TRUE)
        printf("%s ACCEPTED",str);
   else
        printf("%s REJECTED",str);
	return 0;
}


          //ΣΥΝΑΡΤΗΣΕΙΣ ΟΥΡΑΣ
void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%c ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
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
      	     printf("%c ", CurrPtr->Data);
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
