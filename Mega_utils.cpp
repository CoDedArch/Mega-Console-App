#include "ClassOfEmployees.h"
#include "MegaFunctions.h"
#include "MegaConstants.h"

void JobPositionSetter(Employees admin, std::vector<std::string> &adminDetails, std::string employeeType)
{
  admin.SetFirstName();
  std::string firstName = admin.GetFirstName();
  CheckWorkerFirstNames(admin, firstName);        // This function checks and make sure that the input is is that of a human
  AdministratorPushBack(firstName, adminDetails); // A function that passes various instances to the Vector

  admin.SetLastName();
  std::string lastName = admin.GetLastName();
  CheckWorkerLastNames(admin, lastName);
  AdministratorPushBack(lastName, adminDetails);

  admin.SetSurName();
  std::string surName = admin.GetSurName();
  CheckWorkerSurNames(admin, surName);
  AdministratorPushBack(surName, adminDetails);

  admin.SetAge();
  std::string age = admin.GetAge();
  while (stoi(age) < ::adminLowYears || stoi(age) > ::adminHighYears)
  {
    std::cerr << "MR/MRS/MISS " << surName << " Does not qualify for the position " << std::endl; // prints out an error message if age is not within range
    admin.SetAge();
    age = admin.GetAge();
  }
  AdministratorPushBack(age, adminDetails);

  admin.SetGender();
  std::string G_ender = admin.GetGender();
  CheckWorkerGender(admin, G_ender);
  AdministratorPushBack(G_ender, adminDetails);

  if (employeeType == "OtherEmployees")
    ReadCompanyJobs();

  admin.SetPosition();
  std::string Posi_tion = admin.GetPosition();
  if (employeeType == "Administrator")
    CheckIfPositionIsAnAdmin(admin, Posi_tion);
  else if (employeeType == "OtherEmployees")
    CheckIfPositionIsNotAnAdmin(admin, Posi_tion);
  AdministratorPushBack(Posi_tion, adminDetails);

  MakePayments salaries;
  int employeesSalary;
  salaries.setTransactions();
  salaries.writeTransactions();
  employeesSalary = salaries.getTheAmountEntered();
  std::vector<int>Salaries{};
  Salaries.push_back(employeesSalary);

  
  admin.SetAddress();
  std::string Ad_dress = admin.GetAddress();
  CheckWorkerAddress(admin, Ad_dress);
  AdministratorPushBack(Ad_dress, adminDetails);

  admin.SetEmailAddress();
  std::string Email_address = admin.GetEmailAddress();
  CheckWorkerEmail(admin, Email_address);
  AdministratorPushBack(Email_address, adminDetails);

  admin.SetFirstPassword();
  std::string Pass = admin.GetFirstPassword();
  std::string p_ss;
  CheckPassword(admin , Pass);
  p_ss = Pass;
  Pass.replace(0, Pass.length() - 1, "********"); // replaces the input with **** and passes it to the vector
  AdministratorPushBack(Pass, adminDetails);

  admin.SetConfirmPassword();
  std::string Confirm_Password = admin.GetConfirmedPassword();
  while (Confirm_Password != p_ss)
  {
    admin.SetConfirmPassword();
    Confirm_Password = admin.GetConfirmedPassword();
  }
  WritePassword(p_ss);
  // PrintVectorToAdminDatabase(adminDetails , Pass);

  [&](){
    std::ofstream writeEmployeesPays("Employees Salary Database.txt" , std::ios:: app);
    writeEmployeesPays << adminDetails[0] << "-->\t\t\t " << adminDetails[1] <<  "\t\t\t\t\t\t GH$ " << Salaries[0] << std::endl;
    writeEmployeesPays.close();
  }
  ();
}

// this Function takes the instances of the employee and pushes them back to the vector
void AdministratorPushBack(std::string details, std::vector<std::string> &adminDetails)
{
  adminDetails.push_back(details);
}

