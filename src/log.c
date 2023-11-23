void ln(){
	float a;
	char temp[100];
	sprintf(temp, "enter the value of a:");
	printCenteredText(temp);
	printf("enter the value of a:");
	scanf("%f", &a );
	float ans;
	ans=log(a);
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void log10(){
	float a;
	char temp[100];
	sprintf(temp, "enter the value of a:");
	printCenteredText(temp);
	scanf("%f", &a );
	float ans;
	ans=log10(a);
	char output[50];
	
	sprintf(output,"%f", ans);
	printCenteredText(output);
}

