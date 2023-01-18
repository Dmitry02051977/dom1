/*
 * motor.c
 *
 *  Created on: Jan 19, 2023
 *      Author: Denis
 */

#include "motor.h"

void motor_init(xMotor_tt * m){
	motor_stop(m);
	//TODO need read speed of flash
	motor_set(m, 250);
}
void motor_stop(xMotor_tt * m){
	m->state = MOTOR_STATE_STOP;
	*((uint32_t *)m->ccr) = 0;
}
void motor_forward(xMotor_tt * m){
	m->state = MOTOR_STATE_FORWARD;
	HAL_GPIO_WritePin(m->GPIOx, m->pin, GPIO_PIN_RESET);
	*((uint32_t *)m->ccr) = m->speed;
}
void motor_back(xMotor_tt * m){
	m->state = MOTOR_STATE_BACK;
	HAL_GPIO_WritePin(m->GPIOx, m->pin, GPIO_PIN_SET);
	*((uint32_t *)m->ccr) = m->speed;
}
void motor_set(xMotor_tt * m, uint16_t speed){
	m->speed = speed;
}
uint16_t motor_speed(xMotor_tt *m){
	return m->speed;
}
uint8_t motor_dir(xMotor_tt *m){
	return HAL_GPIO_ReadPin(m->GPIOx, m->pin);
}
uint8_t motor_state(xMotor_tt * m){
	return m->state;
}