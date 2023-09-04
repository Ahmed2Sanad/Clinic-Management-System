//**************************************** 
//*****   File:   func.c
//*****   Author: Ahmed Mohamed Sanad
//***** 
//*****   Created on 28 Aug, 2023
//****************************************




#include "func.h"
#include "STD_TYPES.h"

extern u16 ID;
extern u16 Ret_val;
extern u16 choise_nu;
extern u16 comp_rec;
u8 check[5]; 
extern u8 ret;
 u16 Loc_res_nu;
 u16 Lo_ID;	
 

u16 Choose_Mode(void)
{    u16 mode;
    printf("*****************************************************\n");
	printf("\t\tPlease choose the mode '-'");
	printf("\n*****************************************************\n");
	printf(" Enter 1-for Admin mode \n Enter 2-for User mode  \n");
	printf(" please Enter your Choise :");
	scanf("%hu",&mode);

	return mode;
}


u16 ADD_DATA(node *ptr_arr,u16 ID)
{   u16 Ret_val=0;
	u16 counter=ID;
	if(NULL ==ptr_arr)
	{
		
		Ret_val=0;
		
	}
	else
	{    
         
		while(ID==counter)
		{
		printf("\nPlease Enter patiant Name:");
		fflush(stdin);
		scanf("%[^\n]s",&ptr_arr[ID].name);
		printf("please Enter pataint Age:");
		scanf("%hu",&ptr_arr[ID].age);
		printf("Please Enter patiant Gender (Male or Female):");
		fflush(stdin);
		scanf("%[^\n]s",&ptr_arr[ID].gender);
		ptr_arr[ID].id=ID;
		counter++;
		
		}
		
		
         Ret_val = 1;
	
	}
	
	
	
	return Ret_val;
	
	
	
}

u16 check_ID(node *ptr_check , u16 ID)
{
	u8 counter=ID;
	for(counter;counter>0;counter--)
	{
		if(ID==ptr_check[counter].id)
		{
			printf("\n*****************************************************\n");
			printf("\n this procces rejected this ID used before \n");
		    printf("\n*****************************************************\n");
			return 0;
		}
		
		
		return 1;
		
	}
	
	
	
	
}


void Check_Add(node* arr)
{
	  if(choise_nu==1)		   
			    {
		           printf("please Enter ID to record the new data:");
			       scanf("%hu",&ID);
				   Ret_val=check_ID(arr,ID);
				   
				   while(Ret_val == 0 && comp_rec==0)
				   {

					   printf("please Enter another ID no one else used befor '-' :");
					   scanf("%hu",&ID);
				       Ret_val=check_ID(arr,ID);
                       if(Ret_val==0)
					   {
						   
					   printf("if U want to complete record patiant data please press 0 to stop press any number \n");
					   scanf("%hu",&comp_rec);
					   }
				   }
				   if(comp_rec!=0 && Ret_val==0)
				   {
					   
					   printf("thanks\n");   
				   }

				   else
				   {
			                Ret_val = ADD_DATA(arr,ID);
			                   if(Ret_val==0)
			                    {
				                    printf("there is NULL Poiter sent your record failed '~' /n");
			                    }
			                   else
			                    {
				                    printf("\n*****************************************************\n");
				                    printf("your record successfully done '-' \n");
									printf("your ID    :%hu\n",arr[ID].id);
									printf("your Name  :%s\n",arr[ID].name);
									printf("your Age   :%hu\n",arr[ID].age);
									printf("your Gender:%s\n",arr[ID].gender);
		                            printf("\n*****************************************************\n");
			                    }

			      }

		        }

}

