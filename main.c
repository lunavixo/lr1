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
void printTable(double x_arr[], double y_arr[], unsigned int size, double delta);
void pressEnterToContinue();
unsigned int beforeDecimalSize(double num);
unsigned int afterDecimalSize(double num);
unsigned int afterDecimalSizeDelta(double num, double delta);

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

        while(true){
            printf("Кінцеве значення аргументу: ");
            scanf("%lf", &x2);

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
        printTable(x_arr, y_arr, n, delta);
    }
    else {
        double x1, x2;
        printf("Початкове значення аргументу: ");
        scanf("%lf", &x1);

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
        printTable(x_arr, y_arr, n, delta);
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
void printTable(double x_arr[], double y_arr[], unsigned int size, double delta){
    //Обчислення розміру комірки для чисел
    unsigned int max_before_decimal_x = 0;
    unsigned int max_before_decimal_y = 0;
    unsigned int max_after_decimal_x = 0;
    unsigned int max_after_decimal_y = 0;

    for(unsigned int i = 0; i < size; i++){
        unsigned int before_decimal = beforeDecimalSize(x_arr[i]);
        unsigned int after_decimal = afterDecimalSizeDelta(x_arr[i], delta);

        max_before_decimal_x = before_decimal > max_before_decimal_x ? before_decimal : max_before_decimal_x;
        max_after_decimal_x = after_decimal > max_after_decimal_x ? after_decimal : max_after_decimal_x;

        before_decimal = beforeDecimalSize(y_arr[i]);
        after_decimal = afterDecimalSize(y_arr[i]);

        max_before_decimal_y = before_decimal > max_before_decimal_y ? before_decimal : max_before_decimal_y;
        max_after_decimal_y = after_decimal > max_after_decimal_y ? after_decimal : max_after_decimal_y;
    }
    unsigned int max_size_print = max_before_decimal_x + max_after_decimal_x > max_before_decimal_y + max_before_decimal_y
    ? max_before_decimal_x + max_after_decimal_x
    : max_before_decimal_y + max_before_decimal_y;

    //Виведення таблиці
    for(unsigned int i = 0; i < size; i++){
        if(i == 0)printf("╔═╦");
        for(int j = 0; j < max_size_print; j++)printf("═");
        if(i == size - 1)printf("╗\n");
        else printf("╤");
    }

    for(unsigned int i = 0; i < size; i++){
        if(i == 0)printf("║x║");
        printf("%*.*lf",
               max_size_print,
               max_after_decimal_x,
               x_arr[i]);
        if(i == size - 1)printf("║\n");
        else printf("│");
    }

    for(unsigned int i = 0; i < size; i++){
        if(i == 0)printf("╟─╫");
        for(int j = 0; j < max_size_print; j++)printf("─");
        if(i == size - 1)printf("╢\n");
        else printf("┼");
    }

    for(unsigned int i = 0; i < size; i++){
        if(i == 0)printf("║y║");
        printf("%*.*lf",
               max_size_print,
               max_after_decimal_y,
               y_arr[i]);
        if(i == size - 1)printf("║\n");
        else printf("│");
    }

    for(unsigned int i = 0; i < size; i++){
        if(i == 0)printf("╚═╩");
        for(int j = 0; j < max_size_print; j++)printf("═");
        if(i == size - 1)printf("╝\n");
        else printf("╧");
    }
}
//Обчислення ширини комірки, яку займає цифра
unsigned int beforeDecimalSize(double num){
    if(num == 0)return 2;
    return (num < 0 ? 2 : 1) + ((int)floor(log10(fabs(num))) < 1 ? 1 : abs((int)floor(log10(fabs(num)))));
}

unsigned int afterDecimalSize(double num){
    if(num == 0)return 2;
    return (int)floor(log10(fabs(num))) > 0 ? 2 : (abs((int)floor(log10(fabs(num)))) + 2);
}

unsigned int afterDecimalSizeDelta(double num, double delta){
    unsigned int size_num = afterDecimalSize(num);
    unsigned int size_delta = afterDecimalSize(delta);
    if(size_delta > size_num)return size_delta;
    return size_num;
}

//Очікує Enter від користувача щоб продовжити
void pressEnterToContinue() {
    printf("\nНатисніть Enter щоб продовжити...");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    getchar();
}
