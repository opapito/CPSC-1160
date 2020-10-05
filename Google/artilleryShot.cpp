#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


// constants which are used throughout the program
#define kVelocity 200.0  // initial velocity of 200 ft/sec
#define kGravity 32.2    // gravity for distance calculation
#define PI 3.14159265


void StartUp(){
  cout << "Welcome to Artillery." << endl;
  cout << "You are in the middle of a war and being charged by thousands of enemies." << endl;
  cout << "You have one cannon, which you can shoot at any angle." << endl;
  cout << "You only have 10 cannonballs for this target.." << endl;
  cout << "Let's begin..." << endl;
}

int Distance(){
  // Initialize random seed.
  srand (time(NULL));

  // Generate random number between 1 and 100
  return (rand() % 500) + 1;

}

bool HitTarget(double angle, int enemyDistance){
  double shotDistance{0};
  double rad{angle*PI/180};
  double time_in_air{0};
  
  time_in_air = (2.0 * kVelocity * sin(rad))/kGravity;
  shotDistance = round((kVelocity * cos(rad))*time_in_air);
  cout << "\nShoot distance= " << shotDistance << endl;
  if (shotDistance > enemyDistance){
    cout << "You over shot by " << shotDistance - enemyDistance << endl;
  } else {
    cout << "You under shot by " << enemyDistance - shotDistance << endl;
  }
  return (shotDistance == enemyDistance); 

}

int Fire(){
  int enemyDistance{Distance()}, shots{10};
  double angle{0};
  bool hit{false};

  cout << "The enemy is " << enemyDistance << " feet away!!!" << endl;
  while (!hit && shots > 0){
    cout << "What angle?";
    cin >> angle;
    hit = HitTarget(angle, enemyDistance);
    if (!hit){
      shots--;
    } else {
      cout << "You hit him!!!" << endl;
      cout << "It took you " << 10 - shots << " shots. Only " << shots << " shots remain." << endl;
      return 1;
    }

  }
  return 0;
}

int main(){
  int killed{0};
  char done{'y'};
  StartUp();
  do {
    killed = Fire(); // contains the main loop of each round
    if (!killed){
      cout << "You run out of shoots !!!" << endl;
    } else {
      cout << "You have killed " << killed << " enemy." << endl;
    }
    cout << "I see another one, care to shoot again? (Y/N)" << endl;
    cin >> done;
  } while (done != 'n');
  return 0;
}