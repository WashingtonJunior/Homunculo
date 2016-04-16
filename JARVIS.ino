#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <LWiFi.h>
#include <LWiFiServer.h>
#include <LBT.h>
#include <LBTServer.h>
#include <LTask.h>
#include <LFlash.h>
#include <LSD.h>
#include <LStorage.h>
#include <OzOLED.h>
#include <LAudio.h>
#include <LBattery.h>

#define Drv LFlash          // use Internal 10M Flash
//#define Drv LSD           // use SD card

#define SPP_SVR "JARVIS_BT" // it is the server's visible name, customize it yourself.

#define MAXDATA 640
#define MAXDATAFILE 128

/*
static unsigned char Logo[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0, 0xE0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF8,
	0xF8, 0x78, 0x78, 0x78, 0x7C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E,
	0x1E, 0x0E, 0x0E, 0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x1E, 0x1E,
	0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x3E, 0x3E, 0x3C, 0x3C, 0x3C, 0x7C, 0x7C, 0x7C, 0xF8, 0xF8, 0xF8,
	0xF8, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xE0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0xFE, 0xFE,
	0xFF, 0x7F, 0x3F, 0x3F, 0x1F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x1F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF,
	0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xE0, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x0F, 0x03, 0x01,
	0x00, 0x00, 0x00, 0x00, 0x40, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
	0x03, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF0, 0x00,
	0x00, 0x07, 0x1F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF0, 0xE0, 0x80,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x7E,
	0x7E, 0x7E, 0x7E, 0x7C, 0x7C, 0x7C, 0x7C, 0x78, 0x78, 0x78, 0x78, 0x70, 0x30, 0x30, 0x30, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x60, 0x60,
	0x60, 0x70, 0x70, 0x70, 0x70, 0x78, 0x78, 0xF8, 0xF8, 0xFC, 0xFC, 0x7C, 0x7C, 0x7E, 0x7E, 0x7E,
	0x7E, 0x3F, 0x1F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,
	0xE0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x0F, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x0F, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x7F,
	0x7F, 0xFF, 0xFE, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x80,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
	0x80, 0x80, 0xC0, 0xC0, 0xE0, 0xE0, 0xE0, 0xF0, 0xF0, 0xF8, 0xFC, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF,
	0x7F, 0x7F, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x0F,
	0x0F, 0x1F, 0x1F, 0x1E, 0x1E, 0x1E, 0x3E, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x7C, 0x78, 0x78, 0x78,
	0x78, 0x78, 0x78, 0x78, 0x78, 0x7F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78,
	0x78, 0x78, 0x7C, 0x7C, 0x3C, 0x3C, 0x3C, 0x3E, 0x3E, 0x3E, 0x3E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
	0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


static unsigned char Logo[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0, 0xF0, 0xF0, 0x70, 0x70, 0x38, 0x38, 0x38, 0x38,
	0x38, 0x1C, 0x1C, 0x1C, 0x1C, 0x1E, 0x1E, 0x0E, 0x0E, 0x0E, 0x0E, 0x06, 0x06, 0x07, 0x07, 0x07,
	0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07,
	0x07, 0x07, 0x07, 0x06, 0x06, 0x0E, 0x0E, 0x0E, 0x0E, 0x1E, 0x1E, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
	0x38, 0x38, 0x78, 0x78, 0x70, 0x70, 0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xE0, 0xE0, 0xF8, 0xF8, 0xF8, 0x7C, 0x7C, 0x1E, 0x1E,
	0x0F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x0F, 0x0F,
	0x1E, 0x1E, 0x7C, 0x7C, 0x7C, 0xF8, 0xF8, 0xE0, 0xE0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x80, 0xF8, 0xF8, 0xFF, 0xFF, 0x3F, 0x3F, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xE0, 0xE0, 0xF0, 0xF0,
	0xF0, 0xF0, 0xF0, 0xF8, 0xF8, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xE0, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0xE0, 0xE0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF8, 0xF8, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
	0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x07, 0x07, 0x3F, 0x3F, 0xFF, 0xFF, 0xF8, 0xF8, 0x80,
	0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x07, 0x07, 0x0F, 0x0F,
	0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x0F, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x07, 0x07, 0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x0F, 0x0F,
	0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
	0x00, 0x03, 0x03, 0x0F, 0x0F, 0x3F, 0x3F, 0x7C, 0x7C, 0xF0, 0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0xC0,
	0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0,
	0xC0, 0xC0, 0xF0, 0xF0, 0xF0, 0x78, 0x78, 0x7E, 0x7E, 0x1F, 0x1F, 0x0F, 0x0F, 0x01, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x07, 0x07,
	0x0F, 0x0F, 0x0F, 0x0F, 0x1E, 0x1E, 0x3E, 0x3E, 0x38, 0x38, 0x38, 0x38, 0x70, 0x70, 0x70, 0x70,
	0x70, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
	0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
	0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
	0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x70, 0x70, 0x70,
	0x70, 0x70, 0x38, 0x38, 0x38, 0x38, 0x3E, 0x3E, 0x1E, 0x1E, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
*/

