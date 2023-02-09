MEMORY
{
    flash (rx)  : ORIGIN = 0x08000000, LENGTH = 128K
    sram (rwx)  : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.vector_table ALIGN(0x0) : { *(.data.VectorTable) } > flash
	.text : { *(.text) } > flash

	
	/DISCARD/ :
	{
		* (.ARM.exidx);
	}
}

OUTPUT_ARCH(thumb)