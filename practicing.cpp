/**
 * @file practicing.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 * learning tuples and regular expressions
 */

#include <iostream>
#include <tuple>
#include <regex>
#include  <chrono>
#include <random>
#include <stdarg.h>

class Randomizer{
  private:
    double firstNumber{};
    double secondNumber{};
    double results{};
    double answer{};

  public:
    Randomizer()= default;
    Randomizer(double firstNumber , double secondNumber , std::string_view text){
      this->firstNumber = firstNumber;
      this->secondNumber = secondNumber;
      if (text == "addition"){
        this->results = firstNumber+secondNumber;
      }
      else if(text =="subtraction"){
        this->results = firstNumber - secondNumber;
      }
      else if (text == "multiplication"){
        this->results = firstNumber*secondNumber;
      }
    }

    void SetupEngineRandomNumbers(std::string_view moreInfo){

              unsigned seed = std::chrono::steady_clock::now ().time_since_epoch().count();
              std::default_random_engine generateEngine(seed);
              std::uniform_int_distribution<int>firstDistribution(0 , 20);
              std::uniform_int_distribution<int>secondDistribution(0, 10);
              if (moreInfo == "first"){
                this->firstNumber = firstDistribution(generateEngine);
              }
              else if (moreInfo == "second")
                this->secondNumber = secondDistribution (generateEngine);
    }

    Randomizer& SetFirstNumber(){

      SetupEngineRandomNumbers("first");
      return *this;
    }

    auto GetFirstNumber(){
      
      return firstNumber;
    
    }

    Randomizer& SetSecondNumber(){
     
      SetupEngineRandomNumbers("second");
      return *this;
    }

    auto GetSecondNumber(){
      
      return secondNumber;
    
    }

    Randomizer& SetResultsForAddition(){
      this-> results = GetFirstNumber() + GetSecondNumber();
      return *this;
    }

    double GetResultsForAddition(){
      return results;
    }

    Randomizer& SetResultsForSubtraction(){
      this-> results = GetFirstNumber() - GetSecondNumber();
      return *this;
    }

    double GetResultsForSubtraction(){
      return results;
    }

    Randomizer& SetResultsForMultiplication(){
      this-> results = GetFirstNumber()*GetSecondNumber();
      return *this;
    }

    double GetResultsForMultiplication(){
      return results;
    }

    Randomizer& AskQuestionOnAddition(){
      std::cout << GetFirstNumber() << "+" << GetSecondNumber()<< "= ";
      std::cin >> this->answer;
      return *this;
    }

    double GetAnswerForAddition(){
      return answer;
    }
    Randomizer& AskQuestionOnSubtraction(){
      std::cout << GetFirstNumber() << "-" << GetSecondNumber()<< "= ";
      std::cin >> this->answer;
      return *this;
    }

    double GetAnswerForSubtraction(){
      return answer;
    }
    Randomizer& AskQuestionOnMultiplication(){
      std::cout << GetFirstNumber() << "*" << GetSecondNumber()<< "= ";
      std::cin >> this->answer;
      return *this;
    }

    double GetAnswerForMultiplication(){
      return answer;
    }



    void compareAdditionAnswerWithAdditionResults(){
      if (GetResultsForAddition() != GetAnswerForAddition()){
        std::cout << "answer is wrong"<<std::endl;
      }
      else {
        std::cout << "Correct answer"<<std::endl;
      }
    }

    void compareSubtractionAnswerWithSubtractionResults(){
      if (GetResultsForSubtraction() != GetAnswerForSubtraction()){
        std::cout << "answer is wrong"<<std::endl;
      }
      else {
        std::cout << "Correct answer"<<std::endl;
      }
    }

    void compareMultiplicationAnswerWithMultiplicationResults(){
      if (GetResultsForMultiplication() != GetAnswerForMultiplication()){
        std::cout << "answer is wrong"<<std::endl;
      }
      else {
        std::cout << "Correct answer"<<std::endl;
      }
    }
    

};

void PrintMatches(std::string word, std::regex reg){
  std::smatch matches;
  std::cout<<std::boolalpha;
  while (std::regex_search(word , matches , reg)){
      std::cout << "are There any matches " << matches.ready()<<std::endl;
      std::cout << "Are there No matches " << matches.empty()<<std::endl;
      std::cout << "Number of matches " << matches.size()<<std::endl;
      std::cout << matches.str(0)<<std::endl;
      word = matches.suffix().str();

  } 
}


