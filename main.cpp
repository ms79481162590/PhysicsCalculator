/*
Oct 29th, 2021
Dr T. TCC
Physics Calucaltor
Fundamentals of getters and setters and how menus operate along with functions
*/

#include <iostream>
#include "Input_Validation_Extended.h"
#include <cmath>
//Function Prototypes 
double S, T;
double averageSV;
double V;
double averageAC;
double U;
double A;
double M;
double G;
double VelocityMotionE;
double PAMotionFormula;
double Vsquared;
double iandFinalSpeeds;
double Newtons;
double Weight;
double Momentum;
string mps = "m/s";
string accel = "metre per second squared";
string motion = "(kg⋅ m/s)";
string newt = "(m/s2)";
string weight = "kilograms";
string momentum = "kilogram meter per second";
void Velocity(double);
void Accelaration(double);
void Motion(double);
void motionmenu(double);
void MotionMenu1(double);
void MotionMenu2(double);
void MotionMenu3(double);
void MotionMenu4(double);

void Newton(double);

void work(string);
void cleanscreen();

void clearScreen()
{
  system("clear");
}
void setVelocity(double s, double t)
{
  cout << "Enter value for speed for Average Speed Velocity:";
  s = getValidatedInput<double>();
  cout << "Enter value for time for Average Speed Velocity:";
  t = getValidatedInput<double>();
  S = s;
  T = t;
}

double getVelocity()
{
  averageSV = S / T;
  return averageSV;
}

void setAcceleration(double v, double t)
{
  cout << "Enter value for velocity for Average Acceleration:";
  v = getValidatedInput<double>();
  cout << "Enter value for time for Average Acceleration:";
  t = getValidatedInput<double>();
  V = v;
  T = t;
}

double getAcceleration()
{
  averageAC = V / T;
  return averageAC;
}

void setMotionMenu1(double u, double a, double t)
{
 cout << "Enter a value for U (initial position):";  
  u = getValidatedInput<double>();
  cout << "Enter a value for Acceleration:";
  a = getValidatedInput<double>();
  cout << "Enter a value for Time:";
  t = getValidatedInput<double>();
  U = u;
  A = a;
  T = t;
}

double getMotionMenu1()
{
  VelocityMotionE = U + A*T;
  return VelocityMotionE;
}

void setMotionMenu2(double u, double t, double a)
{
 cout << "Enter a value for U (initial position):";  
  u = getValidatedInput<double>();
  cout << "Enter a value for Time:";
  t = getValidatedInput<double>();
  cout << "Enter a value for Acceleration:";
  a = getValidatedInput<double>();
  A = a;
  U = u;
  T = t;
}

double getMotionMenu2()
{
  PAMotionFormula = (U * T) + (1/2); 
  PAMotionFormula += pow(A*T,2);
  return PAMotionFormula;
}
void setMotionMenu3(double u, double a, double s)
{
 cout << "Enter a value for U (initial position):";  
  u = getValidatedInput<double>();
  cout << "Enter a value for Accelertion:";
  a = getValidatedInput<double>();
  cout << "Enter a value for Speed:";
  s = getValidatedInput<double>();
  U = u;
  A = a;
  S = s;

}

double getMotionMenu3()
{
 Vsquared = pow(U,2) + (2*A*S);
 return Vsquared;
}
void setMotionMenu4(double u, double v, double t)
{
 cout << "Enter a value for U (initial position):";  
  u = getValidatedInput<double>();
 cout << "Enter value for velocity:";
  v = getValidatedInput<double>();
  cout << "Enter a value for T(time):";
  t = getValidatedInput<double>();
  U = u;
  V = v;
  T = t;
}
double getMotionMenu4() 
{
  iandFinalSpeeds = 1/2U+V * T;
  return iandFinalSpeeds;
}


