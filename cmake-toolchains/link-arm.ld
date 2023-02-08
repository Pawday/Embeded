MEMORY
{
    flash (rx)  : ORIGIN = 0x08000000, LENGTH = 128K
    sram (rwx)  : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.data ALIGN(0x0) : { *(.data) } > flash
	.text 0x08000200: { *(.text) } > flash

	
	/DISCARD/ :
	{
		* (.ARM.exidx);
	}
}

OUTPUT_ARCH(thumb)