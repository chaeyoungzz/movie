#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	void *ndPtr; //void pointer for linked list node
	
	
	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat", "r");
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while ( !feof( fp ) )
	{	
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		fscanf(fp,"(%s)(%s)(%d)(%f)\n", name, country,runTime, score);
		mv_genMvInfo(name, score, runTime, country);
		list_addTail(mvInfo, list);
	}

	//1.4 FILE close
	fcloes(fp);
	
	//2. program start
	while(exit_flag == 0) 
	{
		//2.1 print menu message and get input option
		printf("------------Menu-------------\n");
		printf("1. print all the movies\n");
		printf("2. search for specific country movies\n");
		printf("3. search for specific runtime movies\n");
		pritnf("4. search fpr specific score movies\n");
		printf("5. exit\n");
		printf("------------Menu-------------\n");
		scanf("%i", option);		
		switch(option)
		{
			case 1: //print all the movies
				printf("printing all the movies in the list.....\n\n\n");
				
				ndPtr = list;
				while ( ndPtr != NULL )
				{
					//2.2 print a movie data : use functions of movie.c and linkedList.c
					
					//ndPtr = the next node of the ndPtr;
					ndPtr = ndPtr+1;
					//get object of ndPtr to mvInfo void pointer
					ndPtr=mvInfo;
					//print the contents of the mvInfo
					mv_print(mvInfo);
				}
				
				break;
				
			case 2: //print movies of specific country
				//2.3.1 get country name to search for
				printf("select a country : ");
				gets(country);
				
				ndPtr = list;
					while (ndPtr == NULL)
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = ndPtr+1;
					//get object of ndPtr to mvInfo void pointer
					ndPtr=mvInfo;
					//if the input country matches to the country of the movie,
					//then print the contents of the mvInfo
					mv_print(mv_getCountry(country));
					
				}
				
				break;
				
			case 3:
				//2.4.1 get minimal runtime value to search for
				printf("select a runtime : ");
		        scanf("%f", &runTime);
		        
				ndPtr = list;
					while (ndPtr == NULL)
				{
					//2.4.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = ndPtr+1;
					//get object of ndPtr to mvInfo void pointer
					ndPtr=mvInfo;
					//if the input runtime is lower than the runtime of the movie,
					//then print the contents of the mvInfo
					mv_print(mv_getRunTime(&runTime));
				}
				
				break;
				
			case 4:
				//2.5.1 get minimal score value to search for
				printf("select a socre : ");
		        scanf("%f", &score);
		        
				ndPtr = list;
					while (ndPtr == NULL)
				{
					//2.5.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = ndPtr+1;
					//get object of ndPtr to mvInfo void pointer
					ndPtr=mvInfo;
					//if the input score is lower than the score of the movie,
					//then print the contents of the mvInfo
					mv_print(mv_getScor(&score));
				}
				break;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
	}
	
	return 0;
}
