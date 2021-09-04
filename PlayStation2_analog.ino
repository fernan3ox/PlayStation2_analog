#include <PS2X_lib.h>

PS2X ps2x;

int error = 0 ;
byte vibrate = 0;


void setup() {

 Serial.begin(9600);
 error=ps2x.config_gamepad(8,12,A0,13,true,true); //clock, comand , attention,data,sensivilidad,vibracion
 
 if (error==0){
  Serial.println("Controlador , encontrado y configurado");
 }
 else{
  Serial.println("Error, Mando no encontrado");
 }
}

void loop() {

  int lx;
  int ly;
  int rx,ry;

  ps2x.read_gamepad(false,vibrate);

  ly=ps2x.Analog(PSS_LY),DEC;
  lx=ps2x.Analog(PSS_LX),DEC;

  //lo mejoramos

 
  if(ly <= 127){
    ly=-1*ly+127;
  }else{
    ly=-1*(ly-128);
  }
 lx=lx-127;


  //2da mejora
  if(ly==-128){

    ly = -127;
    
  }
  if(lx==128){
    lx=127;
  }

  Serial.print("ly = ");
  Serial.print(ly);
  Serial.print("       lx = ");
  Serial.println(lx);
  
  
  

  delay(50);
  
  }
