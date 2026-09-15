/* 
 * File:   eeprom.h
 * Author: Admin
 *
 * Created on 1 September, 2026, 8:21 PM
 */



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif
//


#ifndef EEPROM_H
#define	EEPROM_H
void write_internal_eeprom(unsigned char address, unsigned char data); 
unsigned char read_internal_eeprom(unsigned char address);



#endif	/* EEPROM_H */

