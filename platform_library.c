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
    ReturnValue->Val->Integer = rand();
}
#endif

static int SomeVar = 42;
static int SomeArray[4];
static int Blobcnt, Blobx1, Blobx2, Bloby1, Bloby2, Iy1, Iy2, Iu1, Iu2, Iv1, Iv2;
void PlatformLibraryInit()
{
    struct ValueType *IntArrayType;

    VariableDefinePlatformVar(NULL, "somevar", &IntType, (union AnyValue *)&SomeVar, TRUE);

    VariableDefinePlatformVar(NULL, "blobcnt", &IntType, (union AnyValue *)&Blobcnt, FALSE);
    VariableDefinePlatformVar(NULL, "blobx1", &IntType, (union AnyValue *)&Blobx1, FALSE);
    VariableDefinePlatformVar(NULL, "blobx2", &IntType, (union AnyValue *)&Blobx2, FALSE);
    VariableDefinePlatformVar(NULL, "bloby1", &IntType, (union AnyValue *)&Bloby1, FALSE);
    VariableDefinePlatformVar(NULL, "bloby2", &IntType, (union AnyValue *)&Bloby2, FALSE);
    VariableDefinePlatformVar(NULL, "y1", &IntType, (union AnyValue *)&Iy1, FALSE);
    VariableDefinePlatformVar(NULL, "y2", &IntType, (union AnyValue *)&Iy2, FALSE);
    VariableDefinePlatformVar(NULL, "u1", &IntType, (union AnyValue *)&Iu1, FALSE);
    VariableDefinePlatformVar(NULL, "u2", &IntType, (union AnyValue *)&Iu2, FALSE);
    VariableDefinePlatformVar(NULL, "v1", &IntType, (union AnyValue *)&Iv1, FALSE);
    VariableDefinePlatformVar(NULL, "v2", &IntType, (union AnyValue *)&Iv2, FALSE);
    
    IntArrayType = TypeGetMatching(NULL, &IntType, TypeArray, 4, NULL);
    SomeArray[0] = 12;
    SomeArray[1] = 34;
    SomeArray[2] = 56;
    SomeArray[3] = 78;
    VariableDefinePlatformVar(NULL, "somearray", IntArrayType, (union AnyValue *)&SomeArray, FALSE);
}

#ifdef SURVEYOR_HOST

void Csignal(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)  // check for kbhit, return t or nil
{
    unsigned char ch;
    if (getchar(&ch))
        ReturnValue->Val->Integer = 1;
    else
        ReturnValue->Val->Integer = 0;
}

void Cinput(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)  // return 0-9 from console input
{
    ReturnValue->Val->Integer = getch() & 0x0F;
}

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
        ProgramFail(NULL, "motors():  left motor value out of range");
    rspeed = Param[1]->Val->Integer;
    if ((rspeed < -100) || (rspeed > 100))
        ProgramFail(NULL, "motors():  right motor value out of range");
    if (!pwm1_init) {
        initPWM();
        pwm1_init = 1;
        pwm1_mode = PWM_PWM;
        base_speed = 50;
    }
    setPWM(lspeed, rspeed);
}

void Cservos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    int lspeed, rspeed;
    
    lspeed = Param[0]->Val->Integer;
    if ((lspeed < 0) || (lspeed > 100))
        ProgramFail(NULL, "servos():  TMR2 value out of range");
    rspeed = Param[1]->Val->Integer;
    if ((rspeed < 0) || (rspeed > 100))
        ProgramFail(NULL, "servos()():  TMR3 value out of range");
    if (!pwm1_init) {
        initPPM1();
        pwm1_init = 1;
        pwm1_mode = PWM_PPM;
    }
    setPPM1(lspeed, rspeed);
}

void Cservos2(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    int lspeed, rspeed;
    
    lspeed = Param[0]->Val->Integer;
    if ((lspeed < 0) || (lspeed > 100))
        ProgramFail(NULL, "servos2():  TMR6 value out of range");
    rspeed = Param[1]->Val->Integer;
    if ((rspeed < 0) || (rspeed > 100))
        ProgramFail(NULL, "servos2():  TMR7 value out of range");
    if (!pwm2_init) {
        initPPM2();
        pwm2_init = 1;
        pwm2_mode = PWM_PPM;
    }
    setPPM2(lspeed, rspeed);
}