// Function That writes the details of the Employee to a database file
void PrintVectorToAdminDatabase(std::vector<std::string> adminDetails)
{
  std::ofstream write_Admin_details(adminDetails[5] + ".txt", std::ios::app);
  write_Admin_details << "------------------------------------------------------------------------------------------------" << std::endl;
  write_Admin_details << "FIRST\tNAME    : " << adminDetails[0] << "\t\t\t\t\t\t\t\t\tDATE_CREATED: " << ::dateAccessed << std::endl;
  write_Admin_details << "MIDDLE\tNAME    : " << adminDetails[1] << std::endl;
  write_Admin_details << "SUR\tNAME    : " << adminDetails[2] << std::endl;
  write_Admin_details << "AGE             : " << adminDetails[3] << " YEARS" << std::endl;
  write_Admin_details << "GENDER          : " << adminDetails[4] << std::endl;
  write_Admin_details << "POSITION        : " << adminDetails[5] << std::endl;
  write_Admin_details << "ADDRESS         : " << adminDetails[6] << std::endl;
  write_Admin_details << "EMAIL ADDRESS   : " << adminDetails[7] << std::endl;
  write_Admin_details << "PASSWORD        : " << adminDetails[8] << std::endl;
  write_Admin_details << "-------------------------------------------------------------------------------------------------" << std::endl;

  write_Admin_details.close();
  WriteToListOfAllWorkers(adminDetails); // After writing the details ,  This Function as the identifier suggests write the new employee to the lis of employees
  main();
}

// this function retrieves the information of the searched employee from the database file and displays it to the one who queried
void RetrieveInformationOfWorker()
{
  std::string retrievePost;
  std::cout << "Enter the post to retrieve info: " << std::endl;
  std::cin >> retrievePost;

  std::ifstream retrievePostInfo(retrievePost + ".txt");
  if (retrievePostInfo.is_open())
  {
    std::cout << "Retrieving information of searched position......" << std::endl;
  }
  else if (!retrievePostInfo.is_open())
  {
    std::cout << "Retrieving failed:: file does not Exist" << std::endl;
  }

  std::string retrieve;
  if (retrieve == "Administrator")
  {
    std::cout << "\t\t\t\t\t ADMINISTRATOR INFO\t\t\t\t\t" << std::endl;
  }
  while (getline(retrievePostInfo, retrieve))
  {
    std::cout << retrieve << std::endl;
  }

  retrievePostInfo.close();
}

// this Function checks if Position already exists and returns a message to the User
int CheckIfAdminAlreadyExist(std::vector<std::string> adminDetails)
{
  std::ifstream readName(adminDetails[5] + ".txt");
  if (readName.is_open())
  {
    std::cout << "position Already Exist to an active Worker " << std::endl;
    std::cout << "WITH: " << ::adminHighYears - stoi(adminDetails[3]) << " years to retire " << std::endl;
    readName.close();
  }
  std::string ans;
  std::cout << "Do You want to save:: Y/ N" << std::endl;
  std::cout << "-----> ";
  std::cin >> ans;
  if (ans == "Y")
  {
    PrintVectorToAdminDatabase(adminDetails);
  }
  else if (ans == "N")
  {
    main();
  }
  return 0;
}

// function that checks the first name to ensure that is length is not below three
void CheckWorkerFirstNames(Employees admin, std::string &first_Name)
{
  while (first_Name.length() < 3)
  {
    admin.SetFirstName();
    first_Name = admin.GetFirstName();
  }
}
// function that checks the last name to ensure that is length is not below three
void CheckWorkerLastNames(Employees admin, std::string &last_Name)
{
  while (last_Name.length() < 3)
  {
    admin.SetLastName();
    last_Name = admin.GetLastName();
  }
}
// function that checks the Surname to ensure that is length is not below three
void CheckWorkerSurNames(Employees admin, std::string &sur_Name)
{
  while (sur_Name.length() < 3)
  {
    admin.SetSurName();
    sur_Name = admin.GetSurName();
  }
}

void CheckWorkerGender(Employees admin, std::string &G_ender)
{
  while (G_ender.length() < 4 || G_ender.length() > 6)
  {
    admin.SetGender();
    G_ender = admin.GetGender();
  }
}

void CheckWorkerAddress(Employees admin, std::string &Add)
{

  // bool finder = Add.find("PoBox");
  while (Add.find_first_of("PoBox") == -1)
  {
    std::cout << "postal address not found" << std::endl;
    admin.SetAddress();
    Add = admin.GetAddress();
  }
}

void CheckWorkerEmail(Employees admin, std::string &Email)
{
  while (Email.find_first_of("@gmail.com") == -1)
  {
    std::cout << "Enter a valid Email address" << std::endl;
    admin.SetEmailAddress();
    Email = admin.GetEmailAddress();
  }
}

void CheckPassword(Employees admin, std::string &pass)
{
  while (pass.length() < 16)
  {std::cout << "OOOPS!! Your password is " << pass.length() 
    << "in length short which is very weak! Change it to stay protected"<<std::endl;
    admin.SetFirstName();
    pass = admin.GetFirstName();
  }
}

void EnterCommand(std::string command)
{
  std::cout << command << std::endl;
}

