#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


struct tab_page{
        unsigned long  test[512];
};

#define size 102400
#define TIME 240

int main(void){
        unsigned long i = 0, begin;
	void *buff;
        void *tab_data1[size/3];
        void *tab_data2[size/3];
        void *tab_data3[size/3];
        int r;
        struct tab_page *temp;
        
	posix_memalign(&buff, 4096, 4096*size/3);
        for(i = 0 ;i < size/3 ; i++){
                tab_data1[i] = buff+(4096*i);
        }
        begin=time(NULL);
	printf("%lu\n",begin);
        while(time(NULL) < begin+TIME){
                r = i++%(size/3);
                //printf("%d\n",r);
                temp = tab_data1[r];
                temp->test[r%512] = r;
        }
        
	posix_memalign(&buff, 4096, 4096*size/3);
        for(i = 0 ;i < size/3 ; i++){
                tab_data2[i] = buff+(4096*i);
        }
        begin=time(NULL);
        while(time(NULL) < begin+TIME){
                r = i++%(size/3);
                //printf("%d\n",r);
                temp = tab_data1[r];
                temp->test[r%512] = r;
                temp = tab_data2[r];
                temp->test[r%512] = r;
        }

        posix_memalign(&buff, 4096, 4096*size/3);
        for(i = 0 ;i < size/3 ; i++){
                tab_data3[i] = buff+(4096*i);
        }
        begin=time(NULL);
        while(time(NULL) < begin+TIME){
                r = i++%(size/3);
                //printf("%d\n",r);
                temp = tab_data1[r];
                temp->test[r%512] = r;
                temp = tab_data2[r];
                temp->test[r%512] = r;
                temp = tab_data3[r];
                temp->test[r%512] = r;
        }
                
	free(tab_data3[0]);
        begin=time(NULL);
        while(time(NULL) < begin+TIME){
                r = i++%(size/3);
                //printf("%d\n",r);
                temp = tab_data1[r];
                temp->test[r%512] = r;
                temp = tab_data2[r];
                temp->test[r%512] = r;
        }

        free(tab_data2[0]);
        begin=time(NULL);
	while(time(NULL) < begin+TIME){
                r = i++%(size/3);
                //printf("%d\n",r);
                temp = tab_data1[r];
                temp->test[r%512] = r;
        }
}
