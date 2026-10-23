#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define FIRST_NAME  "Назар"
#define LAST_NAME   "Лотоцький"
#define GROUP_CODE  "РС-зп61"
#define FACULTY     "РТФ"
#define UNIVERSITY  "КПІ ім. Ігоря Сікорського"

int age = 19;
int semester = 1;
float admission_score = 168.7;
float score_subj1 = 72;
float score_subj2 = 85;
float score_subj3 = 67;
float score_subj4 = 76;
float score_subj5 = 78;
float score_subj_avg;

float avg(const float *arr, unsigned int count);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    system("cls");

    printf("***************\n");
    printf("===============\n");

    printf("%s %s\n", FIRST_NAME, LAST_NAME);
    printf("%s %s\n\n", FACULTY, GROUP_CODE);

    score_subj_avg = avg((float[])
                         {score_subj1,
                         score_subj2,
                         score_subj3,
                         score_subj4,
                         score_subj5}, 5);
    printf("Вступний бал: %.1f\n", admission_score);
    printf("Cередній бал з 5-ох предметів: %.2f\n", score_subj_avg);

    return 0;
}

float avg(const float *arr, unsigned int count)
{
    float sum = 0.0;
    for(unsigned int i = 0; i < count; i++){
        sum += arr[i];
    }
    return sum / count;
}