void Claser(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)    // laser(1) turns them on, laser(0) turns them off
{
    *pPORTHIO &= 0xFD7F;  // turn off both lasers
    switch (Param[0]->Val->Integer) {
        case 1:
            *pPORTHIO |= 0x0080;  // turn on left laser
            break;
        case 2:
            *pPORTHIO |= 0x0200;  // turn on right laser
            break;
        case 3:
            *pPORTHIO |= 0x0280;  // turn on both lasers
            break;
    }
}

void Csonar(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) // read sonar module
{
    unsigned int i;
    i = Param[0]->Val->Integer;
    if ((i<1) || (i>4)) {
        ProgramFail(NULL, "sonar():  1, 2, 3, 4 are only valid selections");
    }
    ping_sonar();
    ReturnValue->Val->Integer = sonar_data[i] / 100;
}

void Crange(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = laser_range(0);
}

void Cvcolor(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) // set color bin - 
                //    vcolor (color, ymin, ymax, umin, umax, vmin, vmax);                  
{
    int ix;
    
    ix = Param[0]->Val->Integer;
    ymin[ix] = Param[1]->Val->Integer;
    ymax[ix] = Param[2]->Val->Integer;
    umin[ix] = Param[3]->Val->Integer;
    umax[ix] = Param[4]->Val->Integer;
    vmin[ix] = Param[5]->Val->Integer;
    vmax[ix] = Param[6]->Val->Integer;
}

void Cvcap(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    grab_frame();   // capture frame for processing
}

void Cvrcap(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    grab_reference_frame();   // capture reference frame for differencing
}

void Cvdiff(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    frame_diff_flag = Param[0]->Val->Integer;   // set/clear frame_diff_flag
}

void Cvpix(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    int x, y, ix;
    x = Param[0]->Val->Integer;
    y = Param[1]->Val->Integer;
    ix = vpix((unsigned char *)FRAME_BUF, x, y);
    Iy1 = ((ix>>16) & 0x000000FF);  // Y1
    Iu1 = ((ix>>24) & 0x000000FF);  // U
    Iv1 = ((ix>>8)  & 0x000000FF);  // V
}

void Cvmean(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    vmean((unsigned char *)FRAME_BUF);
    Iy1 = mean[0];
    Iu1 = mean[1];
    Iv1 = mean[2];
}

//    search for blob by color, index;  return center point X,Y and width Z
void Cvblob(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)    {
    int ix, iblob, numblob;

    ix = Param[0]->Val->Integer;
    if (ix > MAX_COLORS)
        ProgramFail(NULL, "blob():  invalid color index");
    iblob = Param[1]->Val->Integer;
    if (iblob > MAX_BLOBS)
        ProgramFail(NULL, "blob():  invalid blob index");
        
    numblob = vblob((unsigned char *)FRAME_BUF, (unsigned char *)FRAME_BUF3, ix);

    if (blobcnt[iblob] == 0) {
        Blobcnt = 0;
    } else {
        Blobcnt = blobcnt[iblob];
        Blobx1 = blobx1[iblob];
        Blobx2 = blobx2[iblob];
        Bloby1 = bloby1[iblob];
        Bloby2 = bloby2[iblob];
    }
    ReturnValue->Val->Integer = numblob;
}

void Ccompass(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)  // return reading from HMC6352 I2C compass
{
    unsigned char i2c_data[2];
    unsigned int ix;
    
    i2c_data[0] = 0x41;  // read compass twice to clear last reading
    i2cread(0x21, (unsigned char *)i2c_data, 2, SCCB_ON);
    i2c_data[0] = 0x41;
    i2cread(0x21, (unsigned char *)i2c_data, 2, SCCB_ON);
    ix = ((i2c_data[0] << 8) + i2c_data[1]) / 10;
    ReturnValue->Val->Integer = ix;
}

void Creadi2c(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)  //  syntax   val = readi2c(device, register);
{
    unsigned char i2c_device, i2c_data[2];
    
    i2c_device = (unsigned char)Param[0]->Val->Integer;
    i2c_data[0] = (unsigned char)Param[1]->Val->Integer;
    
    i2cread(i2c_device, (unsigned char *)i2c_data, 1, SCCB_OFF);
    ReturnValue->Val->Integer = ((int)i2c_data[0] & 0x000000FF);
}

