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
void merge_sort(int LB,int UB);
void merge (int low , int mid , int high);
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
	merge_sort(0,index-1);
	    print();
	    flag=1;
	}
	  
    }while(flag == 0);

    getch();
    clrscr();
return 0;
}

void merge_sort(int LB , int UB){
	int mid;
	if(LB<UB){
		mid=(LB+UB)/2;
		merge_sort(LB,mid);
		merge_sort(mid+1,UB);
		merge(LB,mid,UB);
	}

}
void merge (int low , int mid , int high){

	struct employee temp[5];
	int list1,list2,i;
	list1=low ;
	list2=mid+1;
	i=low;
	while(list1<=mid&&list2<=high){
		if(ar[list1].id<ar[list2].id){
			temp[i]=ar[list1];
			list1++;
			i++;


		}else {


			temp[i]=ar[list2];
			list2++;
			i++;


		}

	}
	while(list1<=mid){

		temp[i]=ar[list1];
		list1++;
		i++;
	}
	while (list2<=high){
		temp[i] =ar[list2] ;
		list2++;
		i++;
	}
	for (i=low;i<=high;i++){

		ar[i]=temp[i];
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
