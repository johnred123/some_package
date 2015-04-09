/* file name:sha1sum.h
 *  
 * This program is free software; you can redistribute it and/or modify it  
 * under the terms of the GNU General Public License as published by the  
 * Free Software Foundation; either version 2, or (at your option) any  
 * later version.  
 *  
 * This program is distributed in the hope that it will be useful,  
 * but WITHOUT ANY WARRANTY; without even the implied warranty of  
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  
 * GNU General Public License for more details.  
 *  
 * You should have received a copy of the GNU General Public License  
 * along with this program; if not, write to the Free Software Foundation,  
 */
#ifndef _SHA_1_H_
#define _SHA_1_H_

#include <stdint.h>

void mk_sha1(uint8_t *Data, int length, uint8_t* sha1_val);
void hmac_sha1(uint8_t *key,int key_length,uint8_t *data,int data_length,uint8_t *digest);

#endif /* _SHA_1_H_ */
