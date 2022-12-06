
/*Δίνεται το αρχείο φοιτητών “foitites.dat”. Κάθε στοιχείο του αρχείου αυτού είναι μια εγγραφή με πεδία:
Αριθμός μητρώου (ΑΜ: int), Επώνυμο (αλφαριθμητικό 20 χαρακτήρες), Ονομα (αλφαριθμητικό 20 χαρακτήρες), Φύλο
(χαρακτήρας, τιμή F/M), Ετος (int), Βαθμός (μέσος όρος: float). Για την πιο αποτελεσματική επεξεργασία του αρχείου
αυτού δημιουργείται ένα ευρετήριο (index) ως ΔΔΑ. Κάθε στοιχείο του ευρετηρίου αυτού αποτελείται από τον ΑΜ και τον
αντίστοιχο αριθμό εγγραφής (γραμμής) στο αρχείο “foitites.dat”. Η αρίθμηση των γραμμών του αρχείου ξεκινούν από την
τιμή 0.
Γράψτε ένα πρόγραμμα που εκτελεί τις παρακάτω λειτουργίες και χρησιμοποιεί ως ευρετήριο ένα ΔΔΑ:
1. Δημιουργία του index (ΔΔΑ) από το αρχείο “foitites.dat”.
Θα διαβάζει 1-1 τις εγγραφές του αρχείου “foitites.dat”και θα καταχωρεί στο ΔΔΑ τον ΑΜ του φοιτητή και τον
αντίστοιχο αύξοντα αριθμό εγγραφής (γραμμής) στο αρχείο. Θα επιστρέφει το πλήθος των κόμβων του ΔΔΑ.
Συνάρτηση int BuildBST(BinTreePointer *Root);
2. Θα εμφανίζει το πλήθος των κόμβων του ΔΔΑ όπως και τους κόμβους του ΔΔΑ με αύξουσα διάταξη ως προς ΑΜ.
3. Εισαγωγή νέων εγγραφών φοιτητών στο αρχείο foitites.dat και ενημέρωση του ΔΔΑ. Κάθε αλφαριθμητικό πεδίο όπως
και το πεδίο φύλο (τύπου χαρακτήρας) να διαβάζονται με scanf() και στη συνέχεια getchar(). Για το φύλο δε χρειάζεται
να γίνεται έλεγχος εγκυρότητας θεωρούμε ότι θα δοθεί F ή Μ. Η fopen θα κληθεί με 2η παράμετρο “a” καθώς οι νέες
εγγραφές θα προστεθούν μετά την τελευταία εγγραφή του αρχείου. Μετά από κάθε προσθήκη εγγραφής στο αρχείο
θα εμφανίζετε το μέγεθος του αρχείου. (δείτε στο στιγμιότυπο εκτέλεσης).
Συνάρτηση void writeNewStudents(BinTreePointer *Root, int *size);
4. Θα εμφανίζει το πλήθος των κόμβων του ΔΔΑ όπως και τους κόμβους του ΔΔΑ με αύξουσα διάταξη ως προς ΑΜ.
5. Αναζήτηση φοιτητή. Θα δίνεται ο ΑΜ του φοιτητή και θα τον αναζητά στο ΔΔΑ. Στη συνέχεια εφόσον υπάρχει στο ΔΔΑ
θα τον εντοπίζει στο αρχείο “foitites.dat” και θα εμφανίζει όλες τις πληροφορίες της αντίστοιχης εγγραφής. Αν δεν
υπάρχει στο ΔΔΑ θα εμφανίζει σχετικό μήνυμα.
6. Θα εμφανίζει το πλήθος των κόμβων του ΔΔΑ όπως και τους κόμβους του ΔΔΑ με αύξουσα διάταξη ως προς ΑΜ.
7. Εκτύπωση των στοιχείων όλων των φοιτητών που είναι καταχωρημένοι στο αρχείο “foitites.dat” με ΜΟ μεγαλύτερο
από ένα δοσμένο βαθμό (πχ 0).
Συνάρτηση void printStudentsWithGrade(float theGrade);
Το αρχείο “foitites.dat” θα «ανοίγει» και θα «κλείνει» σε κάθε συνάρτηση που χρησιμοποιείται και με την κατάλληλη
παράμετρο (“a” για εγγραφή στο τέλος του αρχείου ή “r” για διάβασμα των εγγραφών του αρχείου).
Για κάθε μια από τις παραπάνω λειτουργίες εμφανίζεται στη main() σχετικό μήνυμα (Qx…)
Δίνεται ένα στιγμιότυπο εκτέλεσης όπου φαίνονται και τα σχετικά μηνύματα.
Q1. Build BST from a file
Q2. Print size and BST
Size=8
Nodes of BST
(5, 3), (8, 1), (10, 4), (11, 6), (12, 0), (23, 2), (30, 7), (32, 5),
Q3. Write new students, update file and BST
Give student's AM? 2
Give student surname? DIMITRIOU
Give student name? DIMITRIS
Give student sex F/M? M
Give student's registration year? 2020
Give student's grade? 5
Size=9
Continue Y/N: Y
Give student's AM? 15
Give student surname? ANASTASIOU
Give student name? TASA
Give student sex F/M? F
Give student's registration year? 2019
Give student's grade? 4
Size=10
Continue Y/N: N
Q4. Print size and BST
Size=10
Nodes of BST
(2, 8), (5, 3), (8, 1), (10, 4), (11, 6), (12, 0), (15, 9), (23, 2), (30, 7), (32, 5),
Q5. Search for a student
Give student's code? 2
2, DIMITRIS, DIMITRIOU, M, 2020, 5.0
Q6. Print size and BST
Size=10
Nodes of BST
(2, 8), (5, 3), (8, 1), (10, 4), (11, 6), (12, 0), (15, 9), (23, 2), (30, 7), (32, 5),
Q7. Print students with grades >= given grade
Give the grade: 0
12, KWSTAS, PAPANIKOLAOU, M, 2015, 8.1
8, MICHALIS, ANTONIOU, M, 2014, 5.3
23, RALLIA, RALLIDOU, F, 2016, 6.2
5, ZINA, ZINIDOU, F, 2013, 7.4
Δέντρα - σελίδα 10 από 11
10, KWSTAS, KWSTIDIS, M, 2010, 6.1
32, ANTONIS, ANTWNIOU, M, 2011, 7.0
11, ANNA, ANNANIDOU, F, 2016, 8.0
30, ALKINOOS, ALKINIDIS, M, 2009, 5.4
2, DIMITRIS, DIMITRIOU, M, 2020, 5.0
15, TASA, ANASTASIOU, F, 2019, 4.0*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    int am;
    char surname[20];
    char name[20];
    char filo;
    int year;
    float grade;
}STUDENT;

typedef struct{
    int AM;
    int regnum;
    }BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);

int BuildBST(BinTreePointer *Root);
void RecBSTInorder(BinTreePointer Root);
void writeNewStudents(BinTreePointer *Root, int *size);
void printStudentsWithGrade(float theGrade);
void PrintStudent(int RecNum);

int main()
{
   int size;
   char ch;
   BinTreePointer Root, LocPtr;
   BinTreeElementType Student;
   boolean Found;
   float theGrade;

         //1
//Δημιουργία του index (ΔΔΑ) από το αρχείο “foitites.dat”.
   CreateBST(&Root);
   printf("Q1. Build BST from a file");
   size = BuildBST(&Root);

         //2
// Θα εμφανίζει το πλήθος των κόμβων του ΔΔΑ όπως και τους κόμβους του ΔΔΑ με αύξουσα διάταξη ως προς ΑΜ.
   printf("Q2. Print size and BST\n");
   printf("Size= %d\n",&size);
   printf("Nodes of BST\n");
   RecBSTInorder(Root);
         //3
/*3. Εισαγωγή νέων εγγραφών φοιτητών στο αρχείο foitites.dat και ενημέρωση του ΔΔΑ. Κάθε αλφαριθμητικό πεδίο όπως
και το πεδίο φύλο (τύπου χαρακτήρας) να διαβάζονται με scanf() και στη συνέχεια getchar(). Για το φύλο δε χρειάζεται
να γίνεται έλεγχος εγκυρότητας θεωρούμε ότι θα δοθεί F ή Μ. Η fopen θα κληθεί με 2η παράμετρο “a” καθώς οι νέες
εγγραφές θα προστεθούν μετά την τελευταία εγγραφή του αρχείου. Μετά από κάθε προσθήκη εγγραφής στο αρχείο
θα εμφανίζετε το μέγεθος του αρχείου.*/
   printf(" Q3. Write new students, update file and BST\n");
   writeNewStudents(&Root,&size);
         //4