void Edit_patient_rec(node *arr)
{
	u8 Loc_ID=0;
	u8 Ret_v=0;
	printf("Please Enter ID of your patient to Edit his record :");
	scanf("%hu",&Loc_ID);
	u8 counter=0;
	
	for(counter;counter<=Loc_ID;counter++)
	{
		
		if(Loc_ID == arr[counter].id)
		{
			
			printf("\n*****************************************************\n");
			printf("\t\tyour Old Data '-' \n");
			printf("your ID    :%hu\n",arr[counter].id);
			printf("your Name  :%s\n",arr[counter].name);
			printf("your Age   :%hu\n",arr[counter].age);
			printf("your Gender:%s\n",arr[counter].gender);
		    printf("\n*****************************************************\n");
			
			printf("\n*****************************************************");
			printf("\nPlease Enter your data to Edit the old one\n");
		    printf("*****************************************************\n");
			
			printf("Enter the Name:");
			fflush(stdin);
			scanf("%[^\n]s",&arr[Loc_ID].name);
			printf("Enter the Age:");
			scanf("%hu",&arr[Loc_ID].age);
			printf("Enter the Gender:");
			fflush(stdin);
			scanf("%[^\n]s",&arr[Loc_ID].gender);
			
			Ret_v=1;
			
			break;
		}
		
	
	}

	if(Ret_v==0)
	{
		printf("\n*****************************************************");
		printf("\nyour ID wrong the system not recognize it,Please try to regist before\n");
		printf("*****************************************************\n");
		
	}
	
	
	if(Ret_v==1)
	{
		printf("\n*****************************************************");
		    printf("your record successfully done '-' \n");
		    printf("\"your new data are\"\n");
			printf("your ID    :%hu\n",arr[Loc_ID].id);
			printf("your Name  :%s\n",arr[Loc_ID].name);
		    printf("your Age   :%hu\n",arr[Loc_ID].age);
			printf("your Gender:%s\n",arr[Loc_ID].gender);
		
		printf("*****************************************************\n");
	}
	
	
}


void Features(void)
{
	         printf("\n**********************************************************************\n");
		     printf("YOU have only 4 choises please Enter NO of your selection\n");
			 printf("1.Add new patient record '-'            2.Edit patient record '-'\n3.Reserve a slot with the doctor '.'    4. Cancel reservation '.'\n\n");
			 printf("Enter your choise:");
			 scanf("%hu",&choise_nu);
			 printf("\n**********************************************************************\n");
	
	        
	
}

