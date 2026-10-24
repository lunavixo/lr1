#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FIRST_NAME  "Назар"
#define LAST_NAME   "Лотоцький"
#define GROUP_CODE  "РС-зп61"
#define FACULTY     "РТФ"
#define UNIVERSITY  "КПІ ім. Ігоря Сікорського"

float avg(const float *arr, unsigned int count);
void part1();
void part2();
float avg(const float *arr, unsigned int count);
double f(double x);
void printTable(double x_arr[], double y_arr[], unsigned int size);
unsigned int printSize(double num);
void pressEnterToContinue();

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    system("cls");

    printf("Оберіть частину програми для виконання\n"
           "1-перша частина\n"
           "2-друга частина\n"
           "за умовчуванням 1 та 2-га послідовно: ");
    int t = 0;
    scanf("%d", &t);
    switch(t){
    case 1:
        part1();
        break;
    case 2:
        part2();
        break;
    default:
        part1();
        part2();
        break;
    }

    return 0;
}

void part1(){
    int age, semester;
    float admission_score, score_subj1, score_subj2, score_subj3, score_subj4, score_subj5, score_subj_avg;

    system("cls");

    printf("***************\n");

    printf("%s %s\n", FIRST_NAME, LAST_NAME);
    printf("%s %s\n", FACULTY, GROUP_CODE);

    printf("***************\n");

    unsigned int age, semester, score_subj1, score_subj2, score_subj3, score_subj4, score_subj5;
    float admission_score, score_subj_avg;

    printf("Введіть вік: ");
    scanf("%u", &age);

    printf("Введіть семестр: ");
    scanf("%u", &semester);

    printf("Введіть вступний бал: ");
    scanf("%f", &admission_score);

    printf("Введіть оцінку за предмет №1: ");
    scanf("%u", &score_subj1);

    printf("Введіть оцінку за предмет №2: ");
    scanf("%u", &score_subj2);

    printf("Введіть оцінку за предмет №3: ");
    scanf("%u", &score_subj3);

    printf("Введіть оцінку за предмет №4: ");
    scanf("%u", &score_subj4);

    printf("Введіть оцінку за предмет №5: ");
    scanf("%u", &score_subj5);

    score_subj_avg = avg((float[])
                         {score_subj1,
                         score_subj2,
                         score_subj3,
                         score_subj4,
                         score_subj5}, 5);

    printf("===============\n");

    printf("%s %s\n", FIRST_NAME, LAST_NAME);
    printf("%s %s\n", FACULTY, GROUP_CODE);
    printf("Вступний бал: %.1f\n", admission_score);
    printf("Cередній бал з 5-ох предметів: %.2f\n", score_subj_avg);

    printf("===============\n");
    pressEnterToContinue();
}

void part2(){
    system("cls");

    int t = 0;

    printf("Оберіть варіант введення початкових данних\n"
           "1 - початкове, кінцеве значення та кількість точок в таблиці (за умовчанням)\n"
           "2 - початкове, кінцеве значення та крок зміни аргументу\n"
           ": ");
    scanf("%u", &t);

    if(t == 1){
        double x1, x2;
        printf("Початкове значення аргументу: ");
        scanf("%lf", &x1);
        printf("%lf\n", x1);

        while(true){
            printf("Кінцеве значення аргументу: ");
            scanf("%lf", &x2);
            printf("%lf\n", x2);

            if(x2 > x1)break;
            printf("Неправильне кінцеве значення\n");
        }

        unsigned int n;
        printf("Кількість точок у таблиці: ");
        scanf("%u", &n);

        double delta = 0;
        if(n > 0)delta = (x2 - x1)/(n-1);
        double x_arr[n], y_arr[n];
        for(unsigned int i = 0; i < n; i++){
            x_arr[i] = x1 + delta*i;
            y_arr[i] = f(x_arr[i]);
        }
        printTable(x_arr, y_arr, n);
    }
    else {
        double x1, x2;
        printf("Початкове значення аргументу: ");
        scanf("%lf", &x1);
        printf("%lf\n", x1);

        while(true){
            printf("Кінцеве значення аргументу: ");
            scanf("%lf", &x2);

            if(x2 > x1)break;
            printf("Неправильне кінцеве значення\n");
        }

        double delta;

        while(true){
            printf("Крок зміни аргументу: ");
            scanf("%lf", &delta);

            if(delta > 0)break;
            printf("Неправильний крок зміни аргументу\n");
        }

        unsigned int n = (unsigned int)floor((x2 - x1) / delta) + 1;
        double x_arr[n], y_arr[n];
        for(unsigned int i = 0; i < n; i++){
            x_arr[i] = x1 + delta*i;
            y_arr[i] = f(x_arr[i]);
        }
        printTable(x_arr, y_arr, n);
    }
    pressEnterToContinue();
}

//Обчислює середнє значення чисел з плаваючою комою
float avg(const float *arr, unsigned int count){
    float sum = 0.0;
    for(unsigned int i = 0; i < count; i++){
        sum += arr[i];
    }
    return sum / count;
}

//Функція залежності y від x за умовою варіанту 2
double f(double x){
    return 0.25*pow(x, 5) + 4.0 * pow(x + 20.0, 4) - 2.0 * x;
}

//Виведення таблиці на екран
void printTable(double x_arr[], double y_arr[], unsigned int size){
    //Обчислення розміру комірки для чисел
    unsigned int max_print_size = 0;

    for(unsigned int i = 0; i < size; i++){
        unsigned int print_size = printSize(x_arr[i]);
        if(max_print_size < print_size)max_print_size = print_size;
        print_size = printSize(y_arr[i]);
        if(max_print_size < print_size)max_print_size = print_size;
    }

    //Виведення таблиці
    for(unsigned int i = 0; i < size; i++){
        if(i == 0)printf("╔═╦");
        for(int j = 0; j < max_print_size; j++)printf("═");
        if(i == size - 1)printf("╗\n");
        else printf("╤");
    }

    for(unsigned int i = 0; i < size; i++){
        if(i == 0)printf("║x║");
        printf("%*.*lf",
               max_print_size,
               log10(fabs(x_arr[i])) < 0 ? 2 - (int)floor(log10(fabs(x_arr[i]))) : 2,
               x_arr[i]);
        if(i == size - 1)printf("║\n");
        else printf("│");
    }

    for(unsigned int i = 0; i < size; i++){
        if(i == 0)printf("╟─╫");
        for(int j = 0; j < max_print_size; j++)printf("─");
        if(i == size - 1)printf("╢\n");
        else printf("┼");
    }

    for(unsigned int i = 0; i < size; i++){
        if(i == 0)printf("║y║");
        printf("%*.*lf",
               max_print_size,
               log10(fabs(y_arr[i])) < 0 ? 2 - (int)floor(log10(fabs(y_arr[i]))) : 2,
               y_arr[i]);
        if(i == size - 1)printf("║\n");
        else printf("│");
    }

    for(unsigned int i = 0; i < size; i++){
        if(i == 0)printf("╚═╩");
        for(int j = 0; j < max_print_size; j++)printf("═");
        if(i == size - 1)printf("╝\n");
        else printf("╧");
    }
}
//Обчислення ширини комірки, яку займає цифра
unsigned int printSize(double num){
    if(num == 0)return 1;
    return num<0?1:0 + 2 + abs((int)floor(log10(fabs(num)))) + 2;
}

//Очікує Enter від користувача щоб продовжити
void pressEnterToContinue() {
    printf("\Натисніть Enter щоб продовжити...");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    getchar();
}
