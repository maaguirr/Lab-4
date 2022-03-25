#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct student{
    int ID;
    char firstName[30];
    char lastName[30];
    float GPA;
    struct student *next;
}Student;

struct student *head = NULL;
void add_student(struct student pst);
void print_students();
void print_student(struct student pst);
int total_num_students = 0;

void add_student(struct student pst){
    
    if (head == NULL){
        struct student *tmp = NULL;
        tmp = (struct student*)malloc(sizeof(struct student));
        tmp->next = NULL;
        tmp->ID = pst.ID;
        strcpy(tmp->firstName, pst.firstName);
        strcpy(tmp->lastName, pst.lastName);
        tmp->GPA = pst.GPA;
        
        head = tmp;
        
    }
    else{
        struct student *ptr = NULL;
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next; 
        }
        struct student *tmp = NULL;
        tmp = (struct student*)malloc(sizeof(struct student));
        tmp->next = NULL;
        tmp->ID = pst.ID;
        strcpy(tmp->firstName, pst.firstName);
        strcpy(tmp->lastName, pst.lastName);
        tmp->GPA = pst.GPA;
        
        ptr->next = tmp;
    }
}

void print_students(){
    struct student *ptr = NULL;
    ptr = head;
    while(ptr->next != NULL){
        printf("student id = %d\n", ptr->ID);
        printf("student name = %s\n", ptr->firstName);
        printf("student lastname = %s\n", ptr->lastName);
        printf("gpa: %0.2f\n", ptr->GPA);
        
        ptr = ptr->next;
    }
    printf("student id = %d\n", ptr->ID);
    printf("student name = %s\n", ptr->firstName);
    printf("student lastname = %s\n", ptr->lastName);
    printf("gpa: %0.2f\n", ptr->GPA);
    
    
}

struct student* delete(int ID) {

   //start from the first link
   struct student* current = head;
   struct student* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->ID != ID) {

      //if it is last student
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}

struct student* updateStudent(int ID) {

   //start from the first link
   struct student* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->ID != ID) {
	
      //if it is last student
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	fflush(stdin);
    printf("enter new student ID: ");
    scanf("%d", &current->ID);
    printf("enter new first name: ");
    scanf("%s",current->firstName);
    printf("enter new last name: ");
    scanf("%s", current->lastName);
    printf("enter student new gpa: ");
    scanf("%f", &current->GPA);
    
   return current;
}

int length() {
   int length = 0;
   struct student *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

void sort() {

   int i, j, k, tempID, tempGPA;
   char tempFname[30], tempLname[30];
   struct student *current;
   struct student *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->GPA > next->GPA ) {
            tempGPA = current->GPA;
            current->GPA = next->GPA;
            next->GPA = tempGPA;

            tempID = current->ID;
            current->ID = next->ID;
            next->ID = tempID;
            
            strcpy(tempFname, current->firstName);
            strcpy(current->firstName, next->firstName);
            strcpy(next->firstName, tempFname);
            
            strcpy(tempLname, current->lastName);
            strcpy(current->lastName, next->lastName);
            strcpy(next->lastName,tempLname);
            
         }
			
         current = current->next;
         next = next->next;
      }
   }   
}

void reverse(struct student** head_ref) {
   struct student* prev   = NULL;
   struct student* current = *head_ref;
   struct student* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}

void menu(void) {
	printf("Menu:\n");
	printf("1) List All Students\n");
	printf("2) Add a Student\n");
	printf("3) Remove a Student\n");
	printf("4) Update a Student\n");
    printf("5) Write students to file\n");
	printf("6) quit\n");
    printf("\n");
}

void readFromFile(){
    struct student temp;
    FILE *fp = fopen("student_info.txt", "r");
    fscanf(fp, "%*[^\n]\n"); //skips first line
    while(fscanf(fp, "%f %d %s %s\n", &temp.GPA, &temp.ID, temp.firstName, temp.lastName) != EOF){
        add_student(temp);
    }
    fclose(fp);
}

void writeToFile(){
    FILE *tf = fopen("new_students.txt","w");
    
struct student *ptr = NULL;
    ptr = head;
    while(ptr->next != NULL){
        fprintf(tf, "student id = %d ", ptr->ID);
        fprintf(tf, "student name = %s ", ptr->firstName);
        fprintf(tf, "student lastname = %s ", ptr->lastName);
        fprintf(tf, "gpa: %0.2f\n", ptr->GPA);
        
        ptr = ptr->next;
    }
    fprintf(tf, "student id = %d ", ptr->ID);
    fprintf(tf, "student name = %s ", ptr->firstName);
    fprintf(tf, "student lastname = %s ", ptr->lastName);
    fprintf(tf, "gpa: %0.2f\n", ptr->GPA);
    
    fclose(tf);
}

int main()
{
    fflush(stdin);
    readFromFile(); 
    int choice;
    bool run = 1;
    while(run){
        int dID;
        menu();
        printf("please enter menu choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                sort();
                reverse(&head);
                print_students();
                break;
            case 2:;
                struct student temp;
                printf("enter student ID: ");
                scanf("%d", &temp.ID);
                printf("enter first name: ");
                scanf("%s", temp.firstName);
                printf("enter last name: ");
                scanf("%s", temp.lastName);
                printf("enter student gpa: ");
                scanf("%f", &temp.GPA);
        
                add_student(temp);
                break;
            case 3:
                printf("enter student ID to delete: ");
                scanf("%d", &dID);
                delete(dID);
                break;
            case 4:
                printf("enter student ID to update: ");
                scanf("%d", &dID);
                updateStudent(dID);
                break;
            case 5:
                sort();
                reverse(&head);
                writeToFile();
                printf("students written to file\n");
                break;
            case 6:
                run = 0;
                fflush(stdin);
                fflush(stdout);
                exit(0);
            default:
                printf("please enter valid choice");
                break;
        }
    }
    
    
	return 0;
}
