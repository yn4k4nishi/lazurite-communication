#include "receiver_ide.h"		// Additional Header

#define SUBGHZ_CH	36
#define SUBGHZ_PANID	0xABCD
uint8_t rx_data[256];
uint32_t last_recv_time = 0;
uint8_t myAddr64[8];
SUBGHZ_STATUS rx;

#define BLUE_LED	26

char *temp_act;  //温度
char *press_act; //気圧
char *hum_act;   //湿度

void print_hex_func(uint8_t data)
{
	if(data == 0) Serial.print("00");
	else if(data < 16) {
		Serial.print("0");
		Serial.print_long(data,HEX);
	} else {
		Serial.print_long(data,HEX);
	}
}

void setup(void)
{
	SUBGHZ_MSG msg;
	long myAddress;

	Serial.begin(115200);
	
	msg = SubGHz.init();
	if(msg != SUBGHZ_OK)
	{
		SubGHz.msgOut(msg);
		while(1){ }
	}
	
	myAddress = SubGHz.getMyAddress();
	SubGHz.getMyAddr64(myAddr64);
	Serial.print("myAddress = ");
	Serial.println_long(myAddress,HEX);
	Serial.print_long(myAddr64[0],HEX);
	Serial.print(" ");
	Serial.print_long(myAddr64[1],HEX);
	Serial.print(" ");
	Serial.print_long(myAddr64[2],HEX);
	Serial.print(" ");
	Serial.print_long(myAddr64[3],HEX);
	Serial.print(" ");
	Serial.print_long(myAddr64[4],HEX);
	Serial.print(" ");
	Serial.print_long(myAddr64[5],HEX);
	Serial.print(" ");
	Serial.print_long(myAddr64[6],HEX);
	Serial.print(" ");
	Serial.println_long(myAddr64[7],HEX);
	
	msg = SubGHz.begin(SUBGHZ_CH, SUBGHZ_PANID,  SUBGHZ_100KBPS, SUBGHZ_PWR_20MW);
	if(msg != SUBGHZ_OK)
	{
		SubGHz.msgOut(msg);
		while(1){ }
	}
	msg = SubGHz.rxEnable(NULL);
	if(msg != SUBGHZ_OK)
	{
		SubGHz.msgOut(msg);
		while(1){ }
	}
	
	pinMode(BLUE_LED,OUTPUT);
	digitalWrite(BLUE_LED,HIGH);
	
	Serial.println("Temperature     Pressure       Humidity");
	Serial.println("-----------------------------------------");
	
	return;
}

void loop(void)
{
	SUBGHZ_MAC_PARAM mac;
	short rx_len;
	short index=0;
	uint16_t data16;
	int i;
	
	rx_len = SubGHz.readData(rx_data,sizeof(rx_data));
	rx_data[rx_len]=0;
	if(rx_len>0)
	{
		digitalWrite(BLUE_LED, LOW);
		SubGHz.getStatus(NULL,&rx);										// get status of rx
		SubGHz.decMac(&mac,rx_data,rx_len);
		
		temp_act = strtok((char *)mac.payload,","); //error
		press_act = strtok(NULL,",");
		hum_act   = strtok(NULL,",");

		Serial.print(temp_act);
		Serial.print("[degree]   ");
		Serial.print(press_act);
		Serial.print("[hPa]   ");
		Serial.print(hum_act);
		Serial.println("[%]");

		digitalWrite(BLUE_LED, HIGH);

	}
	
	return;
}
