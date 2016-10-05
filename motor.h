#ifndef MOTOR_H
#define MOTOR_H


class Motor
{
public:
    Motor();
    ~Motor();
    void Forwards(int steps);
    void Backwards(int steps);

private:
    //virtual int readSteps();
    unsigned long microseconds;
    int directionPin;
    int stepPin;
    int enablePin;
    int defaultSteps;
};

#endif // MOTOR_H
