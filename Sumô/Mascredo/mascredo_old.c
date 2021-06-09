#pragma config(Sensor, S1, U1, sensorEV3_Ultrasonic)
#pragma config(Sensor, S4, U2, sensorEV3_Ultrasonic)
#pragma config(Sensor, S2, C1, sensorEV3_Color)
#pragma config(Sensor, S3, C2, sensorEV3_Color)
#pragma config(Motor, motorA, arma, tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor, motorB, esq, tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor, motorC, dir, tmotorEV3_Large, PIDControl, encoder)
int graus=95
int tempo=800
int vel=40
task main()
{
	wait1Msec(5000);
	moveMotorTarget(arma, graus, vel);
	while (true) {




		if ((getColorReflected(C1) < 10)&& (getColorReflected(C2) < 10)){

			if((getUSDistance(U1) < 40) && (getUSDistance(U2) < 40)){

				setMotorSpeed(esq, 90);
				setMotorSpeed(dir, 90);
			}

			if ((getUSDistance(U1) < 40) && (getUSDistance(U2) > 40)){

				setMotorSpeed(esq, 55);
				setMotorSpeed(dir, 90);
			}
			if((getUSDistance(U1) > 40) && (getUSDistance(U2) < 40)){

				setMotorSpeed(esq, 90);
				setMotorSpeed(dir, 55);
			}
			if((getUSDistance(U1) > 40) && (getUSDistance(U2) > 40)){

				setMotorSpeed(esq, -50);
				setMotorSpeed(dir, 50);
			}
		}
		if((getColorReflected(C1) < 10) && (getColorReflected(C2) > 10)){

			setMotorSpeed(esq, -100);
			setMotorSpeed(dir, -55);
			wait1Msec(tempo);
		}
		if((getColorReflected(C1) > 10) && (getColorReflected(C2) < 10)){

			setMotorSpeed(esq, -55);
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
