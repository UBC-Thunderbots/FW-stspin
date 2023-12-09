/*
 * datasheets:
 * {https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-pico-kit.html}
 * 
 * sources:
 * {https://www.analog.com/en/analog-dialogue/articles/introduction-to-spi-interface.html} (1)
 * {https://randomnerdtutorials.com/esp32-spi-communication-arduino/} (2)
 * 
 *                                                                   ESP32 PICO V4 pinout
 *                                                                       ___________
 *                                                                      |           |
 *                                 EMAC_CLK_OUT/U2RXD/HS1_DATA4/GPIO16 -| CS     D1 |- GPIO8/SD_DATA1/SPID/HS1_DATA1/U2CTS
 *                             EMAC_CLK_OUT_180/U2TXD/HS1_DATA5/GPIO17 -| D0     D3 |- GPIO7/SD_DATA0/SPIQ/HS1_DATA0/U2RTS
 *                                  U1RTS/HS1_CMD/SPICS0/SD_CMD/GPIO11 -| D2     CLK|- GPIO6/SD_CLK/SPICLK/HS1_CLK/U1CTS
 *                                           RTC_GPIO0/ADC1_CH0/GPIO36 -| VP     21 |- GPIO21/VSPIHD/EMAC_TX_EN
 *                                           RTC_GPIO3/ADC1_CH3/GPIO39 -| VN     22 |- GPIO22/VSPIWP/U0RTS/EMAC_TXD1
 *                           EMAC_RXD0/RTC_GPIO6/ADC2_CH8/DAC_1/GPIO25 -| 25     19 |- GPIO19/VSPIQ/U0CTS/EMAC_TXD0
 *                           EMAC_RXD1/RTC_GPIO7/ADC2_CH9/DAC_2/GPIO26 -| 26     23 |- GPIO23/VSPID/HS1_STORE
 *                                    RTC_GPIO9/TOUCH9/ADC1_CH4/32K_XP -| 32     18 |- GPIO18/VSPICLK/HS1_DATA7
 *                                    RTC_GPIO8/TOUCH8/ADC1_CH5/32K_XN -| 33      5 |- GPIO5/VSPICS0/HS1_DATA6/EMAC_RX_CLK
 *                                EMAC_RX_DV/RTC_GPIO7/TOUCH7/ADC2_CH7 -| 27     10 |- GPIO10/SD_DATA3/SPIWP/HS1_DATA3/U1TXD
 *    EMAC_TXD2/SD_CLK/HS2_CLK/HSPICLK/MTMS/RTC_GPIO16/TOUCH6/ADC2_CH6 -| 14      9 |- GPIO9/SD_DATA2/SPIHD/HS1_DATA2/U1RXD
 *  EMAC_TXD3/SD_DATA2/HS2_DATA2/HSPIQ/MTDI/RTC_GPIO15/TOUCH5/ADC2_CH5 -| 12     RX0|- GPIO3/U0RXD/CLK_OUT2
 * EMAC_RX_ER/SD_DATA3/HS2_DATA3/HSPID/MTCK/RTC_GPIO14/TOUCH4/ADC2_CH4 -| 13     TX0|- GPIO1/U0TXD/CLK_OUT3/EMAC_RXD2
 *    EMAC_RXD3/SD_CMD/HS2_CMD/HSPICS0/MTDO/RTC_GPIO13/TOUCH3/ADC2_CH3 -| 15     35 |- ADC1_CH7/RTC_GPIO5
 *                SD_DATA0/HS2_DATA0/HSPIWP/RTC_GPIO12/TOUCH2/ADC2_CH2 -| 2      34 |- ADC1_CH6/RTC_GPIO4
 *    EMAC_RTX_ER/SD_DATA1/HS2_DATA1/HSPIHD/RTC_GPIO10/TOUCH0/ADC2_CH0 -| 4      38 |- GPIO38/ADC1_CH2/RTC_GPIO2
 *                     EMAC_TX_CLK/CLK_OUT1/RTC_GPIO11/TOUCH1/ADC2_CH1 -| 0      37 |- GPIO37/ADC1_CH1/RTC_GPIO1
 *                                                                 3V3 -|3V3     EN |- CHIP_PU
 *                                                                 GND -|GND     GND|- GND
 *                                                                 5V0 -| 5V     3V3|- 3V3
 *                                                                      |___________|
 */

#include <SPI.h>

//#define SCK 14
//#define MISO 12
//#define MOSI 13
//#define CS 15
 
void setup() {
  // even though i have the SPI pins declared above, this code just checks what the default SPI pins are onboard
  Serial.begin(9600);       // 9600 baud rate
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS);
  Serial.end();

  // these use functions from the SPI library, so they may only work on some pins... set SS as output
  //pinMode(CS, OUTPUT);            // probably redundant considering SPI.begin() does this for me?
  SPI.setBitOrder(MSBFIRST);      // order: either LSBFIRST or MSBFIRST
  SPI.setDataMode(SPI_MODE1);     // mode: SPI_MODE | check out source (1).Table1
  //setClockDivider();
  SPI.begin();                    // initializes SPI bus; sets all pins to OUTPUTs

  Serial.begin(9600);             // baud rate
}

void loop() {
  // first thing before sending data to peripheral device is to pull controller CS/SS pin LOW
  //digitalWrite(CS, LOW);

  SPI.transfer(0x00);                 // this sends a 0x00 over the data lines

  while(1);                 // terminates
}
