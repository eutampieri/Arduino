const int ldr=A0;
const int led[2]={2,3};
void setup(){
	for(int i=0;i<=1;i++){
		pinMode(led[i],OUTPUT);
	}
	Serial.begin(9600);
}
void loop(){
	float lettura=analogRead(ldr);
	float bite=map(lettura, 0, 1023, 0, 255);
	int pwm=255-bite;
	for(int i=0; i<1; i++){
	    analogWrite(led[i],pwm);
	}
	Serial.print("Sensore:\t");
	Serial.println(lettura);
	Serial.print("PWM\t");
	Serial.println(pwm);
	delay(50);
}