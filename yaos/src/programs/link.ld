OUTPUT_FORMAT("elf32-i386");


ENTRY(_start);

SECTIONS
{
    /* This should be your memory offset (VMA) where the code and data
     * will be loaded. In Linux this is 0x400000, multiboot loader is
     * 0x100000 etc */
    . = 0x80000;

   
    .text : {
        
        *(.text*);
    }

    /* Output the data sections */
    .data : {
        *(.data*);
    }

    .rodata : {
        *(.rodata*);
    }

    /* The BSS section for uniitialized data */
    .bss : {
        __bss_start = .;
        *(COMMON);
        *(.bss);
        . = ALIGN(4);
        __bss_end = .;
    }

    /* Size of the BSS section in case it is needed */
    __bss_size = ((__bss_end)-(__bss_start));

    /* Remove the note that may be placed before the code by LD */
    /DISCARD/ : {
        *(.note.gnu.build-id);
    }
}