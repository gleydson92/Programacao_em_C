/*
#define TNORMAL1 	36.22
#define TNORMAL2 	36.33
#define TNORMAL3 	36.44
#define TNORMAL4 	36.56
#define TNORMAL5 	36.67
#define TNORMAL6 	36.78
#define TNORMAL7 	36.89
#define TNORMAL8 	37.00
#define TNORMAL9 	37.11
#define TNORMAL10	37.22
#define TNORMAL11	37.33
#define TNORMAL12	37.44
#define TNORMAL13	37.56
*/
/*
	//Tarde
while(hours > 6 && hours < 13){

	if (Temp >= TNORMAL3 && Temp <= TNORMAL12)
		print("Temperatura Normal");
	else printf("ALERTA!!!");
};
	//Manhã
while(hours > 12 && hours < 24){

	if (Temp >= TNORMAL13 && Temp <= TNORMAL5)
		print("Temperatura Normal");
	else printf("ALERTA!!!");
};
	//Madrugada
while(hours > 24 && hours < 7){

	if (Temp >= TNORMAL6 && Temp <= TNORMAL1)
		print("Temperatura Normal");
	else printf("ALERTA!!!");
};
*/


char sReport[4][15]={"Hypothermia","Normal","Fever","Hyperpyrexia"};

char *isNormal(float Temp){
	while(Temp < 35.0)	return sReport[0];
	while(Temp > 36.2 && Temp < 37.6)	return sReport[1];
	while(Temp > 37.6 && Temp < 38.3)	return sReport[2];
	while(Temp > 40.0)	return sReport[3];
}
char *Notification(void);
/*
Hypothermia	<35.0 °C (95.0 °F)
Normal	36.5–37.5 °C (97.7–99.5 °F)
Fever	>37.5 or 38.3 °C (99.5 or 100.9 °F)
Hyperthermia	>37.5 or 38.3 °C (99.5 or 100.9 °F)
Hyperpyrexia	>40.0 or 41.5 °C (104.0 or 106.7 °F)

Effects:
Hot[edit]
44 °C (111.2 °F) or more – Almost certainly death will occur; however, people have been known to survive up to 46.5 °C (115.7 °F).
43 °C (109.4 °F) – Normally death, or there may be serious brain damage, continuous convulsions and shock. Cardio-respiratory collapse will likely occur.
42 °C (107.6 °F) – Subject may turn pale or remain flushed and red. They may become comatose, be in severe delirium, vomiting, and convulsions can occur. Blood pressure may be high or low and heart rate will be very fast.
41 °C (105.8 °F) – (Medical emergency) – Fainting, vomiting, severe headache, dizziness, confusion, hallucinations, delirium and drowsiness can occur. There may also be palpitations and breathlessness.
40 °C (104.0 °F) – Fainting, dehydration, weakness, vomiting, headache, breathlessness and dizziness may occur as well as profuse sweating. Starts to be life-threatening.
39 °C (102.2 °F) – Severe sweating, flushed and red. Fast heart rate and breathlessness. There may be exhaustion accompanying this. Children and people with epilepsy may be very likely to get convulsions at this point.
38 °C (100.4 °F) – (this is classed as hyperthermia if not caused by a fever) Feeling hot, sweating, feeling thirsty, feeling very uncomfortable, slightly hungry. If this is caused by fever, there may also be chills.
Normal[edit]
37 °C (98.6 °F) – Normal internal body temperature (which varies between about 36.12–37.8 °C (97.02–100.04 °F))
Cold[edit]
36 °C (97 °F) – Feeling cold, mild to moderate shivering (body temperature may drop this low during sleep). May be a normal body temperature.
35 °C (95 °F) – (Hypothermia is less than 35 °C (95 °F)) – Intense shivering, numbness and bluish/grayness of the skin. There is the possibility of heart irritability.
34 °C (93 °F) – Severe shivering, loss of movement of fingers, blueness and confusion. Some behavioural changes may take place.
33 °C (91 °F) – Moderate to severe confusion, sleepiness, depressed reflexes, progressive loss of shivering, slow heart beat, shallow breathing. Shivering may stop. Subject may be unresponsive to certain stimuli.
32 °C (90 °F) – (Medical emergency) Hallucinations, delirium, complete confusion, extreme sleepiness that is progressively becoming comatose. Shivering is absent (subject may even think they are hot). Reflex may be absent or very slight.
31 °C (88 °F) – Comatose, very rarely conscious. No or slight reflexes. Very shallow breathing and slow heart rate. Possibility of serious heart rhythm problems.
28 °C (82 °F) – Severe heart rhythm disturbances are likely and breathing may stop at any time. Patient may appear to be dead.
24–26 °C (75–79 °F) or less – Death usually occurs due to irregular heart beat or respiratory arrest; however, some patients have been known to survive with body temperatures as low as 14.2 °C (57.6 °F).[17]

*/
