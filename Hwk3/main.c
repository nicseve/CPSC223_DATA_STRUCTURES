#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

typedef struct num Num;

struct num{
    size_t length;
    int value[];
};

void numDestroy(Num *n){
    free(n);
}

//void numPrint(const Num *n, FILE *f){
//
//    assert(f != NULL);
//    fprintf(f,"%lli",n->value);
//}

//
//Num * numMultiply(const Num *x, const Num *y){
//    unsigned long long val1 = x->value;
//    unsigned long long val2 = y->value;
//    unsigned long long len = 0;
//    unsigned long long temp;
//
//    Num *n;
//    n = malloc(sizeof(Num));
//    assert(n);
//
//    n->value = val1 * val2;
//    temp = n->value;
//
//    if (temp == 0){
//        len = 1;
//    }
//    else {
//        while (temp > 0) {
//            len++;
//            temp /= 10;
//        }
//    }
//    printf("%li",n->value);
//    n->len = len;
//
//    return n;
//}
//


//Num * numAdd(const Num *x, const Num *y){
//    int* v1 = x->value;
//    int* v2 = y->value;
//
//    Num *n;
//    n = malloc(sizeof(Num));
//    assert(n);
//
//    //assuming x-value is int array pointer;
//    //malloc Num and assign res -> value
//
//    int LEN = Math.max(x->len,y->len);
//
//    int *res;
//    res = malloc(sizeof(int) * LEN+1);
//
//    int carry = 0;
//    int temp;
//
//    for(int i = LEN-1; i >= 0; i--){
//        temp = v1[i] + v2[i] + carry;
//
//        if(temp < 10){
//            res[i+1] = temp;
//            carry = 0;
//        }
//
//        else{
//            if(i == 0){
//                res[i+1] = temp%10;
//                res[i] = temp/10;
//            }
//            else{
//                carry = temp/10;
//                res[i+1] = temp%10;
//            }
//        }
//    }
//}

Num * numMultiply(const Num *x, const Num *y){
    int* val1 = x->value;
    int* val2 = y->value;

    size_t l1 = x->length;
    size_t l2 = y->length;

    size_t minLen = l1 > l2 ? l2 : l1;
    size_t maxLen = l1 > l2 ? l1 : l2;

    int* min = l1 > l2 ? val2 : val1;
    int* max = l1 > l2 ? val1 : val2;

    int* temp;
    int* sum;
    int* res;

    temp = malloc(sizeof(int) * l1 + l2);
    sum = malloc(sizeof(int) * maxLen +1);
    res = malloc(sizeof(int) * maxLen + 1);

    int carry = 0;
    int cur; //current digit from smaller number
    size_t zeroCount = minLen-1; //number of zeros to append to temp array after storing multiplied digits

    int k = 0;
    for(int i = minLen-1; i >=0; i--){
        cur = min[i];
        for(int p = maxLen-1; p >= 0; p--){
            temp[k++] = (cur*max[p] + carry)%10;
            carry =  (int)floor((cur * max[p] + carry)/10);
//            printf("%d",carry);

        }
    }
    temp[k++] = carry;

    int j = 0;
    while(j < zeroCount){
        temp[k++] = 0;
        j++;
    }

    int w = 0;
    for(int z = (l1+l2); z >= 0; z-=2){

        if(z-1 < 0){
            res[w++] = temp[z];

        }
        else {
            res[w++] = temp[z] + temp[z-1];
        }
    }
    int g = 0;
    while(g < maxLen+1){
       printf("%d",res[g]);
       g++;
   }
}

//int numGetDigit(Num *n, int i){
//    long long val = n->value;
//
//    if(  (i > n->len-1)  || i < 0) {
//        return 0;
//    }
//    else {
//        for (; i > 0; i--) {
//            val = (val / 10);
//        }
//        return (int) val % 10;
//    }
//}

Num * numCreate(const char*s){
    int val = 0;
    char cur;
    size_t len = strlen(s);
    long long i = 0;

    Num *n;
    n = malloc(sizeof(struct num) + sizeof(int)*len+1);
    assert(n);


    for(int j = 0; j < len; j++){
        n->value[j] = 0;
    }
    n->length = len;

    if(len <= 0){
        n->value[0] = 0;
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

    int k = 0;
    for (; i < len; i++) {
        cur = s[i];
        if((cur-'0') < 0 || (cur-'0') > 9){
            free(n);
            return 0;
        }
        cur -= '0';
        n->value[k++] = cur;
    }
        n->length = (size_t) k;

    int p = 0;
    while(p < k) {
//        printf("%d", n->value[p]);
        p++;
    }
//    printf("\n%d",(int)n->length);
    return n;
}


int main() {
    char *s = "9";
    char *p = "12";
    FILE *f;

    Num *r;
    Num *w;
    Num *n;

//    int c;
//    size_t size = 2;
//    char *line = malloc(sizeof(int)*2);
//    long length = 0;
//
//
//    while((c = getchar()) != '\n'){
//
//        if(length >= size-1){
//            size *= 2;
//            line = realloc(line,size);
//        }
//        }
//
//        line[length] = c;
//        length++;
//    }
//
//    line[length] = '\0';
//
//    printf("%s",line);

    r = numCreate(s);
    w = numCreate(p);

    numMultiply(r,w);

    if(r == NULL) {
        return 0;
    }
//
//    numPrint(r,stdout);
    //n = numMultiply(r,w);

    //printf("%d",numGetDigit(r,3));

    numDestroy(r);
    //numDestroy(w);
    //numDestroy(n);

    return 0;
}
