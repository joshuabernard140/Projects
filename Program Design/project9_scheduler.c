#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////
// data definitions //
//////////////////////

#define NAME_LEN 20
#define SIZE_LEN 3

struct job {
	char job_name[NAME_LEN+1], user_name[NAME_LEN+1];
	int num_cpus, num_gpus, memory, priority;
	double time;
	struct job *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

void help();
void read(char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority);
struct job * add_job(struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority);
struct job * pop_job(struct job *scheduler);
void list_user(struct job *scheduler, char *user_name);
void list_jobs(struct job *scheduler, int num_cpus, int num_gpus, int memory, double time);
void list_all_jobs(struct job *scheduler);
struct job * clear_jobs(struct job *scheduler);

///////////////////
// main function //
///////////////////

int main() {
	char code;
	char job_name[NAME_LEN+1], user_name[NAME_LEN+1];
	int num_cpus, num_gpus, memory, priority;
	double time;

	struct job *scheduler = NULL;

	help();
	printf("\n");

	for (;;) {
		// read operation code
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') /* skips to end of line */
			;

		// run operation
		switch (code) {
			case 'h':
				help();
				break;
			case 'a':
				read(job_name, user_name, &num_cpus, &num_gpus, &memory, &time, &priority);
				scheduler = add_job(scheduler, job_name, user_name, num_cpus, num_gpus, memory, time, priority);
				break;
			case 'p':
				scheduler = pop_job(scheduler);
				break;
			case 'u':
				read(NULL, user_name, NULL, NULL, NULL, NULL, NULL);
				list_user(scheduler, user_name);
				break;
			case 'j':
				read(NULL, NULL, &num_cpus, &num_gpus, &memory, &time, NULL);
				list_jobs(scheduler, num_cpus, num_gpus, memory, time);
				break;
			case 'l':
				list_all_jobs(scheduler);
				break;
			case 'q':
				scheduler = clear_jobs(scheduler);
				return 0;
			default:
				printf("Illegal operation code!\n");
		}
		printf("\n");
	}
}

//////////////////////////
// function definitions //
//////////////////////////

void help() {
	printf("List of operation codes:\n");
	printf("\t'h' for help;\n");
	printf("\t'a' for adding a job to the scheduler;\n");
	printf("\t'p' for removing a job from the scheduler;\n");
	printf("\t'u' for searching jobs per user;\n");
	printf("\t'j' for searching jobs per capacity;\n");
	printf("\t'l' for listing all jobs;\n");
	printf("\t'q' for quit.\n");
}

void read(char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority) {
	if(job_name != NULL) {
		printf("Enter the name of the job: ");
		scanf("%s", job_name);
	}
	if(user_name != NULL) {
		printf("Enter the name of the user: ");
		scanf("%s", user_name);
	}
	if(num_cpus != NULL) {
		printf("Enter the number of CPUs: ");
		scanf("%d", num_cpus);
	}
	if(num_gpus != NULL) {
		printf("Enter the number of GPUs: ");
		scanf("%d", num_gpus);
	}
	if(memory != NULL) {
		printf("Enter the amount of memory: ");
		scanf("%d", memory);
	}
	if(time != NULL) {
		printf("Enter the amount of time: ");
		scanf("%lf", time);
	}
	if(priority != NULL) {
		printf("Enter the priority: ");
		scanf("%d", priority);
	}
}

/////////////////////////////////////////////////////////
// WARNING - WARNING - WARNING - WARNING - WARNING     //
/////////////////////////////////////////////////////////
// Do not modify anything before this point, otherwise //
// your solution will be considered incorrect.         //
/////////////////////////////////////////////////////////

struct job * add_job(struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority) {

    struct job *new_job = (struct job *) malloc(sizeof(struct job));

	//assigns each variable to the given data
    strncpy(new_job->job_name, job_name, 20);
    new_job->job_name[20] = '\0';
    strncpy(new_job->user_name, user_name, 20);
    new_job->user_name[20] = '\0';
    new_job->num_cpus = num_cpus;
    new_job->num_gpus = num_gpus;
    new_job->memory = memory;
    new_job->time = time;
    new_job->priority = priority;
    new_job->next = NULL;

	//sorts based on priority
	if (scheduler == NULL){
        scheduler = new_job;
    }
	else if (scheduler->next == NULL){
		struct job *current_job = scheduler;
		if (current_job->priority < new_job->priority){
			new_job->next = current_job;
        	scheduler = new_job;
		}else{
			current_job->next = new_job;
		}
	}
    else if (scheduler->priority > priority){	//last part that needs fixing
		struct job *current_job = scheduler;
		while (current_job->next != NULL && current_job->priority > priority){
			if (current_job->next->priority > priority){
				current_job = current_job->next;
			}else{
				break;
			}
		}
		new_job->next = current_job->next;
		current_job->next = new_job;
	}
	else{
        struct job *current_job = scheduler;
		new_job->next = current_job;
		scheduler = new_job;
    }

    return scheduler;
}

struct job * pop_job(struct job *scheduler) {

	//if scheduler isn't empty, prints out the first entry
	if (scheduler != NULL){
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", scheduler->job_name, scheduler->user_name, scheduler->num_cpus, scheduler->num_gpus, scheduler->memory, scheduler->time, scheduler->priority);
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");

		//removes the first entry
		struct job *temp = scheduler;
    	scheduler = scheduler->next;
    	free(temp);
	}

    return scheduler;

}

void list_user(struct job *scheduler, char *user_name) {

	int i = 0;

	//prints all entries that have the given username
	struct job *current_job = scheduler;
    while (current_job != NULL){
		if (strcmp(current_job->user_name, user_name) == 0){
			if (i == 0){
			printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
			printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
			printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
			i++;
			}
			printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", current_job->job_name, current_job->user_name, current_job->num_cpus, current_job->num_gpus, current_job->memory, current_job->time, current_job->priority);
			printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		}
        current_job = current_job->next;
    }

}

void list_jobs(struct job *scheduler, int num_cpus, int num_gpus, int memory, double time) {

	int i = 0;

	//prints all  entries with given cpus, gpus, memory, and time
	struct job *current_job = scheduler;
    while (current_job != NULL){
		if (current_job->num_cpus == num_cpus){
			if (current_job->num_gpus == num_gpus){
				if (current_job->memory == memory){
					if (current_job->time == time){
						if (i == 0){
							printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
							printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
							printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
							i++;
						}
						printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", current_job->job_name, current_job->user_name, current_job->num_cpus, current_job->num_gpus, current_job->memory, current_job->time, current_job->priority);
						printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
					}
				}
			}
		}
        current_job = current_job->next;
    }
}

void list_all_jobs(struct job *scheduler) {

	int i = 0;

	//lists all entries if any exist
	struct job *current_job = scheduler;
    while (current_job != NULL){
		if (i == 0){
			printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
			printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
			printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
			i++;
		}
		printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", current_job->job_name, current_job->user_name, current_job->num_cpus, current_job->num_gpus, current_job->memory, current_job->time, current_job->priority);
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		current_job = current_job->next;
	}
}

struct job * clear_jobs(struct job *scheduler) {

	//clears all entries
	while (scheduler != NULL){
		struct job *temp = scheduler;
    	scheduler = scheduler->next;
    	free(temp);
	}

    return scheduler;

}