unsigned char img[1024];

char ssid[] = "J.A.R.V.I.S.";  //  your network SSID (name)
char pass[] = "bc25fcb38b";    // your network password

char folder[] = "jarvis/";

unsigned int localPort = 2390;      // local TCP port

LWiFiServer server(localPort);
LWiFiClient client;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); //using the default address 0x40

#define SERVOMIN  153 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  590 // this is the 'maximum' pulse length count (out of 4096)
#define SR04TRIGGERPIN 6
#define SR04ECHOPIN 7
#define LASERPIN 2
#define PAUSE 50

byte packetBuffer[MAXDATA]; //buffer to hold incoming and outgoing packets

int lastpos[16];
int mempos[16][16];
int curmempos = 0;
int servomin[16];
int servomax[16];
int aceleracao = 0;
int BT = 0;
int automatic = 0;
int idxauto = 0;
int reconectar = 1;
int reconectarMsg = 0;
int reconectarMsgBT = 0;
int laser = 0;
int isBusy = 0;

char image[MAXDATA * 2];
char toExecute[MAXDATA];

LFile root;

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);

  Serial.print("Initializing SDcard...");
  pinMode(10, OUTPUT); // CS pin for sdcard/storage
  Serial.println(Drv.begin());
  Serial.println("initialization done.");
  //LFile root = Drv.open("/jarvis");
  //printDirectory(root, 0);
  //Serial.println("done!");

  //readSeqFile("/jarvis/inicial.seq");

  // Head Init
  OzOled.init();  //initialze Oscar OLED display
  delay(50);

  readImgFile("/blink.img");

  // Head display
  //OzOled.setCursorXY(2, 0);
  //OzOled.printString("CHIMICHANGAS");
  //  OzOled.setCursorXY(4, 1);
  //  OzOled.printString("DEADPOOL");

  // Audio test
  LAudio.begin();
  LAudio.setVolume(5);
  OzOled.setCursorXY(2, 0);
  OzOled.printString("    R2D2    ");
  LAudio.playFile(storageFlash, (char*)"r2d2.mp3");
  delay(3000);
  readImgFile("/baymax.img");
  OzOled.setCursorXY(2, 0);
  OzOled.printString("   BAYMAX   ");
  LAudio.playFile(storageFlash, (char*)"baymax.mp3");
  delay(3500);
  readImgFile("/deadpool.img");
  OzOled.setCursorXY(2, 0);
  OzOled.printString("   WALL-e   ");
  LAudio.playFile(storageFlash, (char*)"walle.mp3");
  delay(3500);
  OzOled.setCursorXY(2, 0);
  OzOled.printString("    C3PO    ");
  LAudio.playFile(storageFlash, (char*)"c3po.mp3");
  delay(4000);
  LAudio.stop();
  //LAudio.pause();
  //delay(2000);
  //LAudio.resume();
  //delay(2000);

  readImgFile("/bvs.img");

  showBattery();

  OzOled.setCursorXY(4, 0);
  OzOled.printString("J.A.R.V.I.S.");

  // 

  pinMode(LASERPIN, OUTPUT);

  pinMode(SR04TRIGGERPIN, OUTPUT);
  pinMode(SR04ECHOPIN, INPUT);

  memset(toExecute, 0, MAXDATA);
  toExecute[0] = '\0';

  strcat(toExecute, "^init.seq|BT|");


  Serial.println("J.A.R.V.I.S. Loaded!");
  Serial.println("[A-P][0-180]:speed, OFF, ~[0-9999], ![0-15], ACC, BT");
  
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //Reseting lastpos and mempos for all servos
  for (int i=0;i<16;i++)
  {
    lastpos[i]=-1;

    for (int j=0;j<16;j++)
    {
      mempos[i][j] = -1;
    }

    servomin[i] = SERVOMIN;
    servomax[i] = SERVOMAX;
  }

  //servomin[0]=158;
  //servomax[0]=430;

  //servomin[4]=261;
  //servomax[4]=530;

    // attempt to connect to Wifi network:
  LWiFi.begin();
  while (!LWiFi.connectWPA(ssid, pass))
  {
    delay(1000);
    Serial.println("retry WiFi AP");
  }
  Serial.println("Connected to wifi");
  printWifiStatus();

  delay(5000);

  /*
  char *arq = "/andar.seq";

  if (Drv.exists(arq))
  {
	  Serial.println("Exists.");
  }
  else
  {
	  Serial.println("Doesn't exist.");
  }
  */
  // attempt to start Bluetooth Server
  bool success = LBTServer.begin((uint8_t*)SPP_SVR);
  if (!success)
  {
	  Serial.println("Cannot begin Bluetooth Server successfully\n");
  }
  else
  {
	  LBTDeviceInfo info;
	  if (LBTServer.getHostDeviceInfo(&info))
	  {
		  Serial.print("LBTServer.getHostDeviceInfo: ");
		  Serial.print(info.address.nap[1]);
		  Serial.print(", ");
		  Serial.print(info.address.nap[0]);
		  Serial.print(", ");
		  Serial.print(info.address.uap);
		  Serial.print(", ");
		  Serial.print(info.address.lap[2]);
		  Serial.print(", ");
		  Serial.print(info.address.lap[1]);
		  Serial.print(", ");
		  Serial.println(info.address.lap[0]);
	  }
	  else
	  {
		  Serial.println("LBTServer.getHostDeviceInfo failed\n");
	  }
	  Serial.println("Bluetooth Server begin successfully\n");
  }

  Serial.println("\nStarting TCP server...");
  server.begin();

  Serial.print("TCP Server started at port ");
  Serial.println(localPort);


}

