#include<stdio.h>
#include<math.h>
//addition...:
float add(float a, float b)
{
	float ans=0;
	int n;
    printf("enter the number of values for which you have to perform this operation");
    scanf("%d", &n);
    int i=0;
    if (n==2){
    	printf("enter the first value=");
    	scanf("%f", &a);
    	printf("enter the second value=");
    	scanf("%f", &b);
    	ans=a+b;
	}
	
	else {
		printf("enter the first value=");
		scanf("%f", &a);
		ans=a;
		for(i=1; i<=(n-1); i++){
		printf("enter the other number=");
		scanf("%f", &b);
		ans=ans+b;
		}
	}
	return ans;
}
//subtraction
float sub(float a, float b)
{
	float ans=0;
	int n;
    printf("enter the number of values for which you have to perform this operation");
    scanf("%d", &n);
    int i=0;
    if (n==2){
    	printf("enter the first value=");
    	scanf("%f", &a);
    	printf("enter the second value=");
    	scanf("%f", &b);
    	ans=a-b;
	}
	
	else {
		printf("enter the first value=");
		scanf("%f", &a);
		ans=a;
		for(i=1; i<=(n-1); i++){
		printf("enter the other number=");
		scanf("%f", &b);
		ans=ans-b;
		}
	}
	return ans;
}
//multipliction
float multiply(float a, float b)
{
	float ans=0;
	int n;
    printf("enter the number of values for which you have to perform this operation");
    scanf("%d", &n);
    int i=0;
    if (n==2){
    	printf("enter the first value=");
    	scanf("%f", &a);
    	printf("enter the second value=");
    	scanf("%f", &b);
    	ans=a*b;
	}
	
	else {
		printf("enter the first value=");
		scanf("%f", &a);
		ans=a;
		for(i=1; i<=(n-1); i++){
		printf("enter the other number=");
		scanf("%f", &b);
		ans=ans*b;
		}
	}
	return ans;
}
//Division
float div(float a, float b)
{
	float ans=0;
	int n;
    printf("enter the number of values for which you have to perform this operation");
    scanf("%d", &n);
    int i=0;
    if (n==2){
    	printf("enter the first value=");
    	scanf("%f", &a);
    	printf("enter the second value=");
    	scanf("%f", &b);
    	int i=0;
    	if (b==0){
    		printf("invalid");
		}
		else{
		ans=a/b;	
		}
	}
	
	else {
		printf("enter the first value=");
		scanf("%f", &a);
		ans=a;
		for(i=1; i<=(n-1); i++){
		printf("enter the other number=");
		scanf("%f", &b);
		if (b==0){
			printf("invalid");
		}
		else {
			ans=ans/b;
		}
		
		}
	}
	return ans;
}
//quadratic equation solving:
float quad(float a, float b, float c){
	float x1, x2;
	float bsqr,root;
	printf("enter the value of a= ");
	scanf("%f", &a);
	printf("enter the value of b= ");
	scanf("%f", &b);
	printf("enter the value of c= ");
	scanf("%f", &c);
	bsqr= b*b;
	root=sqrt(bsqr-(4*a*c));
	x1=(-(b)-(root))/(2*a);
	x2=(-(b)+(root))/(2*a);
	printf("%f\n", x1);
	printf("%f", x2);
	
}

int main(){
	int operation;
	float a=0, b=0;
	float ans;
	printf("1=add\n 2=subtract\n 3=multiplication\n 4=division");
	scanf("%d", &operation);
	switch(operation){
		case 1:
			ans=add(a,b);
			break;
		case 2:
			ans=sub(a,b);
			break;
		case 3:
			ans=multiply(a,b);
			break;
		case 4:
			ans=div(a,b);
			break;	
	}
	printf("%f", ans);
}

//