int Sum (int num_args , ...){
  va_list argumentsList;
  int sum{};
  va_start(argumentsList , num_args);
  for (size_t i{0}; i < num_args; i++){
    sum += va_arg(argumentsList , int);
  }
  va_end (argumentsList);
  return sum;
};
int main ()
{
  {
  //Tuples are known for "Quick and dirty to use" and regular expressions
  //declaring a tuple
  // std::tuple <int , std::string>human{20 , "KELVIN"};
  // std::tuple <int , std::string>animal{30 , "Goat"};
  // std::cout << "Name: "<<std::get<1>(human) << " Age: " <<std::get<0>(human)<<std::endl;
  // //decomposing the tuple into individual elements
  // int age{};
  // std::string name{"Noname"};
  // std::tie(age , name) = human;
  // std::cout << "The age using the decomposed Age: "<< age << " The name using the decomposed Name: " << name << std::endl;
  // //Tuples can also be concatenated only if the destination is of the type oder of the resulting concat;
  // //Also Tuples can be swapped using swap key word in the class tuple
  // human.swap (animal);
  // std::cout << std::get<0>(human) << std::endl;
  // std::cout << std::get<1>(human) << std::endl;
  // std::cout << std::get<0>(animal) << std::endl;
  // std::cout << std::get<1>(animal) << std::endl;
  // human = std::make_tuple(40 , "MARK");
  // std::cout << std:: get<0>(human) << " : "  << std:: get<1>(human)<<std::endl;



  //learning regular expressions Now with regex
  std::string word{};
  while (true)
  {
    std::cin >> word;
  //   //if we don't care of the case
  //   //std::regex e("abc." , std:: regex_constants::icase); // speciality is in the special characters (. means any character aside a new line);
    
  //   //std:: regex e ("abc?" , std::regex_constants::icase); // another special character is the (? means zero or one preceeding character)
  //   //std:: regex e ("abc*" /*, std::regex_constants::icase*/); // another special character is the (* means zero or More preceeding character)
  //   // std:: regex e ("abc+"); // this gives one or more preceeding characters ;
  //   // std::regex e ("ab[cd]*");//another special Character is the ([] which defines that any character inside the [] is a Match)
  //   //std::regex e ("ab[^cd]*");//another special Character is the ([^] which defines that any character inside the [] is not a match)
  //   // std::regex e ("ab[cd]{2}");//another special Character is the ({} which defines that any character inside the [] appears exactly  the number that is defined)
    
    std:: regex e ("[[:w:]]+@[[:w:]]+\.com"); // the special charater [[:w:]] is word characters including underscores and the \ is an escape 
    bool checkMatch = std::regex_match(word , e);
    std::cout << (checkMatch? "MATCHES" : 
                              "MISS MATCH")<<std::endl;
  }
  
  }
    {
        // //generating random numbers
        // unsigned seed =  std::chrono::steady_clock::now().time_since_epoch().count();
        // std::default_random_engine eng(seed);  
        // //std::cout << eng << std::endl; // this gives us a range of eng.Min and eng.Max
        // //std::cout << eng() % 6<<std::endl; // this kind of syntax is bad distribution and so uniform in its distribution
        // std::uniform_int_distribution <int> distri(0 , 5);
        // //std::poisson_distribution <int> distr(1.0);
        // //std::normal_distribution<double>distri(10.0 , 3.0 );//(mean ,  mean deviation) 
        // std::vector<int>v(20);
        // int num{};
        // for (int i = 0; i < 800; i++){
        //   num = distri(eng);
        //   if (num >= 0 && num < 20)
        //     v[num]++;
        // }
        // for (int i = 0 ; i < 20; i++){
        //   std::cout << i  <<": " <<v[i]<<std::endl;
        // }
        
  }

  // std::string word ="The ape was at the apex";
  // std::regex reg ("(ape[^] ?)");
  // PrintMatches(word ,reg);

  // std::string s =  "youtttube"; //n-1  ,  n-2  , n-3;
  // for (size_t i=0; i <= s.length()-3; i++){
  //   if (s[i] == s[i+1] && s[i] == s[i+2]){
  //     std::cout <<"True"<<std::endl;
  //   }
  // }

//lets search target a number  in this array 10;
// l = 0; r = N - 1 ; l = 0  and (r - l)/ 2 ;
// int target = 10;
// int middle = 0;
// const int size_ofArray = 7;
// int array[size_ofArray]={2,3,5,6,8,10,12};
// int l= 0;
// int R  =  size_ofArray - 1;
// while (l <= R)
// {
//   middle  = l + (R-l) / 2;
//   if (array[middle] == target){
//     std::cout << "Target found at the middle position"<<std::endl;
//   }
//   if (array[middle] < target){
//     l = middle + 1; 
//   }
//   else {
//     R = middle - 1;
//   return -1;  
//   }
// }


  
  return 0;
}