void loop() {
  char data[MAXDATA];
  int numero;
  int recebeu = 0;

  /*
  if (automatic==1)
  {
    strcpy(data, procedimento[idxauto]);
    
    idxauto++;

    if ((idxauto>=MAXDATA) || (data[0]=='\0'))
    {
      idxauto = 0;
    }
    else
    {
      recebeu = 1;
    }
  }
  */

  if (Serial.available() > 0)
  {
    numero = Serial.readBytesUntil (13,data,MAXDATA);
    data[numero] = 0;
    recebeu = 1;

    Serial.print("Recebeu via Serial: ");
    Serial.println(data);
  }

  if (reconectar)
  {
	if (reconectarMsg == 0)
	{
	  Serial.print("Aguardando cliente...");
	  reconectarMsg = 1;
	}
    client = server.available();

    if (client)
    {
      Serial.println("Novo cliente");
      reconectar = 0;
    }
  }
  
  if (client)
  {
    if (client.connected())
    {
      if (client.available())
      {
        memset(packetBuffer, 0, MAXDATA);
        client.read(packetBuffer, MAXDATA); // read the packet into the buffer
        for (int i = 0; i < MAXDATA; ++i)
        {
          char c = packetBuffer[i];
          data[i] = c;
        }
        
        recebeu = 1;
        
        Serial.print("Recebeu via TCP: ");
        Serial.println(data);
      }
    }
    else
    {
      Serial.println("Conexao interrompida");
      reconectar = 1;
    }
  }

  if (strlen(toExecute) > 0)
  {
	  strcpy(data, toExecute);

	  memset(toExecute, 0, MAXDATA);
	  toExecute[0] = '\0';

	  recebeu = 1;
  }

  if (BT)
  {
	  if (!LBTServer.connected())
	  {
		  // waiting for Spp Client to connect
		  bool connected = LBTServer.accept(1);

		  if (!connected)
		  {
			  if (reconectarMsgBT == 0)
			  {
				  Serial.println("Aguardando cliente bluetooth...");
				  reconectarMsgBT = 1;
			  }
		  }
		  else
		  {
			  Serial.println("Bluetooth Connected\n");
			  reconectarMsgBT = 0;
		  }
	  }
	  else
	  {
		  if (LBTServer.available())
		  {
			  char bufferBT[MAXDATA];

			  memset(bufferBT, 0, MAXDATA);

			  int read_size = LBTServer.readBytes((uint8_t*)bufferBT, MAXDATA);

			  if (read_size > 0)
			  {
				  Serial.print("size read: ");
				  Serial.print(read_size);
				  Serial.print(", data read:");
				  Serial.println(bufferBT);

				  int inidata = 0;

				  if (recebeu)
				  {
					  for (inidata = 0; inidata < MAXDATA; inidata++)
					  {
						  if (data[inidata] == '\0')
						  {
							  break;
						  }
					  }
				  }
				  else
				  {
					  memset(data, 0, MAXDATA);
				  }

				  data[inidata] = '|';
				  inidata++;

				  bufferBT[0] = '^';

				  for (int idx = 0; idx < read_size - 1; idx++)
				  {
					  data[inidata] = bufferBT[idx];
					  inidata++;
				  }
				  data[inidata] = '|';

				  recebeu = 1;
			  }
		  }
	  }
  }

  if (recebeu)
  {
    char tokens[MAXDATA][MAXDATA];

    //clearStr(tokens, MAXDATA);
    //memset(tokens, 0, MAXDATA);
    /*
    Serial.print("Limpando tokens... ");
    for (int z=1;z<MAXDATA;z++)
    {
      tokens[z][0] = '\0';
    }
    Serial.println("ok!");
    */
	Serial.print("data = '");
	Serial.print(data);
	Serial.println("'");

    int qttokens = split(data, "|", tokens);

	Serial.print("qttokens = ");
	Serial.println(qttokens);

    for (int idx=0;idx<qttokens;idx++)
    {
		delay(PAUSE);

		char recebido[MAXDATA];


		Serial.print("token[");
		Serial.print(idx);
		Serial.print("] = ");
		Serial.println(tokens[idx]);

		memset(recebido, 0, MAXDATA);

		strcpy(recebido, tokens[idx]);

		if (recebido[0]=='\0')
			break;

		//Serial.print(idx);
		//Serial.print(" = ");
		//Serial.print("Recebido: ");
		//Serial.println(recebido);
		//Serial.print("==RESET: ");
		//Serial.print(strcmp(recebido, "RESET"));
      
		if (strcmp(recebido, "RESET")==0)
		{
			reconectar = 1;
			reconectarMsg = 0;
			Serial.println("RESET");
		}
		else if (strcmp(recebido, "AUTO")==0)
		{
			Serial.println("AUTO WALK");
			automatic = 1;
		}
		else if (strcmp(recebido, "DISTANCE")==0)
		{
			char resp[MAXDATA];
  
			int qt = sprintf(resp, "%i", getDistanceinCM());
          
			Serial.print("Distance: ");
			Serial.print(resp);
			Serial.println("cm");
			sendData(resp, qt);
		}
		else if (strcmp(recebido, "BUSY") == 0)
		{
			char resp[2];

			int qt = sprintf(resp, "%i", isBusy);

			sendData(resp, qt);
		}
		else if (strcmp(recebido, "OFF")==0)
		{
			Serial.println("ALL OFF");
  
			for (int i=0;i<16;i++)
			{
				offServo(i);
			}
		}
		else if (strcmp(recebido, "LASER") == 0)
		{
			Serial.print("LASER ");

			if (laser == 0)
			{
				laser = 1;
				digitalWrite(LASERPIN, HIGH);
				Serial.println(" ON");
			}
			else
			{
				laser = 0;
				digitalWrite(LASERPIN, LOW);
				Serial.println(" OFF");
			}
		}
		else if (recebido[0]=='~')
		{
			int tempo = getValue(recebido);
			Serial.print("DELAY: ");
			Serial.println(tempo);
			delay(tempo);
		}
		else if (recebido[0] == '^')
		{
			isBusy = 1;
			char arq[MAXDATAFILE];

			memset(arq, 0, MAXDATAFILE);

			strcpy(arq, folder);
			strcat(arq, &recebido[1]);

			/*
			int iarq = 0;

			for (int i = 1; i < MAXDATAFILE; i++)
			{
				arq[iarq] = recebido[i];
				if (recebido[i] == '\0')
					break;
				iarq++;
			}

			String sArq = folder;
		  
			sArq += arq;

			sArq.toCharArray(arq, sArq.length()+1);
			*/

			Serial.print("Arquivo '");
			Serial.print(arq);
			Serial.println("'");
			//Serial.println("':");

			char content[MAXDATA];

			int tam = readSeqFileX(arq, content);

			//Serial.print("content = '");
			//Serial.print(content);
			//Serial.println("'");
			//Serial.println(tam);

			strcat(toExecute, content);

			/*
			char content[MAXDATAFILE][MAXDATAFILE];

			int qtLinhas = readSeqFile(arq, content);

			Serial.print("Qt Linhas:");
			Serial.println(qtLinhas);

			for (int i = 0; i < qtLinhas; i++)
			{
				Serial.print("-> ");
				Serial.print(i);
				Serial.print(" :: '");
				Serial.print(content[i]);
				Serial.println("'");
			}
			*/
		}
		else if (recebido[0]=='!')
		{
			int servo = getValue(recebido);
			Serial.print("OFF: ");
			Serial.println(servo);
			offServo(servo);
		}
		else if (recebido[0]=='(')
		{
			int servonum = getValue(recebido);
			int minvalue = getExtraValue(recebido);
        
			Serial.print("Servo:");
			Serial.print(servonum);
			Serial.print(" - MIN:");
			Serial.println(minvalue);
  
			servomin[servonum] = minvalue;
		}
		else if (recebido[0]==')')
		{
			int servonum = getValue(recebido);
			int maxvalue = getExtraValue(recebido);
        
			Serial.print("Servo:");
			Serial.print(servonum);
			Serial.print(" - MAX:");
			Serial.println(maxvalue);
  
			servomax[servonum] = maxvalue;
		}
		else if (strcmp(recebido, "ACC")==0)
		{
			Serial.print("ACC: ");
			if (aceleracao==1)
			{
				aceleracao = 0;
			}
			else
			{
				aceleracao = 1;
			}
			Serial.println(aceleracao);
		}
		else if (strcmp(recebido, "BT") == 0)
		{
			Serial.print("BT: ");
			if (BT == 1)
			{
				BT = 0;
			}
			else
			{
				BT = 1;
			}
			Serial.println(BT);
		}
		else if (recebido[0]=='*')
		{
			isBusy = 1;
			Serial.println("Desmembrando:");
  
			char cmds[16][16];
  
			for (int i=0;i<15;i++)
			{
				cmds[i][0] = '\0';
			}
        
			char* dado = strtok(recebido, "*;");
  
			int cont = 0;
        
			while (dado!=NULL)
			{
				strcpy(cmds[cont], dado);
  
				Serial.print(cont);
				Serial.print(" = ");
				Serial.println(cmds[cont]);
				cont++;
          
				dado = strtok(NULL, ";:");
			}
        
			//Serial.println(getValue(recebido));
			//Serial.println(getExtraValue(recebido));
			//Serial.println("Fim!");
			playServos(cmds);
		}
		else
		{
			isBusy = 1;
			playServo(recebido);
		}
    }

	isBusy = 0;
  }

  /*
  if (recebido[0]=='%') //Teste feedback
  {
    int retorno = getFeedback(A1);
    int angulo = map(retorno, 110, 473, 0, 180);

    Serial.print("Angulo: ");
    Serial.println(angulo);
    
    moveServo(12, angulo);
  }
  */

}

