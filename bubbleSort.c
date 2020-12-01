  #include<stdio.h>
#include<string.h>
#include<conio.h>


struct employee {
  int id;
  int salary ;
  char name[20];
};
struct employee ar [5];
void fill();
void B_Sort();
void print();
void add_employee (struct employee emp);
int index=0;
int main (){
    int opration;
    int flag = 0;
    do{    if(index<5){
	printf(" to add new employee enter 1 \n and 2 for end program and print \n");
	}else{
	printf("there is no storage for adding new employee \n enter 2 to print \n");
	}
	scanf("%d",&opration);
	if(opration==1){
	   if(index<5){ fill();    }
	}else if (opration==2){
	    B_Sort();
	    print();
	    flag=1;
	}
	
    }while(flag == 0);

    getch();
    clrscr();
return 0;
}
void B_Sort(){

 int i,j;
 struct employee temp;

 for(j=0 ; j<index-1;j++){

   for(i=0;i<index-1-j;i++){

      if(ar[i].id > ar[i+1].id){
	 temp=ar[i];
	 ar[i]=ar[i+1];
	 ar[i+1]=temp;

      }
   }
 }
}

void add_employee (struct employee emp){
	if (index<=4){

		 ar[index]= emp;
		 index++;
	}

	else {
		printf("sorry there is no position for adding now one ");
	}

}
void fill (){
	struct employee emp ;
	printf("enter the id : ");
	scanf("%d",&emp.id);
	printf("enter the name : ");
	scanf("%s",emp.name);
	printf("enter the salary : ");
	scanf("%d",&emp.salary);
	add_employee(emp);
}
void print(){
	int i;
	for (i=0;i<=index-1;i++){
	printf("id : %d  |  name: %s  |  salary: %d \n",ar[i].id,ar[i].name,ar[i].salary);

	}

}
