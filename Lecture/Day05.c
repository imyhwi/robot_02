#include <stdio.h>
#include <math.h>
#include <stdlib.h> // 난수
#include <time.h> // 난수 초기화 (seed 설정)


/*
int main(void) {

    srand(time(NULL)); //랜덤 초기화

    int r1 = rand() % 10; // 0 ~ 9
    int r2 = rand() % 100 + 1; // 1 ~ 100
    int r3 = rand() % 21 - 10; // -10 ~ 10;

    printf("0~9 랜덤: %d\n",r1);
    printf("1~100 랜덤: %d\n",r2);
    printf("-10~10 랜덤: %d\n",r3);

    return 0;

}

*/

// 로그에서 급가속/급제동 이벤트 카운트

/*
int main(void){

    int log_size, i, sudden_stop = 0, sudden_accel = 0;
    double delta;

    printf("========요구 사항 입력========\n");
    printf("주행 로그 개수: "); scanf("%d",&log_size);

    double speed[log_size];
    
    srand(time(NULL));

    for (i = 0; i < log_size; i++){
        speed[i] = rand() % 201;
    }

    for (i=1; i< log_size; i++){
        delta = speed[i] - speed[i-1];
        if (delta >= 10){
            printf("급가속이 인식되었습니다! (%.1lf km/h >> %.1lf km/h)\n", speed[i-1],speed[i]);
            sudden_accel++;
        }
        else if (delta <= -10) {
            printf("급제동이 인식되었습니다! (%.1lf km/h >> %.1lf km/h)\n", speed[i-1],speed[i]);
            sudden_stop++;
        }
    }

    printf("========인식 결과========\n");
    printf("급가속 횟수: %d번\n", sudden_accel);
    printf("급제동 횟수: %d번\n", sudden_stop);



}
*/

// 급제동/가속 범위를 설정하고 해당 범위를 벗어나는 난수 없도록 
/*
int main(void){

    int log_size, i, sudden_stop = 0, sudden_accel = 0, max, min;
    double delta, range = 10;

    printf("========요구 사항 입력========\n");
    printf("주행 로그 개수: "); scanf("%d",&log_size);
    double speed[log_size];
    
    srand(time(NULL));

    for (i = 0; i < log_size; i++){
        if (i == 0) speed[i] = rand() % 201;
        else{
            max = speed[i-1] + range-1;
            min = speed[i-1] - range+1;
            speed[i] = rand() % (max-min+1) + min;

        }
    }

    for (i=1; i< log_size; i++){
        delta = speed[i] - speed[i-1];
        if (delta >= 10){
            printf("급가속이 인식되었습니다! (%.1lf km/h >> %.1lf km/h)\n", speed[i-1],speed[i]);
            sudden_accel++;
        }
        else if (delta <= -10) {
            printf("급제동이 인식되었습니다! (%.1lf km/h >> %.1lf km/h)\n", speed[i-1],speed[i]);
            sudden_stop++;
        }
    }

    printf("========인식 결과========\n");
    printf("급가속 횟수: %d번\n", sudden_accel);
    printf("급제동 횟수: %d번\n", sudden_stop);

}
*/

// 오르다가 내리는 속도 변화

int main(void){

    int log_size, i, max, min, limit, range;

    printf("========요구 사항 입력========\n");
    printf("주행 로그 개수: "); scanf("%d",&log_size);

    int speed[log_size];
    srand(time(NULL));

    for (i = 0; i < log_size; i++){
        limit = rand() % 11 + 1;
        range = rand() % 21 -10;

        // 초기 속도 설정
        if (i == 0) speed[i] = rand() % 180;
        // 감속/가속 설정
        else if (i == 1) {
            if (speed[i-1] < 10){
                speed[i] = rand() % (speed[i-1] + limit + 1) - speed[i-1];
            } else speed[i] = speed[i-1] + range;
        }
        else if (i % 10 == 0) speed[i] = speed[i-1] + range;
        // 나머지 8개 로그 설정
        else{
            if (speed[(i/10) * 10] > speed[(i/10)*10 +1]){
                speed[i] = speed[i-1] - limit;
            }
            else if (speed[(i/10) * 10] < speed[(i/10)*10 +1]){
                speed[i] = speed[i-1] + limit;
            }
            else if (speed[(i/10) * 10] == speed[(i/10)*10 +1]){

            }
        }
    }

    for (i = 0; i < log_size; i++){
        printf("%d. SPEED: %d ", (i+1), speed[i]);
        if (i == 0) printf("DELTA: NULL\n");
        else printf("DELTA: %d\n", speed[i]-speed[i-1]);
    }
    printf("\n");





}


/*
    for (i=1; i< log_size; i++){
        delta = speed[i] - speed[i-1];
        if (delta >= 10){
            printf("급가속이 인식되었습니다! (%.1lf km/h >> %.1lf km/h)\n", speed[i-1],speed[i]);
            sudden_accel++;
        }
        else if (delta <= -10) {
            printf("급제동이 인식되었습니다! (%.1lf km/h >> %.1lf km/h)\n", speed[i-1],speed[i]);
            sudden_stop++;
        }
    }

    printf("========인식 결과========\n");
    printf("급가속 횟수: %d번\n", sudden_accel);
    printf("급제동 횟수: %d번\n", sudden_stop);

*/