int getValue(char *data)
{
    char ndata[MAXDATA];
    int j=0;
    
    for (int i=1;i<MAXDATA;i++)
    {
      if (data[i]==':')
      {
        ndata[j]='\0';
        break;        
      }
      else
      {
        ndata[j]=data[i];
      }
      j++;
    }
    int nvalor = (int)ndata[0];
    int valor = -1;
    
    if (nvalor>=65)
    {
      valor = nvalor-65;
    }
    else
    {
      valor = atoi(ndata);  
    }

    return valor;
}

int getIntValue(char *data)
{
	char ndata[MAXDATA];
	int j = 0;

	for (int i = 1; i<MAXDATA; i++)
	{
		if (data[i] == ':')
		{
			ndata[j] = '\0';
			break;
		}
		else
		{
			ndata[j] = data[i];
		}
		j++;
	}
	int valor = atoi(ndata);

	return valor;
}

int getExtraValue(char *data)
{
    char ndata[MAXDATA];
    int j=0;
    bool achou=0;
    
    for (int i=1;i<MAXDATA;i++)
    {
      if (data[i]==':')
      {
        j=0;
        ndata[j]='\0';
        achou = 1;
      }
      else
      {
        ndata[j]=data[i];
        j++;
        if (j<MAXDATA)
          ndata[j]='\0';
      }
    }

    int valor = atoi(ndata);

    if (!achou)
      valor = 0;
      
    return valor;
}

