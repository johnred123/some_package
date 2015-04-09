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

void mk_sha1(unsigned char *Data, int length, unsigned char* sha1_val);
void mk_sha1_512(unsigned char *Data, int length, unsigned char* sha1_val);
void hmac_sha1(unsigned char *key,int key_length,unsigned char *data,int data_length,unsigned char *digest);

#endif /* _SHA_1_H_ */
