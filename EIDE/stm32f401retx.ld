/**
 * File: Linker_Script.ld
 * Auther: Mostafa Asaad (https://github.com/M0stafa077)
 * Brief: The Linker Script file for the STM32F401RCT6 dev. board.
*/

/* Highest address of the user mode stack */
_estack = ORIGIN(RAM) + LENGTH(RAM); /* End of "RAM" Ram type memory */

_Min_Heap_Size  = 0x200 ;  /* The required size for the Heap memory in Bytes */
_Min_Stack_Size = 0x400 ;  /* The required size for the Stack memory in Bytes */

/* Types of memory in STM32F401RCT6 */
MEMORY
{
    RAM (xrw)    : ORIGIN = 0x20000000, LENGTH = 64K        /* 64KByte Embedded SRAM */
    FLASH (rx)   : ORIGIN = 0x08000000,  LENGTH = 256K       /* 256KByte Flash Memory */
}

/* User defined Memory Sections */
SECTIONS
{
    /* The ISR vector table memory section */
    .isr_vector :
    {
        . = ALIGN(4);
        *(.isr_vector)
        . = ALIGN(4);
    } >FLASH

    /* Text/Code memory section */
    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        . = ALIGN(4);
        _etext = .;             /* The end of the .text section in FLASH memory */
    } >FLASH

    /* Read-Only data memory section */
    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    } >FLASH

    /* Data memory section */
    _sidata = LOADADDR(.data);  /* The Load-Address of the start of .data section in FLASH memory */
    .data :
    {
        . = ALIGN(4);
        _sdata = .;             /* The Virtual-Address of the start of .data section in RAM memory */
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _edata = .;             /* The Virtual-Address of the end of .data section in RAM memory */
    } >RAM AT> FLASH

    /* bss memory section */
    .bss :
    {
        _sbss = .;              /* The start address of .bss segment in RAM memory */
        *(.bss)
        *(.bss*)
        . = ALIGN(4);
        _ebss = .;              /* The end address of .bss segment in RAM memory */
    } >RAM

    /* .User_heap_stack section, used to check that there is enough "RAM" Ram  type memory left */
    ._user_heap_stack :
    {
    . = ALIGN(8);
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
    } >RAM
}