void DrawInputArrowToTheScreen(void)
{
  std::cout << "-----> ";
}

void WriteCompanyJobs()
{
  AvailableJobsPost JobList;
  std::vector<std::string> jobs;
  jobs.push_back(JobList.Post1);
  jobs.push_back(JobList.Post2);
  jobs.push_back(JobList.Post3);
  jobs.push_back(JobList.Post4);
  jobs.push_back(JobList.Post5);
  jobs.push_back(JobList.Post6);
  jobs.push_back(JobList.Post7);
  jobs.push_back(JobList.Post9);
  jobs.push_back(JobList.Post10);
  jobs.push_back(JobList.Post11);

  std::ofstream writeJobs("Job_list.txt", std::ios::app);
  for (size_t i = 0, number = 1; i < jobs.size(); i++, number++)
  {
    writeJobs << number << ". " << jobs[i] << std::endl;
  }
  writeJobs.close();
}

void ReadCompanyJobs()
{
  std::ifstream Read_jobs("Job_list.txt");
  std::string get_job_list;
  if (Read_jobs.is_open())
  {
    std::cout << "retrieving jobs......." << std::endl;
  }
  else if (!Read_jobs.is_open())
  {
    std::cout << "Can't retrieve jobs!!!" << std::endl;
  }
  std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
  std::cout << "\t\t\t\t JOB LISTING IN THE COMPANY\t\t\t\t\t\t\t" << std::endl;
  std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;

  while (getline(Read_jobs, get_job_list))
  {
    std::cout << get_job_list << std::endl;
  }
  std::cout << "---------------------------------------------------------------------------------------------------------" << std::endl;

  Read_jobs.close();
}

void WriteToListOfAllWorkers(std::vector<std::string> Employ)
{
  std::ofstream allWorkers("ListOfAll-Workers.txt", std::ios::app);
  allWorkers << "-------------------------------------------------------------------------------------------------------" << std::endl;
  allWorkers << "DATE_CREATED:" << ::dateAccessed << "\t\t\t\t\tNAME: " << Employ[0] << "\t\t\tPOSITION : " << Employ[5] << std::endl;
  allWorkers << "-------------------------------------------------------------------------------------------------------" << std::endl;
  allWorkers.close();
  std::ofstream junckData("Junck.txt", std::ios::app);
  junckData << Employ[0] << std::endl;
  junckData.close();
}

void ReadFromListOfAllWorkers()
{
  std::ifstream read_from("ListOfAll-Workers.txt");
  if (read_from.is_open())
  {
    std::cout << "reading ongoing ......." << std::endl;
  }
  else if (!read_from.is_open())
  {
    std::cout << "ERRO FILE DOES NOT EXIST" << std::endl;
  }
  std::string reader;
  std::cout << "\t\t\t\t\t ALL WORKERS \t\t\t\t\t\t\t" << std::endl;
  while (getline(read_from, reader))
  {
    std::cout << reader << std::endl;
  }
}

void GiveAnnouncement(std::string Message)
{
  std::ofstream Announce("Announcement.txt", std::ios::app);
  Announce << "DATE: " << ::dateAccessed << " ANNOUNCEMENT: " << Message << std::endl;
  Announce << "------------------------------------------------------------------------------------------------------------" << std::endl;
  Announce.close();
}

void ViewAnnouncement()
{
  std::ifstream view_announcement("Announcement.txt");
  if (view_announcement.is_open())
  {
    std::cout << "retrieving Announcement......." << std::endl;
  }
  else if (!view_announcement.is_open())
  {
    std::cout << "sorry file is not found" << std::endl;
  }
  std::string get_message;
  std::cout << "\t\t\t\tMESSAGE\t\t\t\t\t\t\t\t" << std::endl;
  while (getline(view_announcement, get_message))
  {
    std::cout << get_message << std::endl;
  }
  view_announcement.close();
}

void GiveComments(std::string Comment)
{
  std::ofstream comments("Comments.txt", std::ios::app);
  comments << Comment << " TIME OF COMMENT: " << ::dateAccessed << std::endl;
  comments << "----------------------------------------------------------------------------------------------------------" << std::endl;
  comments.close();
}

void ViewComments()
{
  std::ifstream view_Comments("Comments.txt");
  if (view_Comments.is_open())
  {
    std::cout << "Getting comments......." << std::endl;
  }
  else if (!view_Comments.is_open())
  {
    std::cout << "File not found" << std::endl;
  }
  std::string comments;
  std::cout << "\t\t\t\tCOMMENTS\t\t\t\t\t\t\t\t" << std::endl;
  while (getline(view_Comments, comments))
  {
    std::cout << comments << std::endl;
  }

  view_Comments.close();
}

