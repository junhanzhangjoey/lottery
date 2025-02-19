#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
int generate(int n,int r, int p, int N){
  int randomN=0;
  int powerB=0;
  srand(time(NULL));
  for(int i=0;i<N;i++){
     for(int j=0;j<n;j++){
     	randomN=rand() % (r+1);
     	if(j==n-1){
	   if(p!=-1){
	      powerB=rand() % (p+1);
     	      printf("%d, Power Ball: %d\n",randomN,powerB);
	   }else{
	      printf("%d\n",randomN);
	   }
     	}else{
     	   printf("%d ,",randomN);
     	}
    }
  }
  return 0;
}

int main(int argc, char *argv[]){
  
  int opt;
  int NumbersToGenerate;
  int MaxNumber;
  int MaxPowerBallNumber=-1;
  int NumberSetsToGenerate;
  bool n,r,p,N;
  n=r=N=false;
  p=true;
  while((opt=getopt(argc,argv,"n:r:p:N:"))!=-1){
    switch(opt)
    {
      case 'n':
     	NumbersToGenerate=atoi(optarg);
     	if(NumbersToGenerate>0){
     	   n=true;
     	}
	break;
      case 'r':
      	MaxNumber=atoi(optarg); 
      	if(MaxNumber>0){
     	   r=true;
     	}
	break;
      case 'p':
      	MaxPowerBallNumber=atoi(optarg);
      	if(MaxPowerBallNumber<=0){
     	   p=false;
     	}
	break;
      case 'N':
      	NumberSetsToGenerate=atoi(optarg);
      	if(NumberSetsToGenerate>0){
     	   N=true;
     	}
	break;
      default:
      	break;
    }
  }
if(!(n&&r&&p&&N)){
   fprintf(stderr, "Input format is wrong\n");
   return 1;
} 
generate(NumbersToGenerate,MaxNumber,MaxPowerBallNumber,NumberSetsToGenerate);
return 0;
}
