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

void numPrint(const Num *n, FILE *f){
    assert(f != NULL);
    for(int i = 0; i < n->length;i++){
        fprintf(f,"%d",n->value[i]);
    }
}

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


Num * numAdd(const Num *x, const Num *y){
    int* v1 = x->value;
    int* v2 = y->value;

    size_t l1 = x->length;
    size_t l2 = y->length;

    size_t minLen = l1 > l2 ? l2 : l1;
    size_t maxLen = l1 > l2 ? l1 : l2;


    Num *n;
    n = malloc(sizeof(Num) + sizeof(int)*(maxLen+1));
    assert(n);
    
    //initialize n-value array with 0's
    for(int j = 0; j < maxLen+1; j++){
        n->value[j] = 0;
    }

    int carry = 0;
    int sum = 0;

    int*res;
    res = malloc(sizeof(int)*(maxLen+1));

    int* min = l1 > l2 ? v2 : v1;
    int* max = l1 > l2 ? v1 : v2;

    long long i = minLen-1;
    long long j = maxLen-1;
    int p = 0;

    for(; i >=0;i--) {
        sum = (min[i] + max[j--] + carry );
        carry = sum / 10;
        res[p++] = sum%10;
    }

    while(j >=0){
        sum = max[j] + carry;
        res[p++] = sum%10;
        carry = sum/10;
        j--;
    }
    res[p] = carry;


    int g = maxLen+1;   //erase leading zeros
    while(res[g] == 0){ g--;}

    int z = 0;  //write result to n-value array
    while(g >= 0) {
        n->value[z++] = res[g--];
    }

   n->length = z;  //z == final length

    return n;
}

//    int *res;
//    res = malloc(sizeof(int) * l1+l2+1);
//
//    int carry = 0;
//    int temp;

//    for(int i = Max-1; i >= 0; i--){
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
//        } ///add carry to final val check for length of shorter num and account
//    }
//}



Num * numMultiply2(const Num *x, const Num *y){
    int *val1 = x->value;
    int *val2 = y->value;

    size_t l1 = x->length;
    size_t l2 = y->length;

    size_t minLen = l1 > l2 ? l2 : l1;
    size_t maxLen = l1 > l2 ? l1 : l2;


    int* min = l1 > l2 ? val2 : val1;
    int* max = l1 > l2 ? val1 : val2;

    int *res = malloc(sizeof(int)* l1+l2);
    int sum = 0;
    int carry = 0;
    int pos1 = 0;
    int pos2 = 0;

    for(int i = minLen-1; i >=0; i--){
        pos2 = 0;
        sum = 0;
        for(int j = maxLen-1; j >= 0; j--){
            sum = (min[i]*max[j] + carry);
            res[pos1+pos2] = sum+res[pos1+pos2]%10;
            carry += sum+res[pos1+pos2]/10;
            pos2++;
        }
//        res[pos1+pos2] = carry;
        carry = 0;
        sum = 0;
//        carry = 0;
        pos1++;
    }
    //r//        carry = 0;
res[l2+l1] = carry;
    int i = 0;
    while(i < l1+l2 ){
        printf("%d",res[i]);
        i++;
    }
}



//Num * numMultiply(const Num *x, const Num *y){
//    int* val1 = x->value;
//    int* val2 = y->value;
//
//    size_t l1 = x->length;
//    size_t l2 = y->length;
//
//    size_t minLen = l1 > l2 ? l2 : l1;
//    size_t maxLen = l1 > l2 ? l1 : l2;
//
//    int* min = l1 > l2 ? val2 : val1;
//    int* max = l1 > l2 ? val1 : val2;
//
//    int* temp;
//    int* sum;
//    int* res;
//
//    temp = malloc(sizeof(int) * ((l1 * l2) + 1));
////    sum = malloc(sizeof(int) * maxLen +1);
//    res = malloc(sizeof(int) * maxLen + 1);
//
//    int carry = 0;
//    int cur; //current digit from smaller number
//    size_t zeroCount = minLen-1; //number of zeros to append to temp array after storing multiplied digits
//
//    int k = 0;
//    for(int i = minLen-1; i >=0; i--){
//        cur = min[i];
//        for(int p = maxLen-1; p >= 0; p--){
//            temp[k++] = (cur*max[p] + carry)%10;
//            carry =  (int)floor((cur * max[p] + carry)/10);
////            printf("%d",carry);
//
//        }
//    }
//    temp[k++] = carry;
//
//    int j = 0;
//    while(j < zeroCount && k < (l1*l2+1)){
//        temp[k++] = 0;
//        j++;
//    }
//
//    int w = 0;
//
//    if(minLen == 1){
//        int g = 0;
//        while(g < maxLen+1){
//            res[w++] = temp[--k];
//            g++;
//        }
//    }
//    else {
//        for (int z = (l1 * l2)-1; z >= 0; z -= 2) {
//            if (z - 1 < 0) {
//                res[w++] = temp[z];
//            } else {
//                res[w++] = temp[z] + temp[z - 1];
//            }
//        }
//    }
//
//
//    int i = 0;
//    while(i < maxLen+1){
//       printf("%d",res[i]);
//       i++;
//   }
//}

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

//breaks for values 10000, 100, etc/
int main() {
    char *s = "15";
    char *p = "152";  //multiplication breaks for 0
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
    n = numAdd(r,w);

    numPrint(n,stdout);

//    numMultiply2(r,w);

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
