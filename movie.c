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
		// 구조체 변수에 할당  
		strcpy(mvPtr->name, name);
	    mvPtr->score = score;
	    mvPtr->runTime = runTime;
	    strcpy(mvPtr->madeIn, country);
	}
	
	else{
		printf("ERROR!\n"); // 오류방지  
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
	movInfo_t* mvPtr = (movInfo_t*)obj; // 구조체 할당  
	
	//오류 방지  
	if (mvPtr == NULL){
		printf("ERROR!\n");
	}
	//score 값 반환  
	return mvPtr->score;
	
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj; //구조체 할당  
	
	//오류 방지  
	if (mvPtr == NULL){
		printf("ERROR!\n");
	}
	
	//runtime 값 반환  
	return mvPtr->runTime;
}


//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj; // 구조체 할당  
	
	//오류 방지  
	if (mvPtr == NULL){
		printf("ERROR!\n");
	}
	
	//name 값 반환 
	return mvPtr->name; 
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj; // 구조체 할당  
	//오류 방지  
	if (mvPtr == NULL){
		printf("ERROR!\n");
	}
	//madein 값 반환  
	return mvPtr->madeIn;
	
}