//Θα εμφανίζει το πλήθος των κόμβων του ΔΔΑ όπως και τους κόμβους του ΔΔΑ με αύξουσα διάταξη ως προς ΑΜ.
   printf("Q4. Print size and BST\n");
   printf("Size= %d\n",&size);
   printf("Nodes of BST\n");
   RecBSTInorder(Root);
         //5
/*  Αναζήτηση φοιτητή. Θα δίνεται ο ΑΜ του φοιτητή και θα τον αναζητά στο ΔΔΑ. Στη συνέχεια εφόσον υπάρχει στο ΔΔΑ
θα τον εντοπίζει στο αρχείο “foitites.dat” και θα εμφανίζει όλες τις πληροφορίες της αντίστοιχης εγγραφής. Αν δεν
υπάρχει στο ΔΔΑ θα εμφανίζει σχετικό μήνυμα.*/
   printf("Q5. Search for a student\n");
   printf("Give student's code? ");
   scanf("%d",&Student.AM);
   RecBSTSearch(Root,Student,&Found,&LocPtr);
   if(Found == TRUE)
       PrintStudent(size);
   else
       printf("o foititis me ayton ton arithmo mitroou den yparxei sto arxeio");

         //6
// Θα εμφανίζει το πλήθος των κόμβων του ΔΔΑ όπως και τους κόμβους του ΔΔΑ με αύξουσα διάταξη ως προς ΑΜ.
   printf("Q6. Print size and BST\n");
   size = BuildBST(&Root);
   printf("Size= %d\n",&size);
   printf("Nodes of BST\n");
   RecBSTInorder(Root);
         //7
