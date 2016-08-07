/**
 * Copyright (c) 2011-2016, Mobangjack 莫帮杰 (mobangjack@foxmail.com).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
/****************************************/
/*        Moving Average Filter         */
/****************************************/

#ifndef __MAFILTER_H__
#define __MAFILTER_H__

#ifdef __cpluplus
extern "C" {
#endif

#include <stdint.h>

typedef int16_t Typedef;

typedef struct
{
	Typedef* buf;
	uint32_t len;
	Typedef det;
	uint32_t ptr;
	Typedef sum;
	Typedef out;
}MAFilterI32;

void MAFilterI32_Init(MAFilterI32* mafilter, Typedef* buf, uint32_t len);
MAFilterI32* MAFilterI32_Create(uint32_t len);
Typedef MAFilterI32_Calc(MAFilterI32* mafilter, Typedef v);
void MAFilterI32_Reset(MAFilterI32* mafilter);

#ifdef __cpluplus
}
#endif

#endif