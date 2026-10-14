#include <stdio.h>
/* Name: Iris Grini, CS username: tfy26igi
Date for submission: 14.10.2026 v1.0
This program is a way to calculate judges score in a competition 
AI comment: I used AI to learn how to use pointers and how to find out how to caclulate
my average score without including the highest and lowest score.*/

//Write out the information for the program
void print_menu(void) {
	printf("Program information\n");
	printf("The program reads in the number of judges and the score from each judge.\n"
		"Then it calculates the average score without regard to the lowest and\n"
		"highest judge score. Finally it prints the results (the highest, the\n"
		"lowest and the final average score).\n\n");
}


/*User fills out number of judges,
 will repeat if the number is not between 3 and 10.*/
int number_of_judges (void){
	int judge;
	do {
		printf("Number of judges (min 3 and max 10 judges)? ");
		scanf("%d", &judge);
	} while (judge>10 || judge <3);
	printf("\n");
	return judge;
}

/*The user fills out the attained scores from the judges. 
The program will ask for scores as many times as there are judges.
this funktion will return the scores to main in an array*/
void scan_score(int judge, double score[]){
	for(int i=0; i<judge; i++){
        printf("Score from judge %d? ", i+1);
        scanf("%lf", &score[i]);
	}
	printf("\n");
}

//This funktion writes out the scores from each judge
void load_score(int judge, double score[]) {
	printf("Loaded scores:\n");
	for(int i=0; i<judge; i++){
        printf("Judge %d: %.1lf\n", i+1, score[i]);
	}
	printf("\n");
}

//Calculates the average, highest and lowest scores. 
void calculate_score (double*average_score, int judge, double score[], double *lowest_score, double *highest_score){
	double sum=0;
	for(int i=0; i<judge;i++){
		sum+=score[i];
	}
	sum= sum-*highest_score-*lowest_score;
	*average_score=sum /(judge-2);

	for(int i=1; i<judge;i++){
		if (score[i]>*highest_score){
			*highest_score=score[i];
		}
	}

	for(int i=1; i<judge;i++){
		if (score[i]<*lowest_score){
			*lowest_score=score[i];
		}
	}
}

//This funktion prints out the result
void print_result(double*highest_score, double*lowest_score, double*average_score){
	printf("Final result:\n");
	printf("Highest judge score: %.1lf", *highest_score);
	printf("\nLowest judge score: %.1lf", *lowest_score);
	printf("\nFinal average score: %.1lf", *average_score);
}

//Main calls on the different funktions
int main (void) {

	int judge;
	double score[judge];
	double highest_score= score[0];
	double lowest_score= score[0];
	double average_score;
	
	print_menu(); 
	int judge= number_of_judges();
	scan_score(judge, score);
	load_score(judge, score);
	calculate_score(&average_score, judge, score, &lowest_score, &highest_score);
	print_result(&highest_score, &lowest_score, &average_score);
	
	return 0;
}