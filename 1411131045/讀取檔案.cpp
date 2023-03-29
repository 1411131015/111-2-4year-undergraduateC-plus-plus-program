#include <stdio.h>

// clientData structure definition               
struct clientData {                              
   unsigned int StuNum;
          char Name[20];
          int math;
		  int computer;
          double average;
};             
 
typedef struct clientData CLIENT;

int main(void) 
{ 
   FILE *cfPtr; // accounts.dat file pointer  1.�إ�(�ŧi)�ɮ׫���
	unsigned int i;
   // fopen opens the file; exits if file cannot be opened
   if ((cfPtr = fopen("accounts.dat", "rb+")) == NULL) {   //2.�}���ɮ�(�Q��fopen()���) 
      puts("File could not be opened.");					//// "r"=read(Ū��)�Ҧ�, "b"=binary(�H���s����) "+"�ק��ɮפ��e 
   } 
   else { 
      
	  // create clientData with default information
      CLIENT client = {0, "", 0,0, 0.0}, blankClient={0, "", 0,0, 0.0};
      
      
      
	  for (i = 1; i <= 100; ++i) {                                   
         fwrite(&blankClient, sizeof(struct clientData), 1, cfPtr);  //3.�s���ɮ� fwrite()�N�@��(���c��)��Ƽg�J�ɮ� 
      }             // �C�@��������37bytes,  �ɮפ@�@��100x37=3700bytes ~4K bytes  
      // require user to specify account number
      
      
      
      
      
      printf("%s", "Enter Student number"
         " (1 to 100, 0 to end input): ");
      scanf("%d", &client.StuNum);

      // user enters information, which is copied into file
      while (client.StuNum != 0) { 
         // user enters last name, first name and balance
         printf("%s", "Enter Student Name: ");
        scanf("%s",client.Name);
		printf("%s", "Enter Math score: ");
        scanf("%d",&client.math);
        printf("%s", "Enter Computer score: ");
        scanf("%d",&client.computer);
        client.average=(double(client.math)+client.computer)/2;
         // seek position in file to user-specified record   
         fseek(cfPtr, (client.StuNum - 1) *               //�����ɮ׫��Ш�ت��a���O�����}�W��   
            sizeof(struct clientData), SEEK_SET);         

         // write user-specified information in file              
         fwrite(&client, sizeof(struct clientData), 1, cfPtr);//3.�s���ɮ� fwrite()�N�@��(���c��)��Ƽg�J�ɮ�
																		 // �C�@��������37bytes
         // enable user to input another account number
         printf("%s", "Enter Student number: ");
         scanf("%d", &client.StuNum);
      } 
      
    
      fclose(cfPtr); // fclose closes the file     4.�����ɮ�  
   } 
   
   
   
   
   
   
   
   // fopen opens the file; exits if file cannot be opened
   if ((cfPtr = fopen("accounts.dat", "rb")) == NULL) {
      puts("File could not be opened.");
   } 
   else { 
      printf("%s%10s%11s%11s%10s\n", "Number", "Name",
         "Math", "Computer","average");

      // read all records from file (until eof)
      while (!feof(cfPtr)) { 
         // create clientData with default information
         struct clientData client = {0, "", 0,0, 0.0};

         int result = fread(&client, sizeof(struct clientData), 1, cfPtr);

         // display record
         if (client.StuNum != 0) {   //�L�XŪ���ӵ�(���c)��ƪ����G 
            printf("%4d%12s%10d%10d%11.2f\n", 
               client.StuNum, client.Name, 
               client.math, client.computer,client.average);
         } 
      } 

      fclose(cfPtr); // fclose closes the file
   } 
   
   
   
   
   
   
} 
