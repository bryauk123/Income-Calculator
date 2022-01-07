//
//  Income Calculator.
//
//  Created by Bryan Apodaca on 7/25/20.
//  Copyright © 2020 Bryan Apodaca. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee
{
    char name[20];
    float hours;
    float rate;
};

float taxes(float *gross)
{
    float taxes = *gross * .2;
    return taxes;
}

float grossPay(struct employee* emp)
{
    float grossPay = 0;
    if (emp->hours > 40)
    {
        grossPay = (emp->hours * emp->rate) + ((emp->hours - 40) * (emp->rate * 1.5));
    }
    else if(emp->hours <= 40)
    {
        grossPay = (emp->hours * emp->rate);
    }
    return grossPay;
}

float basePay(struct employee* emp)
{
    float basePay = emp->hours * emp->rate;
    return basePay;
}

float overTime(struct employee* emp)
{
    float overtime = 0;
    if (emp->hours > 40)
    {
        overtime = (emp->hours - 40) * (emp->rate * 1.5);
    }
    else if(emp->hours < 40)
    {
        overtime = 0;
    }
    return overtime;
}

void calculate(struct employee* emp) //gross pay,base and overtime
{
    if(strcmp(emp->name,"-1") != 0 && emp->hours > 0 && emp->rate > 0)
        {
        float gross = grossPay(emp);
        float tax = taxes(&gross);
        printf("-----------------------------------\n");
            printf("This is how much %s made: \n",emp->name);
        printf("Overtime pay: $%.2f\n",overTime(emp));
        printf("Gross pay: $%.2f\n",grossPay(emp));
        printf("Base pay: $%.2f\n",basePay(emp));
        printf("Taxes owed is $%.2f\n",tax);
        printf("Net pay: $%.2f\n",gross - tax);
        }
}

struct employee getInfo(struct employee *emp) // promps for info
{
    
    puts("Enter name of Employee:");
    scanf(" %s",emp->name);
    if(strcmp(emp->name,"-1") == 0)
    {
        return *emp;
    }
    puts("Enter number of hours worked for employee:");
    scanf(" %f",&emp->hours);
    if(emp->hours == -1)
        return *emp;
    puts("Finally, put the hourly rate of employee:");
    scanf(" %f",&emp->rate);
    if(emp->rate == -1)
        return *emp;
    
    return *emp;
}

int main()
{
    int input;
    int index;
    int x = 0;
    char userAnswer[10];
    struct employee employee[5];
    for (int i = 1; i < 6 ; i++)
    {
    getInfo(&employee[i]);
        if(strcmp(employee[i].name,"-1") == 0 || employee[i].hours == -1 || employee[i].rate == -1)
        {
            break;
        }
    }
    while( x == 0)
    {
    printf("Menu:\n 1)Print Employee\n 2)Print All Employees\n 3)Edit An Employee\n 4)Exit Program");
    scanf("%d",&input);
    
    switch(input)
    {
        case 1:
        puts("Which employee would you like to print?\n");
            scanf("%d",&index);
            calculate(&employee[index]);
            continue;
        case 2:
            puts("Data For All Employees In System:\n");
            float total = 0;
            for(int i = 1; i < 6; i ++)
            {
                calculate(&employee[i]);
                total += grossPay(&employee[i]);
            }
            printf("Total Pay For All Employees is: $%.2f\n",total);
            
            continue;
        case 3:
            puts("Which Employee would you like to edit?\n");
            scanf("%d",&index);
            printf("Name: %s\nHours: %.2f\nRate: $%.2f\n",employee[index].name,employee[index].hours,employee[index].rate);
            printf("What would you like to edit about %s? The NAME, HOURS worked or hourly RATE?\n",employee[index].name);
            scanf("%s",&userAnswer);
            if(strcmp(userAnswer,"NAME") == 0 || strcmp(userAnswer,"name") == 0 || strcmp(userAnswer,"Name") == 0)
            {
                puts("Okay, what name would you like to change it to?\n");
                scanf("%s",&employee[index].name);
            }
            else if(strcmp(userAnswer,"HOURS") == 0 || strcmp(userAnswer,"hours") == 0 || strcmp(userAnswer,"Hours") == 0)
            {
                puts("Okay, what hours would you like to change it to?\n");
                scanf("%f",&employee[index].hours);
            }
            else if(strcmp(userAnswer,"RATE") == 0 || strcmp(userAnswer,"rate") == 0 || strcmp(userAnswer,"Rate") == 0)
            {
                puts("Okay, what rate would you like to change it to?\n");
                scanf("%f",&employee[index].rate);
            }
            continue;
        case 4:
            exit(0);
            
    }
}
    
    return 0;
}
