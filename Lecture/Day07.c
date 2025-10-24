#include <stdio.h>
#include <math.h>
#include <stdlib.h>



// 포인터의 제약조건 - 허용되지 않는 포인터의 대입

// int main(void){
//     int a = 10;
//     int *p = &a;
//     double *pd; // 자료형 일치하지 않음

//     //pd = p;

//     //int *pd;
//     //printf("%d\n", *pd);
//     //printf("%lf\n", (double) *pd);
//     printf("%lf\n", (int*) pd);

//     return 0;
// }


// int main(void){
//     int a = 10;
//     int *p = &a;
//     double *pd;

//     //pd = (double *)p;
//     pd = p;

//     printf("%d\n",*(int *)pd);

//     return 0;
// }


//====================================================================================
// 포인터를 사용하는 이유
// : 함수(자식)가 자신을 호출한 상위 함수(부모, main)의 데이터를 직접 수정해야 할 때
// : main 문의 데이터 (원본 데이터)를 수정하려면, 원본의 주소를 넘겨서 수정
// e.g.) scanf("", &);
// C언어는 복사본만을 전달하는데, 그 복사본이 변수의 주소값이라면 그 변수의 값을 변경 가능

// CALL: 함수에 인자(argument)를 전달할 때
    // 1. Call by Value    : 복사본을 넘김 >> 함수를 호출한 곳의 원본 변수는 영향 x (함수를 호출만 할때)
    // 2. Call by Reference: 원본을 넘김 e.g.) 파이썬 - mutation (.append(),...)
    // C언어는 Call by Value (Call by Reference 지원 x)인데, 변수의 주소를 넘기고 함수에서 그 주소를 역참조(*)하여 Call by Reference를 simulation한다




// 포인터를 사용한 두 변수의 값 교환

// void swap(int *pa, int *pb);


// int main(void){
//     int a = 10, b = 20;

//     swap(&a, &b);
//     printf("a: %d, b: %d\n", a,b);

//     return 0;
// }

// void swap(int *pa, int *pb){
//     int temp = *pa;

//     *pa = *pb;
//     *pb = temp;
// }


// 포인터 없이 두 변수의 값을 바꾸는 함수
// error C2065: 'a' : 선언되지 않은 식별자 입니다.

// void swap(void);

// int a = 10, b = 20; //이렇게 전역 변수로 빼는 거는 추천되지 않는다 
// // main 안에 변수를 저장해야 재사용성, 안전성, 디버기에 좋음

// // main: 내 방
// // 포인터: 열쇠
// // 함수: 특정 인물
// // 전역: 광장
// // main

// int main(void){

//     //int a = 10, b = 20;
//     swap();
//     printf("a: %d, b: %d\n", a,b);

//     return 0;
// }

// void swap(void){
//     int temp;

//     temp = a;
//     a = b;
//     b = temp;
// }




// ----------
// 연습문제 (1)
// void swap(double *pa, double *pb);
// void line_up(double *maxp, double *midp, double *minp);


// int main(void){

//     double max, mid, min;

//     printf("실수값 3개 입력: "); scanf("%lf%lf%lf", &max, &mid, &min);
//     line_up(&max, &mid, &min);
//     printf("정렬된 값 출력: %.1lf, %.1lf, %.1lf\n", max, mid, min);

//     return 0;
// }

// void swap(double *pa, double *pb){
//     double temp;
//     temp = *pa;
//     *pa = *pb;
//     *pb = temp;
// }

// void line_up(double *maxp, double *midp, double *minp){
    
//     if (*maxp < *midp) swap(maxp, midp);
//     if (*maxp < *minp) swap(maxp, minp);
//     if (*midp < *minp) swap(midp, minp);

// }

// ----------
// 연습문제 (2)

// void swap(double *pa, double *pb);
// void line_up(double *maxp, double *midp, double *minp);


// int main(void){