/*Εκτύπωση των στοιχείων όλων των φοιτητών που είναι καταχωρημένοι στο αρχείο “foitites.dat” με ΜΟ μεγαλύτερο
από ένα δοσμένο βαθμό (πχ 0). */
   printf("Q7. Print students with grades >= given grade\n");
   printf("Give the grade: ");
   scanf("%f",&theGrade);
   printStudentsWithGrade(theGrade);

return 0;
}
                //ΣΥΝΑΡΤΗΣΕΙΣ
//------------------------------------------------------------------------
void PrintStudent(int RecNum){
    FILE *fp;
    int nscan;
    char termch;
    STUDENT student;
    BinTreeElementType indexRec;
    int lines;

    fp = fopen("foitites.dat", "r");
    lines = 0;
    if (fp == NULL)
          printf("Cannot open fp file\n");
    else {
        while(lines != RecNum+1){
           nscan = fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c",
            &student.am, student.surname, student.name, student.filo, &student.year, &student.grade, termch);
           if (nscan == EOF) break;
           if ( nscan != 7 || termch!= '\n' )
               printf("Improper file format");
           lines++;
        }
        if(lines == (indexRec.regnum+1))
             printf("%d,%s,%s,%s,%d,%.2f\n",
              &student.am, student.surname, student.name, student.filo, &student.year, &student.grade);
    }
    fclose(fp);
}


void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data.AM = Item.AM;
        (*Root) ->Data.regnum = Item.regnum;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item.AM < (*Root) ->Data.AM)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item.AM > (*Root) ->Data.AM)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}


/* 1. Δημιουργία του index (ΔΔΑ) από το αρχείο “foitites.dat”.
Θα διαβάζει 1-1 τις εγγραφές του αρχείου “foitites.dat”και θα καταχωρεί στο ΔΔΑ τον ΑΜ του φοιτητή και τον
αντίστοιχο αύξοντα αριθμό εγγραφής (γραμμής) στο αρχείο. Θα επιστρέφει το πλήθος των κόμβων του ΔΔΑ*/

int BuildBST(BinTreePointer *Root){
    FILE *fp;
    int nscan;
    char termch;
    STUDENT student;
    BinTreeElementType indexRec;
    CreateBST(&(*Root));
    fp = fopen("foitites.dat", "r");
    int size = 0;
    if (fp == NULL)
        printf("Cannot open fp file\n");
    else
    {
      while(TRUE){
            nscan = fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c",
            &student.am, student.surname, student.name, student.filo, &student.year, &student.grade,termch);
            if (nscan == EOF) break;
            printf("%d,%s,%s,%c,%d,%.2f,%c\n",&student.am, student.surname, student.name, student.filo, &student.year, &student.grade,termch);
            if ( termch!= '\n' )
               printf("Improper file format");
            else{
               indexRec.AM = student.am;
               indexRec.regnum = size;
               RecBSTInsert(&(*Root), indexRec);
               size++;
            }
     }
    }
    fclose(fp);
    return size;
}

