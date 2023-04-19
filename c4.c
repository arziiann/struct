#include <stdio.h>
#include <stdlib.h>

/*Ստեղծել Student ստրուկտուրա, որը ուսանողի մասին կպահի տվյալներ ([char տիպի զանգված]անուն,ազգանուն,  [int]ID(մատյանում ուսանողի համարը) և [int-հինգ չափանի զանգված, որը կպահի ուսանողի միավորները]:
a. ստեղծել «create_student» ֆունկցիա, որը ընդունում է ուսանողի անունը, ID-ն և միավորների զանգվածը և ստեղծում է Student կառուցվածքի նոր օրինակ՝ տրված արժեքներով:
b. ստեղծել «get_average_score» ֆունկցիա, որը վերադարձնում է ուսանողի միջին միավորը:
c. ստեղծել  «set_score» ֆունկցիան, որը ընդունում է ինդեքսը (0-4) և միավորի նոր արժեք(int score) և այդ ցուցանիշի միավորը սահմանում է ուսանողի համար նոր արժեքով:
*/

struct Student
{
    char name[20];
    char surname[20];
    int id;
    int point[5];

};

struct Student create_student(char * name, char * surname, int id, int * point)
{
    struct Student new_student;
    for(int i = 0; i < 20; i++)
    {
        new_student.name[i] = name[i];
    }

    for(int i = 0; i < 20; i++)
    {
        new_student.surname[i] = surname[i];
    }

    new_student.id = id;

    for(int i = 0; i < 5; i++)
    {
        new_student.point[i] = point[i];
    }

    return new_student;

}

int get_average_score(struct Student * new)
{
    int sum = 0;
    int avg = 0;
    int count = 0;

    for(int i = 0; i < 5; i++)
    {
        sum += new->point[i];
        count ++;

    }

    avg  = sum / count;

    return avg;
    


}

int* set_score(struct Student *new, int index, int num)
{
    if(index >= 0 && index < 4)
    {
        new -> point[index] = num;

        return new -> point;

    }

}


int main()
{
    char array_name[] = "Gohar";
    char array_surname[] = "Arzumanyan";
    int id = 1;
    int point[5] = {1, 2, 3, 4, 5} ;
    
    struct Student new = create_student(array_name, array_surname, id, point);
    printf("average in points --> %i \n", get_average_score(&new));

    int index = 0;
    int num = 2;

    
    set_score(&new, index, num);
    for(int i = 0; i < 5; i++)
    {
        printf("%i", new.point[i]);
    }


}