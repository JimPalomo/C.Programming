/*
          Davy's auto shop services
          Oil change -- $35
          Tire rotation -- $19
          Car wash -- $7
          Car wax -- $12

          Select first service:
          Tire rotation
          Select second service:
          -

          Davy's auto shop invoice

          Service 1: Tire rotation, $19
          Service 2: No service

          Total: $19
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char first_Service[50];
    char second_Service[50];

    
    int serviceCost1;
    int serviceCost2;
    
    // Prints available services
    printf("Davy's auto shop services\n");
    printf("Oil change -- $35\n");
    printf("Tire rotation -- $19\n");
    printf("Car wash -- $7\n");
    printf("Car wax -- $12\n\n");
    
    // User inputs two services 
    printf("Select first service:\n");
    scanf("%[^\n]%*c", first_Service);
    printf("Select second service:\n");
    scanf("%[^\n]%*c", second_Service);


    // Invoice calculations 1
    printf("\nDavy's auto shop invoice\n\n");
    if (strcmp(first_Service, "Oil change") == 0) {
        serviceCost1 = 35;
    }
    else if(strcmp(first_Service, "Tire rotation") == 0) {
        serviceCost1 = 19;
    }
    else if(strcmp(first_Service, "Car wash") == 0) {
        serviceCost1 = 7;
    }
    else if(strcmp(first_Service, "Car wax") == 0) {
        serviceCost1 = 12;
    }
    else if(strcmp(first_Service, "-") == 0) {
        serviceCost1 = 0;
    }

    // Invoice calculations 2
    if (strcmp(second_Service, "Oil change") == 0) {
        serviceCost2 = 35;
    }
    else if(strcmp(second_Service, "Tire rotation") == 0) {
        serviceCost2 = 19;
    }
    else if(strcmp(second_Service, "Car wash") == 0) {
        serviceCost2 = 7;
    }
    else if(strcmp(second_Service, "Car wax") == 0) {
        serviceCost2 = 12;
    }
    else if(strcmp(second_Service, "-") == 0) {
        serviceCost2 = 0;
    } 
    
   
   // Prints invoice
   if ((serviceCost1 != 0) && (serviceCost2 != 0)) {
      printf("Service 1: %s, $%d\n", first_Service, serviceCost1);
      printf("Service 2: %s, $%d\n\n", second_Service, serviceCost2);
      printf("Total: $%d\n", serviceCost1 + serviceCost2);
   }
   else if ((serviceCost1 != 0) && (serviceCost2 == 0)) {
      printf("Service 1: %s, $%d\n", first_Service, serviceCost1);
      printf("Service 2: No service\n\n");
      printf("Total: $%d\n", serviceCost1 + serviceCost2);
   }
   else if ((serviceCost1 == 0) && (serviceCost2 != 0)) {
      printf("Service 1: No service\n");
      printf("Service 2: %s, $%d\n\n", second_Service, serviceCost2);
      printf("Total: $%d\n", serviceCost1 + serviceCost2);
   } 
   else if ((serviceCost1 == 0) && (serviceCost2 == 0)) {
      printf("Service 1: No service\n");
      printf("Service 2: No service\n\n");
      printf("Total: $%d\n", serviceCost1 + serviceCost2);
   } 

    
    return 0;
}
