#include <stdio.h>
#include <math.h>
#include <string.h>


void sort_arr(double arr_1[]);

int main(void){

    int scanner_num = 36, i, min_i;
    double dist[scanner_num], dist_rank[scanner_num], min_dist;

    for (i=0; i < scanner_num; i++ ){
        printf("%d번째(%d ~ %d도 사이) 스캐너가 인식한 거리값 (cm): ", (i+1),(i*10),((i+1)*10));
        if(scanf("%lf", &dist[i]) != 1) return 1;
    }

    for (i=0; i < scanner_num; i++){
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

    dist_rank = sort_arr(dist);
    index_rank = 

    printf("=========탐색 결과=========\n");
    printf("거리가 최소가 되는 스캐너: %d번째 스캐너(%d ~ %d도 사이)\n", min_i + 1, min_i * 10, (min_i+1)*10);
    printf("해당 스캐너와 장애물 사이의 거리: %.1lf cm\n", min_dist);

    return 0;
}




void sort_arr(double arr_1[], int index[]){
    
    int i, j, temp_1, temp_2; 
    for (i=0; i < sizeof(arr_1)/sizeof(arr_1[0]); i++){
        for(j = 0; j < (sizeof(arr_1)/sizeof(arr_1[0]) - i); j++){
            if (arr_1[j] < arr_1[j+1]){
                temp_1 = arr_1[j];
                arr_1[j] = arr_1[j+1]; arr_1[j+1] = temp_1; 
                temp_2 = index[j];
                index[j] = index[j+1]; index[j+1] = temp_2;
            }
        }
    }




}
