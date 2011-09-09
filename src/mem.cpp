#include "mem.h"
#include "string.h"
#include <stdio.h>


memory::memory(MMC *mmc, PPU *_ppu, PlayPad *_pad)
      : mmc(mmc), ppu(_ppu), pad(_pad)
{
}

void memory::hard_reset() {
    memset(&ram, 0, sizeof(ram));
    mmc->resetMapper();
}

void memory::soft_reset() {
    mmc->resetMapper();
}

byte memory::read(const word offset) {
    if (offset<0x2000) {
        return ram[offset%0x0800];
    }
    if (offset<0x4000) {    /* PPU �Ĵ���                      */
        return ppu->readState(offset);
    }
    if (offset<0x4014) {    /* pAPU �Ĵ���                     */
        return 0;
    }
    if (offset==0x4014) {   /* OAM DMA �Ĵ���                  */
        return 0;
    }
    if (offset==0x4015) {   /* pAPU ״̬�Ĵ���                 */
        return 0;
    }
    if (offset<0x4018) {    /* �����豸״̬�Ĵ���(�ֱ���)      */
        return pad->readPort(offset);
    }
    if (offset<0x401F) {    /* δ��                            */
        return 0;
    }
    if (offset<0x6000) {    /* ��չ ROM                        */
        return 0;
    }
    if (offset<0x8000) {    /* SRAM����ش��� RAM��            */
        return 0;
    }
    return readPro(offset); /* 32K ������� ROM                */
}

void memory::write(const word offset, const byte data) {
    if (offset<0x2000) {
        ram[offset%0x0800] = data;
        return;
    }
    if (offset<0x4000) {    /* PPU �Ĵ���                      */
        ppu->controlWrite(offset, data);
        return;
    }
    if (offset==0x4014) {   /* OAM DMA �Ĵ���                  */
#ifdef SHOW_PPU_REGISTER
        printf("MEM::��PPU����OAM,ram:%04X\n", data<<8);
#endif
        ppu->copySprite(ram + (data<<8));
        return;
    }
    if (offset==0x4016 || offset==0x4017) {
        pad->writePort(offset, data);
        return;
    }
    if (offset>=0x8000) {
#ifdef SHOW_ERR_MEM_OPERATE
        printf("MEM::������д������: 0x%x = 0x%x \n", offset, data);
#endif
        mmc->checkSwitch(offset, data);
    }
}

byte memory::readPro(const word offset) {
    return mmc->readRom(offset);
}
