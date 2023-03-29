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
   FILE *cfPtr; // accounts.dat file pointer  1.建立(宣告)檔案指標
	unsigned int i;
   // fopen opens the file; exits if file cannot be opened
   if ((cfPtr = fopen("accounts.dat", "rb+")) == NULL) {   //2.開啟檔案(利用fopen()函數) 
      puts("File could not be opened.");					//// "r"=read(讀取)模式, "b"=binary(隨機存取檔) "+"修改檔案內容 
   } 
   else { 
      
	  // create clientData with default information
      CLIENT client = {0, "", 0,0, 0.0}, blankClient={0, "", 0,0, 0.0};
      
      
      
	  for (i = 1; i <= 100; ++i) {                                   
         fwrite(&blankClient, sizeof(struct clientData), 1, cfPtr);  //3.存取檔案 fwrite()將一筆(結構的)資料寫入檔案 
      }             // 每一筆紀錄佔37bytes,  檔案一共佔100x37=3700bytes ~4K bytes  
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
         fseek(cfPtr, (client.StuNum - 1) *               //移動檔案指標到目的地的記憶體位址上方   
            sizeof(struct clientData), SEEK_SET);         

         // write user-specified information in file              
         fwrite(&client, sizeof(struct clientData), 1, cfPtr);//3.存取檔案 fwrite()將一筆(結構的)資料寫入檔案
																		 // 每一筆紀錄佔37bytes
         // enable user to input another account number
         printf("%s", "Enter Student number: ");
         scanf("%d", &client.StuNum);
      } 
      
    
      fclose(cfPtr); // fclose closes the file     4.關閉檔案  
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
         if (client.StuNum != 0) {   //印出讀取該筆(結構)資料的結果 
            printf("%4d%12s%10d%10d%11.2f\n", 
               client.StuNum, client.Name, 
               client.math, client.computer,client.average);
         } 
      } 

      fclose(cfPtr); // fclose closes the file
   } 
   
   
   
   
   
   
} 
