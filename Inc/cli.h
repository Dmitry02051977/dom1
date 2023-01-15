/*
 * cli.h
 *
 *  Created on: 12 янв. 2023 г.
 *      Author: Denis
 */

#ifndef CLI_H_
#define CLI_H_

#include "stdint.h"
#include "string.h"
#include "dom.h"


typedef uint8_t (*cli_sender_t)(uint8_t*, uint16_t);

void cli_init(cli_sender_t cli_sender);

void cli_parser(uint8_t * cmd, uint16_t len);

void cli_get_buf(uint8_t * buf, uint16_t len);

void cli_update();



#endif /* CLI_H_ */
