void sine(){
	float a;
	char temp[100];
	sprintf(temp, "enter the value of a:");
	printCenteredText(temp);
	scanf("%f", &a );
	float ans;
	ans=sin(a);
	char output[50];
	printf("ans: %lf", ans);
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void cosine(){
	float a;
	char temp[100];
	sprintf(temp, "enter the value of a:");
	printCenteredText(temp);
	scanf("%f", &a);
	float ans;
	ans=cos(a);
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void tangent(){
	float a;
	char temp[100];
	sprintf(temp, "enter the value of a:");
	printCenteredText(temp);
	scanf("%f", &a );
	float ans;
	ans=tan(a);
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void secant(){
	float a;
	char temp[100];
	sprintf(temp, "enter the value of a:");
	printCenteredText(temp);
	scanf("%f", &a );
	float ans;
	ans=cos(a);
	ans=1/ans;
	
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void cosecant(){
	float a;
	char temp[100];
	sprintf(temp, "enter the value of a:");
	printCenteredText(temp);
	scanf("%f", &a );
	float ans;
	ans=sin(a);
	ans=1/ans;

    char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void cotangent(){
	float a;
	char temp[100];
	sprintf(temp, "enter the value of a:");
	printCenteredText(temp);
	scanf("%f", &a );
	float ans;
	ans=tan(a);
	ans=1/ans;
	
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void asine(){
	float a;
	char temp[100];
	sprintf(temp, "enter the value of a:");
	printCenteredText(temp);
	scanf("%f", &a );
	float ans;
	ans=asin(a);
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void acosine(){
	float a;
	char temp[100];
	sprintf(temp, "enter the value of a:");
	printCenteredText(temp);
	scanf("%f", &a );
	float ans;
	ans=acos(a);
	
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void atangent(){
	float a;
	char temp[100];
	sprintf(temp, "enter the value of a:");
	printCenteredText(temp);
	scanf("%f", &a );
	float ans;
	ans=atan(a);

	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}



/*void trig(){
	const char *menu =
      printf("1. sin\n2. cos\n3. tan\n4. "
      "sec\n5. cosec\n6. cot\n7.sin inverse\n8. cos inverse\n9. cot inverse ");
  printCenteredText(menu);
	int n;
    scanf("%d", &n);
    switch(n)
{
	case 1:
		sine();
	break;
	case2:
	    cosine();
	break;
	case 3:
	    tangent();
	break;	
	case 4:
	    secant();
	break;
	case 5:
	    cosecant();
	break;
	case 6:
	   cotangent();
	break;
	case 7:
	    asine();
	break;
	case 8:
	    acosine();
	break;
	case 9:
	    atangent();
	break;
}
}*/

