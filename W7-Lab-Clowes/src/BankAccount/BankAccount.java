/**
 * BankAccount.java
 *
 * package that holds BankAccount Class
 */
package BankAccount;

/**
 * Bank Account
 *
 * A class that demonstrates information hiding and implementation hiding by simulating a bank account.
 */
public class BankAccount {
    private int accountNumber;
    private double balance;

    /**
     * Bank Account constructor
     * @param initialDeposit
     */
    public BankAccount(double initialDeposit) {
        if (initialDeposit < 0) {
            System.out.println("Invalid Deposit");
        }
        else {
            //create random account number
            int randomNumber = 11111111 + (int) (Math.random() * ((999999999 - 11111111) + 1));
            this.accountNumber = randomNumber;

            //add initial deposit to balance
            this.balance = initialDeposit;
        }

    }

    /**
     * method that allows user to make deposit into bank account
     * @param amount
     */
    public void deposit(double amount){
        if(amount < 0){
            System.out.println("Invalid Deposit");
        }
        else{
            System.out.printf("Deposited: $%.2f", amount);
            this.balance += amount;
            System.out.printf("\nAccount Balance is now: %.2f", getBalance());
        }
    }

    /**
     * method that allows user to withdraw from their bank account
     * @param amount
     */
    public void withdraw(double amount){
        if(amount < 0){
            System.out.println("Amount must be positive!");
        }
        if(amount > this.balance){
            System.out.println("Insufficient funds!");
        }
        else if(amount < this.balance && amount > 0) {
            System.out.printf("Withdrawn: $%.2f", amount);
            this.balance -= amount;
            System.out.printf("\nAccount Balance is now: $%.2f", getBalance());
        }
    }

    /**
     * Get method for the balance variable
     * @return balance
     */
    public double getBalance(){
        return balance;
    }

    /**
     * Get Function for account number
     * @return accountNumber
     */
    public int getAccountNumber(){
        return accountNumber;
    }






}
