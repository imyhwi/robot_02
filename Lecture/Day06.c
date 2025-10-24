#include <stdio.h>
#include <math.h>
#include <stdlib.h>



// IR센서 반사값 임계치 분류기
/*
int main(void){

    int sensor_num, data_num, thres, i;

    printf("\n===========입력 조건 설정 ===========\n");
    printf("센서 개수: "); scanf("%d", &sensor_num);
    printf("임계값 (0 ~ 1023): "); scanf("%d", &thres);

    printf("===========데이터 입력===========\n");
    int value[sensor_num];
    for(i=0; i<sensor_num; i++){
        printf("%d번째 데이터: ", i+1); scanf("%d", &value[i]);
    }

    int is_black[sensor_num], black_count = 0, black_index = 0;
    for(i=0; i<sensor_num; i++){
        if (value[i] < thres) {
            is_black[i] = 1; black_count ++; black_index += i;
        }
        else is_black[i] = 0;
    }
    printf("===========인식 결과===========\n");
    printf("label:");
    for(i=0; i<sensor_num; i++) printf(" %d", is_black[i]);

    printf("\nblack_count: %d 개\n", black_count);

    double index_avg;
    if(black_count == 0) {
         printf("라인이 감지되지 않았습니다.\n");
        return 1;
    }
    else {
        index_avg = black_index / black_count;
        printf("index_avg: %.2lf\n", index_avg);
    }


    

    return 0;
}

// label 분류
void classify_by_threshold(const int value[], int label[], int n, int threshold){
    for(int i = 0; i < n; i++){
        if (value[i] < threshold) label[i] = 1;
        else label[i] = 0;
    }
}

// 특정 label 빈도 계산
int count_black(const int label[], int n){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (label[i] == 1) cnt++;
    }
    return cnt;
}

// 특정 label 인덱스 합 계산
double avg_index_black(const int label[], int n){
    int total = 0, cnt = 0;

    for (int i = 0; i <n; i++){
        total += i * label[i];
        cnt += label[i];
    }

    if (cnt == 0) return -1.0;
    return (double) total / cnt;
}
*/


//======================================================

// ADC
// [센서] 아날로그 ---ADC---> 디지털
/*
struct adc_output
{
    int adc_val;
    double volt;
    double dist;
};

int main(void){


    int adc_num;
    double v_ref, k;

    printf("\n===========입력값 설정===========\n");
    printf("ADC 값의 개수 (1 ~ 10개): "); scanf("%d", &adc_num);
    printf("기준 전압 (V): "); scanf("%lf", &v_ref);
    printf("거리 변환 상수: "); scanf("%lf", &k);

    printf("===========데이터 입력===========\n");
    int adc_val[adc_num];
    for (int i = 0; i < adc_num; i++){
        printf("%d번째 ADC 값: ", i+1); scanf("%d", &adc_val[i]);
    }

    printf("===========실행 결과===========\n");
    double volt[adc_num], dist[adc_num], max, min;
    struct adc_output result[adc_num];

    for (int i = 0; i < adc_num; i++){
        
        volt[i] = ((double) adc_val[i]) / 1023.0 * v_ref;
        if (volt[i] == 0.0) volt[i] = 0.01; dist[i] = k / volt[i]; 
        
        result[i].adc_val = adc_val[i];
        result[i].volt = volt[i];
        result[i].dist = dist[i];
    }
    min = dist[0]; max = dist[0];
    
    for (int i = 0; i < 3; i ++){
        switch(i){
            case 0:
                printf("ADC      -> "); break;
            case 1:
                printf("전압 (V) -> "); break;
            case 2:
                printf("거리 (cm)-> "); break;
        }
        for (int j=0; j < adc_num; j++){
            if (i == 0) printf("%-8d", result[j].adc_val);
            else if (i == 1) printf("%-8.2lf", result[j].volt);
            else if (i == 2) {
                printf("%-8.2lf", result[j].dist);
                if (result[j].dist > max) max = result[j].dist;
                if (result[j].dist < min) min = result[j].dist; 
            }
        }
        printf("\n");
    }
    printf("\n- 최소거리: %.2lf cm ~ 최대거리: %.2lfcm\n", min, max);


    return 0;
}
*/



//=================================================================
// 포인터

// int main(void){

//     int a; double b; char c;

//     // 주소 연산자
//     printf("int형 변수의 주소: %u\n",&a);
//     printf("double형 변수의 주소: %u\n",&b);
//     printf("char형 변수의 주소: %u\n",&c);
    
//     printf("int형 변수의 주소: %p\n",&a);
//     printf("double형 변수의 주소: %p\n",&b);
//     printf("char형 변수의 주소: %p\n",&c);
//     return 0;

// }




// int main(void){
//     int val = 100; 
//     int *pval;                               // [선언 *]

//     pval = &val;                             // [사용 &] val의 주소 (&val)을 -> pval에 저장 // 포인터는 변수의 시작 주소를 저장
    
//     printf("val의 주소      : %p\n", &val);
//     printf("pval에 저장된 값: %p\n", pval);

//     printf("변경 전 val의 값: %d\n", val);
//     *pval = 1000;                           // [사용 *]
//     printf("변경 후 val의 값: %d\n", val);

//     return 0;
// }


// int main(void){
//     int a = 10, b = 15, total;
//     double avg;

//     int *pa, *pb;
//     int *pt = &total;
//     double *pg = &avg;

//     pa = &a; pb = &b;

//     *pt = *pa + *pb;    // 10 + 15
//     *pg = *pt / 2.0;    // 25 / 2.0

//     printf("두 정수의 값: %d, %d\n", *pa, *pb);
//     printf("두 정수의 합: %d\n", *pt);
//     printf("두 정수의 평균: %.1lf\n", *pg);

//     return 0;
// }


// const를 사용한 포인터
// int main(void){

//     int a = 10, b = 20;
//     const int *pa = &a;         // *pa로 사용 불가, 참조만 가능

//     printf("변수 a의 값: %d\n",*pa);

//     pa = &b;
//     printf("변수 b의 값: %d\n", *pa);
    
//     pa = &a;
//     a = 30;
//     // *pa = 40;
//     printf("변수 a의 값: %d\n", *pa);

//     return 0;
// }


// 주소와 포인터의 크기
// int main(void){
//     char ch; int in; double db;

//     char *pc = &ch;
//     int *pi = &in;
//     double *pd = &db;

//     printf("char형 변수의 주소 크기: %lu\n", sizeof(&ch));
//     printf("int형 변수의 주소 크기: %lu\n", sizeof(&in));
//     printf("double형 변수의 주소 크기: %lu\n", sizeof(&db));
//     printf("\n");

//     printf("char *포인터 주소 크기: %lu\n", sizeof(pc));
//     printf("int *포인터 주소 크기: %lu\n", sizeof(pi));
//     printf("double *포인터의 주소 크기: %lu\n", sizeof(pd));
//     printf("\n");

//     printf("char *포인터가 가리키는 변수의 크기: %lu\n", sizeof(*pc));
//     printf("int *포인터가 가리키는 변수의 크기: %lu\n", sizeof(*pi));
//     printf("double *포인터가 가리키는 변수의 크기: %lu\n", sizeof(*pd));
    

//     return 0;
// }





// 포인터를 이용한 변수 값 변경

int main(void){

    int a = 10;
    int *pa = &a;

    printf("변경 전 a의 값: %d\n", a);
    *pa = 20;
    printf("변경 후 a의 값: %d\n", a);

    return 0;
}