/*
char* getTokens(char *data)
{
    char ndata[MAXDATA];
    int j=0;
    bool achou=0;
    
    for (int i=1;i<MAXDATA;i++)
    {
      if (data[i]==':')
      {
        j=0;
        ndata[j]='\0';
        achou = 1;
      }
      else
      {
        ndata[j]=data[i];
        j++;
        if (j<MAXDATA)
          ndata[j]='\0';
      }
    }

    int valor = atoi(ndata);

    if (!achou)
      valor = 0;
      
    return valor;
}
*/

int playServo(char *data)
{
    int servonum = (int)data[0];
 
    servonum -= 65;

    int angulo = getValue(data);
    int velocidade = getExtraValue(data);
    
    //int angulo = atoi(data);

    Serial.print(servonum);
    Serial.print(": ");
    Serial.print(angulo);
    Serial.print(" :: ");
    Serial.println(velocidade);

    moveServo(servonum, angulo, velocidade);
}

int playServos(char data[16][16])
{
    int servonums[16];
    int angulos[16];
    int velocidade = 0;

    for (int i=0;i<16;i++)
    {
      servonums[i] = -1;
      
      if ((int)data[i][0]==0)
        break;
        
      int pri = (int)data[i][0];

      if (pri>=65)
      {
        servonums[i] = pri - 65;
      }
      else
      {
        velocidade = atoi(data[i]);
        break;
      }
      
      angulos[i] = getValue(data[i]);

      /*
      Serial.print(i);
      Serial.println(" <***");
      Serial.print(servonums[i]);
      Serial.print(": ");
      Serial.print(angulos[i]);
      Serial.print(" :: ");
      Serial.println("***>");
      */
    }

    //Serial.print("Velocidade: ");
    //Serial.println(velocidade);

    moveServos(servonums, angulos, velocidade);
}

