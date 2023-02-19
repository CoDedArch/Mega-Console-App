#include "ClassOfEmployees.h"

void Employees:: SetFirstName()
  {
    EnterCommand("Enter Your first Name");
    DrawInputArrowToTheScreen();
    std::cin >> firstName;
  }
  std::string Employees:: GetFirstName()
  {
    return firstName;
  }
  void Employees:: SetLastName()
  {
    EnterCommand("Enter Your Middle Name");
    DrawInputArrowToTheScreen();
    std::cin >> lastName;
  }
  std::string Employees:: GetLastName()
  {
    return lastName;
  }
  void Employees:: SetSurName()
  {
    EnterCommand("Enter Your surName");
    DrawInputArrowToTheScreen();
    std::cin >> surName;
  }
  std::string Employees:: GetSurName()
  {
    return surName;
  }
  void Employees:: SetAge()
  {
    EnterCommand("Enter Your age");
    DrawInputArrowToTheScreen();
    std::cin >> age;
  }
  std::string Employees:: GetAge()
  {
    return age;
  }

  void Employees:: SetGender()
  {
    EnterCommand("Are You a Male or A Female?");
    DrawInputArrowToTheScreen();
    std::cin >> gender;
  }

  std::string Employees:: GetGender()
  {
    return gender;
  }

  void Employees:: SetPosition()
  {
    EnterCommand("Enter Your position in the company");
    DrawInputArrowToTheScreen();
    std::cin >> position;
  }

  std::string Employees:: GetPosition()
  {
    return position;
  }

  void Employees:: SetAddress()
  {
    EnterCommand("Enter Your address");
    DrawInputArrowToTheScreen();
    std::cin >> address;
  }

  std::string Employees:: GetAddress()
  {
    return address;
  }
  void Employees:: SetEmailAddress()
  {
    EnterCommand("Enter Your Email address");
    DrawInputArrowToTheScreen();
    std::cin >> emailAddress;
  }

  std::string Employees:: GetEmailAddress()
  {
    return emailAddress;
  }

  void Employees:: EnterCommand(std::string command)
  {
    std::cout << command << std::endl;
  }

  void Employees:: DrawInputArrowToTheScreen(void)
  {
    std::cout << "-----> ";
  }

  void Employees:: SetFirstPassword()
  {
    EnterCommand("Enter your password");
    DrawInputArrowToTheScreen();
    std::cin >> firstPassword;
  }

  std::string Employees:: GetFirstPassword()
  {
    return firstPassword;
  }
  void Employees:: SetConfirmPassword()
  {
    EnterCommand("confirm_password");
    DrawInputArrowToTheScreen();
    std::cin >> ConfirmPassword;
  }
  std::string Employees:: GetConfirmedPassword()
  {
    return ConfirmPassword;
  }
  void Employees:: SetEnterPassword()
  {
    EnterCommand("Enter confirmation password");
    DrawInputArrowToTheScreen();
    std::cin >> EnterPassword;
  }
  std::string Employees:: GetEnterPassword()
  {
    return EnterPassword;
  }

  
  void Employees:: SetEmployeeSalary(){
    EnterCommand("Enter the prise of the Employee been created");
    DrawInputArrowToTheScreen();
    std::cin>>employeeSalary;
  }

  long int Employees:: GetEmployeeSalary(){
    return employeeSalary;
  }
  

  void Employees:: EmployeeMenu()
  {
    EnterCommand("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    std::cout << "\t\t\t\t\t\t\t\t\t\tOTHER EMPLOYERS AND EMPLOYERS MENU\t\t\tNO OF ANNOUNCEMENTS: " << numberOfAnnouncement("Announcement");
    EnterCommand("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    EnterCommand("1.\t\tCHECK IN TO WORK");
    EnterCommand("2.\t\tVIEW ANNOUNCEMENT");
    EnterCommand("3.\t\tMAKE COMMENTS ON ANNOUNCEMENT");
    EnterCommand("4.\t\tRETURN TO MAIN MENU");
  }
  int Employees:: numberOfAnnouncement(std::string file)
  {
    std::ifstream noOfComment(file + ".txt");
    std::string comments;
    size_t NoOfComments = 0;
    while (getline(noOfComment, comments))
    {
      NoOfComments++;
    }
    return NoOfComments;
  }

  void administrator:: Administrator_Menu()
  {
    EnterCommand("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    std::cout << "\t\t\t\t\t\t\t\t\t\tADMINISTRATOR MENU\t\tNO OF COMMENTS:: " << NumberOfComments("Comments") << std::endl;
    std::cout << "NO OF JOB LISTINGS:: " << NumberOfComments("Job_list") << std::endl;
    std::cout << "NO OF WORKERS CREATED:: " << NumberOfComments("Junck") << std::endl;
    std::cout << "NO OF ANNOUNCEMENT GIVEN:: " << NumberOfComments("Announcement") << std::endl;
    std::cout << "NO OF WORKERS Who CHECKED IN:: " << NumberOfComments("CheckedList") << std::endl;
    EnterCommand("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    EnterCommand("1.\t\tACCESS ALL WORKERS DATABASE");
    EnterCommand("2.\t\tSEARCH FOR A position DETAILS");
    EnterCommand("3.\t\tGIVE AN ANNOUNCEMENT");
    EnterCommand("4.\t\tVIEW COMMENTS TO ANNOUNCEMENT");
    EnterCommand("5.\t\tVIEW ANSWERS TO INTERVIEW QUESTION");
    EnterCommand("6.\t\tVIEW ALL JOB LISTINGS");
    EnterCommand("7.\t\tVIEW LIST OF WORKERS WHO CHECKED IN");
    EnterCommand("8.\t\tENTER INTERVIEW QUESTIONS");
    EnterCommand("9.\t\tENTER SHOP ITEMS");
    EnterCommand("10.\t\tVIEW THE EMPLOYEES PAYMENTS DATABASE");
    EnterCommand("11.\t\tMAKE PAYMENTS TO EMPLOYEES");
    EnterCommand("12.\t\tRETURN TO MAIN MENU");
    EnterCommand("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
  }
  // A method that that get the number of items in the directory that is given
  int administrator:: NumberOfComments(std::string file)
  {
    std::ifstream noOfComment(file + ".txt");
    std::string comments;
    size_t NoOfComments = 0;
    while (getline(noOfComment, comments))
    {
      NoOfComments++;
    }
    return NoOfComments;
  }

  
