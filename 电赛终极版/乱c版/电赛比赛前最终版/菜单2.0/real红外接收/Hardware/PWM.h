#ifndef __PWM_H
#define __PWM_H

void PWM_Init(void);
void PWM_SetCompare1(uint16_t Compare);
void IR_SendNEC(uint8_t address, uint8_t command);
void IR_SendByte(uint8_t byte);
void IR_SendY(void);
void IR_SendBit(uint8_t bit);
void PWM_ON(void);
void PWM_OFF(void);
void Infrared_Send(u16 *irdata,u32 irlen);

#endif