void Reserve_slot(node *arr)
{           				
              u16 check1,check2,check3,check4,check5;
			  
		if(ret>0)
		{       u8 Loc_print=0;
			printf("Please choose the reservation number from the one available to you:\n");

				
			    if((strcmp(arr[1].res_doc,"2pm to 2:30"))&&(strcmp(arr[2].res_doc,"2pm to 2:30"))&&(strcmp(arr[3].res_doc,"2pm to 2:30"))&&(strcmp(arr[4].res_doc,"2pm to 2:30"))&&(strcmp(arr[5].res_doc,"2pm to 2:30")))
			    {
				    printf("1-> 2pm to 2:30pm\n");
			    }
			    if((strcmp(arr[1].res_doc,"2:30pm to 3pm"))&&(strcmp(arr[2].res_doc,"2:30pm to 3pm"))&&(strcmp(arr[3].res_doc,"2:30pm to 3pm"))&&(strcmp(arr[4].res_doc,"2:30pm to 3pm"))&&(strcmp(arr[5].res_doc,"2:30pm to 3pm")))
			    {
				    printf("2-> 2:30pm to 3pm\n");
			    }
			    if((strcmp(arr[1].res_doc,"3pm to 3:30pm"))&&(strcmp(arr[2].res_doc,"3pm to 3:30pm"))&&(strcmp(arr[3].res_doc,"3pm to 3:30pm"))&&(strcmp(arr[4].res_doc,"3pm to 3:30pm"))&&(strcmp(arr[5].res_doc,"3pm to 3:30pm")))
			    {
				    printf("3-> 3pm to 3:30pm\n");
			    }
			    if((strcmp(arr[1].res_doc,"4pm to 4:30pm"))&&(strcmp(arr[2].res_doc,"4pm to 4:30pm"))&&(strcmp(arr[3].res_doc,"4pm to 4:30pm"))&&(strcmp(arr[4].res_doc,"4pm to 4:30pm"))&&(strcmp(arr[5].res_doc,"4pm to 4:30pm")))
			    {
				    printf("4-> 4pm to 4:30pm\n");
			    }
			    if((strcmp(arr[1].res_doc,"4:30pm to 5pm"))&&(strcmp(arr[2].res_doc,"4:30pm to 5pm"))&&(strcmp(arr[3].res_doc,"4:30pm to 5pm"))&&(strcmp(arr[4].res_doc,"4:30pm to 5pm"))&&(strcmp(arr[5].res_doc,"4:30pm to 5pm")))
			    {
				    printf("5-> 4:30pm to 5pm\n");
			    }
				
                   printf("Please Enter ID of your patient to Reserve a slot with the doctor  :");
	               scanf("%hu",&Lo_ID);
	          
 			       printf("Enter the number of slot U want to reserve: ");
	               scanf("%hu",&Loc_res_nu);
				
				 if(1==Loc_res_nu)
			   {
			        strcpy(arr[Lo_ID].res_doc,"2pm to 2:30");
					Loc_print++;
			   }
			    else if(2==Loc_res_nu)
			   {
			         strcpy(arr[Lo_ID].res_doc,"2:30pm to 3pm");
					 Loc_print++;
			   }
			    else if(3==Loc_res_nu)
			   {
			        strcpy(arr[Lo_ID].res_doc,"3pm to 3:30pm");
					Loc_print++;
			   }
			    else if(4==Loc_res_nu)
			   {
			        strcpy(arr[Lo_ID].res_doc,"4pm to 4:30pm");
					Loc_print++;
			   }
			    else if(5==Loc_res_nu)
			   {
			        strcpy(arr[Lo_ID].res_doc,"4:30pm to 5pm");
					Loc_print++;
			   }
			   
			    if( 1==Loc_print)
			  {   
				 printf("\n*****************************************************\n");
				 printf("\t Your selection has been registered ");
			     printf("\n*****************************************************\n");

			  }
			  else
			  {
				    printf("\n*******************************************************************");
					printf("\n Incorrect nummber entered ,please try to enter number from 1 to 5 \n");
					printf("*********************************************************************\n");
				
				
		      }  
			
			
			
			
			
        }
			
			
}				


			
			


	
 
	
u16  First_reserve(node *arr)
{
	         u8 Loc_print=0;
	        if(ret==0)
			{
	           printf("\n*****************************************************\n");
			   printf("\t\t <the available slots are>\n");
			   printf("1-> 2pm to 2:30pm\n2-> 2:30pm to 3pm\n3-> 3pm to 3:30pm\n4-> 4pm to 4:30pm\n5-> 4:30pm to 5pm\n");
			   printf("\n*****************************************************\n");
			   
			   printf("Please Enter ID of your patient to Reserve a slot with the doctor  :");
	           scanf("%hu",&Lo_ID);
	          
 			   printf("Enter the number of slot U want to reserve: ");
	           scanf("%hu",&Loc_res_nu);
			   
		        
				
			   if(1==Loc_res_nu)
			   {
			        strcpy(arr[Lo_ID].res_doc,"2pm to 2:30");
					Loc_print++;
			   }
			    else if(2==Loc_res_nu)
			   {
			         strcpy(arr[Lo_ID].res_doc,"2:30pm to 3pm");
					 Loc_print++;
			   }
			    else if(3==Loc_res_nu)
			   {
			        strcpy(arr[Lo_ID].res_doc,"3pm to 3:30pm");
					Loc_print++;
			   }
			    else if(4==Loc_res_nu)
			   {
			        strcpy(arr[Lo_ID].res_doc,"4pm to 4:30pm");
					Loc_print++;
			   }
			    else if(5==Loc_res_nu)
			   {
			        strcpy(arr[Lo_ID].res_doc,"4:30pm to 5pm");
					Loc_print++;
			   }
			   /*if(5>Lo_ID>20)
			   {
				   printf("please Enter number from 1 to 5 \n");
				  
			   }*/
			   
			  if( 1==Loc_print)
			  {   
				 printf("\n*****************************************************\n");
				 printf("\t Your selection has been registered ");
			     printf("\n*****************************************************\n");

			  }
			  else
			  {
				    printf("\n*******************************************************************");
					printf("\n Incorrect nummber entered ,please try to enter number from 1 to 5 \n");
					printf("*********************************************************************\n");
				
			  }
			   ret++;

			}
	
	     return ret;
	
}

