#include "picoc.h"

void SayHello(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    PlatformPrintf("Hello\n");
}

void PrintInteger(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    PlatformPrintf("%d\n", Param[0]->Val->Integer);
}

#ifdef UNIX_HOST
void Random(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = random();
}
#endif

static int SomeVar = 42;
static int SomeArray[4];
void PlatformLibraryInit()
{
    struct ValueType *IntArrayType;
    
    VariableDefinePlatformVar(NULL, "somevar", &IntType, (union AnyValue *)&SomeVar, TRUE);
    
    IntArrayType = TypeGetMatching(NULL, &IntType, TypeArray, 4, NULL);
    SomeArray[0] = 12;
    SomeArray[1] = 34;
    SomeArray[2] = 56;
    SomeArray[3] = 78;
    VariableDefinePlatformVar(NULL, "somearray", IntArrayType, (union AnyValue *)&SomeArray, FALSE);
}

#ifdef SURVEYOR_HOST
extern int pwm1_mode, pwm2_mode, pwm1_init, pwm2_init;
extern int lspeed, rspeed, lspeed2, rspeed2, base_speed;
extern int sonar_data[];
extern int imgWidth, imgHeight, frame_diff_flag;

void Cdelay(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    int del;
    
    del = Param[0]->Val->Integer;
    if ((del < 0) || (del > 1000000))
        return;
    delayMS(del);
}

void Crand(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = (int)rand() % (unsigned int)(Param[0]->Val->Integer + 1);
}

void Ctime(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = (int)readRTC();
}

void Cmotors(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    lspeed = Param[0]->Val->Integer;
    if ((lspeed < -100) || (lspeed > 100))
        return;
    rspeed = Param[1]->Val->Integer;
    if ((rspeed < -100) || (rspeed > 100))
        return;
    if (!pwm1_init) {
        initPWM();
        pwm1_init = 1;
        pwm1_mode = PWM_PWM;
        base_speed = 50;
        lspeed = rspeed = 0;
    }
    setPWM(lspeed, rspeed);
}

void Cservo(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    int lspeed, rspeed;
    
    lspeed = Param[0]->Val->Integer;
    if ((lspeed < 0) || (lspeed > 100))
        return;
    rspeed = Param[1]->Val->Integer;
    if ((rspeed < 0) || (rspeed > 100))
        return;
    if (!pwm1_init) {
        initPPM1();
        pwm1_init = 1;
        pwm1_mode = PWM_PPM;
    }
    setPPM1(lspeed, rspeed);
}

void Cservo2(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    int lspeed, rspeed;
    
    lspeed = Param[0]->Val->Integer;
    if ((lspeed < 0) || (lspeed > 100))
        return;
    rspeed = Param[1]->Val->Integer;
    if ((rspeed < 0) || (rspeed > 100))
        return;
    if (!pwm2_init) {
        initPPM2();
        pwm2_init = 1;
        pwm2_mode = PWM_PPM;
    }
    setPPM2(lspeed, rspeed);
}

void Claser(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)    // laser(1) turns them on, laser(0) turns them off
{
    if (Param[0]->Val->Integer)
        lasers_on();
    else
        lasers_off();
}

