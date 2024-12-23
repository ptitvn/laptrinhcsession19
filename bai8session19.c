#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct STUDENT{
    int id;
    int age;
    char name[30];
    char phone[12];
};
void swap(struct STUDENT *a,struct STUDENT *b);
int main()
{
    int length=5;
    srand(time(0));
    struct STUDENT sv1[50];
    int phone=1;
    for(int i=0; i<5; i++){
        sv1[i].id=i+1;
        sv1[i].age=(rand()%4)+18;
        sprintf(sv1[i].name,"%c",'a'+i);
        sprintf(sv1[i].phone,"%010d",phone+i);
    }
    PrintStudentList(sv1,&length);
    printf("\nsau khi sap sep\n");
    softStudentList(sv1,&length);
    PrintStudentList(sv1,&length);
    printf("Hello world!\n");
    return 0;
}
void swap(struct STUDENT *a,struct STUDENT *b){
    struct STUDENT temp=*a;
    *a=*b;
    *b=temp;
}
void softStudentList(struct STUDENT sv1[100],int *length){
    for(int i=0; i<*length-1; i++){
        for(int j=0; j<*length-1-i; j++){
            if(sv1[j].age>sv1[j+1].age){
                swap(&sv1[j],&sv1[j+1]);
            }
        }
    }

}
void PrintStudentList(struct STUDENT sv1[100], int *length){
    for(int i = 0; i < *length; i++){
        printf("ID sv[%d]: %d\n", i + 1, sv1[i].id);
        printf("Tuoi sv[%d]: %d\n", i + 1, sv1[i].age);
        printf("Ten sv[%d]: %s\n", i + 1, sv1[i].name);
        printf("so dien thoai sv[%d]: %s\n",i+1,sv1[i].phone);
    }
}