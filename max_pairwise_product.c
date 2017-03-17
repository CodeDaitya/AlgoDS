#include<stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int *numbers;
  int max_pairwise_prod=0;

  for(int i = 0;i<n;++i){
    scanf("%d", numbers+i);
  }

  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      if(i==j)continue;

      if(*(numbers+i)*(*(numbers+j))>max_pairwise_prod)
        max_pairwise_prod = *(numbers+i)*(*(numbers+j));
    }
	}
  printf("%d\n", max_pairwise_prod);
  
  return 0;
}
