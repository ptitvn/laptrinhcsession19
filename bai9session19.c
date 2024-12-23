#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct STUDENT{
    int id;
    int age;
    char name[40];
};

void MENU();
void swapStudent(struct STUDENT *a,struct STUDENT *b );
void PrintStudentList(struct STUDENT sv[100], int *length);
void addStudent(struct STUDENT sv[100], int *length, int *ID);
void correctStudent(struct STUDENT sv[100], int *length);
void searchStudent(struct STUDENT sv[100],int *length);
void deleteStudent(struct STUDENT sv[100],int *length,int *ID);
void softStudentList(struct STUDENT sv[100],int *length);
int main(){
    int menu, ID = 50, length = 5;
    struct STUDENT sv[100];
    char x = 'a';
    srand(time(0));
    for(int i = 0; i < 5; i++){
        sv[i].id = i + 1;
        sv[i].age = (rand()%4)+17;
        sprintf(sv[i].name, "Sinh Vien %c", x++);
    }

    while(1){
        MENU();
        scanf("%d", &menu);
        getchar();
        switch(menu){
            case 1:
                PrintStudentList(sv, &length);
                break;
            case 2:
                addStudent(sv, &length, &ID);
                break;
            case 3:
                correctStudent(sv, &length);
                break;
            case 4:
                deleteStudent(sv,&length,&ID);
                break;
            case 5:
                searchStudent(sv,&length);
                break;
            case 6:
                softStudentList(sv,&length);
                break;
            case 7:
                return 0;
            default:
                printf("khong hop le!!\n");
                break;
        }
    }
    return 0;
}
void swapStudent(struct STUDENT *a,struct STUDENT *b ){
    struct STUDENT temp = *a;
    *a = *b;
    *b = temp;
}
void MENU(){
    printf("Options.\n");
    printf("1. Hien thi danh sach sinh vien.\n");
    printf("2. Them sinh vien.\n");
    printf("3. Sua thong tin sinh vien.\n");
    printf("4. Xoa sinh vien.\n");
    printf("5. Tim kiem sinh vien.\n");
    printf("6. Sap xep danh sach sinh vien.\n");
    printf("7. Thoat.\n");
    printf("Lua chon: ");
}
void PrintStudentList(struct STUDENT sv[100], int *length){
    for(int i = 0; i < *length; i++){
        printf("ID sv[%d]: %d\n", i + 1, sv[i].id);
        printf("Tuoi sv[%d]: %d\n", i + 1, sv[i].age);
        printf("Ten sv[%d]: %s\n", i + 1, sv[i].name);
    }
}
void addStudent(struct STUDENT sv[100], int *length, int *ID){
    printf("Them thong tin sv.\n");
    sv[*ID].id = *ID + 1;
    printf("ID: %d\n", sv[*ID].id);
    printf("Nhap tuoi: ");
    scanf("%d", &sv[*ID].age);
    getchar();
    printf("Ten sv: ");
    fgets(sv[*ID].name, sizeof(sv[*ID].name), stdin);
    sv[*ID].name[strcspn(sv[*ID].name, "\n")] = '\0';
    (*length)++;
    printf("Thong tin sinh vien moi:\n");
    printf("ID: %d\n", sv[*ID].id);
    printf("Tuoi: %d\n", sv[*ID].age);
    printf("Ten: %s\n", sv[*ID].name);
    (*ID)++;
}
void correctStudent(struct STUDENT sv[100], int *length){
    printf("nhap id sinh vien muon sua: ");
    int ID;
    scanf("%d", &ID);
    for(int i = 0; i < *length; i++){
        if(sv[i].id == ID){
            printf("tuoi: ");
            scanf("%d", &sv[i].age);
            getchar();
            printf("nhap ten sv: ");
            fgets(sv[i].name, sizeof(sv[i].name), stdin);
            sv[i].name[strcspn(sv[i].name, "\n")] = '\0';
            printf("id sv[%d]: %d\n", i + 1, sv[i].id);
            printf("tuoi sv[%d]: %d\n", i + 1, sv[i].age);
            printf("ten sv[%d]: %s\n", i + 1, sv[i].name);
            break;
        }
    }
}
void searchStudent(struct STUDENT sv[100],int *length){
        printf("1.tim theo ten.\n");
        printf("2.tim theo id.\n");
        printf("lua chon cua ban: ");
        int menu,z;
        char x[30];
        scanf("%d",&menu);
        getchar();
        switch(menu){
            case 1:
                printf("ten muon tim kiem: ");
                fgets(x,sizeof(x),stdin);
                x[strcspn(x,"\n")]='\0';
                for(int i=0; i<*length; i++){
                    if(strcmp(sv[i].name,x)==0){
                        printf("sv nam o vi tri thu: %d\n", sv[i].id);
                        printf("tuoi sv[%d]: %d\n", i + 1, sv[i].age);
                        printf("ten sv[%d]: %s\n", i + 1, sv[i].name);
                        break;
                    }
                }
                break;
            case 2:
                printf("id tim kiem: ");
                scanf("%d",&z);
                for(int i=0; i<*length; i++){
                    if(sv[i].id==z){
                        printf("sv nam o vi tri thu: %d\n", sv[i].id);
                        printf("tuoi sv[%d]: %d\n", i + 1, sv[i].age);
                        printf("ten sv[%d]: %s\n", i + 1, sv[i].name);
                        break;
                    }
                }
                break;
            default:
                printf("khong hop le:\n");
                break;

        }
}
void deleteStudent(struct STUDENT sv[100],int *length,int *ID){
    printf("nhap id sinh vien muon xoa.\n");
    int s;
    scanf("%d",&s);
    for(int i=s-1; i<*length; i++){
        sv[i].id=sv[i+1].id;
        sv[i].age=sv[i+1].age;;
        strcpy(sv[i].name,sv[i+1].name);
    }
    (*length)--;
    (*ID)--;
}
void softStudentList(struct STUDENT sv[100],int *length){
    for(int i=0;i<*length-1;i++){
        for(int j=0;j<*length-i-1;j++){
            if(sv[j].age>sv[j+1].age){
                swapStudent(&sv[j],&sv[j+1]);
            }
        }
    }
}