void Creadi2c2(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)  //  syntax   two_byte_val = readi2c(device, register); 
{
    unsigned char i2c_device, i2c_data[2];

    i2c_device = (unsigned char)Param[0]->Val->Integer;
    i2c_data[0] = (unsigned char)Param[1]->Val->Integer;
    
    i2cread(i2c_device, (unsigned char *)i2c_data, 2, SCCB_OFF);
    ReturnValue->Val->Integer = (((unsigned int)i2c_data[0] << 8) + i2c_data[1]);
}

void Cwritei2c(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)  //  syntax   writei2c(device, register, value);
{
    unsigned char i2c_device, i2c_data[2];

    i2c_device = (unsigned char)Param[0]->Val->Integer;
    i2c_data[0] = (unsigned char)Param[1]->Val->Integer;
    i2c_data[1] = (unsigned char)Param[2]->Val->Integer;
    
    i2cwrite(i2c_device, (unsigned char *)i2c_data, 1, SCCB_OFF);
}

static int cosine[] = {
10000, 9998, 9994, 9986, 9976, 9962, 9945, 9925, 9903, 9877, 
 9848, 9816, 9781, 9744, 9703, 9659, 9613, 9563, 9511, 9455, 
 9397, 9336, 9272, 9205, 9135, 9063, 8988, 8910, 8829, 8746, 
 8660, 8572, 8480, 8387, 8290, 8192, 8090, 7986, 7880, 7771, 
 7660, 7547, 7431, 7314, 7193, 7071, 6947, 6820, 6691, 6561, 
 6428, 6293, 6157, 6018, 5878, 5736, 5592, 5446, 5299, 5150, 
 5000, 4848, 4695, 4540, 4384, 4226, 4067, 3907, 3746, 3584, 
 3420, 3256, 3090, 2924, 2756, 2588, 2419, 2250, 2079, 1908, 
 1736, 1564, 1392, 1219, 1045,  872,  698,  523,  349,  175, 
    0 
};

void Csin(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)  // sin(angle)
{
    int ix;
    
    ix = Param[0]->Val->Integer;  // input to function is angle in degrees
    while (ix < 0)
        ix = ix + 360;
    while (ix >= 360)
        ix = ix - 360;
    if (ix < 90)  { ReturnValue->Val->Integer = cosine[90-ix] / 100;  return; }
    if (ix < 180) { ReturnValue->Val->Integer = cosine[ix-90] / 100;  return; }
    if (ix < 270) { ReturnValue->Val->Integer = -cosine[270-ix] / 100;  return; }
    if (ix < 360) { ReturnValue->Val->Integer = -cosine[ix-270] / 100;  return; }
}

void Ccos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)  // cos(angle)
{
    int ix;
    
    ix = Param[0]->Val->Integer;  // input to function is angle in degrees
    while (ix < 0)
        ix = ix + 360;
    while (ix >= 360)
        ix = ix - 360;
    if (ix < 90)  { ReturnValue->Val->Integer = cosine[ix] / 100;  return; }
    if (ix < 180) { ReturnValue->Val->Integer = -cosine[180-ix] / 100;  return; }
    if (ix < 270) { ReturnValue->Val->Integer = -cosine[ix-180] / 100;  return; }
    if (ix < 360) { ReturnValue->Val->Integer = cosine[360-ix] / 100;  return; }
}

void Ctan(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)  // tan(angle)
{
    int ix;
    
    ix = Param[0]->Val->Integer;  // input to function is angle in degrees
    while (ix < 0)
        ix = ix + 360;
    while (ix >= 360)
        ix = ix - 360;
    if (ix == 90)  { ReturnValue->Val->Integer = 9999;  return; }
    if (ix == 270) { ReturnValue->Val->Integer = -9999;  return; }
    if (ix < 90)   { ReturnValue->Val->Integer = (100 * cosine[90-ix]) / cosine[ix];  return; }
    if (ix < 180)  { ReturnValue->Val->Integer = -(100 * cosine[ix-90]) / cosine[180-ix];  return; }
    if (ix < 270)  { ReturnValue->Val->Integer = (100 * cosine[270-ix]) / cosine[ix-180];  return; }
    if (ix < 360)  { ReturnValue->Val->Integer = -(100 * cosine[ix-270]) / cosine[360-ix];  return; }
}

