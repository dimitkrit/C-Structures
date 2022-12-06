

                      // File a8f2 DOMES ENDGAME


/*Γράψτε ένα πρόγραμμα που θα δέχεται ένα αλφαριθμητικό, διαβάζοντας το χαρακτήρα προς χαρακτήρα (μέχρι ο
χρήστης να δώσει ως χαρακτήρα #) και θα ελέγχει αν το αλφαριθμητικό που έχει σχηματιστεί, έχει τη μορφή
x C y
όπου x είναι ένα αλφαριθμητικό και y είναι το αντίστροφο του x. Για παράδειγμα, αν x = ‘ΑΒΑΒΒΑ’ τότε y =
‘ABBABA’. Ο έλεγχος θα γίνεται κατά το διάβασμα του κάθε χαρακτήρα. Το πρόγραμμα θα σταματάει να διαβάζει
χαρακτήρες είτε όταν δοθεί ο χαρακτήρας ‘#’, είτε μόλις διαπιστώσει ότι το αλφαριθμητικό δεν ακολουθεί την
επιθυμητή μορφή. Πριν τερματίσει θα εμφανίζει το μήνυμα TRUE ή FALSE αντίστοιχα αν το αλφαριθμητικό έχει ή
όχι αυτή τη μορφή.
Υπόδειξη: οι χαρακτήρες που θα διαβαστούν μέχρι να δοθεί ο χαρακτήρας ‘C’ εισάγονται σε μια στοίβα και κάθε
χαρακτήρας που διαβάζεται μετά τον ‘C’ συγκρίνεται με το στοιχείο που βρίσκεται στην κορυφή της στοίβας. Για το
διάβασμα κάθε χαρακτήρα χρησιμοποιείστε : scanf("%c", &ch); getchar();*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define StackLimit 80  // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 80
//ΔΟΜΕΣ
typedef char StackElementType;  // ο τύπος των στοιχείων  της στοίβας
                                //ενδεικτικά τύπος char

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

//ΟΡΙΣΜΟΣ ΣΥΝΑΡΤΗΣΕΩΝ
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);




//ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ
int main()
{
    StackElementType item,ch;
    StackType AStack;

    bool flag;

    //ΔΗΜΙΟΥΡΓΙΑ ΣΤΟΙΒΑΣ
    CreateStack(&AStack);
    //ΔΙΑΒΑΣΜΑ ΠΡΩΤΟΥ ΧΑΡΑΚΤΗΡΑ
    printf("Enter string: \n");
    scanf("%c", &item); getchar();
    //ΕΛΕΓΧΟΣ ΓΙΑ = #
    if(item=='#')
           return 0;
    //ΕΛΕΓΧΟΣ ΓΙΑ = C
    else
        if(item=='C'){

            scanf("%c", &ch);getchar();

            if(ch=='#')
                flag=TRUE;
            else
                flag=FALSE;
        }
        else{        //ΓΕΜΙΣΜΑ ΣΤΟΙΒΑΣ
            Push(&AStack,item);
            while((item!='#')&&(item!='C')){
                  scanf("%c", &item);getchar();
                  Push(&AStack,item);
             }
             Pop(&AStack,&item);
             if(item=='#')
                flag=FALSE;
             if(item=='C'){
                Pop(&AStack,&item);
                scanf("%c", &ch);getchar();
             }        //ΕΛΕΓΧΟΣ ΕΝΑ ΠΡΟΣ ΕΝΑ ΤΩΝ ΧΑΡΑΚΤΗΡΩΝ ΣΤΟΙΒΑΣ-ΧΑΡΑΚΤΗΡΩΝ ΜΕΤΑ ΤΟ C
             while(!EmptyStack(AStack)){
                     if(item!=ch){
                            flag=FALSE;
                            break;
                     }
                     if(item==ch){
                          scanf("%c", &ch);getchar();
                          Pop(&AStack,&item);
                     }
             }
             if(item==ch){

                    scanf("%c", &ch);getchar();
                    if (ch=='#')
                           flag=TRUE;
                    else
                           flag=FALSE;

             }
        }
          //ΕΜΦΑΝΙΣΗ ΑΠΟΤΕΛΕΣΜΑΤΩΝ
        if(flag==TRUE)
              printf("TRUE");
        else
              printf("FALSE");

  return 0;

}

//ΣΥΝΑΡΤΗΣΕΙΣ
void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται:    Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος:     Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:     Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}




