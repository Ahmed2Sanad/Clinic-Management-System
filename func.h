//***************************************** 
//*****   File:   func.h
//*****   Author: Ahmed Mohamed Sanad
//***** 
//*****   Created on 28 Aug, 2023
//*****************************************




#ifndef _H_FUNC_H_H
#define _H_FUNC_H_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "STD_TYPES.h"

typedef struct NODE_t node;
struct NODE_t
{
	
	u8 name[50];
    u16 age;
	u8 gender[10];
	u16 id;
	u8 res_doc[200];
	
		
};
u16 Choose_Mode(void);



void Features( void );
u16 ADD_DATA( node *ptr_arr , u16 ID );
u16 check_ID( node *ptr_check , u16 ID );
void Check_Add( node* arr );
void Edit_patient_rec( node *arr );
void Reserve_slot( node *arr); 
u16  First_reserve( node *arr );
void Cancel_reserve( node *arr );
void Patient_Record( node* );
u16 User_Mode_choose(void);
void Reserv_view( node *Reserv);



#endif