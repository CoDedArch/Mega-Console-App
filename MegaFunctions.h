#ifndef MEGAFUNC_H

#define MEGAFUNC_H

#include "ClassOfEmployees.h"

void PrintGreetingGraphics(void);
void ClearScreen(void);
void JobPositionSetter(Employees admin, std::vector<std::string> &adminDetails, std::string employeeType);
void AdministratorPushBack(std::string, std::vector<std::string> &adminDetails);
void PrintVectorToAdminDatabase(std::vector<std::string>);
void RetrieveInformationOfWorker(void);

int CheckIfAdminAlreadyExist(std::vector<std::string> adminDetails);
void CheckWorkerFirstNames(Employees admin, std::string &first_Name);
void CheckWorkerLastNames(Employees admin, std::string &last_Name);
void CheckWorkerSurNames(Employees admin, std::string &sur_Name);
void CheckWorkerGender(Employees admin, std::string &G_ender);
void CheckWorkerAddress(Employees admin, std::string &Add);
void CheckWorkerEmail(Employees admin, std::string &Email);
void checkSalaries(Employees admin , int &checkSalary);
void CheckPassword(Employees admin, std::string &pass);

void EnterCommand(std::string command);
void DrawInputArrowToTheScreen(void);
void WriteCompanyJobs(void);
void ReadCompanyJobs(void);
void WriteToListOfAllWorkers(std::vector<std::string> Employ);
void ReadFromListOfAllWorkers(void);
int GetPassword(std::string &password);
void GiveAnnouncement(std::string Message);
void ViewAnnouncement(void);
void GiveComments(std::string Comment);
void ViewComments(void);
void CheckedInListOfWorkers(std::string checklist_sname, std::string checklist_Gen);
void ViewCheckedListOfWorkers(void);
void MainMenu(void);
void DivisionMenu(void);
void CreateUserMenu(void);
int OtherMenu(std::string choice);
void WritePassword(std::string pass_code);
void ReadPassword(std::string enteredPasscode, administrator AdminH, Employees otherDivision, std::string choice);
void CheckIfPositionIsAnAdmin(Employees admin, std::string &position);
void CheckIfPositionIsNotAnAdmin(Employees otherDivision, std::string &position);
void DetailAdminMenu(administrator AdminH);
void DetailOtherEmployersMenu(Employees otherDivision);
void Customer(void);
void CustomerMenu(std::string menu_choice);
void Login(void);
void Signup(void);
void CustomerDetail(std::vector<std::string> Customer);
void ReadCustomerPassword(std::string Pass);
void FinalCustomerMenu(void);
void CustomerApplyForJob(void);
void ViewInterviewQuestions(Employees OCustomer);
void WriteInterviewAnswers(std::vector<std::string> answers);
void ReadInterviewAnswers(void);
void EnterInterviewQuestions(void);
void EnterShopItems(void);
void ViewShopItems(void);
void WriteAMessageToCustomer(std::string instruction);
void DisplayMessageToCustomer();
int main(void);
void accessEmployeesPayments();

#endif