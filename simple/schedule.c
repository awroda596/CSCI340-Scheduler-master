//Andrew Roda
#include "schedule.h"
#include <stdlib.h>

struct PCBNode {
	PCB* pcb; 
	struct PCBnode* next;
};

int size; //ssize of linked list
struct PCBNode* root; 
struct PCBNode* cur; 
/**
 * Function to initialize any global variables for the scheduler.
 */
void init(){
	size = 0; 
	root = (struct PCBNode*) malloc(sizeof(struct PCBNode)); 
	cur = root; 
	cur->pcb = NULL; 
	cur->next = NULL; 
}

/**
 * Function to add a process to the scheduler
 * @Param PCB * - pointer to the PCB for the process/thread to be added to the
 *      scheduler queue
 * @return true/false response for if the addition was successful
 */
int addProcess(PCB *process){
	if(process == NULL){
		return 0; 
	}
	if(size == 0){
		root->pcb = process; 
		root->next = (struct PCBNode*) malloc(sizeof(struct PCBNode)); 
		cur = root->next;
		cur->pcb = NULL;
		cur->next = NULL; 
		size ++; 
		return 1; 
	}
	else{
		cur = root; 
		while(cur->pcb != NULL){
			cur = cur->next;
		}
		cur->pcb = process; 
		cur-> next = (struct PCBNode*) malloc(sizeof(struct PCBNode)); 	
		cur = cur-> next; 
		cur->pcb = NULL;
		cur ->next = NULL; 
		size ++; 
		cur = root; 
		return 1; 
	}
	// should never reaches here; 
	return 0; 
}

/**
 * Function to get the next process from the scheduler
 *
 * @Return returns the Process Control Block of the next process that should be
 *      executed, returns NULL if there are no processes
 */

//use cur to track the next process; 
PCB* nextProcess(){
	struct PCB* p = cur->pcb; 
	cur = cur->next; 
	return p; 
}

/**
 * Function that returns a boolean 1 True/0 False based on if there are any
 * processes still scheduled
 * @Return 1 if there are processes still scheduled 0 if there are no more
 *		scheduled processes
 * using as clean up process as well. 
 */
int hasProcess(){
	if(cur->pcb != NULL){
		return 1; 
	}
	else { // last process, clean up memory
		while(root != NULL){
			cur = root->next; 
			free(root); 
			root = cur; 
		}
		return 0; 
	}
}
