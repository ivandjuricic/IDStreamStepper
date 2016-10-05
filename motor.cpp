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
    myfile.open ("/home/ivan/Desktop/a.txt");
    if (myfile.is_open())
    {
        getline(myfile, line);
        myfile.close();
    }
    return atoi(line.c_str());
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
}
