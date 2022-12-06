

               //ENDGAME

 /* Σε έναν εκπαιδευτικό οργανισμό εργάζονται εκπαιδευτικοί διαφόρων ειδικοτήτων.
 Τα βασικά τους στοιχεία υπάρχουν σε ένα αρχείου κειμένου ‘i4f6.txt’
 (σε διαφορετικές γραμμές για κάθε εκπαιδευτικό):
Ονομα αλφαριθμητικό 10 χαρακτήρες
Επώνυμο αλφαριθμητικό 20 χαρακτήρες
Τηλέφωνο αλφαριθμητικό 10 θέσεων
Κωδικός ειδικότητας
byte (1=Θεολόγοι, 2=Φιλόλογοι, …20=Πληροφορικοί)
Στο κυρίως πρόγραμμα θα υλοποιούνται στη σειρά οι παρακάτω λειτουργίες:
1. BuildHashList
Διάβασμα των στοιχείων από το αρχείο κειμένου και δημιουργία Δομής Δεδομένων (ΔΔ)
που αποθηκεύει και επεξεργάζεται τα στοιχεία της με την τεχνική του κατακερματισμού με αλυσίδες συνωνύμων.
Το κλειδί σχηματίζεται από το όνομα+κενό χαρακτήρα+επώνυμο.
Πχ αν το όνομα είναι «nikos» και το επώνυμο «dimitriou», τότε το κλειδί κατακερματισμού
που θα σχηματιστεί είναι: «nikos dimitriou»
void BuildHashList(HashListType *HList);
2. Insert new teacher
Εισαγωγή των στοιχείων ενός νέου εκπαιδευτικού στη ΔΔ κατακερματισμού με αλυσίδες συνωνύμων.
 Η εισαγωγή νέων εκπαιδευτικών στη ΔΔ γίνεται επαναληπτικά μέσω σχετικού μηνύματος ‘Continue Y/N?’
3. Delete a teacher
Διαγραφή ενός εκπαιδευτικού από τη ΔΔ κατακερματισμού με αλυσίδες συνωνύμων
Κατακερματισμός - σελίδα 3 από 8
4. Search for a teacher
Αναζήτηση και εμφάνιση των στοιχείων ενός εκπαιδευτικού βάσει ονοματεπωνύμου στη
ΔΔ κατακερματισμού με αλυσίδες συνωνύμων
5. Search by subject
Αναζήτηση και εμφάνιση των στοιχείων των εκπαιδευτικών μιας συγκεκριμένης ειδικότητας
(ο κωδικός της ειδικότητας [1..20] αποτελεί παράμετρο της διαδικασίας) στη ΔΔ κατακερματισμού με αλυσίδες συνωνύμων
void Search_HashList_By_Subject(HashListType HList, int code);
Μετά τις λειτουργίες 1, 2, 3 θα καλείτε την PrintPinakes(HList).
Ο πίνακας κατακερματισμού θα έχει 9 θέσεις και ως συνάρτηση κατακερματισμού θα χρησιμοποιηθεί η εξής:
h(i) = average % 9
όπου
average = (κωδικός_πρώτου_ χαρακτήρα + κωδικός_τελευταίου_χαρακτήρα) / 2
Θεωρήστε ότι χρησιμοποιούνται οι ακόλουθοι κωδικοί για τους χαρακτήρες:
‘Α’ = 1, ‘Β’ = 2, …, ‘Ζ’ = 26. Ο πρώτος και ο τελευταίος χαρακτήρας του ονοματεπωνύμου
 θα μετατρέπεται στον αντίστοιχο κεφαλαίο χαρακτήρα, εφόσον είναι πεζός. Ο μέσος όρος average
 θα υπολογίζεται με μια συνάρτηση findAverage, η οποία θα καλείται από τη συνάρτηση HashKey.  */



#define HMax 9              /* Ο πίνακας κατακερματισμού θα έχει 9 θέσεις
και ως συνάρτηση κατακερματισμού θα χρησιμοποιηθεί η εξής:
h(i) = average % 9*/

