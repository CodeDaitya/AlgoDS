#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int *numbers;

long long max_pairwise_product(int );
long long max_pairwise_product_fast(int );

int main()
{
  int n;

  long long result1, result2;

  /*for(int i = 0;i<n;++i){
    scanf("%d", numbers+i);
  }*/

  while(1){
    n = rand()%4 + 2;
    numbers = (int*)malloc(sizeof(int)*n);

    printf("%d\n", n);

    for(int i = 0;i < n; i++){
      *(numbers + i) = rand()%10;
    }
    for(int i = 0;i < n; i++){
      printf("%d ", *(numbers + i));
    }
    printf("\n");

    result1 = max_pairwise_product(n);
    result2 = max_pairwise_product_fast(n);

    if(result1!=result2){
      printf("Warning: %lld %lld\n", result1, result2);
      break;
    }
    else
      printf("OK\n");
  }

  return 0;
}

long long max_pairwise_product(int n){
  long long result = 0;

  for(int i = 0;i<n;++i){
    for(int j;j<n;++j){
      if(i==j)continue;

      if((long long)(*(numbers + i))*(*(numbers + j))>result)
        result = (long long)(*(numbers + i))*(*(numbers + j));
    }
  }

  return result;
}

long long max_pairwise_product_fast(int n){
  long long result;

  int* num = numbers;
  int max_index1 = -1;
  for(int i = 0;i<n;++i){
   if(max_index1 == -1||(*numbers>*(num+max_index1)))
    max_index1 = i;
  }

  int max_index2 = -1;
  for(int i = 0;i<n;++i){
    if(max_index2!=max_index2&&(max_index2 == -1||*numbers>(*(num+max_index2))))
      max_index2 = i;
  }

  return (long long)*(numbers+max_index1)*(*(numbers+max_index2));
}
