#include "stm32f1xx_hal.h"
#include "gpio.h"
#include "String.h"
#include "stdio.h"

#define LCD_LINE1 0x80
#define LCD_LINE2 0xC0
#define LCD_LINE3 0x94
#define LCD_LINE4 0xD4

#define LCD_LINE1_END 0x94
#define LCD_LINE2_END 0xD4
#define LCD_LINE3_END 0xA8
#define LCD_LINE4_END 0xE8

#define LCD_CLEAR        0x01    // Clear LCD display and home cursor
#define CURSOR_MODE_DEC  0x04    // Cursor auto decrement after R/W
#define CURSOR_MODE_INC  0x06    // Cursor auto increment after R/W
#define FUNCTION_SET     0x28    // Setup, 4 bits,2 lines, 5X7
#define LCD_CURSOR_ON    0x0E    // Display ON with Cursor
#define LCD_CURSOR_OFF   0x0C    // Display ON with Cursor off
#define LCD_CURSOR_BLINK 0x0D    // Display on with blinking cursor
#define LCD_CURSOR_LEFT  0x10    // Move Cursor Left One Position
#define LCD_CURSOR_RIGHT 0x14    // Move Cursor Right One Position

void lcd_init (void);
void lcd_send_cmd (char cmd);
void lcd_send_data (char data);
void lcd_init (void);
void lcd_send_string (char *str);
void lcd_goto (char address);