/*2. Θα εμφανίζει το πλήθος των κόμβων του ΔΔΑ όπως και τους κόμβους του ΔΔΑ με αύξουσα διάταξη ως προς ΑΜ.*/
void RecBSTInorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("(%d, ",Root->Data.AM);
        printf("%d),",Root->Data.regnum);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}
/*3. Εισαγωγή νέων εγγραφών φοιτητώνhttps://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&ved=2ahUKEwi0_beM18TwAhXKGuwKHUlaBCMQwqsBMAB6BAgFEAM&url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DJab1qj_QR8s&usg=AOvVaw3-2iL-mwBRjgUPkxv4chF2 στο αρχείο foitites.dat και ενημέρωση του ΔΔΑ. Κάθε αλφαριθμητικό πεδίο όπως
και το πεδίο φύλο (τύπου χαρακτήρας) να διαβάζονται με scanf() και στη συνέχεια getchar(). Για το φύλο δε χρειάζεται
να γίνεται έλεγχος εγκυρότητας θεωρούμε ότι θα δοθεί F ή Μ. Η fopen θα κληθεί με 2η παράμετρο “a” καθώς οι νέες
εγγραφές θα προστεθούν μετά την τελευταία εγγραφή του αρχείου. Μετά από κάθε προσθήκη εγγραφής στο αρχείο
θα εμφανίζετa το μέγεθος του αρχείου.*/
void writeNewStudents(BinTreePointer *Root, int *size){
    FILE *fp;
    STUDENT student;
    BinTreeElementType indexRec;
    boolean found;
    BinTreePointer LocPtr;
    char ch;
    fp = fopen("foitites.dat", "a");
    if (fp == NULL)
        printf("Cannot open fp file\n");
    else
     {do
       {
       printf("Give student's AM? ");
            scanf("%d", &indexRec.AM);
            RecBSTSearch(*Root, indexRec,&found,&LocPtr);
            if(found == FALSE){
                 student.am = indexRec.AM;
                 printf("Give student surname? ");
                    scanf("%s", &student.surname);getchar();
                 printf("Give student name? ");
                    scanf("%s", &student.name);getchar();
                 printf("Give student sex F/M? ");
                    scanf("%s", &student.filo);getchar();
                 printf("Give student's registration year? ");
                    scanf("%d", &student.year);
                 printf("Give student's grade? ");
                    scanf("%f", &student.grade);
                 indexRec.regnum = *size+1;
                 RecBSTInsert(Root,indexRec);
                 fprintf(fp, "%d,%20[^,],%20[^,],%c,%d,%f\n",
                  &student.am, student.surname, student.name, student.filo, &student.year, &student.grade);
                printf("Size= %d\n",size);
                 *size++;
             }
             else
                printf("o AM yparxei hdh sto arxeio");
          printf("\nContinue Y/N: ");
            do
            {
      	      scanf("%c", &ch);
            } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');

    }
    fclose(fp);
}

/* 5 Αναζήτηση φοιτητή. Θα δίνεται ο ΑΜ του φοιτητή και θα τον αναζητά στο ΔΔΑ. Στη συνέχεια εφόσον υπάρχει στο ΔΔΑ
θα τον εντοπίζει στο αρχείο “foitites.dat” και θα εμφανίζει όλες τις πληροφορίες της αντίστοιχης εγγραφής. Αν δεν
υπάρχει στο ΔΔΑ θα εμφανίζει σχετικό μήνυμα.*/
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{

    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue.AM < Root->Data.AM)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue.AM  > Root->Data.AM)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}
  /*Εκτύπωση των στοιχείων όλων των φοιτητών που είναι καταχωρημένοι στο αρχείο “foitites.dat” με ΜΟ μεγαλύτερο
από ένα δοσμένο βαθμό (πχ 0). */
void printStudentsWithGrade(float theGrade){
    FILE *fp;
    int nscan;
    char termch;
    STUDENT student;

    fp = fopen("foitites.dat", "r");
    if (fp == NULL)
        printf("Cannot open fp file\n");
    else
        while(!feof(fp)) {
               nscan = fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c",
               &student.am, student.surname, student.name, student.filo, &student.year, &student.grade,termch);
               if (nscan == EOF) break;
               if ( nscan != 7 || termch!= '\n' )
                    printf("Improper file format");
               else
                   if (student.grade >= theGrade)
                       printf("%d,%s,%s,%c,%d,%.2f\n",
              &student.am, student.surname, student.name, student.filo, &student.year, &student.grade);
       }
    fclose(fp);
}

//-----------------------------------------------------------------
void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}



