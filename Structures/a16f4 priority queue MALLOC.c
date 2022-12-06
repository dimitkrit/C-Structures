
                      //a16f4 DOMES ENDGAME
/*
Σε μία ουρά κάθε στοιχείο εισέρχεται σε κάποια συγκεκριμένη θέση
σύμφωνα με το βαθμό προτεραιότητας (σε αύξουσα σειρά).
Να γραφεί πρόγραμμα που θα περιλαμβάνει τα παρακάτω:
-Εισαγωγή του πλήθους των κόμβων της ουράς.
- Τη συνάρτηση void insert_prot(QueueType *Queue, QueueElementType Item)
την εισαγωγή στοιχείων στην ουρά, κάθε κόμβος της οποίας θα περιέχει
έναν τριψήφιο κωδικό αριθμό και τον βαθμό προτεραιότητας (1-20).
Σε περίπτωση ίδιου βαθμού προτεραιότητας το στοιχείο εισέρχεται
τελευταίο στην αντίστοιχη προτεραιότητα.
- Τη συνάρτηση void TraverseQ(QueueType Queue) που θα εμφανίζει
τα περιεχόμενα της ουράς κατά αύξοντα βαθμό προτεραιότητας.
Τα στοιχεία κάθε κόμβου εμφανίζονται σε ξεχωριστή σειρά με ένα κενό
 μεταξύ τους και πρώτο το βαθμό προτεραιότητας.
Στη συνέχεια δίνεται ένα στιγμιότυπο εκτέλεσης
DWSE TO PLITHOS: 6
DWSE TON KODIKO TOU 1ou KOMVOU: 123
DWSE TO VATHMO PROTERAIOTITAS TOU 1ou KOMVOU: 2
DWSE TON KODIKO TOU 2ou KOMVOU: 234
DWSE TO VATHMO PROTERAIOTITAS TOU 2ou KOMVOU: 1
DWSE TON KODIKO TOU 3ou KOMVOU: 345
DWSE TO VATHMO PROTERAIOTITAS TOU 3ou KOMVOU: 6
DWSE TON KODIKO TOU 4ou KOMVOU: 456
DWSE TO VATHMO PROTERAIOTITAS TOU 4ou KOMVOU: 1
DWSE TON KODIKO TOU 5ou KOMVOU: 567
DWSE TO VATHMO PROTERAIOTITAS TOU 5ou KOMVOU: 3
DWSE TON KODIKO TOU 6ou KOMVOU: 678
DWSE TO VATHMO PROTERAIOTITAS TOU 6ou KOMVOU: 2
----------Priority Queue-------------
1 234
1 456
2 123
2 678
3 567
6 345
*/
#include <stdio.h>
#include <stdlib.h>

//__________OURA_____________________

typedef struct QueueNode *QueuePointer;
typedef struct
{
  int code,vathmos;
} QueueElementType;
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

void TraverseQ(QueueType Queue);
void insert_prot(QueueType *Queue, QueueElementType Item );

//ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ
int main()
{
   QueueType Queue;
   QueueElementType Item;

   int plithos,code,vathmos;
   CreateQ(&Queue);

   //-Εισαγωγή του πλήθους των κόμβων της ουράς.
   printf("DWSE TO PLITHOS: ");
   scanf("%d",&plithos);
   int i;
   for(i=1; i<=plithos; i++){
        printf("DWSE TON KODIKO TOU %dou KOMVOU: ",i);
        scanf("%d",&code);
        Item.code=code;
        printf("DWSE TO VATHMO PROTERAIOTITAS TOU %dou KOMVOU: ",i);
        scanf("%d",&vathmos);
        Item.vathmos=vathmos;
        insert_prot(&Queue,Item);
   }
   printf("----------Priority Queue-------------\n");
   TraverseQ(Queue);

   return 0;
}


          //ΣΥΝΑΡΤΗΣΕΙΣ ΟΥΡΑΣ

 /* - Τη συνάρτηση void insert_prot(QueueType *Queue, QueueElementType Item)
την εισαγωγή στοιχείων στην ουρά, κάθε κόμβος της οποίας θα περιέχει
έναν τριψήφιο κωδικό αριθμό και τον βαθμό προτεραιότητας (1-20).
Σε περίπτωση ίδιου βαθμού προτεραιότητας το στοιχείο εισέρχεται
τελευταίο στην αντίστοιχη προτεραιότητα.*/
void insert_prot(QueueType *Queue, QueueElementType Item){
     QueuePointer neo,trexon,prev;
     neo = (QueuePointer)malloc(sizeof(struct QueueNode));
     boolean flag=FALSE;
     neo->Data = Item;
     neo->Next = NULL;
     if (EmptyQ(*Queue)){
        Queue->Front = neo;//αν είναι άδεια η ουρά το νέο στοιχείο είναι το μοναδικό
        Queue->Rear = neo;
    }
    else{//αλλιώς θα συγκρίνουμε
        prev=Queue->Front;
        trexon=Queue->Front;
        flag=FALSE;
        if(trexon->Data.vathmos>neo->Data.vathmos){
            Queue->Front = neo;
            neo->Next = trexon; //αν το νεο είναι μικρότερο πάει μπροστά
        }
        else{
             while(trexon!=NULL && flag==FALSE){
                 if(trexon->Data.vathmos>neo->Data.vathmos){
                      prev->Next = neo;
                      neo->Next = trexon;
                      flag=TRUE;
                 }
                 prev = trexon;
                 trexon = trexon->Next;
            }
             if(flag==FALSE){
                 prev->Next=neo;
                 Queue->Rear=neo;
            }
        }
    }
}

  /*  Τη συνάρτηση void TraverseQ(QueueType Queue) που θα εμφανίζει
τα περιεχόμενα της ουράς κατά αύξοντα βαθμό προτεραιότητας.
Τα στοιχεία κάθε κόμβου εμφανίζονται σε ξεχωριστή σειρά με ένα κενό
 μεταξύ τους και πρώτο το βαθμό προτεραιότητας.*/

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
          printf("%d ", CurrPtr->Data.vathmos);
      	  printf("%d \n", CurrPtr->Data.code);
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
