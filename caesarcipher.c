
int main(){

char omsg[80];
char rmsg[80];
int shift;

printf("Enter message to be encrypted: ");
scanf("%s", omsg);
printf("Enter number to shift by (1-25): ");
scanf("%i", &shift);
if(shift>25||shift<1){printf("you broke it! \n"); return 1;}
int i;
for(i = 0; i < 80; i++){
	if(isupper(omsg[i])){
	rmsg[i] = ((omsg[i] - 'A') + shift)%26 + 'A';
	}else if(islower(omsg[i])){
	rmsg[i] = ((omsg[i] - 'a') + shift)%26 + 'a';
	}else{
	rmsg[i] = omsg[i];
	}
}

printf("Encrypted message: %s\n", rmsg);


return 0;
}
