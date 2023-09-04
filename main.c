//***************************************** 
//*****   File:   main.c
//*****   Author: Ahmed Mohamed Sanad
//***** 
//*****   Created on 28 Aug, 2023
//*****************************************



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"


node arr[20];

u8 ret_mod;

u16 ID;
u16 Ret_val;
u16 choise_nu;
u16 comp_rec;
u8 ret=0;
u16 U_M=0;
int main()
{
    printf("\n\n\n\n\n");
    printf("#######################################################\n");
    printf("########      Welcome to Our Clinic '-'      ##########\n");
    printf("#######################################################\n");
    
    
    
      printf("\n\n");
	  
       ret_mod = Choose_Mode();

       if(1 == ret_mod)
	   {    u8 trial_num=3;
            u16 get_pass=0;
		 printf("\n*****************************************************\n");
		 printf("\t\tyou try to register as admin'^'\n");  
	     printf("\tplease Enter your Passward to get permission'-'\n ");
		  printf("*****************************************************"); 
		  while(get_pass !=123 && trial_num>0)
		   {
		      printf("\n you have %d- trial to give me the correct pass: ",(trial_num--));
		      scanf("%hu",&get_pass);
		   
		   
		   }
		   if(get_pass!= 123)
		   {
			   
			   printf("\t you are not the admin go away ****\n");
			   printf("\t try to enter as an user :");
		   }
		   else
		   {
		         u16 admin_ch=1;
               
			   while(admin_ch==1)
				{
					Features();
					
					if(1==choise_nu)
			        {
		           Check_Add( arr);

				    }
				 else if(2==choise_nu)
				    {				 
					  Edit_patient_rec(arr);
				    }				 
					else if(3==choise_nu)
					{
						if(ret==0)
						{
							ret=First_reserve(arr);
						}
						else
						{
						
	       					Reserve_slot(arr);
							
						}
					}
					else if(4==choise_nu)
					{
							
						Cancel_reserve(arr);
					}
				     
                      printf("DO you want to continue in admin mode");
					  printf("\"if yes press 1 \" \n\"else press 0 \"");
				      scanf("%hu",&admin_ch);
				}

                
		           
		    } 
			  U_M=User_Mode_choose();
	   }
	   if(2 == ret_mod || 1==U_M )
	   {    
              u8 con_us_m=1;
            while(con_us_m==1)
			{
                u16 cho_n=0;
		      printf("\n------------------------------------------------------\n");
		      printf("\t\t \"welcome in User Mode\"\n\t\t please let me help you ");
		      printf("\n------------------------------------------------------\n");
			  
			  printf("\n----------------------------------------------------------\n");
			  printf("\tPlease choose one of the services available to you");
			  printf("\n----------------------------------------------------------");
			  
			  printf("\n\t\t1-> View patient record '^'  \"\" ");
			  printf("\n\t\t2-> View today's reservations '-'  \"\" ");
              printf("\n\t\tEnter the number:");
              scanf("%hu",&cho_n);			  
	   
	          if(1 == cho_n)
			  {
				 Patient_Record( arr );
				 
			  }
			  else if(2 == cho_n)
			  {
 				  
				  Reserv_view( arr );
                 				  
			  } 
            

			          printf("DO you want to continue in User Mode");
					  printf("\"if yes press 1 \" \n to \"EXIT\" press any number : \"");
				      scanf("%hu",&con_us_m);

			}
	  
              

	  }
 
}