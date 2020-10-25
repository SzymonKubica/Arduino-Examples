#include "U8g2lib.h"
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);



uint8_t draw_state = 0;

void draw(void) {
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr(0,20, "Hello World");
}

void setup(void) {

  // flip screen, if required
  //u8g.setRot180();

  pinMode(13, OUTPUT);           
  digitalWrite(13, HIGH);  
}

void loop(void) {
  
  // picture loop  
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  delay(150);

}
