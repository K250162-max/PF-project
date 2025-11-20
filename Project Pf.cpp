#include<stdio.h>
#include<string.h>

#define maxvoters 100
#define provinces 4
#define candidates 4
int registration(int cnic_array[],char name[100],int votercount){
	int cnic,i,age;
	printf("Enter your Name: ");
	scanf("%s",name);
	
	printf("\nEnter your CNIC: ");
	scanf("%d",&cnic);
	
	for(i=0;i<votercount;i++){
		if(cnic_array[i]==cnic){
			printf("\nCnic Repeated Vote already casted\n");
			return 0;
		}
	}
	cnic_array[votercount]=cnic;
	printf("\nEnter your age: ");
	scanf("%d",&age);
	if(age<18){
		printf("\nNot eligible to vote");
		return 0;
	}
	printf("\n  Registration successfull  \n");
	return age;
}
void voting(int votes[provinces][candidates]){
	
	char candidatenames[provinces][candidates][20]={
	    {"Ali", "Mohammad", "Farooq", "Zaid"},         // Sindh
        {"Fahad", "Usman", "Rayyan", "Tamim"},         // Punjab
        {"John", "Will", "Imran", "Kamran"},           // Balochistan
        {"Saad", "Tariq", "Rehan", "Naveed"}           // kpk
	};
	char provincenames[provinces][20]={"Sindh", "Punjab", "Balochistan", "KPK"};
	
	int province,candidate,i;
	char confirm;
	
	printf("\nEnter your province: ");
	for(i=0;i<provinces;i++){
		printf("%d:%s ",i+1,provincenames[i]);
	}
	scanf("%d",&province);
	if(province<1 || province>provinces){
		printf("\nInvalid input\n");
		return;
	}
	printf("Candidates in %s: \n",provincenames[province-1]);
	for(i=0;i<candidates;i++){
		printf("%d:%s\n",i+1,candidatenames[province-1][i]);
	}
	scanf("%d",&candidate);
	if(candidate<1 || candidate>candidates){
		printf("Invalid input");
		return;
	}
	printf("Are you sure you want to vote to %s (y/n): ",candidatenames[province-1][candidate-1]);
	scanf(" %c",&confirm);
	if (confirm!='y' && confirm!='Y') {
        printf("Vote cancelled.\n");
        return;
    }
    votes[province-1][candidate-1]++;
    printf("Vote casted successfully");
	}
	void showresult(int votes[provinces][candidates]){
		char candidatenames[provinces][candidates][20]={
	    {"Ali", "Mohammad", "Farooq", "Zaid"},         // Sindh
        {"Fahad", "Usman", "Rayyan", "Tamim"},         // Punjab
        {"John", "Will", "Imran", "Kamran"},           // Balochistan
        {"Saad", "Tariq", "Rehan", "Naveed"}           // kpk
	};
	char provincenames[provinces][20]={"Sindh", "Punjab", "Balochistan", "KPK"};
	int i,j;
	printf("\n      ELECTION RESULTS     \n");
		for(i=0;i<provinces;i++){
			printf("\n%s:\n",provincenames[i]);
			for(j=0;j<candidates;j++){
				printf("%s : %d votes",candidatenames[i][j],votes[i][j]);
			}
		}
	}
int main(){
	int cnic_array[maxvoters];
	char name[100];
	int votercount=0;
	int age;
	int votes[provinces][candidates]={0};
	char again;

	do {
	    age = registration(cnic_array,name,votercount);
	    if (age > 0) {
	        votercount++;
	        printf("Voter: %s, age: %d, is registered.\n", name, age);
	        voting(votes);
	    }
	    printf("\nIs there another person who wants to vote? (y/n): ");
	    scanf(" %c",&again);
	} while(again=='y' || again=='Y');

	showresult(votes);
	return 0;
}