void CheckedInListOfWorkers(std::string checklist_sname, std::string checklist_Gen)
{
  std::ofstream checked("CheckedList.txt", std::ios::app);
  if (checklist_Gen == "Male")
  {
    checked << "DATE: " << ::dateAccessed << "\t\t\t MR : " << checklist_sname << std::endl;
  }
  else if (checklist_Gen == "Female")
  {
    checked << "DATE: " << ::dateAccessed << "\t\t\tMRS/MISS: " << checklist_sname << std::endl;
  }
  checked.close();
}

void ViewCheckedListOfWorkers()
{
  std::ifstream checked("CheckedList.txt");
  if (checked.is_open())
  {
    std::cout << "Retrieving List of Workers Who Have CHECKED IN........... DONE!!" << std::endl;
  }
  else if (!checked.is_open())
  {
    std::cout << "NO Worker has CHECKED IN YET!!! AND \t\t\t\tTIME NOW IS: " << ::dateAccessed << std::endl;
  }
  std::string putin;
  while (getline(checked, putin))
  {
    std::cout << putin << std::endl;
  }
  checked.close();
}

void MainMenu()
{
  std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
  std::cout << "\t\t\t\t\t\t\t\t\t\tMAIN MENU\t\t\t\t\t\t\tDATE AND TIME: " << ::dateAccessed << std::endl;
  std::cout << "1.\t\tCREATE USER" << std::endl;
  std::cout << "2.\t\tACCESS DIVISIONS" << std::endl;
  std::cout << "3.\t\tEXIT PROGRAM" << std::endl;
  std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
}

void CreateUserMenu()
{
  std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
  std::cout << "1.CREATE MAIN ADMINISTRATOR" << std::endl;
  std::cout << "2.CREATE AN EMPLOYEE" << std::endl;
  std::cout << "3.RETURN TO MAIN MENU" << std::endl;
  std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
}
void DivisionMenu()
{
  std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
  std::cout << "\t\t\t\t\t\t\t\t\t\tDIVISIONS\t\t\t\t\t\t\t\t" << std::endl;
  std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
  std::cout << "1.\t\tADMINISTRATOR" << std::endl;
  std::cout << "2.\t\tOTHER EMPLOYERS" << std::endl;
  std::cout << "3.\t\tCUSTOMERS" << std::endl;
  std::cout << "4.\t\tRETURN TO MAIN MENU" << std::endl;
  std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
}

int OtherMenu(std::string choice)
{
  bool null = "\0";

  Employees Admin;
  Employees otherDivision;
  administrator AdminH;
  std::vector<std::string> adminDetails;
  std::vector<std::string> otherDivisionDetails;
  std::string P_ass;
  if (choice == "1")
  {
    std::string choice2;
    CreateUserMenu();
    std::cout << std::endl;
    std::cout << "------> ";
    std::cin >> choice2;
    if (choice2 == "1")
    {
      JobPositionSetter(Admin, adminDetails, "Administrator");
      CheckIfAdminAlreadyExist(adminDetails);
      ClearScreen();
    }
    else if (choice2 == "2")
    {
      JobPositionSetter(otherDivision, otherDivisionDetails, "OtherEmployees");
      CheckIfAdminAlreadyExist(otherDivisionDetails);
      ClearScreen();
      main();
    }
    else if (choice2 == "3")
    {
      main();
    }
  }
  else if (choice == "2")
  {
    DivisionMenu();
    std::string choice3;
    std::cout << "------> ";
    std::cin >> choice3;
    if (choice3 == "1")
    {
      AdminH.SetEnterPassword();
      std::string PassCode = AdminH.GetEnterPassword();
      ReadPassword(PassCode, AdminH, otherDivision, choice3);
      // confirmPassword(AdminH,PassCode , adminDetails ,P_ass);
    }
    else if (choice3 == "2")
    {
      otherDivision.SetEnterPassword();
      std::string O_passCode = otherDivision.GetEnterPassword();
      ReadPassword(O_passCode, AdminH, otherDivision, choice3);
    }
    else if (choice3 == "3")
    {
      Customer();
    }
  }
  else if (choice == "3")
  {
    return 0;
  }
  return 0;
}

void WritePassword(std::string pass_code)
{
  std::ofstream write_passcode(pass_code + ".txt");
  write_passcode.close();
}

