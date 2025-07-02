#include<stdio.h>
void main()
{
int arr[4][4],i=0,j=0,c=0;
printf("enter 16 elements");
for(i=0;i<4;i++){
  for(j=0;j<4;j++){
    scanf("%d",&arr[i][j]);
  }
}
printf("The matrix \n");
for(i=0;i<4;i++){
  for(j=0;j<4;j++){
    printf("%d\t",arr[i][j]);
    if(arr[i][j]!=0){
    c=c+1;}
  }
  printf("\n");
}

printf("\n");
printf("\n");


int arr2[c+1][3],k=1,l=0;
arr2[0][0]=4;
arr2[0][1]=4;
arr2[0][2]=c;
for(i=0;i<4;i++){
  for(j=0;j<4;j++){
    if(arr[i][j]!=0){
        arr2[k][0]=i;
        arr2[k][1]=j;
        arr2[k][2]=arr[i][j];
        k++;
      }
    }
  }

    
for(k=0;k<c+1;k++){
  for(l=0;l<3;l++){
    printf("%d\t",arr2[k][l]);
    
  }
  printf("\n");
}

}
