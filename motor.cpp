#include "motor.h"
#include <wiringPi.h>
#include  <QDebug>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <string>

int readSteps(){
    std::ifstream myfile;
    std::string line;
    myfile.open("/home/ivan/Desktop/a.txt"); //place file wherever
    if (myfile.is_open())
    {
        getline(myfile, line);
        myfile.close();
    }
    return atoi(line.c_str());
}

void writeNewSteps(int steps){
    int oldSteps = readSteps();
    std::ofstream myfile;
    myfile.open("/home/ivan/Desktop/a.txt"); //again, place wherever
    myfile << oldSteps + steps;
    myfile.close();
}


Motor::Motor(){
    microseconds = 100;
    directionPin = 23;
    stepPin = 24;
    enablePin = 22;
    defaultSteps = readSteps();

    if (wiringPiSetup() == -1){
        qDebug() << "No GPIO control available" << endl;
    }

    int pins[3] = {directionPin, stepPin, enablePin};
    for(int i; i<3;i++){
    pinMode(pins[i], OUTPUT);
    }
}

Motor::~Motor(){
    qDebug() << "Exiting" << endl;
}


void Motor::Forwards(int steps=0){
    if (steps==0)
        steps=defaultSteps;
    digitalWrite(enablePin, HIGH);
    digitalWrite(directionPin, HIGH);
    int i = 0;
    while(i < steps)
    {
        digitalWrite(stepPin, HIGH);
        usleep(microseconds);
        digitalWrite(stepPin, LOW);
        usleep(microseconds);
        i++;
    }
    digitalWrite(directionPin, LOW);
    digitalWrite(enablePin, LOW);
    writeNewSteps(-steps);
}


void Motor::Backwards(int steps=0){
    if (steps==0)
        steps=defaultSteps;
    digitalWrite(enablePin, HIGH);
    digitalWrite(directionPin, LOW);
    int i = 0;
    while(i < steps)
    {
        digitalWrite(stepPin, HIGH);
        usleep(microseconds);
        digitalWrite(stepPin, LOW);
        usleep(microseconds);
        i++;
    }
    digitalWrite(directionPin, LOW);
    digitalWrite(enablePin, LOW);
    writeNewSteps(steps);
}

void Motor::cancel(){
    int currentSteps = readSteps();
     qDebug() << currentSteps << defaultSteps << endl;
    int stepDifference = defaultSteps - currentSteps;
    if(currentSteps < defaultSteps)
        this->Backwards(abs(stepDifference));
    else if(currentSteps > defaultSteps)
        this->Forwards(abs(stepDifference));
    else
    {
        qDebug() << "Prodje" << endl;
        return;
    }
}