//     int num;
//     printf("==========데이터 입력==========\n");
//     printf("입력할 실수 값 개수: "); scanf("%d", num);
    
//     double arr[num];
//     for (int i = 0; i < num; i++){
//         printf("%번째 실수: "); scanf("%lf", arr[i]);
//     }

//     double parr[num];
//     for (int i = 0; i < num; i++) parr[i] = &arr[i];

//     line_up(parr);
//     printf("정렬된 값 출력: %.1lf, %.1lf, %.1lf\n", max, mid, min);

//     return 0;
// }

// void swap(double *pa, double *pb){
//     double temp;
//     temp = *pa;
//     *pa = *pb;
//     *pb = temp;
// }

// void line_up(double *maxp, double *midp, double *minp){
    
//     if (*maxp < *midp) swap(maxp, midp);
//     if (*maxp < *minp) swap(maxp, minp);
//     if (*midp < *minp) swap(midp, minp);

// }


//====================================================================================
// CHAPTER 10 배열과 포인터

// -------------------------
// 배열명으로 배열 요소 사용하기
// : 배열에서 요소들은, 주소들이 이어져있다.
// : 배열명 = &배열명[0] >> 배열명의 값은 배열의 첫 번째 요소의 주소값이다.
    // arr + 1과 &arr[1]과 동일하다.
        // 이때 + 1은 4byte (int arr[] 기준) e.g.) arr이 100에 저장되어 있다면 arr+1은 104에 저장된다.

// int main(void){

//     int arr[3], i;

//     *(arr + 0) = 10;    // arr의 첫번째 요소의 주소 + 0 의 값에 10을 넣는다.(arr[0] 정의)
//     *(arr + 1) = *(arr + 0) + 10;   // arr[1] 정의, arr[0]의 주소로 값 호출

//     printf("세 번째 배열 요소에 키보드 입력: "); scanf("%d", arr+2);    // arr[0]의 주소 호출
    
//     for(i=0; i<3; i++){
//         printf("%5d", *(arr + i)); // arr[i]의 값 호출
//     }
//     printf("\n");

//     return 0;

// }


// int main(void){
//     int arr[3];
//     int *pa = arr;

//     *pa = 10; // pa와 arr의 값은 동일하다
//     *(pa + 1) = 20; // *(arr + 1) = 20과 동일하다
//     pa[2] = pa[0] + pa[1];

//     return 0;
// }



// --------------------
// 배열명과 포인터의 차이
// e.g.) int arr[k]; int *pa = &arr; 
    // [사이즈] arr: 4 * k byte(배열 전체 크기), pa: 4 byte, *pa: 4 byte
    // [상수, 집주소] arr, [변수, 집주소가 적힌 쪽지] pa
        // arr++, arr += 1 불가, pa += 1, p++은 가능 
        // >> 변수의 주소를 직접 이동할 수는 없다. 포인터는 포인터가 가리키는 주소를 이동할 수 있다.

// int main(void){
//     int arr[3] = {10,20,30};
//     int *pa = arr;

//     printf("배열의 값: ");
//     for (int i = 0; i < 3; i++){
//         printf("%d ", *pa);
//         pa ++;
//     }
//     printf("\n");


//     return 0;
// }


// int main(void){

//     int arr[3] = {10,20,30};
//     int *pa = arr;

//     printf("배열의 값: ");
//     for (int i = 0; i < 3; i++){
//         printf("%d ", *(pa++));     // 후위 연산자
//     }

//     return 0;
// }





// ---------------------
// 포인터의 뺄셈과 관계 연산

// int main(void){
//     int arr[5] = {10,20,30,40,50};
//     int *pa = arr;
//     int *pb = pa + 3;

//     printf("pa: %u\n", pa);
//     printf("pb: %u\n", pb);    // pa 값에서 + 3 x 4 (byte)

//     pa ++;
//     printf("pb - pa: %u\n", pb - pa); // pb - pa = (40-32) / sizeof(int) = 2

