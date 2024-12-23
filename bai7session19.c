#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct student{
    int id;
    int age;
    char name[30];
    char phone[12];
};
void searchAndDelete(struct student sv[20],int *length);
int main()
{
    srand(time(0));
    printf("nhap so sv: ");
    int sosv;
    scanf("%d",&sosv);
    getchar();
    int length=sosv;
    struct student sv[sosv];
    for(int i=0; i<length; i++){
        sv[i].id=i+1;
        sv[i].age=(rand()%4)+17;
        sprintf(sv[i].name,"%c",'a'+i);
        sprintf(sv[i].phone,"%010d",i);
    }
    PrintStudentList(sv,&length);
    searchAndDelete(sv,&length);
    PrintStudentList(sv,&length);
    printf("Hello world!\n");
    return 0;
}
void PrintStudentList(struct student sv[100], int *length){
    for(int i = 0; i < *length; i++){
        printf("ID sv[%d]: %d\n", i + 1, sv[i].id);
        printf("Tuoi sv[%d]: %d\n", i + 1, sv[i].age);
        printf("Ten sv[%d]: %s\n", i + 1, sv[i].name);
        printf("so dien thoai sv[%d]: %s\n",i+1,sv[i].phone);
    }
}
void searchAndDelete(struct student sv[20],int *length){
    printf("nhap id sv muon xoa: ");
    int ID,temp=0;
    scanf("%d",&ID);
    getchar();
    if(ID>=0 && ID<=*length){
        printf("sv nam o vi tri %d. da duoc xoa.\n",ID-1);
        for(int i=ID; i<*length;i++){
        sv[i]=sv[i+1];
        }
        (*length)--;
    }else{
        printf("sinh vien khong ton tai.\n");
        return 0;
    }

}