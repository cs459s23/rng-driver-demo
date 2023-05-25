ENTRY(_entry)
SECTIONS
{
    . = 0x00001000;
    .text : { *(.text) }
    . = ALIGN(8);
    .rodata : { *(.rodata) }
    . = ALIGN(8);
    .data : { *(.data) }
    .bss : { *(.bss) }
}