//     // 배열의 물리적인 위치는 bit 단위
//     // 배열명 + 숫자 연산 => 자료형의 크기 단위로 나눠져서 처리됨 (배열 요소 간의 '간격' 차이)
//         // 배열명의 정수 덧셈: 자료형의 크기를 곱한다
//         // 포인터의 뺄셈: 배열 요소 간의 간격 차이

//     printf("앞에 있는 배열 요소의 값 출력: ");
//     if (pa < pb) printf("%d\n", *pa); 
//     else printf("%d\n", *pb);

//     return 0;
// }



// ---------------------
// 배열 값을 출력하는 함수

// void print_arr(int *pa);

// int main(void){
//     int arr[5] = {10,20,30,40,50};

//     print_arr(arr);

//     printf("\n");
//     return 0;
// }

// void print_arr(int *pa){            // *pa = arr

//     for (int i; i < 5; i ++){
//         printf("%d ", pa[i]);
//     }
// }



// ---------------------
// 크기가 다른 배열을 출력

// void print_arr(int *pa, int size);

// int main(void){

//     int arr_1[] = {10,20,30,40,50,60};
//     int arr_2[] = {10,20,30,40,50,60,70};

//     /*
//     print_arr(arr_1, 5);
//     printf("\n");
//     print_arr(arr_2, 7);
//     */

//     print_arr(arr_1, sizeof(arr_1)/sizeof(arr_1[0]));
//     printf("\n");
//     print_arr(arr_2, sizeof(arr_2)/sizeof(arr_2[0]));
//     printf("\n");


//     return 0;
// }

// void print_arr(int *pa, int size){

//     for (int i = 0;  i < size; i ++) printf("%d ", pa[i]);

// }


// --------------
// 배열에 값을 입력

// void input_arr (double *pa, int size);
// double find_max(double *pa, int size);

// int main(void){


//     double arr[5], max;
//     int size = sizeof(arr) / sizeof(arr[0]);

//     input_arr(arr, size);
//     max = find_max(arr, size);

//     printf("배열의 최대값: %.1lf\n", max);

//     return 0;
// }


// void input_arr (double *pa, int size){
    
//     printf("%d개의 실수값 입력: ", size);

//     for (int i=0; i < size; i++){
//         scanf("%lf", pa + i);
//     }

// }


// double find_max(double *pa, int size){
//     double max = pa[0];

//     for (int i = 1; i < size; i ++) if(max < pa[i]) max = pa[i];

//     return max;
// }



//====================================================================================
// CHAPTER 11 문자


// -----------
// 아스키코드
    // '0' ~ '9' : 48 ~ 57
    // 'A' ~ 'Z' : 65 ~ 90
    // 'a' ~ 'z' : 97 ~ 122

// int main(void){
//     char lower, upper = 'G';

//     if ((upper >= 'A') && (upper <= 'Z')) lower = upper + ('a'- 'A');

//     printf("대문자: %c %c", upper, '\n');
//     printf("소문자: %c\n", lower);

//     return 0;

// }



// int main(void){
//     char ch_1, ch_2;

//     //scanf("%c%c", &ch_1, &ch_2);
//     scanf(" %c %c", &ch_1, &ch_2);


//     printf("[%c%c]", ch_1, ch_2);


//     return 0;
// }



// --------------------------
// getchar 함수 & putchar 함수

// int main(void){
//     int ch;

//     printf("문자 입력: ");
//     ch = getchar(); // scanf("%c",ch);
//     printf("입력한 문자: ");
//     putchar(ch);
//     putchar('\n');


//     return 0;
// }


// ---
// 버퍼
// : 모아서 한 번('enter')에 전달

// int main(void){
    
//     char ch;

//     for(int i = 0; i <3; i ++){
//         scanf("%c", &ch);
//         printf("%c", ch);
//     }
//     printf("\n");

//     return 0;
// }
















