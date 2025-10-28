#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//----------------------------------------------
// scanf 함수의 반환값 활용

    // 입력 문자의 아스키 코드 값을 출력
// int main(void){

//     int res;
//     char ch;

//     while(1){
//         res = scanf("%c", &ch);
//         if (res == -1) break;
//         printf("%d\n", ch);
//     }
//     return 0;

// }


//----------------------------------------------
// getchar 함수를 사용한 문자열 입력
// getchar() -> 버퍼에 남아 있는 것 중 맨 앞 첫 번째 문자를 가져온다.

// void my_gets(char *str, int size);


// int main(void){
//     char str[7];

//     my_gets(str, sizeof(str));
//     printf("입력한 문자열: %s\n", str);

//     return 0;
// }

// void my_gets(char *str, int size){
//     int ch, i = 0;

//     ch = getchar();
    
//     while ((ch !='\n') && (i < size-1)){
//         str[i] = ch;
//         i++;
//         ch = getchar();
//     }
//     str[i] = '\0';
// }


//--------------------------------------
// 입력 버퍼 지우기

// int main(void){
//     int num, grade;

//     printf("학번 입력: "); scanf("%d", &num);
//     getchar();                                  // 버퍼에 남아 있는 개행 문자('\n') 제거
//     //while(getchar() != '\n');
//     printf("학점 입력: ");
//     grade = getchar();
//     printf("학번: %d, 학점: %c\n", num, grade);

//     return 0;
// }




//========================================================
// CHAPTER 12. 문자열
//------------------------------------------------------
// 문자열 상수 구현 방법 
// 문자열 상수: 주소

// int main(void){
//     printf("apple이 저장된 시작 주소 값: %p\n", "apple");
//     printf("두번째 문자의 주소 값: %p\n", "apple"+1);
//     printf("첫 번째 문자: %c\n", *"apple"); // 문자열 상수의 첫번째 문자의 주소값의 값
//     printf("두 번째 문자: %c\n", *("apple"+1)); // 문자열 상수의 두번째 문자의 주소값의 값
//     printf("세 번째 문자(배열로 표현): %c\n", "apple"[2]);

//     return 0;
// }

//------------------------------------------------------
// char 포인터로 문자열 사용
// int main(void){

//     char *dessert = "apple"; // dessert는 해당 문자열의 주소를 저장한다

//     printf("오늘 후식은 %s입니다.\n", dessert); // 주소값으로 문자열을 출력
//     dessert = "banana"; // 주소에 문자열 상수를 대입
//     printf("내일 후식은 %s입니다.\n", dessert); // 해당 주소의 문자열을 출력

//     return 0;
// }

//------------------------------------------------------
// scanf 함수를 사용한 문자열 입력
// : scanf 함수는 자료형 단위로 가져온다.
// : 공백 무시 -> enter 치면 무시하고 첫번째 문자열이 나올 때까지 입력 가능 & 문자가 더 이상 안 나올 때까지 가져옴

// int main(void){
//     char str[80];

//     printf("문자열 입력: "); scanf("%s", str); // 'apple jam'
//     printf("첫 번째 단어: %s\n", str); 
//     scanf("%s", str);
//     printf("버퍼에 남아있는 두 번째 단어: %s\n", str);

//     return 0;
// }

//------------------------------------------------------
// gets() 함수를 사용한 문자열 입력
//: 공백까지 포함

// int main(void){
//     char str[80];

//     printf("공백이 포함된 문자열 입력: ");
    // gets(str);
//     //fgets(str, sizeof(str), stdin); // 배열: str, 크기: 배열의 크기, 키보드(stdin)로부터 읽음 
//     printf("입력한 문자열은 %s입니다.", str);

//     return 0;
// }

//------------------------------------------------------
// fgets() 함수를 사용한 문자열 입력
// fgets(str, sizeof(str), stdin); // 키보드로 입력 받은 값들을 str 배열에 저장한다

// int main(void){

//     char str[80];

//     printf("공백이 포함된 문자열 입력: "); // a | p | p | l | e |  | j | a | m | \n | \0 |
//     fgets(str, sizeof(str), stdin);
//     str[strlen(str)-1] = '\0';// \n을 제거하고 출력하고 싶다면, str[strlen(str)-1] = '\0'
//     printf("입력된 문자열은 %s입니다.\n", str);

//     return 0;
// }