void ReadPassword(std::string enteredPasscode, administrator AdminH, Employees otherDivision, std::string choice)
{
  int chances = 2;
  if (choice == "1")
  {
    std::string admin = enteredPasscode;
    std::ifstream readPasscode(admin + ".txt");
    if (readPasscode.is_open())
    {
      DetailAdminMenu(AdminH);
    }
    else if (!readPasscode.is_open())
    {
      while (!readPasscode.is_open())
      {
        AdminH.SetEnterPassword();
        enteredPasscode = AdminH.GetEnterPassword();
        ReadPassword(enteredPasscode, AdminH, otherDivision, choice);
        chances--;
        if (chances == 0)
        {
          std::cout << "Trying To Gain Unlawful Entry" << std::endl;
          main();
        }
      }
    }
  }
  else if (choice == "2")
  {
    std::string other = enteredPasscode;
    std::ifstream readPasscode(other + ".txt");
    if (readPasscode.is_open())
    {
      DetailOtherEmployersMenu(otherDivision);
    }
    else if (!readPasscode.is_open())
    {
      while (!readPasscode.is_open())
      {
        otherDivision.SetEnterPassword();
        enteredPasscode = otherDivision.GetEnterPassword();
        ReadPassword(enteredPasscode, AdminH, otherDivision, choice);
        chances--;
        if (chances == 0)
        {
          std::cout << "Trying To Gain Unlawful Entry" << std::endl;
          main();
        }
      }
    }
  }
}

void CheckIfPositionIsAnAdmin(Employees admin, std::string &position)
{
  while (position != "Administrator")
  {
    std::cout << "This position must be an Administrator" << std::endl;
    admin.SetPosition();
    position = admin.GetPosition();
  }
}

void CheckIfPositionIsNotAnAdmin(Employees otherDivision, std::string &position)
{
  while (position == "Administrator")
  {
    std::cout << "This position cannot be created in this section" << std::endl;
    otherDivision.SetPosition();
    position = otherDivision.GetPosition();
  }
}

void DetailAdminMenu(administrator AdminH)
{
  MakePayments paySalaries;
  AdminH.Administrator_Menu();
  std::string admin_choice;
  std::cout << "------> ";
  std::cin >> admin_choice;
  if (admin_choice == "1")
  {
    ReadFromListOfAllWorkers();
    DetailAdminMenu(AdminH);
  }
  else if (admin_choice == "2")
  {
    ReadCompanyJobs();
    RetrieveInformationOfWorker();
    DetailAdminMenu(AdminH);
  }
  else if (admin_choice == "3")
  {
    bool Null = "\0";
    std::string Message;
    while (Null)
    {
      getline(std::cin, Message);
      if (Message != "\0")
        break;
    }
    GiveAnnouncement(Message);
    DetailAdminMenu(AdminH);
  }
  else if (admin_choice == "4")
  {
    ViewComments();
    DetailAdminMenu(AdminH);
  }
  else if (admin_choice == "5")
  {
    std::cout << "No Interviews are ready yet" << std::endl;
    DetailAdminMenu(AdminH);
  }
  else if (admin_choice == "6")
  {
    ReadCompanyJobs();
    DetailAdminMenu(AdminH);
  }
  else if (admin_choice == "7")
  {
    ViewCheckedListOfWorkers();
    DetailAdminMenu(AdminH);
  }
  else if (admin_choice == "8")
  {
    EnterInterviewQuestions();
    DetailAdminMenu(AdminH);
  }
  else if (admin_choice == "9")
  {
    EnterShopItems();
    DetailAdminMenu(AdminH);
  }
  else if (admin_choice == "10")
  {
    accessEmployeesPayments();
    DetailAdminMenu(AdminH);
  }
  else if (admin_choice == "11")
  {
    auto NewAmount {paySalaries.readAmount()-paySalaries.readTotalTransactions()};
    paySalaries.writeNewAmount(NewAmount);
    DetailAdminMenu(AdminH); 
  }
  else if (admin_choice == "12")
  {
    main();
  }
}

void DetailOtherEmployersMenu(Employees otherDivision)
{
  otherDivision.EmployeeMenu();
  std::string Ochoice;
  std::cout << "------> ";
  std::cin >> Ochoice;
  if (Ochoice == "1")
  {
    otherDivision.SetSurName();
    std::string SS = otherDivision.GetSurName();
    otherDivision.SetGender();
    std::string Gen = otherDivision.GetGender();
    CheckedInListOfWorkers(SS, Gen);
    DetailOtherEmployersMenu(otherDivision);
  }
  else if (Ochoice == "2")
  {
    ViewAnnouncement();
    DetailOtherEmployersMenu(otherDivision);
  }
  else if (Ochoice == "3")
  {
    bool null = "\0";
    std::string Comment;
    while (null)
    {
      getline(std::cin, Comment);
      if (Comment != "\0")
        break;
    }
    GiveComments(Comment);
    DetailOtherEmployersMenu(otherDivision);
  }
  else if (Ochoice == "4")
  {
    main();
  }
}

