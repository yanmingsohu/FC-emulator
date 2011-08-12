#include "nes_sys.h"
#include <stdio.h>

NesSystem::NesSystem() {
    mmc = new MMC();
    ppu = new PPU(mmc);
    ram = new memory(mmc, ppu);
    cpu = new cpu_6502(ram);
    rom = new nes_file();
    state = 0;
}

NesSystem::~NesSystem() {
    delete cpu;
    delete ram;
    delete ppu;
    delete mmc;
    delete rom;
}

int NesSystem::load_rom(string filename) {
    int res = ::load_rom(rom, &filename);

    if (!res) {
        rom->romInfo();

        if (mmc->loadNes(rom)) {
            printf("INT vector(0xFFFA-0xFFFF): ");
            rom->printRom(0xFFFA - 0x8000, 6);
            ram->reset();
            ppu->swithMirror(rom->t1 & 0x0B);
            cpu->RES = 1;
        } else {
            res = ER_LOAD_ROM_BADMAP;
        }
    }

    return res;
}

cpu_6502* NesSystem::getCpu() {
    if (state) {
        printf("> NesSystem::��δ��ʼ��rom.\n");
    }
    return cpu;
}
