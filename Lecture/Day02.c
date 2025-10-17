#include <stdio.h>
/*
int main(void){

    char grade;
    char name[20];

    printf("학점 입력: ");
    scanf("%c", &grade);
    printf("이름 입력: ");
    scanf("%s", name); //scanf로 문자열 입력 시, char 배열 사용 / &기호를 사용하지 않는
    printf("%s의 학점은 %c입니다\n", name, grade);

    return 0;
}*/


/*
int main(void){
    int a = 10, b = 10;
    
    //printf("a: %d\n", ++a);
    //printf("b: %d\n",--b);

    printf("a: %d\n", a++);
    printf("a: %d\n", a--);
    printf("a: %d",a);


    return 0;
}
*/

int main(void){
/*
    int a = 5, b=5; //초기값
    int pre, post;

    pre = (++a) * 3;
    post = (b++) * 3;

    printf("초기값 a = %d, b = %d\n", a, b);
    printf("전위형: (++a) * 3  = %d, 후위형: (b++) * 3 = %d\n", pre, post);
*/

/*
    int a = 20, int b =3;
    double res;

    res = ((double)a / ((double)b));
    printf("a = %d, b = %d\n", a,b);
    printf("a /b의 결과")

*/

/*
    long a = 32;
    printf("long형 변수의 크기: %d\n", sizeof(a)); // 8byte c.f.) windows에서는 4byte
*/


//조건 연산자
/*
    int a = 10, b = 20, res;

    res = (a>b) ? a-b:b-a;
    printf("두 값의 차이: %d\n", res);
*/

//비트 연산자
/*
    int a = 10;
    int b = 12;

    printf("a & b: %d\n", a & b);    // &: 비트별 논리곱 연산자
    printf("a ^ b: %d\n", a ^ b);    // ^: 비트별 배타적 논리합 연산자
    printf("a | b: %d\n", a | b);    // |: 비트별 논리합 연산자
    printf("~a: %d\n", ~a);          // ~: 비트별 부정 연산자
    printf("a << 2: %d\n", a << b);  // <<: shift 연산자 (왼쪽)
    printf("a >> 2: %d\n", );        // >>: shift 연산자 (오른쪽)
*/


//연산자 우선순위 & 방향

/*
    int a = 10, b = 5;
    int res;

    res = a / b * 2;
    printf("res = %d\n", res);
    res = ++a * 3;               // ++ >> *
    printf("res = %d\n", res);
    res = a>b && a !=5;         
    printf("res = %d\n", res);
    res = a % 3 == 0;
    printf("res = %d\n", res);
*/

//선택문
/*
    int a = 20;
    int b = 0;

    if (a > 10){
        b = a;
    }
    printf("a: %d, b: %d\n", a,b);
*/

/*
    int a = 0, b = 0;
    if (a > 0){
        b = 1;
    }
    else if (a == 0){
        b = 2;
    }
    else{
        b = 3;
    }
    printf("b: %d\n",b);
*/

/*
    int a = 10;

    if (a==1)a=1;
    else if (a==2)a=2;
    else if (a==3)a=3;
    else if (a==4)a=4;
    else if (a==5)a=5;
    else if (a==6)a=6;
    else if (a==7)a=7;
    else if (a==8)a=8;
    else if (a==9)a=9;
    else if (a==10)a=10;

    printf("a: %d",a);
*/

// switch~case 문
/*
    int rank = 2, m = 0;

    switch (rank){
        case 1:
            m = 300;
            break;
        case 2:
            m = 200;
            break;
        default:
            m = 10;
            break;
    }


    // switch~case 문은 특정 조건에 맞는 시행을 하려고 하니까 break 반드시 작성
    
    switch (rank){
        case 1:
            m += 300;
        case 2:
            m += 200;
        case 3:
            m += 100;
    }

    printf("m: %d\n",m);
*/

// (실습 예제. 이동 로봇의 배터리 용량 선정)
/*
개념정리
    전력; 특정 순간에 에너지가 소비되는 순간 비율
        와트(Watt, W)
    에너지; 일정시간 동안 소비된 전력
        와트시(Watt-hour, Wh)

    평균 전류: I_load [A]
    평균 속도: vel    [km/h]
    예비율:    R      [0~1]

    배터리 정보
        공칭 전압:      V   [V]
        용량 Capacity: C   [Ah]
        시스템 효율:    eta [0~1]

// MDROBOT >> MDH150
    8A / 6.4km/h / 0.1 / 48V / 80Ah / 0.95 
*/
    
    int I_load = 8, V = 48, C = 80;

    double vel =6.4, R = 0.1, eta = 0.95, Wh, P, t, d;

    Wh = V * C * eta * (1-R);
    P = V * I_load / eta;
    t = Wh / P;
    d = vel * t;

    printf("[결과]\n사용 가능 에너지 E_usable: %.2lfWh\n소비 전력 P: %.2lfW\n런타임 t: %.2lfh (%.1lf min)\n주행거리 d: %.2lfkm\n", Wh, P, t,t*60, d);

    return 0;
}







