#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <string.h>
#include <time.h>

void create_image(){
    int x_res = 500;
    int y_res = 500;
    int max_color = 255;
    int ctr = 1;
    int row, col, random1, random2, random3, random_tmp, ctr_tmp, beg, mid, end;
    char data[12];
    
    int image = open("image.ppm", O_CREAT| O_TRUNC | O_WRONLY, 0644);
    sprintf(data, "P3 %d %d %d\n", x_res, y_res, max_color);
    write(image, data, strlen(data));
    
    for (row = 0; row < y_res; row++){
        random1 = rand()%100;
        random2 = rand()%200;
        random3 = rand()%256;
        beg = end = ctr;
        mid = x_res - beg - end;
        for (; beg > 0; beg--){
            sprintf(data, "%d %d %d\n", random1, random2, max_color);
            write(image, data, strlen(data));
        }
        for (; mid > 0; mid--){
            sprintf(data, "%d %d %d\n", random1, random2, random3);
        }
        for (; end > 0; end--){
            sprintf(data, "%d %d %d\n", random1, random2, max_color);
            write(image, data, strlen(data));
        }
        ctr++;
    }
    
    /*for (row = 0; row < y_res; row++){
        ctr_tmp = ctr;
        for (col = 0; col < x_res; col++){
            random1 = rand()%100;
            random2 = rand()%200;
            random3 = rand()%256;
            if (ctr_tmp > 0){
                sprintf(data, "%d %d %d\n", random1, random2, max_color);
                ctr_tmp--;
            }
            else
                sprintf(data, "%d %d %d\n", random1, random2, random3);
            write(image, data, strlen(data));
        }
        ctr++;
    }*/
    
    
    close(image);
}

int main(){
    srand(time(NULL));
    create_image();
    return 0;
}