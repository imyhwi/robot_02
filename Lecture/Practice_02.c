#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void){

    int total_scanner = 36, i, j, k, scanner_i[total_scanner], pivot;
    double dist[total_scanner], dist_rank[total_scanner];
    
    // 거리 입력
    for (i=0; i < total_scanner; i++ ){
        
        printf("%d번째(%d ~ %d도 사이) 스캐너가 인식한 거리값 (cm): ", (i+1),(i*10),((i+1)*10));
        if(scanf("%lf", &dist[i]) != 1) return 1;
        
        if(i==0){
            dist_rank[0] = dist[0];
            scanner_i[0] = i;
        }else{
            for(j=0; j<i ; j++){
                if(dist[i] <= dist_rank[j]){
                    pivot = j;
                    break;
                }else if(j == i){
                    pivot = j;
                }else continue;
            }
            for(k=0; k < i+1; k++){
                if(k < pivot) continue;
                else if(k == pivot){
                    dist_rank[k] = dist[i];
                    scanner_i[k] = i;
                }else{
                    dist_rank[k+1] = dist_rank[k];
                    scanner_i[k+1] = scanner_i[k];
                }
            }
        }
    }

    // 최소 거리가 되는 스캐너 탐색
    /*
    double min_dist;
    for (i=0; i < total_scanner; i++){
        if (i==0) {
            min_dist = dist[i];
            min_i = i;
        }
        else {
            if(min_dist > dist[i]) {
                min_dist = dist[i];
                min_i = i;
            }else continue;
        }
    }
    */

    printf("\n=========탐색 결과=========\n");
    /*
    printf("거리가 최소가 되는 스캐너: %d번째 스캐너(%d ~ %d도 사이)\n", min_i + 1, min_i * 10, (min_i+1)*10);
    printf("해당 스캐너와 장애물 사이의 거리: %.1lf cm\n", min_dist);
    */
    printf(">> 거리에 따른 스캐너 우선순위 <<\n\n");
    for(k=0; k<3; k++){
        printf("%d. %d번째 스캐너(%d ~ %d도 사이)\n", k+1, scanner_i[k]+1, scanner_i[k] * 10, (scanner_i[k]+1)*10);
        printf(">>> 해당 스캐너와 장애물 사이의 거리: %.1lf cm\n", dist_rank[k]);
    }

    return 0;
}

