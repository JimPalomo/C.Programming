/*
    Not Finished
*/

#include<stdio.h>
#include <string.h>

struct ItemInCart{
    char* name;
    int price;
    int quantity;
};

struct ItemInCart MakeItem(char* string) {  

    struct ItemInCart item;   // Creates a variable for ItemInCart by calling ItemInCart struct
    item.name = string;       // Sets variable name (from struct) to string
    
    printf("Item: %s\n", item.name);
    printf("Enter the price: ");
    scanf("%d",&item.price);
    printf("\nEnter the quantity: ");
    scanf("%d", &item.quantity);
    printf("\n\n");
    
    return item; 

}

int PrintItemCost(struct ItemInCart item) {
    int itemCost = item.quantity * item.price; 
   
    printf("%s: %d @ $%d = $%d\n", item.name, item.quantity, item.price, itemCost );
    
    return itemCost;    
    
}

int main() {
   
    int total;
    
   
    struct ItemInCart firstItem = MakeItem("Pink Lady Apples");
    struct ItemInCart secondItem = MakeItem("Baby Carrots");
   
    printf("SHOPPING CART: \n");
    total = PrintItemCost(firstItem) + PrintItemCost(secondItem);  
        
    printf("\nTotal: $%d", total);
        
        
        return 0;
}
