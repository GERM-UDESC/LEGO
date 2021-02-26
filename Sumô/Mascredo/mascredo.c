#pragma config(Sensor, S2, U1, sensorEV3_Ultrasonic)
#pragma config(Sensor, S3, U2, sensorEV3_Ultrasonic)
#pragma config(Sensor, S1, C1, sensorEV3_Color)
#pragma config(Sensor, S4, C2, sensorEV3_Color)
#pragma config(Motor, motorA, arma, tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor, motorB, esq, tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor, motorC, dir, tmotorEV3_Large, PIDControl, encoder)
int graus=95;
int tempo=800;
int vel=40;
int faixa = 0;
int vira = 0;
int chao = 42;
int frente = -38;
task main()
{
	while (!getButtonPress(buttonEnter)){
		setMotorSpeed(dir, 00);
  	setMotorSpeed(esq, 00);
	}

  wait1Msec(5000);
  setLEDColor(ledGreen);

  while(!faixa){
  	setMotorSpeed(esq, 100);
	setMotorSpeed(dir, 100);

		if((getColorReflected(C1) > 10)||(getColorReflected(C2) > 10)){
			faixa = 1;
			}
  	}
  setMotorSpeed(dir, 00);
  setMotorSpeed(esq, 00);
  playSound(soundBeepBeep);
  setLEDColor(ledRed);
  moveMotorTarget(arma, graus, vel);
  setMotorSpeed(esq, -10);
  setMotorSpeed(dir, -100);
  wait1Msec(1000);
  setMotorSpeed(esq, 00);
  setMotorSpeed(dir, 00);

	while (true) {

		if ((getColorReflected(C1) < 10)&& (getColorReflected(C2) < 10)){

			if((getUSDistance(U1) < 40) && (getUSDistance(U2) < 40)){

				setMotorSpeed(esq, 90);
				setMotorSpeed(dir, 90);
			}
			if((getUSDistance(U1) < 20) && (getUSDistance(U2) < 20)){
				setMotorSpeed(esq, 100);
				setMotorSpeed(dir, 100);
				moveMotorTarget(arma, frente, 100);
			}
			moveMotorTarget(arma, chao, 100);

			if ((getUSDistance(U1) < 40) && (getUSDistance(U2) > 40)){

				setMotorSpeed(esq, 55);
				setMotorSpeed(dir, 90);
				vira = 1;
			}
			if((getUSDistance(U1) > 40) && (getUSDistance(U2) < 40)){

				setMotorSpeed(esq, 90);
				setMotorSpeed(dir, 55);
				vira = 0;
			}
			if((getUSDistance(U1) > 40) && (getUSDistance(U2) > 40)/* && (vira == 1)*/){

				setMotorSpeed(esq, -50);
				setMotorSpeed(dir, 50);
			}
			/*if((getUSDistance(U1) > 40) && (getUSDistance(U2) > 40) && (vira == 0)){
				setMotorSpeed(esq, 50);
				setMotorSpeed(dir, -50);
			}*/
		}
		if((getColorReflected(C1) < 10) && (getColorReflected(C2) > 10)){

			setMotorSpeed(esq, -100);
			setMotorSpeed(dir, -45);
			wait1Msec(tempo);
		}
		if((getColorReflected(C1) > 10) && (getColorReflected(C2) < 10)){

			setMotorSpeed(esq, -45);
			setMotorSpeed(dir, -100);
			wait1Msec(tempo);
		}
		if((getColorReflected(C1) > 10) && (getColorReflected(C2) > 10)){

			setMotorSpeed(esq, -100);
			setMotorSpeed(dir, -100);
			wait1Msec(tempo);
		}

	}
}
