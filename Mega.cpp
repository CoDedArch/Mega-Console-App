/**
 * @file Mega.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-23
 *
 * @copyright Copyright (c) 2022
 *
 * A program About An Employees Management System
 * IN which some graphics Have been created at the start.
 */

#include <iostream>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>
#include <climits>
#include "ClassOfEmployees.h"
#include "MegaFunctions.h"
//#include <graphics.h>


// structures that contain the Job listings in the Company

// this  is the Minimum and the Maximum age an employee must be to be employed or given a certain job position


// setting the local time As a Global variable so that other functions in the program can access it


// Functions definition All written in In the UpperCamel style


// the main Function
int main(void)
{
  // MakePayments CompanyMony;
  // CompanyMony.writeAmount();
  //WriteCompanyJobs();
  //  int graphicDriver = DETECT;
  //  int graphicMode;
  //  initgraph(&graphicDriver , &graphicMode ,(char*)""); // passing the graphic driver and graphic mode to the initgraph function to create the graphic window
  //  PrintGreetingGraphics();

  // getch();
  // closegraph();

  ClearScreen();
  bool done = true;
  std::string choice;
  MainMenu();
  std::cout << "------> ";
  std::cin >> choice;
  OtherMenu(choice);

  return 0;
}

// this function is to take instances of the employee being created and pass it to the Vector
