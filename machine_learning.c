#include <stdlib.h>
#include <stdio.h>
#include <time.h>

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4}, 
    {3, 6},
    {4, 8},
};

float validate[][1] = {
    {0},
    {1},
    {2}, 
    {3},
    {4},
    {5},
    {6}
};

#define train_count sizeof(train)/sizeof(train[0])


float rand_float(void) {
    return (float)  rand() / (float) RAND_MAX;
}

float cost(float w, float b) {
    float result = 0.0f;
   	for(size_t i = 0; i < train_count; ++i){
        float x = train[i][0];
        float y = x*w + b;
        float d = y - train[i][1];
        result += d*d; 
        //printf("actual: %f, expected: %f\n", y, train[i][1]);
    }
    result /= train_count;
    return result;

}

int main()
{
    srand(time(0));
    float w = rand_float();

    float eps = 1e-3;
    float rate = 1e-3;
    float b = rand_float();

    for (size_t i = 0; i < 1000*1000; ++i) {
        float c = cost(w, b);
        float dcostw = (cost(w + eps, b) - c)/eps;
        float dcostb = (cost(w, b + eps) - c)/eps;
        w -= rate*dcostw;
        b -= rate*dcostb;
        printf("cost = %f, w = %f, b = %f\n", cost(w, b), w, b);
    }

    printf("/-----------------------------------/\n");
    printf("%f\n", w);

    for(size_t i = 0; i <= 4; ++i) {
        printf("%zu = %f\n", i, i * w);
    }

    printf("Try validate array\n");

    for(size_t i = 0; i <= 7; ++i){
        printf("%zu = %f\n", i, i*w);


    }

    
    return 0;

}
