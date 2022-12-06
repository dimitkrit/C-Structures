
//FILE a1f1.c DOMES Kritsimi Dimitra

/*Ένα σημαντικό πρόβλημα της θεωρίας αριθμών (του πεδίου των μαθηματικών που έχει ως αντικείμενο τη
μελέτη των ιδιοτήτων των μη αρνητικών ακεραίων) είναι το πρόβλημα του προσδιορισμού του κατά πόσο
ένας ακέραιος είναι πρώτος. Ένας θετικός ακέραιος n είναι πρώτος (prime) αν έχει ακριβώς δύο θετικούς
διαιρέτες, τον εαυτό του και το 1. Οι πρώτοι αριθμοί είναι ιδιαίτερα σημαντικοί σήμερα για την
κρυπτογραφία, αφού πολλές από τις καλύτερες τεχνικές κρυπτογράφησης βασίζονται στους πρώτους
αριθμούς. Να γραφεί πρόγραμμα που θα περιλαμβάνει τα παρακάτω υποπρογράμματα:
 συνάρτηση isPrime που θα δέχεται ένα θετικό ακέραιο n και θα επιστρέφει την τιμή TRUE ή FALSE
ανάλογα με το αν ο n είναι ή όχι αντίστοιχα πρώτος αριθμός
 διαδικασία createPrimeSet που θα δέχεται δύο θετικούς ακεραίους, έστω first και last, και θα
δημιουργεί και επιστρέφει το σύνολο των πρώτων αριθμών που ανήκουν στο διάστημα [first .. last]
 διαδικασία displaySet που δέχεται τον πρώτο αριθμό first ενός συνόλου θετικών ακεραίων S και
εμφανίζει τα στοιχεία του συνόλου στην ίδια γραμμή με ένα κενό χαρακτήρα μεταξύ τους.
Στη συνέχεια, γράψτε κυρίως πρόγραμμα όπου θα διαβάζονται δύο ακέραιοι αριθμοί, έστω first και last,
που θα πρέπει να ανήκουν στο διάστημα [2..200] και επιπλέον να ισχύει first < last. Στη συνέχεια, θα
καλούνται οι διαδικασίες createPrimeSet και displaySet για τη δημιουργία και εμφάνιση του συνόλου των
πρώτων αριθμών που ανήκουν στο διάστημα [first .. last].
Να χρησιμοποιηθεί ο ΑΤΔ σύνολο με πίνακα. Η διαδικασία displaySet θα δέχεται ένα σύνολο θετικών
ακεραίων S, τον πρώτο (first) και τον τελευταίο (last) αριθμό αυτού του συνόλου.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 200        //μέγιστο πλήθος στοιχείων συνόλου

//ΟΡΙΣΜΟΣ ΔΟΜΩΝ
typedef enum
{
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;


//ΟΡΙΣΜΟΣ ΣΥΝΑΡΤΗΣΕΩΝ
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void displayset(typos_synolou set, stoixeio_synolou first, stoixeio_synolou last);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

boolean isPrime(stoixeio_synolou n);
void createPrimeSet(typos_synolou set,stoixeio_synolou first, stoixeio_synolou last);

//ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ
int main()
{
    typos_synolou sprime;
    stoixeio_synolou first,last;

    printf("Doste enan arithmo>=2 first: ");
    scanf("%d", &first);
    while (first<2 || first>=200)
    {
        printf("o arithmos pou dosate den einai egkyros \n");
        printf("Doste enan arithmo>=2 first: ");
        scanf("%d", &first);
    }
    printf("Doste enan arithmo<=200 last: ");
    scanf("%d", &last);
    while (last<=first || last>200)
    {
        printf("o arithmos pou dosate den einai egkyros\n");
        printf("Doste enan arithmo<=200 last: ");
        scanf("%d", &last);
    }

    createPrimeSet(sprime,first,last);

    displayset(sprime, first, last);


    return 0;
}

//ΣΥΝΑΡΤΗΣΕΙΣ
boolean isPrime(stoixeio_synolou n)
{
    stoixeio_synolou j=2;
    while (j*j<=n)
    {
        if ((n%j)==0)
            return FALSE;
        j++;
    }
    return TRUE;

}



boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}

void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}

void createPrimeSet(typos_synolou set,stoixeio_synolou first, stoixeio_synolou last)
{

    //ΔΗΜΙΟΥΡΓΙΑ ΣΥΝΟΛΟΥ
    Dimiourgia(set);

    stoixeio_synolou i;

    for (i=first; i<=last; i++)
    {

        if (isPrime(i)==TRUE)
        {
            Eisagogi(i,set);
        }
    }
}

void displayset(typos_synolou set, stoixeio_synolou first, stoixeio_synolou last)
{
    stoixeio_synolou i;

    for (i=first; i<=last; i++)
        if(Melos(i,set))
            printf(" %d",i);

    printf("\n");
}

