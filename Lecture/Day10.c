#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



//---------------------------------------------------
// 공용체
// : 구조체와 달리 메모리 공유가 된다, 같은 메모리 주소 공유 (덮어쓰기, Overlap) = '하나의 방'
// : 오직 하나의 멤버만 유효하게 저장
// : 메모리 부족에 적합
// c.f.) 구조체: stack

// union student
// {
//     int num;
//     double grade;
// };


// int main(void){
//     union student s1 = {315};

//     printf("학번: %d\n", s1.num);
//     s1.grade = 4.4;
//     printf("학점:%.1lf\n", s1.grade);
//     printf("학번: %d\n", s1.num);


//     return 0;
// }


//---------------------------------------------------
// 열거형

// enum season {SPRING, SUMMER, FALL, WINTER};

// int main(void){
//     enum season ss;
//     char *pc = NULL;

//     ss = SPRING;

//     switch(ss)
//     {
//         case SPRING:
//         pc = "inline"; break;

//         case SUMMER:
//         pc = "swimming"; break;

//         case FALL:
//         pc = "trip"; break;

//         case WINTER:
//         pc = "skiing"; break;
//     }

//     printf("나의 레저 활동 => %s\n", pc);

//     return 0;
// }


//---------------------------------------------------
// typedef: 형 재정의


// struct student
// {
//     int num;
//     double grade;
// };

// typedef struct student Student;
// //typedef struct
// //{
// //    int num;
// //    double grade;
// //} Student;



// void print_data(Student *ps);

// int main(void){
//     Student s1 = {315, 4.2};

//     print_data(&s1);

//     return 0;
// }

// void print_data(Student *ps){
//     printf("학번: %d\n", ps -> num);
//     printf("학점: %.1lf\n", ps -> grade);
// }

//-----------------
// 예시 생성

// typedef struct account
// {
//     char id[10];
//     int amount;
//     int balance;
//     char date[11];

// } Account;

// void print_data(Account *ps);

// int main(void){
//     Account custom_1 = {"A-001", 20000, 1000000 - custom_1.amount, "2025-10-29"};

//     print_data(&custom_1);

//     return 0;
// }

// void print_data(Account *ps){
//     printf("계좌 번호: %s\n", ps -> id);
//     printf("거래 내역: %d\n", ps -> amount);
//     printf("잔액: %d\n", ps -> balance);
//     printf("거래일: %s\n", ps -> date);
// }



//-----------------
// 예제
// 학생 5명의 국어, 영어, 수학 점수 입력 -> 총점, 평균, 학점 -> 총점 순으로 정렬하여 출력
// 학점은 평균이 90점 이상이면 A, 80점 이상이면 B, 70점 이상이면 C, 그 외에는 F

// {315, 홍길동, 88,75,90} {316, 이순신, 88,92,100} {317, 서하윤, 95,99,98} {318, 유관순,84,70,72} {319, 박신혜, 60,65,40}
// >> 317, 316, 315,318, 319

// typedef struct score
// {
//     int total;
//     double avg;
//     char grade;
// } Score;

// typedef struct student
// {
//     int id;
//     char name[10];
//     int kr;
//     int eng;
//     int math;
//     Score cal;
//     int ranking;

// } Student;

// char grader(double avg);                    // 평균 점수 -> 학점
// void rank(Student info[], int num);         // 등수 설정
// void sort_asc(Student info[], int num);     // 등수로 정렬

// int main(void){

//     int num;
//     printf("학생 수: "); scanf("%d", &num);
//     Student info[num];                      // 구조체 객체를 담아두는 리스트

//     for (int i = 0; i < num; i++){
//         printf("====== %d번째 학생 정보 ======\n", i+1);
//         printf("학번: "); scanf("%d", &info[i].id);
//         printf("이름: "); scanf("%s", &(*info[i].name)); 
//         //printf("이름: "); scanf("%s", info[i].name);  // 배열명: 그 배열의 첫 번째 요소의 주소로 자동 변환
//         printf("국어 점수: "); scanf("%d", &info[i].kr);
//         printf("영어 점수: "); scanf("%d", &info[i].eng);
//         printf("수학 점수: "); scanf("%d", &info[i].math);
//         info[i].cal.total = info[i].kr + info[i].eng + info[i].math;
//         info[i].cal.avg = (double)info[i].cal.total / 3.0;
//         info[i].cal.grade = grader(info[i].cal.avg);
//         info[i].ranking = 1;
//     }

//     printf("\n# 정렬 전 데이터...\n");
//     printf("%5s\t%5s\t%5s\t%5s\t%5s\t%5s\t%5s\t%5s\n",
//         "학번", "이름", "국어", "영어", "수학", "총점","평균", "학점");
//     for (int i = 0; i < num; i++){
//         printf("%5d\t%5s\t%5d\t%5d\t%5d\t%5d\t%.1lf\t%5c\n", 
//             info[i].id, info[i].name, info[i].kr, info[i].eng, info[i].math, 
//             info[i].cal.total, info[i].cal.avg, info[i].cal.grade);
//     }


//     rank(info, num);
//     sort_asc(info, num);

