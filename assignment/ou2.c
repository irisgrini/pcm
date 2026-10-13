#include <stdio.h>
/* Name: Iris Grini, CS username: tfy26igi
Date for submission: 07.10.2026 v1.0
This program is a way to calculate judges score in a competition 
AI comment: */

//Write out the information for the program
void print_menu(void) {
	printf("Program information\n");
	printf("The program reads in the number of judges and the score from each judge.\n"
"Then it calculates the average score without regard to the lowest and\n"
"highest judge score. Finally it prints the results (the highest, the\n"
"lowest and the final average score).\n\n");
}


/*Ask the user for the number of judges, this will repeat if the number is not between 3 and 10. 
This funktion returns the number of judges to main*/
int number_of_judges (void){
	int judge;
	do {
		printf("Number of judges (min 3 and max 10 judges)? ");
		scanf("%d", &judge);
	} while (judge>10 || judge <3);
	return judge;
}


/*The user fills our the attained scores from the judges. The program will ask for scores as many times as there are judges.
this funktion will return the scores to main in an array*/
void scan_score(int judge, double score[]){
	for(int i=0; i<judge; i++){
        printf("Score from judge %d? ", i+1);
        scanf("%lf", &score[i]);
}
}

//This funktion writes out the scores from each judge
void load_score(int judge, double score[]) {
	printf("Loaded scores:\n");
	for(int i=0; i<judge; i++){
        printf("Judge %d: %.1lf\n", i+1, score[i]);
}
}

/*Räkna fram resultat- I steg 5 ska en funktion användas där högsta, lägsta och medelpoäng ''returneras'' via
 tre separata pekarparametrar. Detta krav på programmet kan verka godtyckligt, 
 men ett av de viktigaste målen med denna uppgift är att ni ska testas på er förståelse av pekarparametrar
  och hur man använder dessa på ett korrekt sätt.*/

// Skriv ut resultat

int main (void) {
	
	print_menu(); 

	int judge= number_of_judges();

	double score[judge];
	scan_score(judge, score);

	load_score(judge, score);
	
	printf("normal exit\n");
	return 0;
}