#define VMax 30             /*το μέγεθος της λίστας,
                                ενδεικτικά ίσο με 30 */
#define EndOfList -1        /* σημαία που σηματοδοτεί το τέλος της λίστας
                                και της κάθε υπολίστας συνωνύμων */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//typedef int ListElementType;  /*τύπος δεδομένων για τα στοιχεία της λίστας
                               //* ενδεικτικά τύπου int */
typedef char KeyType[40];

typedef struct{
    char onoma[10]; //Ονομα αλφαριθμητικό 10 χαρακτήρες
    char eponimo[20]; //Επώνυμο αλφαριθμητικό 20 χαρακτήρες
    char tel[11]; //Τηλέφωνο αλφαριθμητικό 10 θέσεων
    int kind; // Κωδικός ειδικότητας byte (1=Θεολόγοι, 2=Φιλόλογοι, …20=Πληροφορικοί)
}ListElementType;


typedef struct {
	KeyType RecKey;//Το κλειδί σχηματίζεται από το όνομα+κενό χαρακτήρα+επώνυμο.
    ListElementType Data;   //Πχ αν το όνομα είναι «nikos» και το επώνυμο «dimitriou», τότε το κλειδί κατακερματισμού
    int Link;                      //που θα σχηματιστεί είναι: «nikos dimitriou»
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

void BuildHashList(HashListType *HList);
void Search_HashList_By_Subject(HashListType HList, int code);
int findAverage(KeyType key);



//---------------------ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ--------------------------------------------------
//**************************************************************************************

int main(){

      char ch;
      HashListType HList;
      ListElm AnItem;
      KeyType Key;
      int Loc, Pred;
      int code;
/* Σε έναν εκπαιδευτικό οργανισμό εργάζονται εκπαιδευτικοί διαφόρων ειδικοτήτων.
 Τα βασικά τους στοιχεία υπάρχουν σε ένα αρχείου κειμένου ‘i4f6.txt’
 (σε διαφορετικές γραμμές για κάθε εκπαιδευτικό)*/

/*
Διάβασμα των στοιχείων από το αρχείο κειμένου και δημιουργία Δομής Δεδομένων (ΔΔ)
που αποθηκεύει και επεξεργάζεται τα στοιχεία της με την τεχνική του κατακερματισμού με αλυσίδες συνωνύμων.
Το κλειδί σχηματίζεται από το όνομα+κενό χαρακτήρα+επώνυμο.
Πχ αν το όνομα είναι «nikos» και το επώνυμο «dimitriou», τότε το κλειδί κατακερματισμού
που θα σχηματιστεί είναι: «nikos dimitriou»
void BuildHashList(HashListType *HList); */



//1 ------------------1. BuildHashList------------------------------

      printf("1. Create HashList\n");
      BuildHashList(&HList);
      PrintPinakes(HList);

/*Εισαγωγή των στοιχείων ενός νέου εκπαιδευτικού στη ΔΔ κατακερματισμού με αλυσίδες συνωνύμων.
 Η εισαγωγή νέων εκπαιδευτικών στη ΔΔ γίνεται επαναληπτικά μέσω σχετικού μηνύματος ‘Continue Y/N?’*/
//2 ------------------2. Insert new teacher------------------------------
      printf("2. Insert new teacher\n");


    do{
       printf("Enter teacher's name: ");
       scanf("%s", AnItem.Data.onoma);
       printf("Enter teacher's surname: ");
       scanf("%s", AnItem.Data.eponimo);
       printf("Enter teacher's phone: ");
       scanf("%s", AnItem.Data.tel);
       printf("Enter teacher code: ");
       scanf("%d", &AnItem.Data.kind);
       AnItem.Link=EndOfList;
       strcpy (AnItem.RecKey,AnItem.Data.onoma);
       strcat(AnItem.RecKey, " ");
       strcat(AnItem.RecKey, AnItem.Data.eponimo);
       AddRec(&HList,AnItem);
//AnItem.Link=EndOfList;
       printf("\nContinue Y/N: ");
       do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
       } while (toupper(ch)!='N');
       PrintPinakes(HList);

/*Διαγραφή ενός εκπαιδευτικού από τη ΔΔ κατακερματισμού με αλυσίδες συνωνύμων
Κατακερματισμός - σελίδα 3 από 8*/
//3 ------------------3. Delete a teacher------------------------------

        printf("3. Delete a teacher\n");
        printf("Enter teacher's name: ");
        scanf("%s", AnItem.Data.onoma);
        printf("Enter teacher's surname: ");
        scanf("%s", AnItem.Data.eponimo);
        strcpy (Key,AnItem.Data.onoma);
        strcat(Key, " ");
        strcat(Key,AnItem.Data.eponimo);
        DeleteRec(&HList,Key);
        PrintPinakes(HList);

/*Αναζήτηση και εμφάνιση των στοιχείων ενός εκπαιδευτικού βάσει ονοματεπωνύμου στη
ΔΔ κατακερματισμού με αλυσίδες συνωνύμων*/
//4 ------------------4. Search for a teacher------------------------------
        printf("4. Search for a teacher\n");
        printf("Enter teacher's name: ");
        scanf("%s",AnItem.Data.onoma);
        printf("Enter teacher's surname: ");
        scanf("%s", AnItem.Data.eponimo);
        strcpy (Key,AnItem.Data.onoma);
        strcat(Key, " ");
        strcat(Key, AnItem.Data.eponimo);
        SearchHashList(HList,Key,&Loc,&Pred);
        if ( Loc != -1)
                        printf("[%s %s, %s, %d]\n",
                               HList.List[Loc].Data.onoma,HList.List[Loc].Data.eponimo,HList.List[Loc].Data.tel,HList.List[Loc].Data.kind);
                    else
                        printf("DEN YPARXEI EGGRAFH ME KLEIDI %s %s\n", AnItem.Data.onoma,AnItem.Data.eponimo);
        printf("\n");

/*Αναζήτηση και εμφάνιση των στοιχείων των εκπαιδευτικών μιας συγκεκριμένης ειδικότητας
(ο κωδικός της ειδικότητας [1..20] αποτελεί παράμετρο της διαδικασίας) στη ΔΔ κατακερματισμού με αλυσίδες συνωνύμων
      void Search_HashList_By_Subject(HashListType HList, int code);*/
//5------------------5. Search by subject------------------------------
       printf("5. Search by subject\n");
       printf("Enter code: ");
       scanf("%d", &code);
       printf("List of teachers with subject code %d:\n",code);
       Search_HashList_By_Subject(HList,code);

       return 0;
}

//---------------------------ΣΥΝΑΡΤΗΣΕΙΣ-------------------------------------
//****************************************************************************


/*Αναζήτηση και εμφάνιση των στοιχείων των εκπαιδευτικών μιας συγκεκριμένης ειδικότητας
(ο κωδικός της ειδικότητας [1..20] αποτελεί παράμετρο της διαδικασίας) στη ΔΔ κατακερματισμού με αλυσίδες συνωνύμων*/
void Search_HashList_By_Subject(HashListType HList, int code){

     int i,Subindex;
	 for (i=0; i<HMax; i++){
        Subindex = HList.HashTable[i];
        while ( Subindex != EndOfList ){
              if (HList.List[Subindex].Data.kind == code)
                    printf("%d:[%s %s, %s, %d]\n",Subindex,
                    HList.List[Subindex].Data.onoma,HList.List[Subindex].Data.eponimo,
                    HList.List[Subindex].Data.tel,HList.List[Subindex].Data.kind);
	          Subindex=HList.List[Subindex].Link;
        }
	 }
}

/*Διάβασμα των στοιχείων από το αρχείο κειμένου και δημιουργία Δομής Δεδομένων (ΔΔ)
που αποθηκεύει και επεξεργάζεται τα στοιχεία της με την τεχνική του κατακερματισμού με αλυσίδες συνωνύμων.
Το κλειδί σχηματίζεται από το όνομα+κενό χαρακτήρα+επώνυμο.
Πχ αν το όνομα είναι «nikos» και το επώνυμο «dimitriou», τότε το κλειδί κατακερματισμού
που θα σχηματιστεί είναι: «nikos dimitriou»
void BuildHashList(HashListType *HList); */
void BuildHashList(HashListType *HList){
     FILE *fp;
     int nscan;
     char termch;
     ListElm AnItem;
     CreateHashList(HList);
     fp = fopen("i4f6.txt", "r");
     if (fp == NULL)
          printf("Cannot open fp file\n");
     else {
        while(!feof(fp)){
           nscan = fscanf(fp,"%10[^,],%20[^,],%10[^,],%d%c",
            AnItem.Data.onoma, AnItem.Data.eponimo, AnItem.Data.tel,&AnItem.Data.kind, &termch);
                       if (nscan == EOF) break;
           if ( nscan != 5 || termch!= '\n' )
               printf("Improper file format");
           else{
               strcpy (AnItem.RecKey,AnItem.Data.onoma);
               strcat(AnItem.RecKey, " ");
               strcat(AnItem.RecKey, AnItem.Data.eponimo);
               AddRec(HList,AnItem);
          }
      }
   }
     fclose(fp);
}



/*average = (κωδικός_πρώτου_ χαρακτήρα + κωδικός_τελευταίου_χαρακτήρα) / 2
Θεωρήστε ότι χρησιμοποιούνται οι ακόλουθοι κωδικοί για τους χαρακτήρες:
‘Α’ = 1, ‘Β’ = 2, …, ‘Ζ’ = 26. Ο πρώτος και ο τελευταίος χαρακτήρας του ονοματεπωνύμου
 θα μετατρέπεται στον αντίστοιχο κεφαλαίο χαρακτήρα, εφόσον είναι πεζός. Ο μέσος όρος average
 θα υπολογίζεται με μια συνάρτηση findAverage, η οποία θα καλείται από τη συνάρτηση HashKey.  */

int HashKey(KeyType Key){
/* Δέχεται:    Την τιμή Key ενός κλειδιού.
   Λειτουργία: Βρίσκει την τιμή κατακερματισμού HValue για το κλειδί Key.
   Επιστρέφει: Την τιμή κατακερματισμού HValue
*/
{
	/*σε περίπτωση που το KeyType δεν είναι ακέραιος
	θα πρέπει να μετατρέπεται κατάλληλα το κλειδί σε αριθμό*/
	int average;

	average=findAverage(Key);

	return average%HMax;
}
}
int findAverage(KeyType key){

	int a,b;
	int k = strlen(key);
	a = toupper(key[0])-64; //η θέση -64 είναι ο αντίστοιχος ακέραιος στον ascii
	b = toupper(key[k-1])-64;

    int average, x, y;

    return (a+b)/2;

}


void Print_HashList(HashListType HList)
{
   int i, SubIndex;

    /* printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
     printf("========================================\n");

          printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");
            for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);*/

          printf("Hash List\n");
          for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                   printf("%d), %s, %s, %s, %d",i,HList.List[SubIndex].Data.onoma,HList.List[SubIndex].Data.eponimo,
                          HList.List[SubIndex].Data.tel,HList.List[SubIndex].Data.kind);
                   //printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)
             // printf("TELOS % dHS YPO-LISTAS\n", i);
          }

         /* printf("H STOIBA TWN ELEY8ERWN 8ESEWN THS LISTAS:\n");
          SubIndex = HList.StackPtr;
          while ( SubIndex != EndOfList )
          {
                printf("%d <= ",SubIndex);
                SubIndex = HList.List[SubIndex].Link;
          }
          printf("TELOS\n");

          printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
          printf("========================================\n");*/
}

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d,",HList.HashTable[i]);

	printf("\nHash List\n");
    for (i=0;i<HList.Size;i++)
	     printf("%d) %s %s, %d\n",i,HList.List[i].Data.onoma,HList.List[i].Data.eponimo,
                   HList.List[i].Link);
    printf("\n");
}
/*void PrintPinakes(HashListType HList)
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

}*/


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
		if (strcmp(HList.List[Next].RecKey,KeyArg)==0)
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
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %s \n",DelKey);
	}
}