void Customer(void)
{
  std::cout << "Welcome Customer RESPOND WITH-----> Thank you / No thank you/ TO PROCEED" << std::endl;
  std::string menu_choice;
  std::cout << "--------> ";
  std::cin.ignore(1000000000, '\n');
  getline(std::cin, menu_choice);
  CustomerMenu(menu_choice);
}
void CustomerMenu(std::string menu_choice)
{
  if (menu_choice == "Thank you")
  {
    std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "1.LOGIN/ALREADY HAVE AN ACCOUNT\t\t\t\t\t\t2.SIGNUP/CREATE ACCOUNT" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;
    std::string choice;
    std::cout << "------> ";
    std::cin >> choice;

    if (choice == "1")
    {
      Login();
    }
    else if (choice == "2")
    {
      Signup();
    }
  }
  else if (menu_choice == "No thank you")
  {
    main();
  }
  else
  {
    main();
  }
}

void Login()
{
  std::cout << "Enter Your pass_code" << std::endl;
  std::string pass;
  std::cout << "------> ";
  std::cin >> pass;
  ReadCustomerPassword(pass);
}

void Signup()
{
  std::vector<std::string> customer;
  std::string userName;
  std::cin.ignore(1000000000, '\n');
  EnterCommand("Enter Your UserName");
  DrawInputArrowToTheScreen();
  getline(std::cin, userName);
  customer.push_back(userName);
  std::cout << "Customers Who decide to be regular customers are given some kind of discount on purchase." << std::endl;
  std::string stats;
  std::cout << "Are You going to be a regular Customer? Type----> Yes/No " << std::endl;
  std::cout << "------> ";
  std::cin >> stats;
  customer.push_back(stats);
  if (stats == "Yes")
  {
    std::string cus_pass;
    std::cout << "please Enter a secured password" << std::endl;
    std::cout << "------> ";
    std::cin >> cus_pass;
    customer.push_back(cus_pass);
    std::cout << "Account created" << std::endl;
  }
  else if (stats == "No")
  {
    std::cout << "Account created" << std::endl;
  }

  CustomerDetail(customer);
  Customer();
}

void CustomerDetail(std::vector<std::string> Customer)
{
  std::ofstream writeCustomerDetails("Customer.txt", std::ios::app);
  writeCustomerDetails << "USER_NAME: " << Customer[0] << "\t\t\t:STATUS:REGULAR(YES)/NON REGULAR(NO): " << Customer[1] << std::endl;
  writeCustomerDetails.close();
  if (Customer[1] == "Yes")
  {
    std::ofstream writeCustomerPassword(Customer[0] + ".txt", std::ios::app);
    writeCustomerPassword << "YOUR PASSWORD IS: " << Customer[2] << std::endl;
    writeCustomerPassword.close();
  }

  std::ofstream write_Pass(Customer[2] + ".txt");
}

void ReadCustomerPassword(std::string Pass)
{
  std::ifstream ofs(Pass + ".txt");
  if (ofs.is_open())
  {
    FinalCustomerMenu();
  }
  else if (!ofs.is_open())
  {
    std::cerr << "Password does not Exist" << std::endl;
    Customer();
  }
}

void FinalCustomerMenu()
{
  administrator an;
  std::cout << std::endl;
  std::cout << "-------------------------------------------------------------------------------------" << std::endl;
  //using Lambda functions in implementing something  
  std::cout << "NUMBER OF MESSAGES RECEIVED IN YOUR IN BOX:\t\t\t\t "<< []()->int{
    std::ifstream readNumber("CustomerMessage.txt");
    size_t count{0};
    std::string str{};
    while(getline(readNumber , str)){
      ++count;
    }
    return count;
  }() <<std::endl;

  std::cout << std::endl;
  std::cout << "1.ACCESS ALL COMPANY JOBS\t\t2.APPLY FOR A JOB\t\t3.ENTER SHOP\t\t4.VIEW ANNOUNCEMENT\t\t5.RETURN TO MAIN MENU" << std::endl;
  std::cout << "-------------------------------------------------------------------------------------" << std::endl;
  std::string in_choice;
  std::cout << "------> ";
  std::cin >> in_choice;
  if (in_choice == "1")
  {
    ReadCompanyJobs();
    FinalCustomerMenu();
  }
  else if (in_choice == "2")
  {
    CustomerApplyForJob();
    FinalCustomerMenu();
  }
  else if (in_choice == "3")
  {
    ViewShopItems();
  }
  else if (in_choice == "4")
  {
    DisplayMessageToCustomer();
    FinalCustomerMenu();
  }
  else if (in_choice == "5")
  {
    Customer();
  }
}