//------------------------------------------------------
// 표준 입력 함수의 버퍼 공유 문제 - 개행 문자로 인해 gets 함수가 입력을 못하는 경우 (scanf와 gets를 혼용해서 쓸 때 주의)

// int main(void){
//     int age;
//     char name[20];

//     printf("나이 입력: "); scanf("%d", &age); // 17 --> 1 | 7 | \n

//     //gets(); // 버퍼 초기화
//     printf("이름 입력: "); gets(name); // 버퍼에 남아있던 \n -> \0으로 끝
    
//     printf("나이: %d, 이름: %s\n", age, name);

//     return 0;
// }

//------------------------------------------------------
// 문자열을 출력: puts(), fputs()

// int main(void){

//     char str[80] = "apple juice";

//     char *ps = "banana";

//     puts(str);
//     fputs(ps, stdout);
//     puts("milk");


//     return 0;
// }


// ----------->> 문자열 연산 함수 <<-------------------
//---------------------------------------------------
// strcpy(): 문자열 대입
// : sttcpy(복사 받을 곳, 복사할 내용)

// int main(void){
//     char str1[80] = "strawberry";
//     char str2[80] = "apple";
//     char *ps1 = "banana";
//     char *ps2 = str2;

//     printf("최초 문자열: %s\n", str1);
//     strcpy(str1, str2);
//     printf("바뀐 문자열: %s\n", str1);

//     strcpy(str1, ps1);
//     printf("바뀐 문자열: %s\n", str1);

//     strcpy(str1, ps2);
//     printf("바뀐 문자열: %s\n", str1);

//     strcpy(str1, "banana");
//     printf("바뀐 문자열: %s\n", str1);
    
//     return 0;
// }

//---------------------------------------------------
// strncpy(): 문자열 대입
// : strncpy(복사 받을 배열명, 복사할 문자열, 복사할 문자수)

// int main(void){
//     char str[20] = "mango tree";
//     //strncpy(str, "apple-pie", 5); // 'apple tree'
//     strncpy(str+6, "apple-pie", 5); // 'mango apple'
//     printf("%s\n", str);

//     return 0;
// }

//---------------------------------------------------
// strcat(), strncat(): 문자열 붙이기
// 최초 \0을 찾고 >> 해당 \0 자리부터 뒤에 붙인 후 >> \0을 붙인다.

// int main(void){
//     char str[80] = "straw";

//     strcat(str, "berry");
//     printf("%s\n",str);

//     strncat(str,"piece", 3);
//     printf("%s\n",str);

//     // 주의 사항: 배열의 크기 고려 -> 메모리 침범 가능성 -> 출력할 때 문제
//     // char str[10]; 인 경우
//     return 0;
// }


//---------------------------------------------------
// strlen(배열명): 문자열 길이 계산 c.f.) sizeof(배열명) -> 배열의 크기 계산

// int main(void){
//     char str1[80], str2[80];

//     char *resp;

//     printf("2개의 과일 이름 입력: "); scanf("%s%s", str1, str2);
//     if (strlen(str1)> strlen(str2)) resp = str1;
//     else resp = str2;

//     printf("이름이 긴 과일은 '%s'입니다.\n", resp);

//     return 0;
// }



//---------------------------------------------------
// strcmp(), strncmp(): 문자열 비교(순서)

// int main(void){
//     char str1[80] = "pear";
//     char str2[80] = "peach";

//     printf("사전 이름 순서에서 뒤에 있는 과일: "); 
//     //if (strcmp(str1, str2) > 0 )  // str1이 str2보다 뒤에 있으면 1, 앞에 있으면 -1, 같으면 0
//     if (strncmp(str1, str2, 3) > 0) // 3자리 까지 비교하자 -> 0
//         printf("%s\n", str1); 
//     else printf("%s\n", str2);

//     return 0;
// }


//========================================================
// CHAPTER 13 변수의 영역 & 데이터 공유
//-------------->> 변수의 영역 <<--------------------------
//-----------------------------------------------------
// 지역 변수
    // - 선언된 함수(블록) 내에서만 사용 => 디버깅에 유리
    // - 선언된 블록이 끝나면 메모리에서 사라진다 => 메모리 효율적 사용
// void assign(void);

// int main(void){
//     auto int a = 0;

//     assign();

//     printf("main 함수 a: %d\n", a);

//     return 0;
// }


// void assign(void){
//     int a;

