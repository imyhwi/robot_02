#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



//========================================================
// CHAPTER 15 응용 포인터

//----------->> 이중 포인터 & 배열 포인터 <<------------------------
//---------------------------------------------------
// 이중 포인터

// int main(void){
//     int a = 10;
//     int *pi;
//     int **ppi;

//     pi = &a;
//     ppi = &pi;

//     printf("---------------------------------------\n");
//     printf("변수   변숫값    & 연산    * 연산    **연산\n");
//     printf("  a%10d%10u\n",a &a);
//     printf(" pi%10u%10u%10d\n", pi, &pi, *pi);
//     printf("ppi%10u%10u%10u%10u\n", ppi, &ppi,*ppi, **ppi);
//     printf("---------------------------------------\n");


//     return 0;
// }


//---------------------------------------------------
// 이중 포인터 활용 - 포인터 값을 바꾸는 함수의 매개변수

// void swap_ptr(char **ppa, char **ppb);

// int main(void){
//     char *pa = "success";
//     char *pb = "failure";

//     printf("pa -> %s, pb -> %s\n", pa, pb);
//     swap_ptr(&pa, &pb);                      // 포인터 변수(문자열)의 주소: 이중 포인터
//     printf("pa -> %s, pb -> %s\n", pa, pb);

//     return 0;
// }


// void swap_ptr(char **ppa, char **ppb){
//     char *pt;

//     pt = *ppa;
//     *ppa = *ppb;
//     *ppb = pt;

// }

//---------------------------------------------------
// 이중 포인터 활용 - 포인터 배열을 매개변수로 받는 함수

// void print_str(char **pps, int cnt);

// int main(void){
//     char *ptr_arr[] = {"eagle", "tiger","lion","squirrel"};
    
//     int count;
//     count = sizeof(ptr_arr) / sizeof(ptr_arr[0]);

//     print_str(ptr_arr, count); // 포인터 배열의 배열명 -> 배열의 포인터의 주소 (이중 포인터)

//     return 0;
// }


// void print_str(char **pps, int cnt){

//     for (int i = 0; i < cnt ; i ++){
//         printf("%s\n", pps[i]);
//     }

// }



//---------------------------------------------------
// 배열 요소의 주소 & 배열의 주소

// int main(void){
//     int arr[5];

//     printf("  arr의 값: %u\t", arr);
//     printf("arr의 주소: %u\n", &arr);
//     printf("  arr + 1: %u\t", arr + 1);
//     printf(" &arr + 1: %u\n", &arr + 1);

//     return 0;
// }
// arr과 arr+1의 차이: 요소 크기 차이 (4) (arr = &arr[0], arr + 1 = &arr[1])
// &arr과 &arr+1의 차이: 배열 크기 차이 (8 * 5)
// %u: 10진수 주소, %p: 16진수 주소


//---------------------------------------------------
// 2차원 배열 & 배열 포인터

// 1. 포인터 배열 Array of Pointers; '서랍장' -> 여러 개의 '서랍'[] -> '주소 쪽지' *
        // int *arr[10];
            // arr: 10칸 짜리 배열
            // int *: 각 칸(arr[0], arr[1]... arr[10])의 자료형 (int를 가리키는 포인터)
// 2. 배열 포인터 Pointer to an Array; '봉투' -> 하나의 '주소 쪽지' * -> '아파트 건물 전체' []
    //: 요소(행) 하나를 가리키는 포인터
        // int (*parr)[10];
            // parr: 단 하나의 포인터 변수
            // [10]: 10개의 int로 이루어진 배열 하나의 시작 주소를 저장
// int main(void){
//     int arr[3][4] = {{1,2,3,4}, {5,6,7,8},{9,10,11,12}};
//     int (*pa)[4]; // 배열 포인터

