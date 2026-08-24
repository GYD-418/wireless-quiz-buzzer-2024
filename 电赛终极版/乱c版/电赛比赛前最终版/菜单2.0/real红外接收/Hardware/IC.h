#ifndef __IC_H
#define __IC_H
 
void IC_Init(void);
uint32_t IC_GetFreq(void);
uint8_t IR_GetDataFlag(void);
uint8_t IR_GetRepeatFlag(void);
uint8_t IR_GetAddress(void);
uint8_t IR_GetCommand(void);
 
#endif
