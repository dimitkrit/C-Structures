
                     //ENDGAME

/*Γράψτε ένα πρόγραμμα για τη δημιουργία και επεξεργασία μιας ΔΔ που αποθηκεύει
και επεξεργάζεται τα στοιχεία της με την τεχνική του κατακερματισμού με αλυσίδες
συνωνύμων, στην οποία αποθηκεύονται τα στοιχεία των μελών ενός γυμναστηρίου.
Κάθε εγγραφή περιλαμβάνει τα εξής στοιχεία της κάρτας μέλους που δίνεται
σε κάθε μέλος όταν εγγράφεται στο γυμναστήριο:
 τον κωδικό (ακέραιος αριθμός – κλειδί κατακερματισμού)
 το όνομα μέλους (username) (αλφαριθμητικό 20 θέσεων)
 το ποσό οφειλής του μέλους στο γυμναστήριο (ακέραιος)
Η συνάρτηση κατακερματισμού να είναι: h(i) = i % 5.
Στο κυρίως πρόγραμμα θα υλοποιούνται στη σειρά οι παρακάτω λειτουργίες:
1. Create HashList
Δημιουργία της δομής δεδομένων
2. Insert new member
Εισαγωγή νέου μέλους
3. Search for a member
Αναζήτηση μέλους – αν υπάρχει μέλος με το συγκεκριμένο κωδικό θα εμφανίζονται
τα στοιχεία του, αλλιώς θα εμφανίζεται το μήνυμα ‘DEN YPARXEI EGGRAFH ME KLEIDI x’,
όπου x ο κωδικός που δόθηκε προς αναζήτηση
4. Update member amount
Ενημέρωση της οφειλής του μέλους – ο χρήστης δίνει τον κωδικό του μέλους και το ποσό
και ενημερώνεται κατάλληλα το ποσό της οφειλής. Κατ’ αρχήν θα γίνεται έλεγχος αν υπάρχει
μέλος με το συγκεκριμένο κωδικό, αν δεν υπάρχει θα εμφανίζεται το μήνυμα
‘DEN YPARXEI EGGRAFH ME KLEIDI x’, όπου x ο κωδικός που δόθηκε.
Αν ο κωδικός υπάρχει θα διαβάζεται το ποσό που θα πληρώσει.
Θα γίνεται έλεγχος ώστε το ποσό που δίνεται να είναι μικρότερο ή ίσο της καταχωρημένης οφειλής.
5. Delete a member
Διαγραφή μέλους – η διαγραφή δεν μπορεί να πραγματοποιηθεί αν το ποσό οφειλής του μέλους δεν έχει εξοφληθεί.
Σε αυτή την περίπτωση η διαγραφή δεν πραγματοποιείται και εμφανίζεται το μήνυμα ‘Not deleted arrange amount’.
Κατ’ αρχήν θα γίνεται έλεγχος αν υπάρχει μέλος με το συγκεκριμένο κωδικό,
αν δεν υπάρχει θα εμφανίζεται το μήνυμα ‘DEN YPARXEI EGGRAFH ME KLEIDI x’, όπου x ο κωδικός που δόθηκε.
6. Print list of synonyms
Ο χρήστης δίνει τον κωδικό ενός μέλους του γυμναστηρίου και εμφανίζονται τα περιεχόμενα της υπολίστας
των συνωνύμων στην οποία ανήκει. Θα γίνεται έλεγχος αν υπάρχει μέλος με το συγκεκριμένο κωδικό,
αν δεν υπάρχει θα εμφανίζεται το μήνυμα ‘DEN YPARXEI EGGRAFH ME KLEIDI x’, όπου x ο κωδικός που δόθηκε.
Συνάρτηση void PrintListOfSynonyms(HashListType HList, int key);


Για τις λειτουργίες 2 έως και 6 ο χρήστης του προγράμματος θα έχει τη δυνατότητα εισαγωγής,
αναζήτησης, ενημέρωσης, διαγραφής και εμφάνισης της λίστας συνωνύμων
για όσα μέλη του γυμναστηρίου επιθυμεί μέσω σχετικού μηνύματος ‘Continue Y/N?’

Μετά τις λειτουργίες 1, 2, 4, 5 θα καλείτε τις Print_HashList(HList) και PrintPinakes(HList).
Στην Print_HashList(HList) δε θα εμφανίζετε τη λίστα με τις ελεύθερες θέσεις της δομής.*/


#define HMax 5              /*     το μέγεθος του πίνακα HashTable ενδεικτικά ίσο με 5 */

