#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getMonthDay(int month);

int getDay(int day, int aLong);

int getHiDay(int days, int num);

int getLowDay(int days, int num);

double getAve(int days, int num);

void display();

int main() {
    int input_month = 0;
    int start_day = 0;
    int how_long = 0;
    
    double input_tmp[32];
    
    printf("월을 입력하세요 : ");
    scanf_s("%d", &input_month);
    printf("%d\n", input_month);

// 1.2 달에 대한 최대 일자(dayNum) 계산한다(getMonthDay).
    int dayNum = getMonthDay(input_month);
    
    printf("온도를 입력하시오 (1 ~ 31일) : ");
    for (int i = 0; i < dayNum; i++) {
        scanf_s("%lf", &input_tmp[i]);
    }
    printf("%lf", input_tmp[2]);
    
    printf("그래프 출력을 원하는 기간 (시작일 , 기간) : ");
    scanf_s("%d %d", &start_day, &how_long);
    
    int days = getDay(start_day, how_long);
//2.1 월 최고 기온(hiDay)을 기록한 날짜를 계산한다(getHiDay).
    
    int hi_day = getHiDay(days, dayNum);
    
    int low_day = getLowDay(days, dayNum);
    
    double avg_value = getAve(days, dayNum);
    
    display();
    
    return 0;
}

void display() {

}
/*
 *  @ 목적 : 평균 구하기
 *   @ 매개변수 : int days  int  num : 해당 월의 총 날짜수
 *
 * */
double getAve(int days, int num) {
    
    return 0;
}
/*
 *  @목적 : 최저기온을 구합니다
 *
 * */
int getLowDay(int days, int num) {
    
    return 0;
}
/*
 *  @ 목적 : 최고기온을 구합니다
 *
 * */
int getHiDay(int days, int num) {
    
    return 0;
}

int getDay(int day, int aLong) {
    
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
            return 0 ;
    }
}