void CustomerApplyForJob()
{
  Employees OCustomer;
  if (OCustomer.numberOfAnnouncement("Junck") < OCustomer.numberOfAnnouncement("Job_list"))
  {
    std::cout << "IN APPLY FOR JOB SECTION" << std::endl;
    std::cout << "--------------------------------------------------------------------------------------" << std::endl;
    std::cout << "1.Answer Interview Question" << std::endl;
    std::cout << "--------------------------------------------------------------------------------------" << std::endl;
    std::string enter;
    std::cout << "Enter 1 to proceed or 0 to return To previous menu" << std::endl;
    std::cout << "------> ";
    std::cin >> enter;
    if (enter == "1")
    {
      ViewInterviewQuestions(OCustomer);
    }
    else if (enter == "0")
    {
      FinalCustomerMenu();
    }
  }
  else if (OCustomer.numberOfAnnouncement("Junck") == OCustomer.numberOfAnnouncement("Job_list"))
  {
    std::cout << "ALL POSITIONS ARE OCCUPIED" << std::endl;
    std::cout << "Thank You For Attempting to Apply" << std::endl;
    FinalCustomerMenu();
  }
}

void ViewInterviewQuestions(Employees OCustomer)
{
  std::ifstream interview("Interview.txt");
  if (interview.is_open())
  {
    std::cout << "displaying interview Questions......." << std::endl;
  }
  else if (!interview.is_open())
  {
    std::cerr << "NO INTERVIEW Questions Have been Entered yet" << std::endl;
    std::cerr << "Stay Tunned to your IN BOX!" << std::endl;
    FinalCustomerMenu();
  }

  std::string questions;
  while (getline(interview, questions))
  {
    std::cout << questions << std::endl;
  }

  std::string answer {};
  std::vector<std::string> Answers{};
  for (size_t i = 0; i < OCustomer.numberOfAnnouncement("Interview"); i++)
  {
    std::cin.ignore(10000000, '\n');
    std::cout << "-------> ";
    getline(std::cin, answer);
    Answers.push_back(answer);
  }
  WriteInterviewAnswers(Answers);
}

void WriteInterviewAnswers(std::vector<std::string> answers)
{
  std::ofstream inter_answers("Interview_Answers.txt");
  for (size_t i = 0; i < answers.size(); i++)
  {
    inter_answers << answers[i] << std::endl;
  }
}

void ReadInterviewAnswers()
{
  std::ifstream view_answers("Interview_Answers.txt");
  std::string get_answers;
  while (getline(view_answers, get_answers))
  {
    std::cout << get_answers << std::endl;
  }
}

void EnterInterviewQuestions()
{
  std::string question;
  std::vector<std::string> questions = {"\0"};
  int number_of_questions = 0;
  std::cerr << "How Many Questions are You going to Upload?" << std::endl;
  std::cout << "------> ";
  std::cin >> number_of_questions;
  std::cin.ignore(100000000, '\n');

  for (int i = 1; i <= number_of_questions; i++)
  {
    std::cout << "Enter " << i << ". question" << std::endl;
    std::cout << "-----> ";
    getline(std::cin, question);
    questions.push_back(question);
    /* code */
  }

  std::cout << "SUBMIT QUESTIONS-----> YES/NO?" << std::endl;
  std::string ans;
  std::cout << "-----> ";
  std::cin >> ans;

  if (ans == "YES")
  {
    std::ofstream write_Questions("Interview.txt");
    for (int i = 1; i < questions.size(); i++)
    {
      write_Questions << questions[i] << std::endl;
      WriteAMessageToCustomer("Interview");
    }
  }
  else if (ans == "NO")
  {
    main();
  }
}

