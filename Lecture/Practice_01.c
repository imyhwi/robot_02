#include <stdio.h>
#include <math.h>

// 안전계수 <- 순간적인 물리적인 현상을 견디는 수치, 환경에 유연한 정도, 필요한 것보다 몇 배 더 강하게(하중) 설계했는가
// 설계마진 <- 온도 등 환경(사양)에 의해서 부품의 성능이 달라질 수 있는 점을 고려 

// MDR100 -> 바퀴 + 감속기 + 모터
// e.g.)
// 감속비 = 10(모터, 1차):1(바퀴, 2차) -> 모터가 10번 돌면 바퀴가 1바퀴 회전한다
// 모터의 토크 = 3 Nm -> 바퀴의 토크 = 30
// 모터 안의 인코더; 얼마나 회전했는가?
// 속도 = 10:1
// 토크 10배, 속도 1/10배

/*
int main(void){

    int wheels;
    double mass, SF, margin, radius, torque, gear;
    const double g = 9.81; // 중력가속도 [9.81N/m^2]
    const double c = 0.018; // 구름저항계수 (일반적인 고무바퀴 & 아스팔트)

    printf("-----------요구사항 설정-----------\n");
    printf("구동 바퀴 수  (개)          : "); if(scanf("%d",&wheels) != 1) return 1;
    printf("총 하중(질량) (kg)         : "); if(scanf("%lf",&mass) != 1) return 1;
    printf("안전 계수                  : "); if(scanf("%lf",&SF) != 1) return 1;
    printf("설계 마진 (30%% = 1.3로 입력): "); if(scanf("%lf",&margin) != 1) return 1;
    
    printf("-----------모터 및 바퀴 사양 입력-----------\n");
    printf("모터 정격 토크 (N*m): "); if(scanf("%lf", &torque) != 1) return 1;
    printf("감속비: "); if(scanf("%lf",&gear) != 1) return 1;
    printf("바퀴 반지름 (m): "); if(scanf("%lf", &radius) != 1) return 1;

    // 입력값으로 견인값 계산
    printf("-----------적정성 여부 판단-----------\n");
    double f_min, f_motor;
    const char *is_proper;

    f_min = c * mass * g * margin * SF;
    f_motor = torque * gear / radius * wheels;
    if(f_min <= f_motor) is_proper = "만족!"; 
    else is_proper = "불만족! 큰 모터나 감속비가 필요합니다!";

    printf("필요한 최소 견인력: %.2lf N\n", f_min);
    printf("모터가 낼 수 있는 견인력: %.2lf N\n", f_motor);
    printf("결과: %s\n",is_proper);
    
    return 0;

}
*/


// 반복문
int main(void){

    int wheels;
    double mass, SF, margin, radius, torque, gear;
    const double g = 9.81; // 중력가속도 [9.81N/m^2]
    const double c = 0.018; // 구름저항계수 (일반적인 고무바퀴 & 아스팔트)
    double f_min, f_motor;
    
    printf("-----------요구사항 설정-----------\n");
    printf("구동 바퀴 수  (개)          : "); if(scanf("%d",&wheels) != 1) return 1;
    printf("총 하중(질량) (kg)         : "); if(scanf("%lf",&mass) != 1) return 1;
    printf("안전 계수                  : "); if(scanf("%lf",&SF) != 1) return 1;
    printf("설계 마진 (30%% = 1.3로 입력): "); if(scanf("%lf",&margin) != 1) return 1;
    
    do{
        printf("-----------모터 및 바퀴 사양 입력-----------\n");
        printf("모터 정격 토크 (N*m): "); if(scanf("%lf", &torque) != 1) return 1;
        printf("감속비: "); if(scanf("%lf",&gear) != 1) return 1;
        printf("바퀴 반지름 (m): "); if(scanf("%lf", &radius) != 1) return 1;

        // 입력값으로 견인값 계산
        printf("-----------적정성 여부 판단-----------\n");
        const char *is_proper;
        f_min = c * mass * g * margin * SF;
        f_motor = torque * gear / radius * wheels;

        if(f_min <= f_motor) is_proper = "만족!"; 
        else is_proper = "불만족! 큰 모터나 감속비가 필요합니다!\n";

        printf("필요한 최소 견인력: %.2lf N\n", f_min);
        printf("모터가 낼 수 있는 견인력: %.2lf N\n", f_motor);
        printf("결과: %s\n",is_proper);
    } while(f_min > f_motor);
    printf("=====종료=====\n");

    return 0;

}   
