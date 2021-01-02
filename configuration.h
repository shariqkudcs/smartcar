/*Assumption:The total swing of the servo from min to max is 180 degrees*/
#define HEAD_FRONT  277 //90 degree
#define HEAD_180 HEAD_MAX //Full 180 degrees
#define HEAD_120 HEAD_FRONT + 120 //135 degrees
#define HEAD_40 HEAD_MIN + 102 //45 degrees infact
#define HEAD_0 HEAD_MIN //Zero degree
#define HEAD_MAX 482
#define HEAD_MIN  72
#define HEAD_SERVO_NUM 0

#define PWMA 9 // Needs to be a PWM pin to be able to control motor speed
#define DIRA 8 //Motor direction
#define PWMB 6 // Needs to be a PWM pin to be able to control motor speed
#define DIRB 7 //Motor direction

//Should you keep PWMA and PWMB for speed????? since it is from chinese code
#define MOTOR_GO_FORWARD  {digitalWrite(DIRA,LOW);analogWrite(PWMA,250);digitalWrite(DIRB,LOW);analogWrite(PWMB,250);}                             
#define MOTOR_GO_BACK   {digitalWrite(DIRA,HIGH);analogWrite(PWMA,250);digitalWrite(DIRB,HIGH);analogWrite(PWMB,250);}
#define MOTOR_GO_LEFT   {digitalWrite(DIRA,LOW);analogWrite(PWMA,250);digitalWrite(DIRB,HIGH);analogWrite(PWMB,250);}
#define MOTOR_GO_RIGHT    {digitalWrite(DIRA,HIGH);analogWrite(PWMA,250);digitalWrite(DIRB,LOW);analogWrite(PWMB,250);}
#define MOTOR_GO_STOP   {digitalWrite(DIRA,LOW);analogWrite(PWMA,0);digitalWrite(DIRB,LOW);analogWrite(PWMB,0);}

/*From left to right, connect to D3,A1-A3 ,D10*/
#define LFSensor_0  3
#define LFSensor_1 A1
#define LFSensor_2 A2
#define LFSensor_3 A3
#define LFSensor_4 10



#define Echo_PIN   11 // Ultrasonic Echo pin connect to D11
#define Trig_PIN   12  // Ultrasonic Trig pin connect to D12

#define BUZZ_PIN     13  //buzzer connect to D13

int sensor[5];
#define AD_SPEED1   200  //avoidance motor speed
#define BACK_SPEED1  100     //back speed
#define BACK_SPEED2  150     //back speed
#define TRACK_SPEED   150  //line follow motor speed

int leftscanval, centerscanval, rightscanval, ldiagonalscanval, rdiagonalscanval;
int distancelimit = 30; //distance limit for obstacles in front           
int sidedistancelimit = 30; //minimum distance in cm to obstacles at both sides (the car will allow a shorter distance sideways)

const int turntime = 800; //Time the robot spends turning (miliseconds)
const int backtime = 600; //Time the robot spends turning (miliseconds)
int distance;
int numcycles = 0;

int thereis;
bool flag1=false;
bool stopFlag = true;
bool JogFlag = false;
uint16_t JogTimeCnt = 0;
uint32_t JogTime=0;

#define MAX_PACKETSIZE 32    //Serial receive buffer
char buffUART[MAX_PACKETSIZE];
unsigned int buffUARTIndex = 0;
unsigned long preUARTTick = 0;

enum DS
{
  MANUAL_DRIVE,
  AUTO_DRIVE_LF, //line follow
  AUTO_DRIVE_UO  //ultrasonic obstruction
}Drive_Status=MANUAL_DRIVE;

enum DN
{ 
  GO_ADVANCE, 
  GO_LEFT, 
  GO_RIGHT,
  GO_BACK,
  STOP_STOP,
  DEF
}Drive_Num=DEF;