void EnterShopItems()
{
  std::string itemName;
  std::vector<std::string> Items = {"\0"};
  int itemAmount = 0;
  std::vector<int> prices = {0};
  // prices[0] = 0;
  int Number_Of_Items = 0;
  std::cin.ignore(100000000, '\n');
  std::cerr << "How Many Items are You going to Upload?" << std::endl;
  std::cout << "------> ";
  std::cin >> Number_Of_Items;

  for (int i = 1; i <= Number_Of_Items; i++)
  {
    std::cin.ignore(100000000, '\n');
    std::cout << "Enter " << i << ". Item" << std::endl;
    std::cout << "-----> ";
    getline(std::cin, itemName);
    Items.push_back(itemName);
    std::cout << "Enter " << i << ". Price/Amount for " << itemName << std::endl;
    std::cout << "-----> ";
    std::cin >> itemAmount;
    prices.push_back(itemAmount);
  }
  std::ofstream writeItemsPrices("shop_items.txt", std::ios::app);
  for (int i = 1; i < Items.size(); i++)
  {
    writeItemsPrices << "Item Name: " << Items[i] << "\t\tItem Price: " << prices[i] << std::endl;
  }

  WriteAMessageToCustomer("Shop");
  writeItemsPrices.close();
  ClearScreen();
}

void ViewShopItems()
{
  ClearScreen();
  std::ifstream shop_items("shop_items.txt");
  if (shop_items.is_open())
  {
    std::cout << "displaying items....... Done!!" << std::endl;
  }
  else if (!shop_items.is_open())
  {
    std::cerr << "NO ITEMS HAVE BEEN UPLOADED YET" << std::endl;
    std::cerr << "STAYED TUNED TO YOUR IN BOX" << std::endl;
  }
  std::cout << std::endl;
  std::string items;
  while (getline(shop_items, items))
  {
    std::cout << items << std::endl;
  }
  FinalCustomerMenu();
}

void ClearScreen(void)
{
  system("cls");
}

// void PrintGreetingGraphics(void)
// {
//   int i, j = 0;
//   //setbkcolor(BACKGROUND_RED);
//   char *welcome = (char*)"WELCOME TO CoDed_ARCH";
//   for( i = 0 ; i <= 700 ; i = i + 5, j++ )
//   {
//     rectangle(50 , 100 , getmaxx()-50 , getmaxy()-100);
//     settextstyle(BOLD_FONT , HORIZ_DIR , 5);
//     outtextxy(getmaxx()/2 - textwidth(welcome)/2 , getmaxy()/2 - textheight(welcome)/2 , welcome);
//     rectangle(50+i,275,150+i,400);
//     rectangle(150+i,350,200+i,400);
//     circle(75+i,410,10);
//     circle(175+i,410,10);
//     setcolor(j);
//     delay(100);

//     if (i==700)
//       break;
//     if ( j == 15 )
//         j = 2;

//     cleardevice(); // clear screen
//   }

//}0543626257 ibrahim stc 

void WriteAMessageToCustomer(std::string instruction)
{
  instruction == "\0";
  std::ofstream messageToCustomer("CustomerMessage.txt", std::ios::app);
  if (instruction == "Shop")
  {
    messageToCustomer << "PLEASE BE NOTIFIED THAT AN ITEM HAS BEEN STOCKED IN THE SHOP" << std::endl;
  }
  else if (instruction == "Interview")
  {
    messageToCustomer << "!!!!!!! BE ALERT THAT AN INTERVIEW HAS BEEN SCHEDULED AND QUESTIONS HAVE BEEN UPLOADED" << std::endl;
  }
  messageToCustomer.close();
}

void DisplayMessageToCustomer()
{
  std::ifstream displayMessage("CustomerMessage.txt");
  if (displayMessage.is_open())
  {
    std::cerr << "Displaying Your Message:...... "<<std::endl;
    std::cout <<std::endl;
    std::cout << "YOU::----> MESSAGE SENT FROM THE ADMINISTRATOR" <<std::endl;
  }
  else if (!displayMessage.is_open())
  {
    std::cerr << "YOU HAVE NOT RECEIVED ANY MESSAGE FROM THE ADMINISTRATOR"<<std::endl;
  }

  std::string receiveMessage = "\0";
  while(getline(displayMessage , receiveMessage))
  {
    std::cout << receiveMessage << std::endl;
  }
  displayMessage.close();
}

void accessEmployeesPayments()
{
  std::ifstream readEmployeesPayments("Employees Salary Database.txt");
  if (readEmployeesPayments.is_open()){
    std::cout << "Reading Ongoing...."<<std::endl;
  }
  else if (!readEmployeesPayments.is_open()){
    std::cerr << "File can't be accessed"<<std::endl;
  }

  std::cout << "First NAME\tMID NAME\t\t\t -+SALARIES"<<std::endl;
  std::string getLines{};
  while (getline(readEmployeesPayments , getLines))
  {
    std::cout << getLines << std::endl;
  }
  readEmployeesPayments.close();
  
}