void Casin(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)  // asin(y,hyp)
{
    int y, hyp, quot, sgn, ix;
	y = Param[0]->Val->Integer;
	hyp = Param[1]->Val->Integer;
    if (y > hyp)
        ProgramFail(NULL, "asin():  opposite greater than hypotenuse");
	if (y == 0) {
        ReturnValue->Val->Integer = 0;
	    return;
	}
	sgn = hyp * y;
	if (hyp < 0) 
	    hyp = -hyp;
	if (y < 0)
	    y = -y;
	quot = (y * 10000) / hyp;
	if (quot > 9999)
	    quot = 9999;
	for (ix=0; ix<90; ix++)
	    if ((quot < cosine[ix]) && (quot >= cosine[ix+1]))
	        break;
	if (sgn < 0)
	    ReturnValue->Val->Integer = -(90-ix);
	else
	    ReturnValue->Val->Integer = 90-ix;
}

void Cacos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)  // acos(x,hyp)
{
    int x, hyp, quot, sgn, ix;
	x = Param[0]->Val->Integer;
	hyp = Param[1]->Val->Integer;
    if (x > hyp)
        ProgramFail(NULL, "acos():  adjacent greater than hypotenuse");
	if (x == 0) {
	    if (hyp < 0)
            ReturnValue->Val->Integer = -90;
        else
            ReturnValue->Val->Integer = 90;
	    return;
	}
	sgn = hyp * x;
	if (hyp < 0) 
	    hyp = -hyp;
	if (x < 0)
	    x = -x;
	quot = (x * 10000) / hyp;
	if (quot > 9999)
	    quot = 9999;
	for (ix=0; ix<90; ix++)
	    if ((quot < cosine[ix]) && (quot >= cosine[ix+1]))
	        break;
	if (sgn < 0)
	    ReturnValue->Val->Integer = -ix;
	else
	    ReturnValue->Val->Integer = ix;
}

void Catan(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)  // atan(y,x)
{
    int x,y, angle, coeff_1, coeff_2, r;
	y = Param[0]->Val->Integer;
	x = Param[1]->Val->Integer;
	if (x == 0) {
	    if (y >= 0)
	        ReturnValue->Val->Integer = 90;
	    else
	        ReturnValue->Val->Integer = -90;
	    return;
	}
	coeff_1 = 3141/4;
	coeff_2 = coeff_1*3;
    if (y < 0)
        y = -y;
	if (x >= 0) {
		r = (x - y)*1000 / (x + y);
		angle = (coeff_1*1000 - coeff_1 * r);
	} else {
		r = (x + y)*1000 / (y - x);
		angle = (coeff_2*1000 - coeff_1 * r);
	}
	angle = angle*57/1000000;
	if (y < 0)
	    ReturnValue->Val->Integer = -angle;
	else
	    ReturnValue->Val->Integer = angle;
} 

/* list of all library functions and their prototypes */
struct LibraryFunction PlatformLibrary[] =
{
    { SayHello,     "void sayhello()" },
    { PrintInteger, "void printint(int)" },
    { Csignal,      "int signal()" },
    { Cinput,       "int input()" },
    { Cdelay,       "void delay(int)" },
    { Crand,        "int rand(int)" },
    { Ctime,        "int time()" },
    { Cmotors,      "void motors(int, int)" },
    { Cservos,      "void servos(int, int)" },
    { Cservos2,     "void servos2(int, int)" },
    { Claser,       "void laser(int)" },
    { Csonar,       "void sonar(int)" },
    { Crange,       "int range()" },
    { Cvcolor,      "void vcolor(int, int, int, int, int, int, int)" },
    { Cvcap,        "void vcap()" },
    { Cvrcap,       "void vrcap()" },
    { Cvdiff,       "void vdiff(int)" },
    { Cvpix,        "void vpix(int, int)" },
    { Cvmean,       "void vmean()" },
    { Cvblob,       "int vblob(int, int)" },
    { Ccompass,     "int compass(int)" },
    { Creadi2c,     "int readi2c(int, int)" },
    { Creadi2c2,    "int readi2c2(int, int)" },
    { Cwritei2c,    "void writei2c(int, int, int)" },
    { Csin,         "int sin(int)" },
    { Ccos,         "int cos(int)" },
    { Ctan,         "int tan(int)" },
    { Casin,        "int asin(int, int)" },
    { Cacos,        "int acos(int, int)" },
    { Catan,        "int atan(int, int)" },
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

