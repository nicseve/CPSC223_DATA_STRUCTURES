#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

void test(){
    int i;
    for(i = 5; i>0; i--){
        printf("%d\n",i);
    }
}

typedef struct num Num;

struct num{
    long value;
    long len;
};


/* add two Nums, returning a new Num */
/* does not destroy its inputs, caller must destroy output */
Num * numAdd(const Num *x, const Num *y){
    long val1 = x->value;
    long val2 = y->value;
    long len = 0;
    long temp;

    Num *n;
    n = malloc(sizeof(Num));
    assert(n);

    n->value = val1+val2;
    temp = n->value;

    if (temp == 0){
        len = 1;
    }
    else {
        while (temp > 0) {
            len++;
            temp /= 10;
        }
    }
//    printf("%d",len);
    n->len = len;

    return n;
}



int numGetDigit(Num *n, int i){
    long val = n->value;

    if(  (i > n->len-1)  || i < 0) {
        return 0;
    }
    else {
        for (; i > 0; i--) {
            val = (val / 10);
        }
        return (int) val % 10;
    }
}


void numDestroy(Num *n){
    free(n);
}


Num * numCreate(const char*s){
    long val = 0;
    char cur;
    long len = strlen(s);
    long i = 0;

    Num *n;
    n = malloc(sizeof(struct num));
    assert(n);

    n->value = 0;
    n->len = len;

    if(len <= 0){
        n->value = 0;
        return n;
    }

    else{
            while (i < len) {
                cur = s[i];
                if((cur-'0') < 0 || (cur-'0') > 9){
                    free(n);
                    return 0;
                }
                else if((cur - '0') != 0){
                    break;
                }
                i++;
            }
        }

        for (; i < len; i++) {
            cur = s[i];
            if((cur-'0') < 0 || (cur-'0') > 9){
                free(n);
                return 0;
            }
            cur -= '0';
            val *= 10;
            val += cur;
        }
        n->value = val;
        return n;
}


int main() {
    char *s = "127";
    char *p = "0";

    Num *r;
    Num *w;
    Num *n;

    r = numCreate(s);
    w = numCreate(p);

    if(r == NULL){
        return 0;
    }


    n = numAdd(r,w);


//    printf("%d",numGetDigit(r,3));

    numDestroy(r);
    numDestroy(w);
    numDestroy(n);

    return 0;
}


