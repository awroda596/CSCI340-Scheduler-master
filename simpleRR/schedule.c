//Andrew Roda
#include "schedule.h"
#include <stdlib.h>
#include <stdio.h>

//linked list node
struct SchedNode
 {
	PCB* pcb; 
	struct SchedNode
	* next;
};

//globals
struct SchedNode
* root; 
struct SchedNode
* cur; 
/**
 * Function to initialize any global variables for the scheduler.
 */
void init(){
	root = (struct SchedNode*) malloc(sizeof(struct SchedNode)); 
	cur = root; 
	cur->next = NULL; 
}

/**
 * Function to add a process to the scheduler
 * @Param process - Pointer to the process control block for the process that
 * 			needs to be scheduled. PCB is defined in the header.
 * @return true/false response for if the addition was successful
 */
int addProcess(PCB* process){
	if(process == NULL){
		return 0; 
	}
	if(root->pcb == NULL)
	{
	  root->pcb = process; 
	  return 1; 
	}
	else{
	  cur = root; 
	  while(cur->next != NULL){
		 cur = cur->next; 
	  }
	  cur->next = (struct SchedNode*) malloc(sizeof(struct SchedNode));
	  cur = cur->next; 
	  cur->next = NULL; 
	  cur->pcb = process; 
	  return 1;  
	}
	return 0; 
}

/**
 * Function to get the next process from the scheduler
 * @Param time - pass by reference variable to store the quanta of time
 * 		the scheduled process should run for
 * @Return returns pointer to process control block that needs to be executed
 * 		returns NULL if there is no process to be scheduled.
 */
PCB* nextProcess(int *time){
	if(root == NULL){
		return NULL; 
	}
	time += 4; 
	struct PCB*  p = root->pcb; 
	cur = root; 
	root = cur->next;
	free(cur); 
	return p;	
}

/**
 * Function that returns a boolean 1 True/0 False based on if there are any
 * processes still scheduled
 * @Return 1 if there are processes still scheduled 0 if there are no more
 *		scheduled processes
 */
int hasProcess(){
	if(root == NULL){
		return 0;
	}
	return 1;
}