void Cancel_reserve(node*arr)
{
	u16 Canc_ID;
	printf("please enter patient ID to cancel reservation:");
	scanf("%hu",&Canc_ID);
	
	
	
	  strcpy((arr[Canc_ID].res_doc)," Reservation cancelled");
	 while(1<=Canc_ID<=5)
	 {		 
	  if((strcmp((arr[Canc_ID].res_doc)," Reservation cancelled")) == 0)
	  {
		  
	    printf("\n*******************************************************************");
		printf("\nYour Reservation successfully cancelled");
	    printf("\n*******************************************************************\n");

		  
		  
	  }
	 }
	  
	  if(Canc_ID>5 && 1>Canc_ID)
	  {
		printf("\n*******************************************************************");
		printf("\nyou have a prolem your ID is wrong or You entered an invalid number\n");
		printf("\nPlease check your ID & Number of your reservation\n");
	    printf("\n*******************************************************************\n");
	  }
	
	
}
void Patient_Record( node *arr_View )
{             u16 pat_id;
	  printf("\n----------------------------------------------------------");
	  printf("\n\t\t \"view patient record\" ");
	  printf("\n----------------------------------------------------------\n");
	
	   printf("\n\nplease Enter patient ID: ");
	   scanf("%hu",&pat_id);
	   
	   
	        printf("your ID    :%hu\n",arr_View[pat_id].id);
			printf("your Name  :%s\n",arr_View[pat_id].name);
		    printf("your Age   :%hu\n",arr_View[pat_id].age);
			printf("your Gender:%s\n",arr_View[pat_id].gender);
	 
	
}
u16 User_Mode_choose(void)
{     
      u16 Us_mode;
	printf("\n----------------------------------------------------------\n");
	printf("\t\tChoose 1-> User mode\n2-> EXIT\n");
	printf("\n----------------------------------------------------------");
     printf("\nEnter the number:");
	 scanf("%hu",&Us_mode);
	 
	 return Us_mode;
}
void Reserv_view( node *Reserv)
{
	 printf("\n----------------------------------------------------------");
	 printf("\t \"All Reservations for today are:\"\n" );
	 printf("\n----------------------------------------------------------");
   for(u16 i=0;i<20;i++)
   {  
	  printf("%s\n",Reserv[i].res_doc);
	 
   }
       printf("\n----------------------------------------------------------");
	   printf("\n\t\t \"The available one\" \n ");
	   printf("\n----------------------------------------------------------");
	    if((strcmp(Reserv[1].res_doc,"2pm to 2:30"))&&(strcmp(Reserv[2].res_doc,"2pm to 2:30"))&&(strcmp(Reserv[3].res_doc,"2pm to 2:30"))&&(strcmp(Reserv[4].res_doc,"2pm to 2:30"))&&(strcmp(Reserv[5].res_doc,"2pm to 2:30")))
	    {
		    printf("1-> 2pm to 2:30pm\n");
	    }
	    if((strcmp(Reserv[1].res_doc,"2:30pm to 3pm"))&&(strcmp(Reserv[2].res_doc,"2:30pm to 3pm"))&&(strcmp(Reserv[3].res_doc,"2:30pm to 3pm"))&&(strcmp(Reserv[4].res_doc,"2:30pm to 3pm"))&&(strcmp(Reserv[5].res_doc,"2:30pm to 3pm")))
	    {
		    printf("2-> 2:30pm to 3pm\n");
	    }
	    if((strcmp(Reserv[1].res_doc,"3pm to 3:30pm"))&&(strcmp(Reserv[2].res_doc,"3pm to 3:30pm"))&&(strcmp(Reserv[3].res_doc,"3pm to 3:30pm"))&&(strcmp(Reserv[4].res_doc,"3pm to 3:30pm"))&&(strcmp(Reserv[5].res_doc,"3pm to 3:30pm")))
	    {
		    printf("3-> 3pm to 3:30pm\n");
	    }
	    if((strcmp(Reserv[1].res_doc,"4pm to 4:30pm"))&&(strcmp(Reserv[2].res_doc,"4pm to 4:30pm"))&&(strcmp(Reserv[3].res_doc,"4pm to 4:30pm"))&&(strcmp(Reserv[4].res_doc,"4pm to 4:30pm"))&&(strcmp(Reserv[5].res_doc,"4pm to 4:30pm")))
	    {
		    printf("4-> 4pm to 4:30pm\n");
	    }
	    if((strcmp(Reserv[1].res_doc,"4:30pm to 5pm"))&&(strcmp(Reserv[2].res_doc,"4:30pm to 5pm"))&&(strcmp(Reserv[3].res_doc,"4:30pm to 5pm"))&&(strcmp(Reserv[4].res_doc,"4:30pm to 5pm"))&&(strcmp(Reserv[5].res_doc,"4:30pm to 5pm")))
	    {
		    printf("5-> 4:30pm to 5pm\n");
	    }
	
	
}



