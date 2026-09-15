/*
 * File:   main.c
 * Author: Admin
 *
 * Created on 1 September, 2026, 7:49 PM
 */


#include <xc.h>
#include "digital_keypad.h"
#include "ssd_display.h"
#include "eeprom.h"
void init_config()
{
    TRISBbits.TRISB0 = 0;
    PORTBbits.RB0 = 0;
    init_digital_keypad();
    init_ssd_control();
}

void main(void) 
{
    init_config();
    
    // storing password 1234 to eeprom
    write_internal_eeprom(0x00,1);
    write_internal_eeprom(0x01,2);
    write_internal_eeprom(0x02,3);
    write_internal_eeprom(0x03,4);
    // read and store it in one variable to verify
    //unsigned int password = read_internal_eeprom(0x03) + read_internal_eeprom(0x02)*10
                           // + read_internal_eeprom(0x01)*100 + read_internal_eeprom(0x00)*1000;  // 1234
    unsigned char d0 = read_internal_eeprom(0x00);
    unsigned char d1 = read_internal_eeprom(0x01);
    unsigned char d2 = read_internal_eeprom(0x02);
    unsigned char d3 = read_internal_eeprom(0x03);

    unsigned int password = d0*1000 + d1*100 + d2*10 + d3;   // 1234
    
    static unsigned char ssd[MAX_SSD_CNT];
    static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    unsigned int temp_password = password;
    unsigned int i;
    unsigned char key ;
    unsigned sw1_count = 0;
    unsigned sw2_count = 0;
    unsigned enterd_password[4] = {0};
    // ---- TEMP DEBUG: show what password actually holds ----
    /*
    static unsigned char dbg[MAX_SSD_CNT];
    dbg[0] = digit[password/1000];
    dbg[1] = digit[(password/100)%10];
    dbg[2] = digit[(password/10)%10];
    dbg[3] = digit[password%10];
    for(unsigned long d = 0; d < 200000; d++)
    {
        display(dbg);
    }
    */
// ---- END DEBUG ----
    ssd[0] = E;
    ssd[1] = N;
    ssd[2] = T;
    ssd[3] = R;
    
    while(1)
    {
        // Showing the ENter password : ENTR
        display(ssd);
        for(i = 0;i < 50;i++);
        
        key = read_digital_keypad(STATE_CHANGE); 
        if(key == SWITCH2)
        {
            sw1_count = 0;
            sw2_count++;
            if(sw2_count > 3)
            {
                sw2_count = 0;
            }
        }
        if(key == SWITCH1)
        {
            sw1_count++;
            if(sw1_count > 9)
            {
                sw1_count = 0;
            }
            ssd[sw2_count] = digit[sw1_count];
            display(ssd);
            for(i = 0;i < 500;i++);
             
        }
        if(key == SWITCH3)
        {
            
            enterd_password[0] = ssd[0];
            enterd_password[1] = ssd[1];
            enterd_password[2] = ssd[2];
            enterd_password[3] = ssd[3]; 
            // after enter switch pressd check the password is correct or wrong
            if(enterd_password[0] == digit[temp_password/1000] && enterd_password[1] == digit[(temp_password/100)%10] &&
                enterd_password[2] == digit[(temp_password/10)%10] && enterd_password[3] == digit[temp_password%10])
            {
                
                ssd[0] = P;
                ssd[1] = A;
                ssd[2] = S;
                ssd[3] = S;
                RB0 = 1;
                for(i = 0;i < 500;i++)
                {
                    display(ssd);
                }
            }
            else
            {
                ssd[0] = F;
                ssd[1] = A;
                ssd[2] = I;
                ssd[3] = L;
                RB0 = 0;
                for(i = 0;i < 500;i++)
                {
                    display(ssd);
                }
            }
             // reset for next entry
            sw1_count = 0;
            sw2_count = 0;
            ssd[0] = E;
            ssd[1] = N;
            ssd[2] = T;
            ssd[3] = R;
            display(ssd);
            for(i = 0;i < 500;i++);
        }
        if(key == SWITCH4) // clearing the ssd 
        {
            ssd[0] = ZERO;
            ssd[1] = ZERO;
            ssd[2] = ZERO;
            ssd[3] = ZERO;
            sw2_count = 0;
            sw1_count = 0;
            for(i = 0;i < 500;i++)
            {
                display(ssd);
            }
        }
    }
    return;
}
