#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int account_number;
    char name[MAX_NAME_LENGTH];
    float balance;
} account;

account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void add_account() {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Cannot add more accounts.\n");
        return;
    }

    account new_account;

    printf("Enter account number: ");
    scanf("%d", &new_account.account_number);

    printf("Enter name: ");
    scanf("%s", new_account.name);

    printf("Enter balance: ");
    scanf("%f", &new_account.balance);

    accounts[num_accounts] = new_account;
    num_accounts++;

    printf("Account added successfully.\n");
}

void display_account(account acc) {
    printf("Account number: %d\n", acc.account_number);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}

void display_all_accounts() {
    printf("Accounts:\n");

    for (int i = 0; i < num_accounts; i++) {
        printf("\n");
        display_account(accounts[i]);
    }
}

void deposit() {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            accounts[i].balance += amount;

            printf("Deposit successful.\n");
            return;
        }
    }

    printf("Account not found.\n");
}

void withdraw() {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > accounts[i].balance) {
                printf("Insufficient balance.\n");
                return;
            }

            accounts[i].balance -= amount;

            printf("Withdrawal successful.\n");
            return;
        }
    }

    printf("Account not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("Bank Management System\n");
        printf("======================\n");
        printf("1. Add account\n");
        printf("2. Display all accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                display_all_accounts();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
