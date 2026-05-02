/**
 * File: Linker_Script.ld
 * Brief: Linker Script for AT32F403ARGT7 (雅特力 ARTERY)
 */

/* Highest address of the user mode stack */
_estack = ORIGIN(RAM) + LENGTH(RAM); /* End of "RAM" Ram type memory */

_Min_Heap_Size  = 0x200 ;  /* Heap size */
_Min_Stack_Size = 0x800 ;  /* Stack size */

/* AT32F403ARGT7 内存布局 */
MEMORY
{
    RAM (xrw)     : ORIGIN = 0x20000000, LENGTH = 32K     /* 32KB SRAM */
    FLASH (rx)    : ORIGIN = 0x08000000, LENGTH = 128K    /* 128KB Flash */
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
        _etext = .;
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
    _sidata = LOADADDR(.data);
    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } >RAM AT> FLASH

    /* bss memory section */
    .bss :
    {
        _sbss = .;
        *(.bss)
        *(.bss*)
        . = ALIGN(4);
        _ebss = .;
    } >RAM

    /* Heap & Stack */
    ._user_heap_stack :
    {
        . = ALIGN(8);
        . = . + _Min_Heap_Size;
        . = . + _Min_Stack_Size;
        . = ALIGN(8);
    } >RAM
}