//     a = 10;
//     printf("assign 함수 a: %d\n", a);
// }                                       // main의 a와 assign의 a는 다른 변수이다.
                                           // 연동하려면 포인터로 해야 된다.

//-----------------------------------------------------
// 블록 안에서 사용하는 지역 변수

// int main(void){
//     int a = 10, b = 20;

//     printf("[변경 전] a: %d, b: %d\n", a, b);
    
//     {
//         int temp;

//         temp = a; a = b; b = temp;
//     } 

//     printf("[변경 후] a: %d, b: %d\n", a, b);

//     return 0;
// }

    // 함수 내부 {}
        // [DEFAULT] auto -> 지역변수 (호출 시 매번 초기화) 
        // static         -> 지역변수 (함수 종료 시에도 기억) 
    // 함수 외부 
        // [DEFAULT] global
        // static
    // extern


//-----------------------------------------------------
// 전역 변수
    // - 변수명이 변경되면 사용한 함수의 모든 이름을 찾아 변경해야 됨
    // - 값에 오류가 있다 -> 접근 가능한 모든 함수를 탐색해야 됨.
    // - 같은 이름의 지역변수에 의해 제한 될 수 있음.
    // >> 포인터로 참조가 유리

// void assign10(void);
// void assign20(void);

// int a; // a는 전역변수

// int main(void){
//     printf("함수 호출 전 a: %d\n", a);

//     assign10();
//     assign20();

//     printf("함수 호출 후 a: %d\n",a);

//     return 0;
// }


// void assign10(void){
//     a = 10;
// }

// void assign20(void){
//     int a; // 이 때 a는 지역 변수 -> return (x)
//     a = 20;
// }


//-----------------------------------------------------
// 정적 지역 변수 Static local variable

// void auto_func(void);
// void static_func(void);

// int main(void){

//     printf("일반 지역 변수(auto)를 사용한 함수...\n");
//     for (int i = 0; i < 3; i++) auto_func();

//     printf("정적 지역 변수(static)를 사용한 함수...\n");
//     for (int i = 0; i < 3; i++) static_func();

//     return 0;
// }


// void auto_func(void){
//     auto int a = 0; // 호출 시마다 초기화
//     a ++;
//     printf("%d\n", a);
// }

// void static_func(void){
//     static int a; // 메모리에 남아 있음
//     a ++;
//     printf("%d\n", a);
// }


//-----------------------------------------------------
// 레지스터 변수
// : 연산속도 개선

// int main(void){
//     register int i;
//     auto int total = 0;
    
//     clock_t start, end;
//     start = clock();

//     for (i; i <=1000000 ; i ++) total += i;

//     end = clock();
//     double process_duration = (double)(end - start) / CLOCKS_PER_SEC;


//     printf("%d\n", total);
//     printf("연산 속도: %lf", process_duration);

//     return 0;
// }


// RAM 구조
// : stack영역 (지역변수, 매개변수) + heap영역 (동적 메모리)  + data (전역변수, static 변수)
//      heap 영역: 개발자가 관리
//      stack 영역 & data 영역: 시스템이 관리

//      data 영역: 프로그램 시작 ~ 종료


//-------------->> 데이터 공유 <<--------------------------
//-----------------------------------------------------
// 값을 복사해서 전달

// void add_ten(int a);


// int main(void){
//     int a = 10;

//     add_ten(a);

//     printf("a: %d\n", a);

//     return 0;
// }

// void add_ten(int a){
//     a += 10;
// } 
// main의 a는 변화 x


//-----------------------------------------------------
// 주소를 복사해서 전달

// void add_ten(int *pa);


// int main(void){
//     int a = 10;

//     add_ten(&a);

//     printf("a: %d\n", a);
    
//     return 0;
// }

// void add_ten(int *pa){
//     *pa += 10;
// }

//-----------------------------------------------------
// 주소를 반환하는 함수

// int *total(int a, int b);

// int main(void){
//     int *resp;

//     resp = total(10, 20);

//     printf("두 정수의 합: %d\n", *resp);

//     return 0;
// }

// int *total(int a, int b){
//     static int res;
//     res = a + b;

//     return &res;
// }
// 주소 반환하는 경우: 함수가 반호나된 후에도 저장 공간이 유지되는 경우만 (정적 지역 변수, 전역 변수)



//========================================================
// CHAPTER 14 다차원 배열 & 포인터 배열

