#include <time.h>
#include <stdlib.h>
#include <limits.h>

#define size 102400
#define TIME 2

struct tab_page{
        unsigned long  test[512];
};

int main(void){
        unsigned long i = 0;
        void *tab_data[size];
        int r, begin;
        struct tab_page *temp;
        for(i = 0 ;i < size ; i++){
                tab_data[i] = (struct tab_page *) malloc(4096);
        }

        begin=time(NULL);
        while(time(NULL) < begin+TIME){
		r = i++%size;
                //printf("%d\n",r);
                temp = tab_data[r];
                temp->test[r%512] = r;
        }
}