#define VMax 30             /*το μέγεθος της λίστας,
                                ενδεικτικά ίσο με 30 */
#define EndOfList -1        /* σημαία που σηματοδοτεί το τέλος της λίστας
                                και της κάθε υπολίστας συνωνύμων */
#include <stdio.h>
#include <ctype.h>

//typedef int ListElementType;  /*τύπος δεδομένων για τα στοιχεία της λίστας
                               //* ενδεικτικά τύπου int */
typedef int KeyType;

typedef struct{
    char username[20]; // το όνομα μέλους (username) (αλφαριθμητικό 20 θέσεων)
    int poso; // το ποσό οφειλής του μέλους στο γυμναστήριο (ακέραιος)
}ListElementType;


typedef struct {
	KeyType RecKey;//τον κωδικό (ακέραιος αριθμός – κλειδί κατακερματισμού)
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // πίνακας δεικτών προς τις υπολίστες συνωνύμων
    int Size;                // πλήθος εγγραφών της λίστας List
	int SubListPtr;          // Dδείκτης σε μια υπολίστα συνωνύμων
    int StackPtr;           // δείκτης προς την πρώτη ελεύθερη θέση της λίστας List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);

void Print_HashList(HashListType HList);
void PrintPinakes(HashListType HList);

void PrintListOfSynonyms(HashListType HList, KeyType key);

//---------------------ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ--------------------------------------------------
//**************************************************************************************

int main(){

     char ch;
     HashListType HList;
     ListElm AnItem;
     KeyType AKey;
     int Loc, Pred;
     int amount;
/*Για τις λειτουργίες 2 έως και 6 ο χρήστης του προγράμματος θα έχει τη δυνατότητα εισαγωγής,
αναζήτησης, ενημέρωσης, διαγραφής και εμφάνισης της λίστας συνωνύμων
για όσα μέλη του γυμναστηρίου επιθυμεί μέσω σχετικού μηνύματος ‘Continue Y/N?’ */



//1 ------------------Δημιουργία της δομής δεδομένων------------------------------

     printf("1. Create HashList\n");
     CreateHashList(&HList);
     Print_HashList(HList);
     PrintPinakes(HList);

//2 ------------------Εισαγωγή νέου μέλους------------------------------

    printf("2. Insert new member\n");
    do{
       printf("Give code: ");
       scanf("%d", &AnItem.RecKey);
       printf("Give name: ");
       scanf("%s", &AnItem.Data.username);
       printf("Give amount: ");
       scanf("%d", &AnItem.Data.poso);
       AnItem.Link=EndOfList;
       AddRec(&HList,AnItem);
       printf("\nContinue Y/N: ");

       do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
      } while (toupper(ch)!='N');
      Print_HashList(HList);
      PrintPinakes(HList);

//3 ------------------Αναζήτηση μέλους------------------------------

    /*αν υπάρχει μέλος με το συγκεκριμένο κωδικό θα εμφανίζονται
τα στοιχεία του, αλλιώς θα εμφανίζεται το μήνυμα ‘DEN YPARXEI EGGRAFH ME KLEIDI x’,
όπου x ο κωδικός που δόθηκε προς αναζήτηση*/

     printf("3. Search for a member\n");
     do{
        printf("Give code: ");
        scanf("%d",&AKey);
        SearchHashList(HList,AKey,&Loc,&Pred);
        if ( Loc != -1)
               printf("[%d, %s, %d, %d]\n",
               HList.List[Loc].RecKey,HList.List[Loc].Data.username,HList.List[Loc].Data.poso,HList.List[Loc].Link);
        else
               printf("DEN YPARXEI EGGRAFH ME KLEIDI %d\n", AKey);
        printf("\nContinue Y/N: ");
        do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
        } while (toupper(ch)!='N');
    //  Print_HashList(HList);
    //  PrintPinakes(HList);

//4 ------------------Ενημέρωση της οφειλής του μέλους------------------------------

  /*ο χρήστης δίνει τον κωδικό του μέλους και το ποσό
και ενημερώνεται κατάλληλα το ποσό της οφειλής. Κατ’ αρχήν θα γίνεται έλεγχος αν υπάρχει
μέλος με το συγκεκριμένο κωδικό, αν δεν υπάρχει θα εμφανίζεται το μήνυμα
‘DEN YPARXEI EGGRAFH ME KLEIDI x’, όπου x ο κωδικός που δόθηκε.
Αν ο κωδικός υπάρχει θα διαβάζεται το ποσό που θα πληρώσει.
Θα γίνεται έλεγχος ώστε το ποσό που δίνεται να είναι μικρότερο ή ίσο της καταχωρημένης οφειλής.*/
      printf("4. Update member amount\n");
      do{
        printf("Give code: ");
        scanf("%d",&AKey);
        SearchHashList(HList,AKey,&Loc,&Pred);
        if ( Loc != -1){
              printf("[%d, %s, %d, %d]\n",
              HList.List[Loc].RecKey,HList.List[Loc].Data.username,HList.List[Loc].Data.poso,HList.List[Loc].Link);
              printf("Give amount: ");
              scanf("%d",&amount);
              if(HList.List[Loc].Data.poso>=amount)
                    HList.List[Loc].Data.poso = HList.List[Loc].Data.poso - amount;
        }
        else
              printf("DEN YPARXEI EGGRAFH ME KLEIDI %d\n", AKey);
        printf("\nContinue Y/N: ");
        do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
       } while (toupper(ch)!='N');
       Print_HashList(HList);
       PrintPinakes(HList);

//5------------------Διαγραφή μέλους------------------------------

 /*η διαγραφή δεν μπορεί να πραγματοποιηθεί αν το ποσό οφειλής του μέλους δεν έχει εξοφληθεί.
Σε αυτή την περίπτωση η διαγραφή δεν πραγματοποιείται και εμφανίζεται το μήνυμα ‘Not deleted arrange amount’.
Κατ’ αρχήν θα γίνεται έλεγχος αν υπάρχει μέλος με το συγκεκριμένο κωδικό,
αν δεν υπάρχει θα εμφανίζεται το μήνυμα ‘DEN YPARXEI EGGRAFH ME KLEIDI x’, όπου x ο κωδικός που δόθηκε.*/
      printf("5. Delete a member\n");
      do{
           printf("Give code: ");
           scanf("%d",&AKey);
           SearchHashList(HList,AKey,&Loc,&Pred);
           if ( Loc != -1){
               if(HList.List[Loc].Data.poso == 0)
                    DeleteRec(&HList,AKey);
               else
                    printf("Not deleted arrange amount\n");
           }
           else
               printf("DEN YPARXEI EGGRAFH ME KLEIDI %d\n", AKey);
           printf("\nContinue Y/N: ");
           do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
       } while (toupper(ch)!='N');
       Print_HashList(HList);
       PrintPinakes(HList);

//6 ------------------Εμφάνιση------------------------------

/*Ο χρήστης δίνει τον κωδικό ενός μέλους του γυμναστηρίου και εμφανίζονται τα περιεχόμενα της υπολίστας
των συνωνύμων στην οποία ανήκει. Θα γίνεται έλεγχος αν υπάρχει μέλος με το συγκεκριμένο κωδικό,
αν δεν υπάρχει θα εμφανίζεται το μήνυμα ‘DEN YPARXEI EGGRAFH ME KLEIDI x’, όπου x ο κωδικός που δόθηκε.
Συνάρτηση void PrintListOfSynonyms(HashListType HList, int key);
θα καλείτε τις Print_HashList(HList) και PrintPinakes(HList).
Στην Print_HashList(HList) δε θα εμφανίζετε τη λίστα με τις ελεύθερες θέσεις της δομής*/
      printf("6. Print list of synonyms\n");
      do{
           printf("Give code: ");
           scanf("%d",&AKey);
           SearchHashList(HList,AKey,&Loc,&Pred);
           if ( Loc != -1){
               // printf("[%d, %s, %d, %d]\n",
                //HList.List[Loc].RecKey,HList.List[Loc].Data.username,HList.List[Loc].Data.poso,HList.List[Loc].Link);
                PrintListOfSynonyms(HList, AKey);
           }
           else
                printf("DEN YPARXEI EGGRAFH ME KLEIDI %d\n", AKey);
           printf("\nContinue Y/N: ");
           do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
        } while (toupper(ch)!='N');

     return 0;
}

//---------------------------ΣΥΝΑΡΤΗΣΕΙΣ-------------------------------------
//****************************************************************************

/*Αρχικοποίησε κατάλληλα το SubIndex στην αρχή της λίστας συνωνύμων
Όσο δεν φτάνουμε στο τέλος της λίστας{
Εμφάνισε όλα τα στοιχεία του τρέχοντος πελάτη της λίστας
Ενημέρωσε το SubIndex στο επόμενο στοιχείο της λίστας συνωνύμων*/

void PrintListOfSynonyms(HashListType HList, KeyType key){

     int Hval, SubIndex;
     Hval = HashKey(key);
     SubIndex = HList.HashTable[Hval];
     printf("[%d, %s, %d, %d]\n", HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.username,
                   HList.List[SubIndex].Data.poso, HList.List[SubIndex].Link );

     while ( SubIndex != EndOfList )
            {

             printf("%d: [%d, %s, %d]\n",SubIndex,
                   HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.username,
                   HList.List[SubIndex].Data.poso);
                   SubIndex=HList.List[SubIndex].Link;

            }
 }

void Print_HashList(HashListType HList)
{
   int i, SubIndex;

     printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
     printf("========================================\n");

          printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");
            for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

          printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");
          for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                   printf("[%d, %s, %d, %d] -> ",
                   HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.username,
                   HList.List[SubIndex].Data.poso,HList.List[SubIndex].Link);
                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)
              printf("TELOS % dHS YPO-LISTAS\n", i);
          }

          /*printf("H STOIBA TWN ELEY8ERWN 8ESEWN THS LISTAS:\n");
          SubIndex = HList.StackPtr;
          while ( SubIndex != EndOfList )
          {
                printf("%d <= ",SubIndex);
                SubIndex = HList.List[SubIndex].Link;
          }
          printf("TELOS\n");*/

          printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
          printf("========================================\n");
}


