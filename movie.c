#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

typedef struct movInfo{
	char name[200];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;


void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;
	//allocate memory and set the member variables
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
	
	if(mvPtr != NULL){
		strcpy(mvPtr->name, name);
	    mvPtr->score = score;
	    mvPtr->runTime = runTime;
	    strcpy(mvPtr->madeIn, country);
	}
	
	else{
		printf("ERROR!\n");
	}

	return (void*)mvPtr;
}

void mv_print(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}


//return the score value from the input instance of movInfo_t structure
float mv_getScore(void* obj)
{
	movInfo_t* mvPtr;
	
	if (mvPtr != NULL){
		printf("selsect a score : ");
		scanf("%f", obj);
		if(mvPtr->score >= *(float *)obj){
			return *(float *)obj;
		}
	}
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{
	movInfo_t* mvPtr;
	
	if (mvPtr != NULL){
		printf("selsect a runtime : ");
		scanf("%i", obj);
		
		if(mvPtr->runTime >= *(int*)obj){
			return *(int*)obj;
		}
	}
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	movInfo_t* mvPtr;
	
	if (mvPtr != NULL){
		printf("selsect a name : ");
		scanf("%i", obj);
		
		if(strcmp(mvPtr->name, obj) == 0){
			return obj;
		}
		
	}
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	movInfo_t* mvPtr;
	
	if (mvPtr != NULL){
		printf("selsect a country : ");
		scanf("%i",&obj);
		
		if(strcmp(mvPtr->madeIn, obj) == 0){
			return obj;
		}
		
	}
}


