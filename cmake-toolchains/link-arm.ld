ENTRY(start)

SECTIONS
{
	. = 0x0;
	.text ALIGN(0x0) : { *(.text.start) }
	
	
	/DISCARD/ :
	{
		* (.ARM.exidx);
	}
}

OUTPUT_ARCH(arm)