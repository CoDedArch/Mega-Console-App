#ifndef EMPLOYEES_H

#define EMPLOYEES_H
#include <iostream>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>
#include <climits>

/*
A class of Employees and A sub Class of Administrator position Who inherits instances and methods from the super class Employees
*/
class Employees
{
  /*Instances of the Employee*/
private:
  std::string firstName;
  std::string lastName;
  std::string surName;
  std::string age;
  std::string gender;
  std::string position;
  std::string address;
  std::string emailAddress;
  std::string firstPassword;
  std::string ConfirmPassword;
  std::string EnterPassword;

  int employeeSalary{}; 
  long long int companyMoney = 10000000000;


public:
  /*Methods of the Employee*/
  void SetFirstName();
  
  std::string GetFirstName();
  
  void SetLastName();
  
  std::string GetLastName();
  
  void SetSurName();
  
  std::string GetSurName();
  
  void SetAge();
  
  std::string GetAge();
  

  void SetGender();
  

  std::string GetGender();
  

  void SetPosition();
  

  std::string GetPosition();
  

  void SetAddress();
  
  std::string GetAddress();
  
  void SetEmailAddress();
  

  std::string GetEmailAddress();
  
  void EnterCommand(std::string command);
  
  void DrawInputArrowToTheScreen(void);
  
  void SetFirstPassword();
  

  std::string GetFirstPassword();
  
  void SetConfirmPassword();
  
  std::string GetConfirmedPassword();
  
  void SetEnterPassword();
  
  std::string GetEnterPassword();
  
  void EmployeeMenu();
  
  int numberOfAnnouncement(std::string file);

  void SetEmployeeSalary();
   

  long int GetEmployeeSalary();
};

class administrator : public Employees
{
private:
  std::string First_password;
  std::string Confirm_password;
  std::string Enter_password;

public:
  void Administrator_Menu();
  
  // A method that that get the number of items in the directory that is given
  int NumberOfComments(std::string file);
  
};

class MakePayments{
  private:
    long double Amount {1000000};
    long int Entered_amount {};
    std::vector<double> Transactions{};
  
  public:
  MakePayments()= default;
  MakePayments(int const amount){
    this->Amount;
  }

  MakePayments* setTransactions(){
    double Trans{};
    std:: cout << "Enter the Salary of the worker"<<std::endl;
    std::cout << "---> ";
    std::cin >> Trans;
    checkSalaries(Trans);
    this->Entered_amount = Trans;
    this->Transactions.push_back(Trans);
    return this;
  }

  void checkSalaries(double &checkSalary){
    MakePayments first;
    if (checkSalary > 9000)
    {
      std::cerr << "The Salary is too High for an employee in this company." <<std::endl;
      first.setTransactions();
      checkSalary = first.getTheAmountEntered();
      checkSalaries(checkSalary);
    }
    else if (checkSalary < 1500)
    {
      std::cout << "Salary is too Low for an employee in this company." << std::endl;
      first.setTransactions();
      checkSalary = first.getTheAmountEntered();
      checkSalaries(checkSalary);
    }
  }

  double TransactionsSize(){
    return Transactions.size();
  }

  double getTheAmountEntered(){
    return Entered_amount;
  }

  void PrintTransactions(){
    for (size_t i{0}; i <TransactionsSize(); i++){
      std::cout << Transactions[i]<<std::endl;
    }
  }

  auto getAmount(){
    return Amount;
  }
  
  auto writeAmount(){
    std::ofstream Trans("Total Amount.txt");
    Trans << Amount << std::endl;
    Trans.close();
  }
  auto writeNewAmount(int amount){
    std::ofstream New_Trans("Total Amount.txt");
    New_Trans << amount << std::endl;
    New_Trans.close();
  }

  void writeTransactions(){
    std::ofstream Write_Trans ("Transactions.txt", std::ios:: app);
    for (size_t i{0}; i < TransactionsSize(); i++){
      Write_Trans<< Transactions[i] <<std::endl;
    }
    Write_Trans.close();
  }

  auto readAmount(){
    std::ifstream Read_Trans("Total Amount.txt");
    std:: string Total_Amount{};
    getline(Read_Trans, Total_Amount);
    return stold(Total_Amount);
  }

  auto readTotalTransactions(){
    std::ifstream Read_Total_Trans("Transactions.txt");
    std::vector<int>getTrans{};
    std::string amount{};
    int transactionAmount{};
    while(std::getline (Read_Total_Trans , amount)){
      transactionAmount= stoi(amount);
      getTrans.push_back(transactionAmount);
    }

    auto totalTransactions{0};
    for (size_t i = 0; i < getTrans.size(); i++){
      totalTransactions+=getTrans[i];
    }
    return totalTransactions;
  }



};

typedef struct
{
  const std::string Post1 = "Chief_Executive_Officer";
  const std::string Post2 = "Human_Resource_Officer";
  const std::string Post3 = "Manager";
  const std::string Post4 = "General Manager";
  const std::string Post5 = "Administrator";
  const std::string Post6 = "Accountant";
  const std::string Post7 = "Software Engineer";
  const std::string Post8 = "R_Estate";
  const std::string Post9 = "Public_Relation";
  const std::string Post10 = "Cleaner";
  const std::string Post11 = "Security_Manager";

} AvailableJobsPost;




#endif