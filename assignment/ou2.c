#include <stdio.h>
/* Name: Iris Grini, CS username: tfy26igi
Date for submission: 07.10.2026 v1.0
Syfte: 
AI comment: */

//Skriv ut information
void menu(void) {
	printf("Program information\n");
	printf("The program reads in the number of judges and the score from each judge.\n"
"Then it calculates the average score without regard to the lowest and\n"
"highest judge score. Finally it prints the results (the highest, the\n"
"lowest and the final average score).\n\n");
}


//Läs in antal domare
int nr_judges (void){
	int judge;
	do {
		printf("Number of judges (min 3 and max 10 judges)? ");
		scanf("%d", &judge);
	} while (judge>10 || judge <3);
	printf ("%d\n", judge);
	return judge;
}

//Läs in domarpoäng
void score_from_judge (int judge) {
	double score[judge];
	int i=0;
	
	for (i=0; i<judge; i++) {
		printf("Score from judge %d? ", i+1);
		scanf("%.1lf", &score[i]);
	}
}

//Skriv ut de inlästa domarpoängen

/*Räkna fram resultat- I steg 5 ska en funktion användas där högsta, lägsta och medelpoäng ''returneras'' via
 tre separata pekarparametrar. Detta krav på programmet kan verka godtyckligt, 
 men ett av de viktigaste målen med denna uppgift är att ni ska testas på er förståelse av pekarparametrar
  och hur man använder dessa på ett korrekt sätt.*/

// Skriv ut resultat

int main (void) {
	menu(); 

	int judge= nr_judges();

	score_from_judge(judge);
	//gör en pekare
	double score[judge];

	return 0;
}