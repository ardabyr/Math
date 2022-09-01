students.h

#ifndef l_stud_h
#define l_stud_h

typedef struct{
  char surname[20]; 
  char name[2];
  char male[1];
  unsigned numb_sch;
  unsigned medals;
  unsigned math;
  unsigned lang;
  unsigned inf;
  unsigned soch;
}students;

#endif //l_stud_h


________________________________________________
students_dump.c

#include <stdio.h> 
#include <string.h> 
#include <errno.h> 
 
#include "student.h" 
 
void usage() { 
    printf("Usage: program input_filename output_filename\n"); 
} 
 
int readstudent(FILE *in, students *p) { 
    return fscanf(in, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%d\t%d\t%d\t%d\t%d\t", p->surname, p->name, p->male, &p->numb_sch, &p->medals, &p->math, &p->lang, &p->inf, &p->soch) == 10; 
} 
 
int main(int argc, char *argv[]) { 
    if (argc != 3) { 
        usage(); 
        return 1; 
    } 
    students p; 
    FILE *out = fopen(argv[2], "w"); 
    FILE *in = fopen(argv[1], "r"); 
    if (!(out && in)) { 
        perror("Can't open file"); 
        return 2; 
    } 
    while (readstudent(in, &p)) { 
        fwrite(&p, sizeof(p), 1, out); 
    } 
    return 0; 
}


___________________________________________
cool_students.h

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <limits.h> 
#include "student.h" 
 
int main(int argc, char *argv[]) { 
    FILE *in; 
    int f = 0; 
    if (!(argc == 3 || argc == 4)) { 
        return 1; 
    } 
    if (strcmp(argv[1], "-f") == 0) { 
        f = 1; 
        in = fopen(argv[2], "r"); 
    } else { 
        return 2; 
    } 
    students stud; 
    if (!in) { 
        perror("Can not open file\n"); 
        return 3; 
    } 
  
   int flag = 0, sr_ball = 0,kolvo = 0,p = 0; 
   while (fread(&stud, sizeof(stud), 1, in) == 1) { 
     if ((stud.medals || stud.soch) > 1 || (stud.medals || stud.math || stud.lang || stud.inf || stud.soch) < 0 || (stud.math || stud.lang || stud.inf) > 100) { 
           flag = 1; 
       } 
       if (f) { 
  sr_ball += (stud.math + stud.lang + stud.inf);
  kolvo++; 
       } 
   } 
   p = (sr_ball)/kolvo;
   if (f) { 
       return 0; 
   } 
   if (flag == 1) { 
    printf("Данные введены неверно!\n"); 
    return 4; 
   } 
    fseek(in, 0, SEEK_SET); 
    printf("Фамилия\tИ.О.\tпол\tшкола№\tмедали\tэкз 1\tэкз 2\tэкз 3\tсочинение\n");
    while (fread(&stud, sizeof(stud), 1, in) == 1) { 
        if ((stud.math + stud.lang + stud.inf) > p && stud.medals == 0) { 
            printf("%-15s\t%-2s\t%-6s\t%-5d\t%-1d\t%-1d\t%-1d\t%-1d\t%-1d\t\n", stud.surname, stud.name, 
                  stud.male, stud.numb_sch, stud.medals, stud.math, stud.lang, stud.inf, stud.soch);
        } 
    } 
    return 0;
}