void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

	printf("Hash List\n");
    for (i=0;i<HList.Size;i++)
	    printf("%d) %d, %s, %d, %d\n",i,
        HList.List[i].RecKey,HList.List[i].Data.username,HList.List[i].Data.poso,HList.List[i].Link);
	printf("\n");
}


int HashKey(KeyType Key)
/* Δέχεται:    Την τιμή Key ενός κλειδιού.
   Λειτουργία: Βρίσκει την τιμή κατακερματισμού HValue για το κλειδί Key.
   Επιστρέφει: Την τιμή κατακερματισμού HValue
*/
{
	/*σε περίπτωση που το KeyType δεν είναι ακέραιος
	θα πρέπει να μετατρέπεται κατάλληλα το κλειδί σε αριθμό*/
	return Key%HMax;
}

void CreateHashList(HashListType *HList)
/* Λειτουργία: Δημιουργεί μια δομή HList.
   Επιστρέφει: Την δομή HList
*/
{
	int index;

	HList->Size=0;           //ΔΗΜΙΟΥΡΓΕΙ ΜΙΑ ΚΕΝΗ ΛΙΣΤΑ
	HList->StackPtr=0;       //ΔΕΙΚΤΗς ΣΤΗ ΚΟΡΥΦΗ ΤΗΣ ΣΤΟΙΒΑΣ ΤΩΝ ΕΛΕΥΘΕΡΩΝ ΘΕΣΕΩΝ

    /*ΑΡΧΙΚΟΠΟΙΕΙ ΤΟΝ ΠΙΝΑΚΑ HashTable ΤΗΣ ΔΟΜΗΣ HList ΩΣΤΕ ΚΑΘΕ ΣΤΟΙΧΕΙΟΥ ΤΟΥ
        ΝΑ ΕΧΕΙ ΤΗ ΤΙΜΗ EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //Δημιουργία της στοίβας των ελεύθερων θέσεων στη λίστα HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
/* Δέχεται:    Μια δομή HList.
   Λειτουργία: Ελέγχει αν η λίστα List της δομής HList είναι γεμάτη.
   Επιστρέφει: TRUE αν η λίστα List είναι γεμάτη, FALSE διαφορετικά.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στην υπολίστα συνωνύμων.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της προηγούμενης
                εγγραφής στην υπολίστα
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].RecKey==KeyArg)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στη δομή HList.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της
                προηγούμενης εγγραφής της υπολίστας στην οποία ανήκει.
                Αν δεν υπάρχει εγγραφή με κλειδί KeyArg τότε Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg); //h(i) = i % 5.
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* Δέχεται:    Μια δομή HList και μια εγγραφή InRec.
   Λειτουργία: Εισάγει την εγγραφή InRec στη λίστα List, αν δεν είναι γεμάτη,
                και ενημερώνει τη δομή HList.
   Επιστρέφει: Την τροποποιημένη δομή HList.
   Έξοδος:     Μήνυμα γεμάτης λίστας, αν η List είναι γεμάτη, διαφορετικά,
                αν υπάρχει ήδη εγγραφή με το ίδιο κλειδί,
                εμφάνιση αντίστοιχου μηνύματος
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %d \n",DelKey);
	}
}


