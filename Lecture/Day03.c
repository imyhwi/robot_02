#include <stdio.h>
#include <math.h>

/*
int main(void){


    double I_load, vel, R, V, C, eta;
    int motor_n;
    
    // 배터리 사양 및 환경정보 입력\
        // scanf 함수: 성공적으로 읽어서 할당한 항목의 개수를 Return
    printf("----------------사전 선정 정보----------------");
    printf("평균전류 I_load [A] (부하측): ");  if (scanf("%lf",&I_load) != 1) return 1;
    printf("평균속도 vel [km/h]: ");          if (scanf("%lf",&vel) != 1) return 1;
    printf("예비율 R [20% =0.2]: ");         if (scanf("%lf",&R) != 1) return 1;
    
    printf("----------------배터리 정보----------------");
    printf("공칭전압 V [V]: ");               if (scanf("%lf",&V) != 1) return 1;
    printf("용량 C [Ah]: ");                 if (scanf("%lf",&C) != 1) return 1;
    printf("시스템 효율 eta [90% = 0.9]: ");  if (scanf("%lf",&eta) != 1) return 1;

    printf("모터의 개수 (n >= 1): ");         if (scanf("%d",&motor_n) != 1) return 1;

    // 입력 범위 검증
    if (V<=0 || C<=0 || I_load<=0 || vel <0 || R<=0 || eta<=0 || eta >100) {
        printf("입력값 범위를 확인하세요\n");
        return 1;


    // 계산
    // 소비전력 (W)
    const double P = (V * I_load) / eta * motor_n;
    // 사용가능 에너지 (Wh)
    const double E_usable = V * C * eta * (1.0 -R);
    // 런타임 계산 (h)
    const double t_h = E_usable / P;
    const double t_min = t_h * 60;
    // 주행거리 계산 (km)
    const double d_km = vel * t_h;

    // 출력결과
    printf("사용가능 에너지 E_usable: %.2f Wh\n", E_usable);
    printf("런타임 t              : %.2f h (%.1lf min)", t_h, t_min);
    printf("주행거리");


    return 0
}   

*/



int main(void){

/*
    double x, y;

    printf("실수 x: "); scanf("%lf",&x);
    printf("실수 y: "); scanf("%lf",&y);

    printf("\n[math.h 함수 예제]\n");
    printf("sqrt(x)  = %.4f\n", sqrt(x));
    printf("pow(x,y) = %.4f\n", pow(x,y));
    printf("sin(x)   = %.4f\n", sin(x));
    printf("cos(x)   = %.4f\n", cos(x));
    printf("log(x)   = %.4f\n", log(x));
    printf("fabs(x)  = %.4f\n", fabs(x));
*/


/*
// while 문
    int a = 1;

    while (a < 10){
        a = a *2;
    }
    printf("a: %d\n",a);
*/

/*
// for 문    
    int a = 1;
    int i;
    
    for (i = 5; i <8; i ++){
        a *= 2;
    }

    printf("a: %d\n",a);
*/

/*
// do ~ while 문 (1번은 반드시 실행)
    int a = 1;
    
    do {
        a = a*2;
    } while (a<10);
    printf("a: %d\n", a);
*/


// 중첩 반복문
/*
    int i, j; //행렬

    for (i = 0; i < 5 ; i++){
        for (j = 0; j<5-i; j++){
            printf("*");
        }
        printf("\n");
    }
*/

/*
// 구구단
    int i, j;

    for (i=2; i<10; i ++){
        printf("====== <%d단> ======\n",i);
        for (j=0; j<9; j++){
            printf("%d x %d = %d\n", i, j+1, i*(j+1));
        }
        printf("\n");
    }
*/

// break는 반복문을 벗어나는 것이다! c.f.) 조건문
// continue는 반복문의 해당 순서를 건너뛴다(반복문의 처음으로 돌아감)
// 무한 반복문: while(1), for(;;) >> break로 종료


// >> THEME: 함수 <<

// 함수 형식: [반환형] [함수명]([매개변수]...){}


// 문자,문자열 변수
// 1. char*    : 읽기 전용 %s, 
    // scanf()불가하지만 malloc()쓰면 가능(동적 메모리를 미리 할당)
    // e.g.) char* a = malloc(sizeof(char)*10);
// 2. char []  : 쓰기 전용 %c, scanf()


    return 0;
}