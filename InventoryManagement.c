#include <stdio.h> 
#include <string.h> 
#define MAX 100 
typedef struct { 
int itemID; 
char itemName[50]; 
int quantity; 
int expiryDate; 
} Item; 
Item stockStack[MAX];   
int top = -1;   
void insertItem(int id, char name[], int quantity, int expiry) { 
if (top >= MAX - 1) {   
printf("Inventory is full! Cannot add more items.\n"); 
} else { 
top++;   
stockStack[top].itemID = id;   
strcpy(stockStack[top].itemName, name); 
stockStack[top].quantity = quantity; 
        stockStack[top].expiryDate = expiry; 
        printf("Item added successfully.\n"); 
    } 
} 
 
 
void discardItem() { 
    if (top == -1) {   
        printf("No items to discard, inventory is empty.\n"); 
    } else { 
        printf("Discarding item: %s (ID: %d)\n", stockStack[top].itemName, 
stockStack[top].itemID); 
        top--;  
    } 
} 
 
 
void removeExpiredItems(int currentDate) { 
    int removedCount = 0;  
    printf("\nRemoving expired items:\n"); 
     
    for (int i = top; i >= 0; i--) {   
        if (stockStack[i].expiryDate < currentDate) {   
            printf("Removing expired item: %s (ID: %d)\n", stockStack[i].itemName, 
stockStack[i].itemID); 
            removedCount++;  
             
            for (int j = i; j < top; j++) { 
                stockStack[j] = stockStack[j + 1]; 
            } 
            top--;   
        } 
    } 
 
    if (removedCount == 0) { 
        printf("No expired items found.\n");   
    } else { 
        printf("Total expired items removed: %d\n", removedCount);  
    } 
} 
 
 
void inspectLatestStock() { 
    if (top == -1) {  
        printf("Inventory is empty.\n"); 
    } else { 
        printf("Most recent item in stock: %s (ID: %d, Quantity: %d, Expiry Date: %d)\n", 
               stockStack[top].itemName, stockStack[top].itemID, 
               stockStack[top].quantity, stockStack[top].expiryDate); 
    } 
} 
 
 
void displayAllItems() { 
    if (top == -1) {   
        printf("Inventory is empty.\n"); 
    } else { 
        printf("\nInventory List:\n"); 
        for (int i = 0; i <= top; i++) {   
            printf("ID: %d, Name: %s, Quantity: %d, Expiry Date: %d\n", 
                   stockStack[i].itemID, stockStack[i].itemName, 
                   stockStack[i].quantity, stockStack[i].expiryDate); 
        } 
    } 
} 
 
 
void listOfExpiryItems(int currentDate) { 
    int expiredCount = 0;   
    printf("\nExpired Items:\n"); 
    for (int i = 0; i <= top; i++) {   
        if (stockStack[i].expiryDate < currentDate) {   
            printf("ID: %d, Name: %s, Quantity: %d, Expiry Date: %d\n", 
                   stockStack[i].itemID, stockStack[i].itemName, 
                   stockStack[i].quantity, stockStack[i].expiryDate); 
            expiredCount++;   
        } 
    } 
     
    if (expiredCount == 0) { 
        printf("No expired items found.\n");   
        return;   
    } 
 
     
    char choice; 
    printf("Do you want to remove these expired items? (y/n): "); 
    scanf(" %c", &choice);  
 
    if (choice == 'y' || choice == 'Y') { 
        removeExpiredItems(currentDate);   
    } else { 
        printf("Expired items will not be removed.\n"); 
    } 
} 
 
 
int main() { 
    int choice, id, quantity, expiry, currentDate; 
    char name[50]; 
     
    do { 
        printf("\nInventory Management System\n"); 
        printf("1. Insert Item\n"); 
        printf("2. Discard Item\n"); 
        printf("3. List Expired Items\n"); 
        printf("4. Inspect Latest Stock\n"); 
        printf("5. Display All Items\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter item ID: "); 
                scanf("%d", &id); 
                printf("Enter item name: "); 
                scanf("%s", name); 
                printf("Enter quantity: "); 
                scanf("%d", &quantity); 
                printf("Enter expiry date (YYYYMMDD): "); 
                scanf("%d", &expiry); 
                insertItem(id, name, quantity, expiry); 
                break; 
             
            case 2: 
                discardItem(); 
                break; 
 
            case 3: 
                printf("Enter current date (YYYYMMDD): "); 
                scanf("%d", &currentDate); 
                listOfExpiryItems(currentDate); 
                break; 
 
            case 4: 
                inspectLatestStock(); 
                break; 
 
            case 5: 
                displayAllItems(); 
                break; 
 
            case 6: 
                printf("Exiting the program.\n"); 
                break; 
 
            default: 
                printf("Invalid choice! Please enter a valid option.\n"); 
        } 
    } while (choice != 6); 
 
    return 0; 
} 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
