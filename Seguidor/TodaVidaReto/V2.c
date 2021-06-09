#pragma config(Sensor, S1,     SE,             sensorEV3_Color)
#pragma config(Sensor, S2,     SM,             sensorEV3_Color)
#pragma config(Sensor, S3,     SD,             sensorEV3_Color)
#pragma config(Motor,  motorA,          ME,            tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          MD,            tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	//	int ve, vd;
	int vo=50, erro, erro_ant, v_e,v_d, n_sensores, kp=7, ki=1;
	float erroi=0;
	int tempo_agora=0, tempo_antes=0;
	while(1){
		n_sensores=0;
		erro_ant=erro;
		erro=0;


		if(SensorValue[SE]>50){
			n_sensores++;
			erro+=10;}
		if(SensorValue[SM]>50){
			n_sensores++;}
		if(SensorValue[SD]>50){
			n_sensores++;
			erro-=10;}


		tempo_agora=time1[timer1];
		erroi+=(tempo_agora-tempo_antes)*erro*0.001;
		tempo_antes=tempo_agora;

		if(n_sensores>0){
			erro=erro/n_sensores;
		}
		else
			erro=erro_ant;

		v_e=vo+kp*erro+ki*erroi;
		v_d=vo-kp*erro-ki*erroi;
		if(v_d>100)
			v_d=100;
		if(v_e>100)
			v_e=100;

		motor[ME]=v_e;
		motor[MD]=v_d;
	}
}