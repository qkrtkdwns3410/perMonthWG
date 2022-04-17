#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double input_tmp[35];

int getMonthDay(int month);

int getDay();

int getHiDay();

int getLowDay();

double getAve();

void display();

int size_of_list;

int main() {
    int input_month = 0;
    int start_day = 0;
    int how_long = 0;
    
    
    printf("월을 입력하세요 : ");
    scanf_s("%d", &input_month);

// 1.2 달에 대한 최대 일자(dayNum) 계산한다(getMonthDay).
    int dayNum = getMonthDay(input_month);
    
    printf("온도를 입력하시오 (1 ~ 31일) : ");
    for (int i = 1; i <= dayNum; i++) {
        scanf_s("%lf", &input_tmp[i]);
    }
    
    size_of_list = sizeof(input_tmp) / sizeof(double);
    
    printf("그래프 출력을 원하는 기간 (시작일 , 기간) : ");
    scanf_s("%d %d", &start_day, &how_long);
    printf("%d %d\n", start_day, how_long);
    
    
//2.1 월 최고 기온(hiDay)을 기록한 날짜를 계산한다(getHiDay).
    
    int hi_day = getHiDay();
    
    int low_day = getLowDay();
    
    double avg_value = getAve();
    
    printf("%d월 기온 보고서\n", input_month);
    printf("=======================================\n");
    printf(" 가장 추운날 :                   %d일\n", low_day);
    printf(" 가장 더운날 :                   %d일\n", hi_day);
    printf(" 평균 기온 :                   %.2lf도\n", avg_value);
    printf("=======================================\n");
    display(start_day, how_long);
    
    return 0;
}

void display( int start_day, int how_long) {
    printf("%d\n", start_day);
    printf("%d\n", how_long);
    
    printf("day:=====0=============================\n");
    for (int i = start_day; i <= start_day + how_long; i++) {
        printf("  %d :", i);
        if (input_tmp[i] < 0.0f) {
            for (int j = 0; j < 10 + (int)input_tmp[i]-1; j++) {
                printf(" ");
            }
            printf("*");
            for (int j = 0; j < 0 - (int)input_tmp[i]-1; j++) {
                printf(" ");
            }
            
            printf("|\n");
            continue;
    
        } else if (input_tmp[i] > 0.0f) {
            printf("         |");
            
            for (int j = 0; j < input_tmp[i] - 0.0; j++) {
                printf(" ");
            }
            
        } else {
            printf("         ");
            
        }
        printf("*\n");
        
    }
    printf("day:===========0=============================\n");
}

/*
 *  @ 목적 : 평균 구하기
 *   @ 매개변수 : int days  int  num : 해당 월의 총 날짜수
 *
 * */
double getAve() {
    double avg_num = 0.0;
    
    for (int i = 0; i < size_of_list; i++) {
        avg_num += input_tmp[i];
    }
    
    avg_num = avg_num / (double) size_of_list;
    
    
    return avg_num;
}

/*
 *  @목적 : 최저기온을 가진 날을 구합니다.
 *
 * */
int getLowDay() {
    double min = 300.0;
    int index = 0;
    
    for (int i = 0; i < size_of_list; i++) {
        if (min > input_tmp[i]) {
            min = input_tmp[i];
            index = i;
        }
    }
    return index + 1;
}

/*
 *  @ 목적 :  최고기온을 가진 날을 구합니다.
 *
 * */
int getHiDay() {
    double max = -300.0;
    int index = 0;
    
    for (int i = 0; i < size_of_list; i++) {
        if (max < input_tmp[i]) {
            max = input_tmp[i];
            index = i;
        }
    }
    return index + 1;
}

int getDay() {
    
    return 0;
}

/*
 * @ 목적 : 입력 월의 최대 일수를 구합니다.
 *
 * */
int getMonthDay(int month) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return 28;
        default:
            return 0;
    }
}
