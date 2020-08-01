#include "stm32f4xx_hal.h"
#include "w25qxx.h"
#include "fatfs.h"


uint8_t buffer[_MAX_SS]; /* a work buffer for the f_mkfs() */

void W25Q_FAT_Main()
    {

    FRESULT res;
    uint8_t tx[] = "This is STM32 working with FatFs using W25QXX as storage medium.";
    uint8_t rx[100] = "0";

    UINT cnt;

    res = f_mount(&USERFatFS, (TCHAR const*) USERPath, 0);

    /*only first time*/
//    W25QXX_Erase_Chip();
//    res = f_mkfs((TCHAR const*) USERPath, FM_ANY, 0, buffer, sizeof(buffer));
//    res = f_open(&USERFile, "STM32.TXT", FA_CREATE_ALWAYS | FA_WRITE);
//    res = f_write(&USERFile, tx, sizeof(tx), &cnt);
//    res = f_close(&USERFile);

    res = f_open(&USERFile, "STM32.TXT", FA_READ);
    res = f_read(&USERFile, rx, sizeof(rx), &cnt);
    res = f_close(&USERFile);

    }