//----------->> 다차원 배열 <<------------------------
//---------------------------------------------------
// 2차원 배열 선언 & 요소 사용

// int main(void){
//     int score[3][4];
//     int total;
//     double avg;

//     for (int i = 0; i < 3; i ++){
//         printf("4과목의 점수 입력: ");
//         for (int j = 0; j < 4; j++) scanf("%d", &score[i][j]);
//     }

//     for (int i = 0; i< 3; i++){
//         total = 0;
//         for(int j = 0; j <4; j++) total += score[i][j];
//         avg = total / 4.0;
//         printf("총점: %d, 평균: %.2lf\n", total, avg);
//     }


//     return 0;

// }


//---------------------------------------------------
// 2차원 배열 초기화

// int main(void){
//     int num[3][4] = {
//         {1,2,3,4},
//         {5,6,7,8},
//         {9,10,11,12}
//     };
// }


// int num[3][4] = {{1},{5,6},{9,10,11}};


//---------------------------------------------------
// 2차원 char 배열 초기화


//---------------------------------------------------
// 3차원 배열

// int main(void){
//     int score[2][3][4] = {
//         {{72,80,95,60}, {68,98,83,90}, {75,72,84,90}},
//         {{66,85,90,88}, {95,92,88,95}, {43,72,56,75}}
//     };

//     printf("\n");
//     for (int i = 0; i < 2; i++){
//         printf("%d반 점수\n", i+1);
//         for (int j = 0; j < 3; j++){
//             for (int k = 0; k < 4; k++){
//                 printf("%5d", score[i][j][k]);
//             }
//             printf("\n");
//         }
//         printf("\n");
//     }
//     return 0;
// }

//----------->> 포인터 배열 <<------------------------
//---------------------------------------------------
// 포인터 배열 선언
// : 배열 안에 (문자열의) 주소를 저장
// : 초기화는 문자열의 시작 주소만 배열 요소에 저장 c.f) 2차원 char 배열의 초기화: 문자열 자체를 배열의 공간에 저장

// int main(void){
//     char *parr[6]; // char: 배열 요소의 자료형, parr: 배열명, 6: 배열 요소의 개수

//     parr[0] = "dog"; // d o g \0 의 주소값이 배열의 요소로 저장된다.
//     parr[1] = "elephant";
//     parr[2] = "lion";
//     parr[3] = "cat";
//     parr[4] = "leopard";
//     parr[5] = "whale";

//     for (int i = 0; i < 6; i ++) printf("%s\n", parr[i]);
    
//     return 0;
// }


// 'char 포인터 배열'의 초기화 (40 byte): char *parr[5] = {"dog", "elephant", "horse", "tiger", "lion"};
// '2차원 char 배열'의 초기화 (100 byte): char animal[5][20] = {"dog", "elephant", "horse", "tiger", "lion"};

//---------------------------------------------------
// 2차원 배열처럼 활용하는 포인터 배열

// int main(void){
//     int arr1[4] = {1,2,3,4};
//     int arr2[4] = {11,12,13,14};
//     int arr3[4] = {21,22,23,24};

//     int *parr[3] = {arr1, arr2, arr3}; // 배열명 =  주소 ~= arr1 = &arr1[0]

//     for (int i = 0; i < 3; i ++){
//         for (int j = 0; j < 4; j ++){
//             printf("%5d", parr[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }


//---------------------------------------------------
// 포인터 배열 <=> 2차원 배열
// : parr[i][j] = *(parr[i]+j)

//---------------------------------------------------
// 연습 문제

// int main(void){
//     int row_arr[4], col_arr[5], arr[5][6];

//     for (int i = 0; i < 4; i++){
//         for (int j = 0; j <5; j++){
//             arr[i][j] = 5 * i + j+1;
//             row_arr[i] += arr[i][j];
//             col_arr[j] += arr[i][j];
//         }
//     }
//     for (int i = 0; i < 4; i++){
//         for (int j = 0; j <5; j ++){
//             printf("%5d", arr[i][j]);
//         }
//         printf("%5d\n", row_arr[i]);
//     printf("%5d", col_arr);
//     }

//     return 0;

// }

void fill_col(int )
void fill_row()

int main(void){
    int arr[5][6], num = 0, *row_sum[4], *col_sum[5];
    
    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 5; j++){
            num += 1;
            arr[i][j] = num;
        }
    }

    return 0;
}