//     printf("\n# 정렬 후 데이터...\n");
//     printf("%5s\t%5s\t%5s\t%5s\t%5s\t%5s\t%5s\t%5s\n",
//         "학번", "이름", "국어", "영어", "수학", "총점","평균", "학점");
//     for (int i = 0; i < num; i++){
//         printf("%5d\t%5s\t%5d\t%5d\t%5d\t%5d\t%.1lf\t%5c\n", 
//             info[i].id, info[i].name, info[i].kr, info[i].eng, info[i].math, 
//             info[i].cal.total, info[i].cal.avg, info[i].cal.grade);
//     }
//     return 0;
// }

// char grader(double avg){
//     char grade;

//     if (avg >= 90) grade = 'A';
//     else if (avg >= 80) grade = 'B';
//     else if (avg >= 70) grade = 'C';
//     else grade = 'F';

//     return grade;
// }

// void rank(Student info[], int num){
//     for (int i = 0; i < num-1; i++){
//         for (int j = i+1; j < num; j ++){
//             if (info[i].cal.total < info[j].cal.total) info[i].ranking += 1;
//             else if (info[i].cal.total > info[j].cal.total) info[j].ranking += 1;
//         }
//     }
// }

// void sort_asc(Student info[], int num){
//     for (int i = 0; i < num-1; i++){
//         for (int j = i+1; j < num; j ++){
//             if (info[i].ranking > info[j].ranking) {
//                 Student temp;
//                 temp = info[i];
//                 info[i] = info[j];
//                 info[j] = temp;
//             }
//         }
//     }
// }





//==================================================================================
// CHAPTER 18. 파일 입출력

// 입출력 장치
    // 입력 장치: 키보드, 마우스
    // 출력 장치: 모니터
// 스트림: 입출력 장치 & 컴퓨터 연결

//----------->> 파일 개방 & 입출력 <<-----------
//--------------------------------------------
// 파일 개방 & 폐쇄
// 파일을 연다: 컴퓨터와 파일을 연결한다.
    // 선언: FILE *fp;
    // 개방: fp = fopen("파일명","개방 모드");

// int main(void){
//     FILE *fp;

//     fp = fopen("a.txt", "r");
//     if (fp == NULL){
//         printf("파일이 열리지 않았습니다.\n");
//         return 1;
//     }
//     printf("파일이 열렸습니다.\n");
//     fclose(fp);

//     return 0;
// }

//--------------------------------------------
// fgetc(): 문자 입력 함수 c.f.) fgets()
// <-> fputc()

// int main(void){
//     FILE *fp;
//     int ch;

//     fp = fopen("a.txt", "r");
//     if (fp == NULL){
//         printf("파일이 열리지 않았습니다.\n");
//         return 1;
//     }

//     while(1){
//         ch = fgetc(fp);             // 문자열 하나씩만 받음
//         if (ch == EOF) break;
//         putchar(ch);
//     }
//     printf("\n");
//     fclose(fp);

//     return 0;
// }



//--------------------------------------------
// fputc(): 문자 출력 함수

// int main(void){
//     FILE *fp;
//     char str[] = "kiwi";

//     //fp = fopen("b.txt", "w"); // 덮어쓰기
//     fp = fopen("b.txt", "a"); // 이어쓰기
//     if (fp == NULL){
//         printf("파일을 생성할 수 없습니다.\n");
//         return 1;
//     }

//     int i = 0;
//     while(str[i] != '\0'){
//         fputc(str[i], fp);
//         i ++;
//     }
//     fputc('\n', fp);
//     fclose(fp);

//     return 0;
// }


//--------------------------------------------
// 입출력 스트림 파일 (기본)

// int main(void){
//     int ch;

//     while(1){
//         ch  = getchar();
//         if (ch == EOF) break;
//         putchar(ch);
//     }


//     return 0;
// }


//--------------------------------------------
// stdin/stdout을 이용한 문자 입출력

// int main(void){
//     int ch;

//     while(1){
//         ch = fgetc(stdin);
//         if (ch == EOF) break;
//         fputc(ch, stdout);
//     }
//     return 0;
// }



//--------------------------------------------
// 실습
#include <regex.h>


// Command:          logd
// Path:             /usr/libexec/logd   
// Resource Coalition: "com.apple.logd"(7)
// On Behalf Of:     5 samples deleted [1392] (5 samples originated by UNKNOWN [32]), 5 samples UNKNOWN [1540] (5 samples originated by UNKNOWN [85])
// Architecture:     arm64e
// Parent:           launchd [1]        
// PID:              33                 // 프로세스 ID

// Event:            disk writes
// Action taken:     none
// Writes:           1073.78 MB of file backed memory dirtied over 26727 seconds (40.18 KB per second average), exceeding limit of 12.43 KB per second over 86400 seconds
// Writes limit:     1073.74 MB
// Limit duration:   86400s
// Writes caused:    1073.78 MB
// Writes duration:  26727s
// Duration:         26726.67s
// Duration Sampled: 26593.73s (event starts 7.28s before samples, event ends 125.66s after samples)
// Steps:            1295 (10 gigacycles/step, 3 samples lost, 10.49 MB/step)



int main(void){
    FILE *fp;

    fp = fopen("fast.log.txt", "r");
    if (fp == NULL){
        printf("파일을 찾을 수 없습니다.\n");
        return 1;
    }

    while(1)


}
