#pragma config(Sensor, S1,     SE,             sensorEV3_Color)
#pragma config(Sensor, S2,     SM,             sensorEV3_Color)
#pragma config(Sensor, S3,     SD,             sensorEV3_Color)
#pragma config(Motor,  motorA,          ME,            tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          MD,            tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
//	int ve, vd;
	clearTimer(T1);
	int vo=45, erro, erro_ant, n_sensores, flag=0, contador=0, t=0;
	float kp=3.7;
	while(t<710){
		t=time100[T1];
		n_sensores=0;
		erro_ant=erro;
		erro=0;


		if(SensorValue[SE]>40){
				n_sensores+=2;
				erro+=24;}
		if(SensorValue[SM]>40){
				n_sensores++;

				}
		if(SensorValue[SD]>40){
				n_sensores+=2;
				erro-=24;}

		if((erro_ant == 12 || erro_ant==0 || erro_ant==8) && erro == -12 )
		{
			erro=erro_ant;
		}
		if((erro_ant == -12 || erro_ant==0 || erro_ant==-8) && erro == 12)
		{
			erro=erro_ant;
		}

		if(erro==12)
			flag=1;
		if(erro==-12)
			flag=-1;
		if(flag==1||flag==-1)
			contador++;
		if(contador>75){
			flag=0;
			contador=0;}

		if(n_sensores>0)
			erro=erro/n_sensores;
		else
			erro=erro_ant;
		if(erro==0)
			erro=-4*flag;
	if(erro>0){
	motor[ME]=vo-kp*erro;
	motor[MD]=vo;}
	else{
	motor[ME]=vo;
	motor[MD]=vo+kp*erro;}

	}
}