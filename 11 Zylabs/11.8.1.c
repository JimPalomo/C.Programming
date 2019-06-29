#include <stdio.h>
#include <string.h>

typedef struct ItemInCart_struct{
    char name[50];
    int price;
    int quantity;
} ItemInCart;

ItemInCart MakeItem(char string[50]) {  

    ItemInCart item;  
    strcpy(item.name, string); 
    
    printf("Item: %s\n", item.name);
    printf("Enter the price: ");
    scanf("%d",&item.price);
    printf("\nEnter the quantity: ");
    scanf("%d", &item.quantity);
    printf("\n\n");
    
    return item; 
}

int PrintItemCost(ItemInCart item) {
    int itemCost;
    itemCost = item.quantity * item.price; 
    
    return itemCost;    
}

int main() {
   
    int total;
    
   
    ItemInCart firstItem = MakeItem("Pink Lady Apples");
    ItemInCart secondItem = MakeItem("Baby Carrots");
   
    printf("SHOPPING CART: \n");
    printf("%s: %d @ $%d = $%d\n", firstItem.name, firstItem.quantity, firstItem.price, PrintItemCost(firstItem));
    printf("%s: %d @ $%d = $%d\n", secondItem.name, secondItem.quantity, secondItem.price, PrintItemCost(secondItem));

    total = PrintItemCost(firstItem) + PrintItemCost(secondItem);  
        
    printf("\nTotal: $%d", total);
        

    return 0;
}
