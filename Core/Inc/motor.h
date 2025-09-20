#pragma once
#include "stdbool.h"
#include "stdint.h"

#define FORWARD     1
#define BACKWARD    0

void M_Init(void);

void M_Enable(void);
void M_Disable(void);

void M_SetSpeed(uint16_t spd_a, uint16_t spd_b, bool dir_a, bool dir_b);