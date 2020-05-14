
/** Put this in the src folder **/

#include "i2c-lcd.h"


extern I2C_HandleTypeDef hi2c2;  // change your handler here accordingly

#define SLAVE_ADDRESS_LCD 0x4F // change this according to ur setup


void lcd_send_cmd (char cmd)
{
  char data_u, data_l;
	uint8_t data_t[4];
	data_u = cmd&0xf0;
	data_l = (cmd<<4)&0xf0;
	data_t[0] = data_u|0x0c;  //en=1, rs=0 Backlight=on;
	data_t[1] = data_u|0x08;  //en=0, rs=0 Backlight=on;
	data_t[2] = data_l|0x0c;  //en=1, rs=0 Backlight=on;
	data_t[3] = data_l|0x08;  //en=0, rs=0 Backlight=on;
	HAL_I2C_Master_Transmit (&hi2c2, (0x4F),(uint8_t *) data_t, 4, 1);
}

void lcd_send_data (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = data&0xf0;
	data_l = (data<<4)&0xf0;
	data_t[0] = data_u|0x0D;  //en=1, rs=0 ,Backlight=on;
	data_t[1] = data_u|0x09;  //en=0, rs=0 Backlight=on;
	data_t[2] = data_l|0x0D;  //en=1, rs=0 Backlight=on;
	data_t[3] = data_l|0x09;  //en=0, rs=0 Backlight=on;
	HAL_I2C_Master_Transmit (&hi2c2, (0x4F),(uint8_t *) data_t, 4, 1);
}


/*

void lcd_send_cmd (char cmd)
   {
        char data_u, data_l;
	uint8_t data_t[4];
	data_u = cmd&0xf0;    // select only upper nibble
	data_l = (cmd<<4)&0xf0;    // select only lower nibble
	data_t[0] = data_u|0x04;  //en=1, rs=0
	data_t[1] = data_u;  //en=0, rs=0
	data_t[2] = data_l|0x04;  //en=1, rs=0
	data_t[3] = data_l;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c2, (0x4F),(uint8_t *) data_t, 4, 100);
   }
   */
/*
void lcd_send_data (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = data&0xf0;    // upper data nibble
	data_l = (data<<4)&0xf0;    // lower data nibble
	data_t[0] = data_u|0x05;  //en=1, rs=0
	data_t[1] = data_u|0x01;  //en=0, rs=0
	data_t[2] = data_l|0x05;  //en=1, rs=0
	data_t[3] = data_l|0x01;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c2, (0x4F),(uint8_t *) data_t, 4, 100);
}*/



void lcd_init (void)
{
	lcd_send_cmd (0x02);HAL_Delay(50);
	lcd_send_cmd (0x28);HAL_Delay(50);
	lcd_send_cmd (0x0c);HAL_Delay(50);
	lcd_send_cmd (0x80);HAL_Delay(50);
	lcd_send_cmd (0x01); HAL_Delay(100);
	lcd_send_cmd (0x00);
}

void lcd_send_string (char *str)
{
	while (*str) lcd_send_data (*str++); HAL_Delay(1);
}

void lcd_goto (char address)
{
 lcd_send_cmd(address);

}