int moveServo(int servonum, int pos, int velocidade)
{
    int pulso = -1;

    if (velocidade<=0)
      velocidade = 1;

    int pulselength = map(pos, 0, 180, servomin[servonum], servomax[servonum]);
    int plold = map(lastpos[servonum], 0, 180, servomin[servonum], servomax[servonum]);
    int dif = pulselength-plold;

    /*
    Serial.print("plold/pulselength: ");
    Serial.print(plold);
    Serial.print("/");
    Serial.println(pulselength);
    */
    
    int incr = dif / velocidade;
    pulso = plold;

    if (velocidade>1)
    {
      for (int v=velocidade; v>0; v--)
      {
        if (aceleracao==1)
        {
          incr = dif / v;
          pulso = plold + incr;
        }
        else
        {
          pulso += incr;
        }

        /*
        Serial.print(v);
        Serial.print("->");
        Serial.print(pulso);
        Serial.print(" (incr: ");
        Serial.print(incr);
        Serial.println(")");
        */
        
		//if (pulso > pulselength)
		//	pulso = pulselength;

        pwm.setPWM(servonum, 0, pulso);
  
        delay(PAUSE);
      }
    }
    pwm.setPWM(servonum, 0, pulselength);

    lastpos[servonum] = pos;
    
    return pulselength;
}


void moveServos(int servonums[], int poss[], int velocidade)
{
    int incrs[16];

    for (int i=0; i<16; i++)
    {
      incrs[i] = 0;
    }
    
    int pulso = -1;

    if (velocidade<=0)
      velocidade = 1;

    if (velocidade>1)
    {
      for (int v=velocidade; v>0; v--)
      {
        for (int k=0;k<16;k++)
        {
          int servonum = servonums[k];

          if (servonum==-1)
            break;
            
          int pos = poss[k];
        
          int pulselength = map(pos, 0, 180, servomin[servonum], servomax[servonum]);
          int plold = map(lastpos[servonum], 0, 180, servomin[servonum], servomax[servonum]);
          int dif = pulselength-plold;

          /*
          Serial.print(k);
          Serial.println(" ***");
          Serial.print("  plold/pulselength: ");
          Serial.print(plold);
          Serial.print("  /");
          Serial.println(pulselength);
          */
          
          int incr;
          
          if (incrs[k]==0)
          {
            incr = dif / velocidade;
            incrs[k] = incr;
          }
          else
          {
            incr = incrs[k];
          }
          
          pulso = plold;

          if (aceleracao==1)
          {
            incr = dif / v;
            pulso = plold + incr;
          }
          else
          {
            pulso += incr;
          }

          /*
          Serial.print(v);
          Serial.print("->");
          Serial.print(pulso);
          Serial.print(" (incr: ");
          Serial.print(incr);
          Serial.print(")");
          */

          int npos = -1;
          
          if (lastpos[servonum]==-1) // Nao tem posicao anterior
          {
            pwm.setPWM(servonum, 0, pulselength);
            npos = map(pulselength, servomin[servonum], servomax[servonum], 0, 180);
          }
          else
          {
			//if (pulso > pulselength)
			//	pulso = pulselength;

            pwm.setPWM(servonum, 0, pulso);
            npos = map(pulso, servomin[servonum], servomax[servonum], 0, 180);
          }

          lastpos[servonum] = npos;

          /*
          Serial.print("[");
          Serial.print(npos);
          Serial.print(" graus]");
          */
        }
        delay(PAUSE);
      }
    }

    for (int k=0;k<16;k++)
    {
      int servonum = servonums[k];
      if (servonum==-1)
        break;
        
      int pos = poss[k];
      int pulselength = map(pos, 0, 180, servomin[servonum], servomax[servonum]);

      /*
      Serial.print("Final ");
      Serial.print(servonum);
      Serial.print(": ");
      Serial.println(pulselength);
      */
      
      pwm.setPWM(servonum, 0, pulselength);

      lastpos[servonum] = pos;
    }
}

int offServo(int servonum)
{
    pwm.setPWM(servonum, 0, 0);

    lastpos[servonum] = -1;

    return 0;
}