//     pa = arr;
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 4; j++){
//             printf("%5d", pa[i][j]);
//         }
//         printf("\n");
//     }


//     return 0;
// }



//---------------------------------------------------
// 2차원 배열의 요소를 참조하는 원리
// 행 1개 단위
    // int arr[3][4];
    // arr + 1 = 다음 행 주소값
    // *(arr + 1) = arr[1]
    // *(arr + 1) + 2 = *(arr + 1) + 2 * sizeof(arr[1][0])
    // *(*(arr + 1) + 2) = arr[1][2]

    // 2차원 배열명 + 1 => 2번재 행의 주소 값
    // 2차원 배열의 포인터 + n = 인덱스 n 열의 주소값



//--------------------------------------------------
// 함수가 주소를 반환

// int *func(int a, int *x);

// int main(void){
//     int x = 10;
//     int *p;
//     int a[100];

//     for (int i = 0; i < 100; i++){
//         a[i] = i * 10;              // {0,10, 20,.....,990}
//     }

//     p = func(x,a);
//     printf("sum = %d\n", x + a[0] + a[1] + p[0] + p[1]); // 10 + 0 + 20 + 20 + 20 

//     return 0;
// }


// int *func(int a, int *x){           // a = 10, x = &a[0]
//     a += 10;                        // a = 20 (임시) 
//     x += 1;                         // &a[1] (1차원 배열)
//     *x *= 2;                        // a[1] *= 2 => a[1] = 20 => a = {0, 20, 20, 30, 40,... ,990}

//     return x;                       // &a[1]
// }



//----------->> 함수 포인터 & void 포인터 <<------------------------
//---------------------------------------------------------------
// 함수 포인터

// int total(int, int);

// int main(void){
//     int (*fp)(int, int);
//     int res;

//     fp  = total;                    // fp: 함수(total)의 주소를 담은 포인터 변수
//     res = fp(10,20);                // = (*fp)(10,20) 
//     printf("result: %d\n", res);

//     return 0;
// }

// int total(int a, int b) {return (a + b);}

//---------------------------------------------------------------
// 함수 포인터 활용
// 선언: 함수명(출력 자료형 (*fp)(파라미터 1 자료형, 파라미터 2 자료형...) );
// 사용: 함수명(참조할 함수명);
// void func(int (*fp)(int, int));
// int sum(int a, int b);
// int mul(int a, int b);
// int max(int a, int b);

// int main(void){
//     int sel;

//     printf("01. 두 정수의 합\n");
//     printf("02. 두 정수의 곱\n");
//     printf("03. 두 정수 중 큰 값\n");
//     printf("원하는 연산을 선택하세요: "); scanf("%d", &sel);

//     switch(sel){
//         case 1: func(sum); break;
//         case 2: func(mul); break;
//         case 3: func(max); break;
//     }

//     return 0;
// }

// void func(int (*fp)(int, int)){
//     int a, b;
//     int res;

//     printf("두 정수를 입력하세요: "); scanf("%d%d", &a, &b);
//     res = fp(a,b);
//     printf("결과: %d\n", res);
// }

// int sum(int a, int b) {return (a + b);}
// int mul(int a, int b) {return (a * b);}
// int max(int a, int b){
//     if (a > b) return a;
//     else return b;
// }


//---------------------------------------------------------------
// void 포인터
// : '주소 보관함'
// : (int *), (double *) 등 casting 필요

// int main(void){
//     int a = 10;
//     double b = 3.5;
//     void *vp;

//     vp = &a;
//     printf("a: %d\n", *(int *)vp); // (int *): 명시적 형변환 (int 포인터 타입으로 취급한다, casting)

//     return 0;
// }



//========================================================
// CHAPTER 16 메모리 동적 할당

//----------->> 동적 할당 함수 <<----------------------
//---------------------------------------------------
// malloc(), free()
// malloc: memory allocation 메모리 할당
// free: {} 블록 해제와 비슷한 개념

// int main(void){
//     int *pi;
//     double *pd;

//     pi = (int *)malloc(sizeof(int)); 
//     // sizeof(int) : int형 변수의 크기로 
//     // >> malloc() : 저장공간을 할당하고 (void *)형을 반환하고 
//     // >> (int *)  : 반환되는 주소를 int형 변수의 주소로 형 변환하고
//     // >> pi =     : int형을 가리키는 포인터에 저장
    
//     if (pi == NULL){
//         printf("# 메모리가 부족합니다.\n");
//         exit(1); // 프로그램 종료 함수
//     }

//     pd = (double *)malloc(sizeof(double));

//     *pi = 10; // 포인터로 동적 할당 영역(heap) 사용
//     *pd = 3.4;

//     printf("정수형으로 사용: %d\n", *pi);
//     printf("실수형으로 사용: %.1lf\n", *pd);

//     free(pi);
//     free(pd);

//     return 0;
// }



//---------------------------------------------------
// 동적 할당 영역을 배열처럼 활용

// int main(void){
//     int *pi;
//     int sum = 0;

//     pi = (int *)malloc(5 * sizeof(int)); // 20 바이트 저장공간 할당
//     if (pi == NULL){
//         prinf("# 메모리가 부족합니다.\n");
//         exit(1);
//     }

//     printf("다섯 명의 나이를 입력하시오: ");
//     for (int i = 0; i < 5; i++){
//         scanf("%d", &pi[i]);           
//         // pi[i] = *(pi + i) 
//             // pi + i   : pi의 시작 주소에서 i칸 만큼 (자료형 크기에 따라) 건너뛴 주소
//             // *(...)   : 그 주소의 자료형 값을 가져온다
//         // &pi[i]       : i번째 값의 주소
//         // int *변수명   : *p를 실행하면 int 타입의 값이 나온다
//             // 변수명    : int가 저장된 주소를 담는다.
//         // int 자료형 vs. int * 자료형: 집 vs. 주소 쪽지
//         sum += pi[i];
//     }

//     printf("다섯 명의 평균 나이: %.1lf\n", (sum / 5.0));
//     free(pi);

//     return 0;
// }


//========================================================
// CHAPTER 17 사용자 정의 자료형
//----------->> 구조체 <<----------------------
//-------------------------------------------
// 구조체 선언과 멤버 사용

// struct student          // 예약어: 'struct', 구조체 이름: 'student'
// {
//     int num;
//     double grade;
// };

// int main(void){
//     struct student s1;  // 구조체 변수명: s1

//     s1.num = 2;
//     s1.grade = 2.7;
//     printf("학번: %d\n", s1.num);
//     printf("학점: %.1lf\n", s1.grade);

//     return 0;
// }


//-------------------------------------------
// 구조체 변수의 크기 - 패딩 바이트
// => 구조체 멤버 선언 시, 크기가 큰 순서대로 정렬


//-------------------------------------------
// 구조체 멤버 (배열, 포인터)

// struct profile
// {
//     char name[20];
//     int age;
//     double height;
//     char *intro;
// };

// int main(void){
//     struct profile myungsu;
//     strcpy(myungsu.name, "박명수");
//     myungsu.age = 50;
//     myungsu.height = 168.4;

//     myungsu.intro = (char *)malloc(80);
//     printf("자기소개: "); gets(myungsu.intro); // intro가 해당 문자열의 주소를 담고 있다
//     // 80 byte 이내에... [한글] 2byte, [영어] 1byte

//     printf("이름: %s\n", myungsu.name);
//     printf("나이: %d\n", myungsu.age);
//     printf("키: %.1lf\n", myungsu.height);
//     printf("자기소개: %s\n", myungsu.intro);

//     free(myungsu.intro);

//     return 0;
// }

//-------------------------------------------
// 구조체의 멤버로 다른 구조체 사용

// struct profile
// {
//     int age;
//     double height;
// };

// struct student
// {
//     struct profile pf;
//     int id;
//     double grade;
// };

// int main(void){
//     struct student hongchul;
//     hongchul.pf.age = 40; 
//     hongchul.pf.height = 175.6;
//     hongchul.id = 315;
//     hongchul.grade = 2.7;

//     printf("나이: %d\n",hongchul.pf.age);
//     printf("키: %.1lf\n",hongchul.pf.height);
//     printf("학번: %d\n",hongchul.id);
//     printf("학점: %.1lf\n",hongchul.grade);

//     return 0;
// }




//-------------------------------------------
// 구조체 변수 초기화 & 대입 연산

// struct student
// {
//     int id;
//     char name[20];
//     double grade;
// };

// int main(void){
//     struct student s1 = {315, "강호동", 4.3}, s2 = {316, "이승기", 3.3}, s3 = {317, "은지원", 4.1};
    
//     struct student max;
//     max = s1; // 복사
//     if (s2.grade > max.grade) max = s2;
//     if (s3.grade > max.grade) max = s3;

//     printf("학번: %d\n",max.id);
//     printf("이름: %s\n",max.name);
//     printf("학점: %.1lf\n",max.grade);

//     return 0;
// }

//-------------------------------------------
// 구조체 변수를 -> 함수의 매개변수에 사용

// struct vision
// {
//     double left;
//     double right;
// };

// struct vision exchange (struct vision robot); // struct vision으로 반환한다

// int main(void){
//     struct vision robot;
//     printf("시력 입력: "); scanf("%lf%lf", &(robot.left), &(robot.right));
//     robot = exchange(robot);
//     printf("바뀐 시력: %.1lf  %.1lf\n", robot.left, robot.right);

//     return 0;
// }

// struct vision exchange(struct vision robot){
//     double temp;

//     temp = robot.left;
//     robot.left = robot.right;
//     robot.right = temp;

//     return robot;
// }


//-------------------------------------------
// 구조체 포인터와 -> 연산자

// struct score
// {
//     int kr;
//     int eng;
//     int math;
// };

// int main(void){
//     struct score you = {90, 80, 70};
//     struct score *ps = &you;            // 구조체 포인터: struct 구조체명 *구조체 포인터명 = 주소

//     printf("국어: %d\n", (*ps).kr);     // 구조체.멤버명
//     printf("영어: %d\n", ps -> eng);    // 구조체 주소 -> 멤버명
//     printf("수학: %d\n", ps -> math);

//     return 0;
// }


//-------------------------------------------
// 구조체 배열

// struct address
// {
//     char name[20];
//     int age;
//     char tel[20];
//     char addr[80];
// };


// int main(void){
//     struct address list[5]={
//         {"관우", 23, "123-456", "서울 마포구"},
//         {"장비", 21, "123-457", "서울 동대문구"},
//         {"유비", 26, "123-458", "서울 용산구"},
//         {"조조", 33, "123-459", "서울 성동구"},
//         {"제갈량", 42, "123-450", "서울 종로구"},
//     };

//     for (int i = 0; i < 5; i++){
//         printf("%10s%5d%15s%20s\n",
//         list[i].name, list[i].age, list[i].tel, list[i].addr);
//     }

//     return 0;
// }



//-------------------------------------------
// 구조체 배열을 처리하는 함수

// struct book
// {
//     char name[20];
//     int age;
//     char tel[20];
//     char address[80];
// };

// void print_list(struct book *lp);

// int main(void){
//     struct book list[5] = {
//         {"손흥민", 33, "111-1111", "서울시 성동구"},
//         {"박지성", 42, "222-2222", "서울시 강남구"},
//         {"스태판 커리", 40, "333-3333", "로스앤젤레스"},
//         {"르브론 제임스", 42, "444-4444", "로스엔젤레스"},
//         {"오타니 쇼헤이", 34, "555-5555", "샌프란시스코"},
//     };
//     print_list(list); // list: 구조체 배열의 주소

//     return 0;
// }

// void print_list(struct book *lp){ 

//     //lp = lp + 2; // list[2]부터 시작
//     //for (int i = 0; i < 3; i++){

//     for (int i = 0; i < 5; i++){
//         printf("%15s%5d%15s%20s\n",
//         (lp+i) -> name, 
//         (lp+i) -> age,
//         (lp+i) -> tel,
//         (lp+i)-> address);
//     }
// }


//-------------------------------------------
// 자기 참조 구조체

struct list
{
    int num;
    struct list *next;          // 자기 참조 구조체
};

int main(void){
    struct list a = {10, 0}, b = {20,0}, c = {30,0};

    struct list *head = &a, *current;

    a.next = &b;
    b.next = &c;

    printf("head -> num: %d\n", head->num);
    printf("head -> next -> num: %d\n", head->next->num);

    printf("list all: ");
    current = head;
    while (current != NULL){
        printf("%d  ", current->num);
        current = current->next;
    }
    printf("\n");
    
    return 0;
}



