#define _GNU_SOURCE
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct AttributesHeroes
{
    int strength;
    int HP;
    int stamina;
    int intelligence;
    int swiftnes;
    int speed;
    char attitude[50];
    int control;
    int valor;
};

struct Hero
{
   char  name[35];
   char power[50];
   char description[150];
   int age;
   int id;
   struct AttributesHeroes atr;

};


void greating (struct Hero hero);
int chooseHero(struct Hero hero);
void RemoveSpaces(char* source);


int main()
{
    struct Hero hero;
    struct AttributesHeroes atr;
   // printf() displays the string inside quotation
   printf ("Enter the full name of the hero:");
   scanf ("%[^\n]",&hero.name);
   printf ("Enter the power of the hero:");
   scanf(" %[^\n]",&hero.power); 
   printf("Enter the age of the hero:");
   scanf("%d",&hero.age);
   printf ("Description of the power of the hero:");
   scanf(" %[^\n]",&hero.description);
/*    printf ("Now we are going to put the hero attributes: \n");
   printf ("Strength:\n");
   scanf(" %d",&hero.atr.strength);
   printf("Intelligence \n");
   scanf("%d", &hero.atr.intelligence);
   printf("Swiftness both mind and body \n");
   scanf("%d", &hero.atr.swiftnes);
   printf("Speed \n");
   scanf("%d", &hero.atr.speed);
   printf("Attitude\n");
   scanf(" %[^\n]", hero.atr.attitude);
   printf("Control in Their abilities\n");
   scanf("%d", &hero.atr.control);
   printf("Valor as a Hero \n");
   scanf("%d", &hero.atr.valor); */

  
   
   int len = strlen(hero.name);
   len = len-1;
   //printf("El tamano es : %d  \n", len);
   if (len % 2 == 0) {
       hero.id = 1;
   }
   else
   {
       hero.id = 2;
   }
   greating(hero);
   system("pause");
   return 0;
}

void greating(struct Hero hero) {
    if (hero.id % 2) {
        printf("\n");
        printf("\n");
        printf("  %s  Shonen soy All Might y te doy la Bienvenida HAHAHAHAHAHAHAHAHAHAAHAHA \n", hero.name);
        printf("\n");
        printf("\n");
        chooseHero(hero);
    }
    else
    {
        printf("\n");
        printf("\n");
        printf("  %s  Soy Shouta Aizawa , pasa nino \n ", hero.name);
        printf("\n");
        printf("\n");
         chooseHero(hero);
    }  
}

int chooseHero( struct Hero hero){
    int index;
    int puntuacion = 0;
        
         printf("Bienvenido al examen de admision, en el cual se determinara si tienes madera de ser estudiante de la U.A\n");
         
        FILE *file = fopen("TestEval.txt", "r");
        int count = 0;
        if ( file != NULL )
        {
            int resault = firstTest(file,puntuacion);
    }else
        {
            printf("El archivo especificado no existe");
            
        }
}

void RemoveSpaces(char* source)
            {
                char* i = source;
                char* j = source;
                while(*j != 0)
                {
                    *i = *j++;
                    if(*i != ' ')
                    i++;
                }
                *i = 0;
            }


int firstTest(FILE *file, int puntuacion ){
    int  i;
    int count = 0;
    char question1[35];
    for( i = 0; i < 3; i++)
            {
            
                srand(time(NULL));   
                int r = rand() %7;
                char line[256]; 
                int lineNumber = r;  
            while (fgets(line, sizeof line, file) != NULL) 
            {
                if (count == lineNumber)
                {
                   printf("\n");
                   printf("\n");
                    char *p = strtok (line, ";");
                    char *array[3];
                    while (p != NULL)
                    {
                        array[i++] = p;
                        p = strtok (NULL, ";");
                    }
                   RemoveSpaces(array[1]);
                   printf("Pregunta :\n%s\n", array[0]);
                   scanf (" %[^\n]",&question1);
                   RemoveSpaces(question1);
                   

                   int temporal =strcmp(array[1],question1);
                   //printf("\n Pues lo que vale la comparacion es : %d \n", temporal);
                   if (temporal == 0) {
                    
                       puntuacion++;
                       printf("la puntuacion es : %d \n" ,puntuacion);
                       
                        

                   }
                   else
                   {
                       printf("you are wrong the answer is %s an you answered %s \n", array[1],question1);
                       
                      
                   }
                   count++;
                  // printf("Count aumenta a : %d \n", count);
                }
                else
                {
                    count++;
                   // printf("Count aumenta a en el else : %d \n", count);
                }
            }
          
           count = 0;
           
           
           
        
         fclose(file);
            }

    
}