void printWifiStatus()
{
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(LWiFi.SSID());

  // print your LWiFi shield's IP address:
  IPAddress ip = LWiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  OzOled.setCursorXY(0, 1);
  OzOled.printNumber((long)(ip[0]));
  OzOled.printString(".");
  OzOled.printNumber((long)(ip[1]));
  OzOled.printString(".");
  OzOled.printNumber((long)(ip[2]));
  OzOled.printString(".");
  OzOled.printNumber((long)(ip[3]));

//  OzOled.setCursorXY(0, 1);
//  OzOled.print(ip);

//  char sIP[16];

//  sprintf(sIP, "%s", (Print&)ip);
//  Serial.print("sIP: ");
//  Serial.println(sIP);

  //OzOled.setCursorXY(2, 0);
  //OzOled.printString(ip);

  // print the received signal strength:
  long rssi = LWiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

int getFeedback(int pino)
{
    int mean;
    int result;
    int test;
    boolean done;
    int reading[20];
     
    for (int j=0; j<20; j++){
      reading[j] = analogRead(pino);    //get raw data from servo potentiometer
      delay(3);
    }                                // sort the readings low to high in array                                
    done = false;              // clear sorting flag             
    while(done != true){       // simple swap sort, sorts numbers from lowest to highest
    done = true;
    for (int j=0; j<20; j++){
      if (reading[j] > reading[j + 1]){     // sorting numbers here
        test = reading[j + 1];
        reading [j+1] = reading[j] ;
        reading[j] = test;
        done = false;
       }
     }
   }
    mean = 0;
    for (int k=6; k<14; k++){        //discard the 6 highest and 6 lowest readings
      mean += reading[k];
    }
    result = mean/8;                  //average useful readings
    return(result);
}

int split(char* data, char* separador, char retorno[MAXDATA][MAXDATA])
{
    char* dado = strtok(data, separador);

    int cont = 0;
                  
    while (dado!=NULL)
    {
//		memset(retorno[cont], 0, MAXDATA);

		for (int i = 0; i < 50; i++)
		{
			retorno[cont][i] = '\0';
		}
		
		Serial.print("dado = ");
		Serial.println(dado);
		//Serial.print("retorno[");
		//Serial.print(cont);
		//Serial.print("] = ");
		//Serial.println(retorno[cont]);

		strcpy(retorno[cont], dado);

		Serial.print("retorno[");
		Serial.print(cont);
		Serial.print("] = ");
		Serial.println(retorno[cont]);
		cont++;
      
		dado = strtok(NULL, separador);
    }

    return cont;
}

int getDistanceinCM()
{
    long duration, distance;
    digitalWrite(SR04TRIGGERPIN, LOW);
    delayMicroseconds(2);
    digitalWrite(SR04TRIGGERPIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(SR04TRIGGERPIN, LOW);
    duration = pulseIn(SR04ECHOPIN, HIGH);
    distance = (duration/2) / 29.1;

    if (distance >= 200 || distance <= 0)
    {
      distance = -1;
    }
  
    return distance;
}

/*
void clearStr(char* data, int qt)
{
  for (int i=0; i<qt; i++)
  {
    data[i] = '\0';
  }
}

void clearStr(char data[MAXDATA][MAXDATA], int qt)
{
  for (int i=0; i<qt; i++)
  {
    data[i][0] = '\0';
  }
}
*/

int sendData(char data[MAXDATA], int qt)
{
  Serial.print("Enviando '");
  Serial.print(data);
  Serial.println("'");
  //Serial.print("' para '");
  //Serial.print(Udp.remoteIP());
  //Serial.print("':");
  //Serial.println(Udp.remotePort());

  int ret = client.write((uint8_t*)data, qt);

  /*
  for (int i=0; i++; i<MAXDATA)
  {
    char c = data[i];
    Udp.write(c);

    if (c=='\0')
      break;
  }
  */
  
  //int ret = Udp.endPacket();

  Serial.print("Retorno: ");
  Serial.println(ret);
}

void printDirectory(LFile dir, int numTabs) {
	while (true) {

		LFile entry = dir.openNextFile();
		if (!entry) {
			// no more files
			break;
		}
		for (uint8_t i = 0; i<numTabs; i++) {
			Serial.print('\t');
		}
		Serial.print(entry.name());
		if (entry.isDirectory()) {
			Serial.println("/");
			printDirectory(entry, numTabs + 1);
		}
		else {
			// files have sizes, directories do not
			Serial.print("\t\t");
			Serial.println(entry.size(), DEC);
		}
		entry.close();
	}
}

int readSeqFile(char *arq, char retorno[MAXDATAFILE][MAXDATAFILE])
{
	LFile myFile;
	int linha = 0;
	int col = 0;

//	memset(retorno[linha], 0, MAXDATAFILE);

	// re-open the file for reading:
	myFile = Drv.open(arq);
	if (myFile)
	{
		//Serial.println(arq);
		myFile.seek(0);
		// read from the file until there's nothing else in it:
		while (myFile.available()) {
			char c = myFile.read();

			//Serial.print(c);
			//Serial.print(" -> ");
			//Serial.println((int)c);

			if ((c == 13) || (c == 10))
			{
				//pass
			}
			else
			{
				retorno[linha][col] = c;
				col++;
			}

			Serial.print(c);

			if (col >= MAXDATAFILE)
				Serial.println("Estouro de caracteres na linha!");

			if (c == 13)
			{
				linha++;
//				memset(retorno[linha], 0, MAXDATAFILE);

				if (linha >= MAXDATAFILE)
					Serial.println("Estouro de linhas no arquivo!");

				col = 0;
			}
		}
		// close the file:
		myFile.close();

		for (int i = 0; i < linha; i++)
		{
			String sLinha = String(retorno[i]);
			String nLinha = "^";

			if (sLinha.endsWith(".seq"))
			{
				//nLinha += folder;
				nLinha += sLinha;

				nLinha.toCharArray(retorno[i], nLinha.length() + 1);
			}

			Serial.print("retorno[");
			Serial.print(i);
			Serial.print("]='");
			Serial.print(retorno[i]);
			Serial.println("'");
		}
	}
	else
	{
		// if the file didn't open, print an error:
		Serial.print("error opening ");
		Serial.println(arq);
	}

	return linha;
}

int readSeqFileStr(char *arq, char retorno[MAXDATA])
{
	LFile myFile;
	char linha[MAXDATA];
	int col = 0;

	memset(linha, 0, MAXDATA);

	// re-open the file for reading:
	myFile = Drv.open(arq);
	if (myFile)
	{
		//Serial.println(arq);
		myFile.seek(0);
		// read from the file until there's nothing else in it:
		while (myFile.available()) {
			char c = myFile.read();

			//Serial.print(c);
			//Serial.print(" -> ");
			//Serial.println((int)c);

			if ((c == 13) || (c == 10))
			{
				//pass
			}
			else
			{
				linha[col] = c;
				col++;
			}

			Serial.print(c);

			if (col >= MAXDATA)
				Serial.println("Estouro de caracteres na linha!");

			if (c == 13)
			{
				String sLinha = String(linha);

				if (sLinha.endsWith(".seq"))
				{
					String nLinha = "^";
					//nLinha += folder;
					nLinha += sLinha;
					nLinha += "|";

					nLinha.toCharArray(linha, nLinha.length() + 1);
				}
				else
				{
					linha[col] = '|';
				}

				strcat(retorno, linha);

				Serial.println(retorno);


				memset(linha, 0, MAXDATA);
				col = 0;
			}
		}
		// close the file:
		myFile.close();
	}
	else
	{
		// if the file didn't open, print an error:
		Serial.print("error opening ");
		Serial.println(arq);
	}

	return strlen(retorno);
}


int readSeqFileX(char *arq, char retorno[MAXDATA])
{
	LFile myFile;
	int linha = 0;
	int col = 0;
	char linhas[MAXDATAFILE][MAXDATA];

	memset(linhas[linha], 0, MAXDATA);

	// re-open the file for reading:
	myFile = Drv.open(arq);
	if (myFile)
	{
		//Serial.println(arq);
		myFile.seek(0);
		// read from the file until there's nothing else in it:
		while (myFile.available()) {
			char c = myFile.read();

			//Serial.print(c);
			//Serial.print(" -> ");
			//Serial.println((int)c);

			if ((c == 13) || (c == 10))
			{
				//pass
			}
			else
			{
				linhas[linha][col] = c;
				col++;
			}

			Serial.print(c);

			if (col >= MAXDATA)
				Serial.println("Estouro de caracteres na linha!");

			if (c == 13)
			{
				linha++;
				memset(linhas[linha], 0, MAXDATA);

				if (linha >= MAXDATAFILE)
					Serial.println("Estouro de linhas no arquivo!");

				col = 0;
			}
		}
		// close the file:
		myFile.close();

		//memset(retorno, 0, MAXDATA);
		retorno[0] = '\0';

		for (int i = 0; i < linha; i++)
		{
			String sLinha = String(linhas[i]);

			if (sLinha.endsWith(".seq"))
			{
				String nLinha = String(folder);
				//nLinha += folder;
				nLinha += sLinha;

				char cont[MAXDATA];
				char arqn[MAXDATAFILE];

				nLinha.toCharArray(arqn, nLinha.length() + 1);

				readSeqFileX(arqn, cont);

				strcat(retorno, cont);
			}
			else
			{
				strcat(retorno, linhas[i]);
				strcat(retorno, "|");
			}

			Serial.print("retorno = '");
			Serial.print(retorno);
			Serial.println("'");
		}
	}
	else
	{
		// if the file didn't open, print an error:
		Serial.print("error opening ");
		Serial.println(arq);
	}

	return linha;
}


int readImgFile(char *arq)
{
	LFile myFile;
	int idx = 0;

	myFile = Drv.open(arq);
	if (myFile)
	{
		myFile.seek(0);
		// read from the file until there's nothing else in it:
		while (myFile.available()) {
			unsigned char c = myFile.read();

			img[idx] = c;
			idx++;
		}
		// close the file:
		myFile.close();
	}
	else
	{
		// if the file didn't open, print an error:
		Serial.print("error opening ");
		Serial.println(arq);
	}

	showImg();
	showBattery();

	return idx;
}

void showImg()
{
	//OzOled.clearDisplay();
	OzOled.drawBitmap(img, 0, 0, 16, 8);
}

void showBattery()
{
	long int batteryLevel = LBattery.level();
	bool batteryCharging = LBattery.isCharging() == 1;

	OzOled.setCursorXY(11, 1);
	OzOled.printNumber(batteryLevel);
	OzOled.printString("%");

	if (batteryCharging)
	{
		OzOled.printString("C");
	}
	else
	{
		OzOled.printString(" ");
	}
}