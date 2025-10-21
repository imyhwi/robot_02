#include <stdio.h>
#include <math.h>
#include <string.h>

/*
int main(void){

    double m, Tm, G, eta, r, c, SF;
    int motor_n;
    const double cloud = 0.020, g = 9.81;
    double f_motor, f_need, sin_theta, grade_pct;

    printf("-------------요구사항 설정-------------\n");
    printf("총 질량 (kg)     : "); if(scanf("%lf",m) != 1) return 1;
    printf("모터 정격토크 (Nm) : "); if(scanf("%lf", Tm) != 1) return 1;
    printf("구동 모터 수 (개) : "); if(scanf("%d", motor_n) != 1) return 1;
    printf("감속비           : "); if(scanf("%lf", G) != 1) return 1;
    printf("구동 효율 (0~1)  : "); if(scanf("%lf", eta) != 1) return 1;
    printf("바퀴 반지름 (m)  : "); if(scanf("%lf", r) != 1) return 1;
    printf("안전계수 (>=1)   : "); if(scanf("%lf", SF) != 1) return 1;

    f_motor = motor_n * Tm * G * eta / r; // 총 구동 토크
    f_need = m * g * sin(45) + cloud * m * g; // 가용 견인력

    if(sin_theta < 0.0) sin_theta = 0.0;
    if(sin_theta > 1.0) sin_theta = 1.0;
    
    double 
    sin_theta = ((f_motor/SF - cloud * m * g)/ (m*g),0,1); // 등판 최대각
    grade_pct = sin_theta * 100;


    printf("-------------계산 결과-------------");
    printf("총 가용 견인력  : %.2lfN", f_motor);
    printf("등판 가능 최대각 : %.2lf도", sin_theta);
    printf("등판율         : %.1lf %%", grade_pct);


    return 0;
}
*/

/*
#define EARNED_INCOME_TAX_RATE 4
#define LOCAL_INCOME_TAX_RATE 10
#define NATIONAL_PENSION_RATE 4.5
#define EMPLOYMENT_INSURANCE_RATE 0.8
#define HEALT_INSURANCE_RATE 3.38

int main(void){

    float salary;
    float eit, lit, np, ei, hi;
    float total;

    printf("This program calculates socail insurance tax.\n");
    printf("Please enter your salary(month): "); scanf("%f", &salary);

    eit = salary * (EARNED_INCOME_TAX_RATE / 100.0);
    lit = eit * (LOCAL_INCOME_TAX_RATE / 100.0);
    np = salary * (NATIONAL_PENSION_RATE / 100.0);
    ei = salary * (EMPLOYMENT_INSURANCE_RATE / 100.0);
    hi = salary * (HEALT_INSURANCE_RATE / 100.0);
    total  = eit  + lit + np + ei + hi;

    printf("\nEarned income tax:     %10d Won\n",(int)eit);
    printf("Local income tax:     %10d Won\n",(int)lit);
    printf("National pension:      %10d Won\n",(int)np);
    printf("Employment insurance:  %10d Won\n",(int)ei);
    printf("Health insurance:      %10d Won\n",(int)hi);
    printf("--------------------------------------\n");
    printf("Total:                 %10d Won\n",(int)total);

    return 0;

}
*/


/*
// 반환값 x, 매개변수 x

void print_line(void);

int main(void){
    print_line();
    printf("학번     이름     전공     학점\n");
    print_line();

    return 0;
}

void print_line(void){
    int i;
    for (i = 0; i<50; i++){
        printf("-");
    }
    printf("\n");
}
*/


/*
// 재귀호출 함수

void fruit(int count);

int main(void){
    fruit(1);
    return 0;
}

void fruit(int count){
    printf("apple\n");
    if(count==3) return; // main 함수의 return 0으로 감
    fruit(count+1);
}
*/

/*
void add_num(int count);

int total = 0;

int main(void){
    add_num(1);
    printf("총합: %d\n",total);
    return 0;
}

void add_num(int count){
    if(count > 10) return;
    total += count;
    add_num(count + 1);
}
*/


/*
// 재귀함수와 반복문의 차이점

void fruit(int count);

int main(void){
    fruit(1);
    return 0;
}

void fruit(int count){
    printf("apple\n");
    if(count == 3) return;
    fruit(count + 1);
    printf("jam\n");
}
*/



// >> 배열 Array <<
/*
int main(void){

    int score[5]; int i; int total = 0;

    for(i = 0; i <5; i++){
        scanf("%d",&score[i]);
    }

    for (i = 0; i < 5; i++){
        total += score[i];
    }
    
    double avg = total / 5.0;

    for (i = 0; i <5; i++){
        printf("%d", score[i]);
    }
    printf("\n");

    printf("평균: %.1lf\n", avg);
    
    return 0;
}
*/
/*
int main(void){

    int score[5], i, total = 0, count; 
    double avg;

    count = sizeof(score) / sizeof(score[0]); // 배열의 크기
    
    for (i = 0; i < count; i++){
        scanf("%d", &score[i]);
    }
    
    for (i = 0; i < count; i++){
        total += score[i];
    } 

    avg = total / (double)count;

    for (i = 0; i < count; i++){
        printf("%5d", score[i]);
    }
    printf("\n");
    printf("평균: %.1lf\n", avg);
    return 0;
}
*/

/*
int main(void){

    char str[80] = "applejam";
    printf("최초 문자열: %s\n", str);
    printf("문자열 입력: ");
    scanf("%s", str); // 문자열은 &없이 작성
    printf("입력 후 문자열: %s\n", str);

    return 0;
}
*/



// 문자열 대입
/*
int main(void){

    char str1[80] = "cat", str2[80];
    
    strcpy(str1, "tiger"); strcpy(str2, str1); // str(변수, 문자열)
    printf("str1: %s\nstr2: %s\n", str1,str2);

    return 0;
}
*/


// 문자열 전용 입출력 함수: gets, puts
/*
int main(void){
    
    char str[80];

    printf("문자열 입력: "); fgets(str, 80, stdin); // 집 주소를 읽음 (변수, 사이즈, 스트림:어디서 읽을지 키보드 입력은 stdin)
    printf("입력된 문자열: "); puts(str); // 주소의 내용을 읽음
 
    return 0;
}
*/








