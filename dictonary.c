#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct {
    char eng[32];
    char uz[32];
}word;

void display(){
    puts("+--------------------------------+");
    puts("|  Ingilizcha Uzbekcha lug'at.   |");
    puts("+--------------------------------+");
    puts("|  1. Yangi so'z qo'shish.       |");
    puts("|  2. Barcha so'zlarni ko'rish.  |");
    puts("|  3. Qidiruv.                   |");
    puts("|  4. Chiqish.                   |");
    puts("+--------------------------------+");
    printf("  Tanlang: ");
}

void add_new_word(){

    word new;
    word old;
    int check=1,n;

    printf("Ingilizcha: ");scanf("%s",new.eng);
    printf("Uzbekcha: ");scanf("%s",new.uz);

    FILE *f = fopen("dict.txt","r+");

    while (fscanf(f,"%s",old.eng) != EOF){
        fscanf(f,"%s",old.uz);
        for (int i = 0; old.eng[i]!='\0'; i++){
            old.eng[i]=tolower(old.eng[i]);
        }
        for (int i = 0; new.eng[i]!='\0'; i++){
            new.eng[i]=tolower(new.eng[i]);
        }
        
        if (!strcmp(old.eng,new.eng)){
            check=0;
            break;
        }
        
    }

    fseek(f,0,2);

    if (check){
        fprintf(f,"%s %s\n",new.eng, new.uz);
    }else{
        printf("\nBunday so'z Bor.\n");
    }
    

    printf("\n1. Menu ga qaytish\n");
    printf("2. Chiqish");
    printf(">>> ");scanf("%d",&n);
    if (n==2){
        system("cls");
        exit(0);
    }

    fclose(f);
}

void show_words(){
    word current;
    int n;

    FILE *f = fopen("dict.txt","r");
    if (f == NULL){
        printf("Bunday fayl yo'q");
        exit(1);
    }

    puts("+--------------------------------+");
    puts("|   Ingilizcha   |   Uzbekcha    |");
    puts("+--------------------------------+");

    while (fscanf(f,"%s",current.eng) != EOF){
        fscanf(f,"%s",current.uz);
        printf("| %14s | %-13s |\n",current.eng,current.uz);
    }
    puts("+--------------------------------+");

    printf("\n1. Menu ga qaytish\n");
    printf("2. Chiqish");
    printf(">>> ");scanf("%d",&n);
    if (n==2){
        system("cls");
        exit(0);
    }

    fclose(f);
    
}

void search_word(){
    word search;
    char found[32];
    int n,check=1;

    printf("\nqaysi so'zni qidiryapsiz: ");scanf("%s",found);

    FILE *f = fopen("dict.txt","r");

    while (fscanf(f,"%s",search.eng) != EOF){
        fscanf(f,"%s",search.uz);
        for (int i = 0; search.eng[i]!='\0'; i++){
            search.eng[i]=tolower(search.eng[i]);
        }
        for (int i = 0; search.uz[i]!='\0'; i++){
            search.uz[i]=tolower(search.uz[i]);
        }
        for (int i = 0; found[i]!='\0'; i++){
            found[i]=tolower(found[i]);
        }
        
        if (!strcmp(search.uz,found)){
            printf("\nIngilizchasi: %s",search.eng);
            check=0;
            break;
        }else if (!strcmp(search.eng,found)){
            printf("\nUzbekchasi: %s",search.uz);
            check=0;
            break;
        }
        
    }

    if (check){
        printf("\nBunday so'z topilmadi.");
    }
    

    printf("\n1. Menu ga qaytish\n");
    printf("2. Chiqish");
    printf(">>> ");scanf("%d",&n);
    if (n==2){
        system("cls");
        exit(0);
    }

    fclose(f);    
}


int main(){

    int choise = 0;

    while (choise!=4){
        system("cls");
        display();

        scanf("%d",&choise);

        switch (choise){
            case 1: add_new_word(); break;
            case 2: show_words(); break;
            case 3: search_word(); break;
            case 4: break;
            default: printf("faqat menudagilardan tanlang!!!\n"); break;
        }
    }
    
}