/******************************************************************************
  File Name     : utf8-to-unicode.c
  Version       : Initial Draft
  Author        : john kazmath (johnred123@github)
  Created       : 2014/1/6
  Last Modified :
  Description   : utf8 to unicode decoder
  Function List :
              ExchgPhone
              Hex2String
              Hex210
              utf8_to_unicode
  History       :
  1.Date        : 2014/1/6
    Author      : john kazmath (johnred123@github)
    Modification: Created file

******************************************************************************/

#include "utf8-to-unicode.h"
#include <stdint.h>

/*
 * Prototype    : Hex210
 * Description  : hexadecimal to decimal
 * Input        : uint8_t ucData  
                  char *cpBuffer        
 * Output       : None
 * Return Value : void
 * Calls        : 
 * Called By    : 
 * 
 * History        :
 1.Date           : 2014/1/6
 *    Author       : huangliang
 *    Modification : Created function
 */
char Hex210(uint8_t ucData, char *cpBuffer)
{
    if(NULL == cpBuffer)return -1;

    sprintf(cpBuffer, "%d", ucData);
    return 0;
}

/*
 * Prototype    : Hex2String
 * Description  : hexadecimal to string
 * Input        : uint8_t ucData  
                  char *cpBuffer        
 * Output       : None
 * Return Value : 
 * Calls        : 
 * Called By    : 
 * 
 * History        :
 1.Date           : 2014/1/6
 *    Author       : huangliang
 *    Modification : Created function
 */
char Hex2String( uint8_t ucData , char * cpBuffer )
{  
    if(NULL == cpBuffer)return -1;

    sprintf(cpBuffer, "%02X", ucData);
    return 0;
}

/*
 * Function Name: utf8_to_unicode()
 * Description:   
 * Argument:	  char *cpPhoneNum ----- Phone numbers
 *				  char *cpBuffer ----- A buffer to save exchanged phone number
 *				  char *cpText ---- Text will be sended
 */
void utf8_to_unicode( uint8_t *cpInput , int Len )
{
    #define max_buffer_size 150
    int iBufPos = 0 , offset = 0 ;
    uint8_t *savetmp = NULL;
    uint8_t *tmp = NULL;

    tmp = (uint8_t *)mem_malloc(max_buffer_size);
    if(NULL == tmp){
        return;
    }
    memset(tmp, 0, max_buffer_size);
    savetmp = cpInput ; 
    for ( iBufPos = 0; (iBufPos <= Len) && (iBufPos <= max_buffer_size); iBufPos ++){
        if( *savetmp != 0x00 ){
            /* ----- if a ASCII code ----- */
            if ( *savetmp > 0x00 && *savetmp <= 0x7F ){
                *(tmp + offset + 1) = *savetmp;
                *(tmp + offset ) = 0;
                savetmp ++;
                offset += 2 ;
                continue;
            }else{
                /* ----- If is double bype code ----- */
                if ( ((*savetmp) & 0xE0) == 0xC0 ){
                    char temp1 = 0x00;
                    char temp2 = 0x00;
                    temp1 = * ( savetmp + 1 ) & 0x3F ;
                    temp2 = * savetmp & 0x03 ;
                    temp2 = temp2 << 6 ;
                    *( tmp + offset + 1 ) = temp2 + temp1 ;
                    temp1 = * savetmp & 0x1C ;
                    temp1 = temp1 >> 2 ;
                    *( tmp + offset ) = temp1 ;
                    savetmp += 2 ;
                    iBufPos ++ ;
                    offset +=2 ;
                    continue;
                }else{
                    /* -----  If is a 3 bype code  ----- */
                    if ( ((*savetmp) & 0xF0) == 0xE0 ){
                        char temp1 = 0x00;
                        char temp2 = 0x00;
                        temp1 = *( savetmp + 2 ) & 0x3F ;
                        temp2 = *( savetmp + 1 ) & 0x3F ;
                        temp2 = ( temp2 & 0x03 ) << 6 ;
                        *( tmp + offset + 1 ) = temp1 + temp2 ;
                        temp1 = *savetmp & 0x0F ;
                        temp2 = ( *( savetmp + 1 ) & 0x3C ) >> 2 ;
                        *( tmp + offset ) = ( temp1 << 4 ) +  temp2 ;
                        savetmp += 3 ;
                        iBufPos += 2 ;
                        offset += 2 ;
                        continue;
                    }else{
                        /* -----  If is a 4 Bype code  ----- */
                        if ( ( ( *savetmp ) & 0xF0) == 0xF0  ){
                            iBufPos += 3 ;
                            savetmp += 4 ;
                            offset += 2 ;
                            continue;
                        }
                    }
                }
            }
        }
    }
    memset( cpInput , 0 , max_buffer_size ) ;
    memcpy( cpInput , tmp , max_buffer_size ) ;
    mem_free(tmp);
    return;
}
