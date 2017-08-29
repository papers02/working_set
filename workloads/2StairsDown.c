#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


struct tab_page{
        unsigned long  test[512];
};

#define size 102400
#define TIME 300

int main(void){
        unsigned long i = 0, begin;
        void *buff;
        struct tab_page *tab_data1[size/2];
        struct tab_page *tab_data2[size/2];
        int r;
        struct tab_page *temp;

	posix_memalign(&buff, 4096, 4096*size/2);	
        for(i = 0 ;i < size/2 ; i++){
                tab_data1[i] = buff+(4096*i);
        }
	posix_memalign(&buff, 4096, 4096*size/2);	
        for(i = 0 ;i < size/2 ; i++){
                tab_data2[i] = buff+(4096*i);
        }

        begin=time(NULL);
        while(time(NULL) < begin+TIME+60){
                r = i++%(size/2);
                //printf("%d\n",r);
                temp = tab_data1[r];
                temp->test[r%512] = r;
		temp = tab_data2[r];
                temp->test[r%512] = r;
        }

	printf("down\n");
        free(tab_data2[0]);

        begin=time(NULL);
        while(time(NULL) < begin+TIME){
                r = i++%(size/2);
                //printf("%d\n",r);
                temp = tab_data1[r];
                temp->test[r%512] = r;
        }
}