/*
void imgcap()
{
    start_check();
    grab_frame();
    finish_check();
}

void imgrcap()
{
    start_check();
    grab_reference_frame();
    finish_check();
}

void imgdiff()
{
    start_check();
    eval_exp(&frame_diff_flag);
    finish_check();
}


int blob()    //    search for blob by color, index;  return center point X,Y and width Z
{
    int ix, iblob;

    start_check();
    eval_exp(&ix);
    if ((ix < 0) || (ix > 9))
        sntx_err(PARAM_ERR);

    get_token(); // look for comma separator 
    if(*token != ',')
        sntx_err(SYNTAX); 

    eval_exp(&iblob);
        
    if (iblob == 0)
        vblob((unsigned char *)FRAME_BUF, (unsigned char *)FRAME_BUF3, ix);

    if (blobcnt[iblob] == 0) {
        assign_var("x", 0); 
        assign_var("y", 0); 
        assign_var("z", 0); 
    } else {
        assign_var("x", (blobx1[iblob] + blobx2[iblob]) / 2); 
        assign_var("y", (bloby1[iblob] + bloby2[iblob]) / 2); 
        assign_var("z", (blobx2[iblob] - blobx1[iblob]) + 1); 
    }
    finish_check();
    return blobcnt[iblob];
}

int readi2c()  //  syntax   val = readi2c(device, register);
{
    unsigned char i2c_device, i2c_data[2];
    int itmp;
    
    start_check();
    eval_exp(&itmp);
    i2c_device = (unsigned char)itmp;
    
    get_token(); // look for comma separator 
    if(*token != ',')
        sntx_err(SYNTAX); 

    eval_exp(&itmp);
    i2c_data[0] = (unsigned char)itmp;
    
    i2cread(i2c_device, (unsigned char *)i2c_data, 1, SCCB_OFF);
    finish_check();
    return ((int)i2c_data[0] & 0x000000FF);
}

int readi2c2()  //  syntax   two_byte_val = readi2c(device, register); 
{
    unsigned char i2c_device, i2c_data[2];
    int itmp;
    
    start_check();
    eval_exp(&itmp);
    i2c_device = (unsigned char)itmp;
    
    get_token(); // look for comma separator 
    if(*token != ',')
        sntx_err(SYNTAX); 

    eval_exp(&itmp);
    i2c_data[0] = (unsigned char)itmp;
    
    i2cread(i2c_device, (unsigned char *)i2c_data, 2, SCCB_OFF);
    finish_check();
    return (((unsigned int)i2c_data[0] << 8) + i2c_data[1]);
}

void writei2c()  //  syntax   writei2c(device, register, value);
{
    unsigned char i2c_device, i2c_data[2];
    int itmp;
    
    start_check();
    eval_exp(&itmp);
    i2c_device = (unsigned char)itmp;
    
    get_token(); // look for comma separator 
    if(*token != ',')
        sntx_err(SYNTAX); 

    eval_exp(&itmp);
    i2c_data[int crand()
{
    start_check();
    finish_check();
    return (int)rand();
}

0] = (unsigned char)itmp;
    
    get_token(); // look for comma separator 
    if(*token != ',')
        sntx_err(SYNTAX); 

    eval_exp(&itmp);
    i2c_data[1] = (unsigned char)itmp;
    
    i2cwrite(i2c_device, (unsigned char *)i2c_data, 1, SCCB_OFF);
    finish_check();
}

int sonar()  //  syntax   val = sonar(channel);
{
    int i1;
   
    ping_sonar();
    start_check();
    eval_exp(&i1);
    
    finish_check();
    return sonar_data[i1];
}

void color() // set color bin - 
                //    color (color, ymin, ymax, umin, umax, vmin, vmax);                  
{
  int ix, y1, y2, u1, u2, v1, v2;
 
  start_check();
  eval_exp(&ix);
  if ((ix < 0) || (ix > 9))
    sntx_err(PARAM_ERR);
  get_token(); // look for comma separator 
  if(*token != ',')
    sntx_err(SYNTAX); // syntax error 
  eval_exp(&y1);
  if ((y1 < 0) || (y1 > 255))
    sntx_err(PARAM_ERR);
  get_token(); // look for comma separator 
  if(*token != ',')
    sntx_err(SYNTAX); // syntax error 
  eval_exp(&y2);
  if ((y2 < 0) || (y2 > 255))
    sntx_err(PARAM_ERR);
  get_token(); // look for comma separator 
  if(*token != ',')
    sntx_err(SYNTAX); // syntax error 
  eval_exp(&u1);
  if ((u1 < 0) || (u1 > 255))
    sntx_err(PARAM_ERR);
  get_token(); // look for comma separator 
  if(*token != ',')
    sntx_err(SYNTAX); // syntax error 
  eval_exp(&u2);
  if ((u2 < 0) || (u2 > 255))
    sntx_err(PARAM_ERR);
  get_token(); // look for comma separator 
  if(*token != ',')
    sntx_err(SYNTAX); // syntax error 
  eval_exp(&v1);
  if ((v1 < 0) || (v1 > 255))
    sntx_err(PARAM_ERR);
  get_token(); // look for comma separator 
  if(*token != ',')
    sntx_err(SYNTAX); // syntax error 
  eval_exp(&v2);
  if ((v2 < 0) || (v2 > 255))
    sntx_err(PARAM_ERR);

  ymin[ix] = y1;
  ymax[ix] = y2;
  umin[ix] = u1;
  umax[ix] = u2;
  vmin[ix] = v1;
  vmax[ix] = v2;
  finish_check();
}

void resolution()
{
    int target;
    start_check();
    eval_exp(&target);
    if(target == 'a'){
        camera_reset(160);
    } else if (target == 'b'){ 
        camera_reset(320);
    } else if (target == 'c'){
        camera_reset(640);
    } else if (target == 'A'){
        camera_reset(1280);
    }
    finish_check();
}

int crange()
{
    start_check();
    finish_check();
    return (int)laser_range(0);
}
*/

/* list of all library functions and their prototypes */
struct LibraryFunction PlatformLibrary[] =
{
    { SayHello,     "void sayhello()" },
    { PrintInteger, "void printint(int)" },
    { Cdelay,       "void delay(int)" },
    { Crand,        "int rand(int)" },
    { Ctime,        "int time()" },
    { Cmotors,      "void motors(int, int)" },
    { Cservo,       "void servo(int, int)" },
    { Cservo2,      "void servo2(int, int)" },
    { Claser,       "void laser(int)" },
    { NULL,         NULL }
};
#endif

#ifdef UNIX_HOST
/* list of all library functions and their prototypes */
struct LibraryFunction PlatformLibrary[] =
{
    { SayHello,     "void sayhello()" },
    { PrintInteger, "void printint(int)" },
    { Random,       "int random()" },
    { NULL,         NULL }
};
#endif

