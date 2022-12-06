
                     //ENDGAME

/*Γράψτε ένα πρόγραμμα που θα πραγματοποιεί ορθογραφικό έλεγχο ενός κειμένου.
 Οι λέξεις που απαρτίζουν το λεξικό είναι αποθηκευμένες στο αρχείο κειμένου
‘I112f5.TXT’ (σε κάθε γραμμή του υπάρχει μία λέξη). Διαβάζονται και αποθηκεύονται
μία-μία σε ένα ΔΔΑ με τη συνάρτηση CreateDictionary και έτσι δημιουργείται
το λεξικό-ΔΔΑ. Μετά τη δημιουργία του λεξικού-ΔΔΑ θα εμφανίζετε τις λέξεις του λεξικού
Στη συνέχεια το πρόγραμμα μέσω της συνάρτησης SpellingCheck θα διαβάζει ένα κείμενο
που είναι αποθηκευμένο στο αρχείο κειμένου ‘I111F5.TXT’, σε κάθε γραμμή του
οποίου υπάρχει μία λέξη και θα διενεργεί ορθογραφικό έλεγχο, δηλαδή θα αναζητά τη λέξη
του αρχείου ‘I111F5.TXT’ στο λεξικό-ΔΔΑ. Κατά τον ορθογραφικό έλεγχο θα πρέπει να
εκτυπώνετε τις λέξεις που δεν βρέθηκαν στο λεξικό και να υπολογίζετε το πλήθος τους.
Το πλήθος των λέξεων που δεν βρέθηκαν στο λεξικό θα εμφανίζεται στη main.
Δίνονται τα πρωτότυπα των συναρτήσεων
void CreateDictionary(BinTreePointer *Root, FILE *fp);
int SpellingCheck(BinTreePointer Root, FILE *fp);
Η 1η παράμετρος της fopen θα πρέπει να περιλαμβάνει το όνομα του αρχείου χωρίς διαδρομή δηλαδή:
fp1 = fopen("i112f5.txt", "r");
Δίνεται στιγμιότυπο εμφάνισης αποτελεσμάτων*********
fp2 = fopen("i111f5.txt", "r");*Dictionary**********

array
begin
boolean
char
const
div
Δέντρα - σελίδα 4 από 10
do
else
end
for
function
if
integer
mod
procedure
program
repeat
string
then
type
var
while
**********Not in Dictionary**********
name
Pascal
Turbo
programming
text
pc
Number of words not in Dictionary: 6*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char ch;
    }BinTreeElementType[20];

typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void InorderTraversal(BinTreePointer Root);

void CreateDictionary(BinTreePointer *Root, FILE *fp);
int SpellingCheck(BinTreePointer Root, FILE *fp);

int main()
{
    FILE *fp1;
    FILE *fp2;
    BinTreePointer Root;


    int count;
    CreateDictionary(&Root,&fp1);
    //Μετά τη δημιουργία του λεξικού-ΔΔΑ θα εμφανίζετε τις λέξεις του λεξικού
    printf("**********Dictionary**********\n");
    InorderTraversal(Root);
    //Κατά τον ορθογραφικό έλεγχο θα πρέπει να κτυπώνετε τις λέξεις που δεν βρέθηκαν στο λεξικό
    fclose(fp1);
    printf("\n**********Not in Dictionary**********\n");
    count=SpellingCheck(Root,&fp2);
    //Το πλήθος των λέξεων που δεν βρέθηκαν στο λεξικό θα εμφανίζεται στη main.
    printf("Number of words not in Dictionary:%d",count);

    fclose(fp2);
    return 0;

}

/*Διαβάζονται και αποθηκεύονται
μία-μία σε ένα ΔΔΑ με τη συνάρτηση CreateDictionary και έτσι δημιουργείται
το λεξικό-ΔΔΑ.*/
void CreateDictionary(BinTreePointer *Root, FILE *fp){

    BinTreeElementType str2, str1;
    CreateBST(&(*Root));
    fp = fopen("i112f5.txt", "r");
    if (fp == NULL)
        printf("Cannot open fp file\n");
    else
    {
        while(!feof(fp)) {
             fscanf(fp, "%s", &str1);
             strcpy(str2, str1);
             BSTInsert(&(*Root),str2);
        }
    }
}
/* μέσω της συνάρτησης SpellingCheck θα διαβάζει ένα κείμενο
που είναι αποθηκευμένο στο αρχείο κειμένου ‘I111F5.TXT’, σε κάθε γραμμή του
οποίου υπάρχει μία λέξη και θα διενεργεί ορθογραφικό έλεγχο, δηλαδή θα αναζητά τη λέξη
του αρχείου ‘I111F5.TXT’ στο λεξικό-ΔΔΑ. Κατά τον ορθογραφικό έλεγχο θα πρέπει να
εκτυπώνετε τις λέξεις που δεν βρέθηκαν στο λεξικό και να υπολογίζετε το πλήθος τους.
Το πλήθος των λέξεων που δεν βρέθηκαν στο λεξικό θα εμφανίζεται στη main.*/
int SpellingCheck(BinTreePointer Root, FILE *fp){
    BinTreePointer LocPtr,Parent;
    boolean Found;
    BinTreeElementType str1,str2;
    int COUNT=0;
    fp = fopen("i111f5.txt", "r");
    if (fp == NULL)
        printf("Cannot open fp file\n");
    else
    {
        while(!feof(fp)) {
             fscanf(fp, "%s", &str1);
             strcpy(str2, str1);
             BSTSearch(Root, str2, &Found,&LocPtr);
             if (Found==FALSE){
                printf("%s\n",str1);
                COUNT++;
             }
        }

    return COUNT;
    }

}

void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{   return (Root==NULL);
}

void InorderTraversal(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s \n",Root->Data);
        InorderTraversal(Root->RChild);
    }
}


void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (strcmp(Item,LocPtr->Data)<0)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item,LocPtr->Data)>0)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %c EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr->Data,Item);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item,Parent->Data)<0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if  (strcmp(KeyValue,(*LocPtr)->Data)<0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue,(*LocPtr)->Data)>0)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του
                και τον πατέρα του κόμβου αυτού.
   Επιστρέφει: Η Found έχει τιμή TRUE, ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue και ο Parent δείχνει στον πατέρα
                αυτού του κόμβου, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE.
*/
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (strcmp(KeyValue,(*LocPtr)->Data)<0) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if(strcmp(KeyValue,(*LocPtr)->Data)>0) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