void motionmenu()
{
  cout << "Choose a motion formula: " << endl << "1. Velocity Motion Formula " << endl << "2. Displacement with Positive Acceleration Motion Formula " << endl << "3. Velocity Squared Motion Formula " << endl << "4. Displacement Knowing Initial and Final Speeds "<< " 5. clear screen " << endl;
  int motionMenuNum = getValidatedInput<int>();
  switch (motionMenuNum)
  {
    case 1:
    cout << "Velocity Motion Formula requires U, A and T values (V = U + AT): ";
    setMotionMenu1(U, A, T);
    cout << "Velocity Motion Formula:";
    getMotionMenu1();
    cout << motion;
    break;
    case 2:
    cout << "Displacement with Positive Acceleration Motion Formula requires U, T, A values (S = UT + 1/2 AT^2)";
    setMotionMenu2(U, T, A);
    getMotionMenu2();
     cout << motion;
    break;
    case 3:
     cout << motion;
    cout << "Velocity Squared Motion Formula requires U, A, S values (v^2 = u^2 + 2as)";
    setMotionMenu3(U, A, S);
    getMotionMenu3();
    break;
    case 4:
     cout << motion;
    cout << "Displacement Knowing Initial and Final Speeds requires values U, V, T (1/2(u + v)t):";
    setMotionMenu4(U, V, T);
    getMotionMenu4();
    case 5:
    clearScreen();
    break;
    default:
    cout << "not a valid option";

  }
}

void setNewtons(double m, double a)
{
  cout << "Enter a value for M(mass):";
  m = getValidatedInput<double>();
  cout << "Enter a value for Acceleration:";
  a = getValidatedInput<double>();
  M = m;
  A = a;
}
double getNewtons()
{
 Newtons = M * A;
 return Newtons;
}

void setWeight(double m, double g)
{
  cout << "Enter a value for M (mass):";
  m = getValidatedInput<double>();
   cout << "Enter a value for G (gravity):";
  g = getValidatedInput<double>();
  M = m;
  G = g;

}

double getWeight()
{
  Weight = M * G;
  return Weight;
}

void setMomentum(double m, double v)
{
cout << "Enter a value for M (mass):";
  m = getValidatedInput<double>();
  cout << "Enter a value for V (velocity):";
  v = getValidatedInput<double>();
  M = m;
  V = v;
}

double getMomentum()
{
 Momentum = M * V;
 return Momentum;
}

int main() 
{
  
  int menuNum;
  do 
  {
  std::cout << "Choose your formula:" << endl;
  cout << " 1. Velocity " << endl <<  " 2. Acceleration " << endl << " 3. Motion " << endl << " 4. Newton's Second Law " << endl <<  " 5. Weight " << endl <<  " 6. Momentum" << endl<<  " 7. clear screen " << endl << "Enter 8 to Exit" << endl;
  
  cout << "Enter an option: ";
  menuNum = getValidatedInput<int>();
  
  switch (menuNum)
  {
    case 1:  
    cout << "Velocity formula requires speed and time values (V = S/T): " << endl;
    setVelocity(S, T);
    cout << "Average Speed Velocity: ";
    cout << getVelocity() << mps << endl;
    break;

    case 2:
    cout << "Average Acceleration formula requires velocity and time (A = V/T): ";
    setAcceleration(V, T);
    cout << "Average Acceleration:" << getAcceleration() << accel << endl;
    break;

    case 3:
    cout << "Choose one of four Motion Formulas:";
    motionmenu();
    break;

    case 4:
    cout << "Newton's second law:";
    setNewtons(M, A);
    cout << " Newtons Second Law = " << getNewtons() << newt;
    break;

    case 5:
    cout << "Weight Formula:";
    setWeight(M, G);
    cout << "Weigth formula = " << getWeight() << weight;

    break;

    case 6:
    cout << "Momentum Formula:";
    setMomentum(M, V);
    cout << "Momentum Formula = " << getMomentum() << momentum;
    break;

    case 7: 

    cout << " 7 = (E)scape clear screen";
    clearScreen();
    break;
   
  }
  }
  while (menuNum != 8); 
    return 8;
  } 
