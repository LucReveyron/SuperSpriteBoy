
@{{BLOCK(testC2)

@=======================================================================
@
@	testC2, 32x32@8, 
@	+ palette 256 entries, not compressed
@	+ 16 tiles not compressed
@	Total size: 512 + 1024 = 1536
@
@	Time-stamp: 2020-01-18, 03:11:07
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global testC2Tiles		@ 1024 unsigned chars
testC2Tiles:
	.word 0x01010000,0x01010101,0x05050100,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505
	.word 0x05050501,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505
	.word 0x01010101,0x01010101,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x01010101,0x01010101,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x01010101,0x00000101,0x05050505,0x00010505,0x05050505,0x01050505,0x01010101,0x01050505
	.word 0x01131301,0x01050505,0x01131301,0x01050505,0x01010101,0x01050505,0x05050505,0x01050505

	.word 0x05050501,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505
	.word 0x05050501,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x01050505,0x05050505,0x01050505,0x05050505,0x00010505,0x05050505,0x00000105
	.word 0x05050505,0x00000001,0x01050505,0x00000000,0x00010505,0x00000000,0x00000105,0x00000000

	.word 0x05050501,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505
	.word 0x05050501,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x00000001,0x00000000,0x00000105,0x00000000,0x00010505,0x00000000,0x01050505,0x00000000
	.word 0x05050505,0x00000001,0x05050505,0x00000105,0x05050505,0x00010505,0x05050505,0x01050505

	.word 0x05050501,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505,0x05050501,0x05050505
	.word 0x05050501,0x05050505,0x05050501,0x05050505,0x05050100,0x05050505,0x01010000,0x01010101
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x01010101,0x01010101
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x01010101,0x01010101
	.word 0x05050505,0x01050505,0x05050505,0x01050505,0x05050505,0x01050505,0x05050505,0x01050505
	.word 0x05050505,0x01050505,0x05050505,0x01050505,0x05050505,0x00010505,0x01010101,0x00000101

	.section .rodata
	.align	2
	.global testC2Pal		@ 512 unsigned chars
testC2Pal:
	.hword 0x0000,0x1884,0x1CA8,0x18EC,0x1D51,0x11DB,0x329B,0x4F1D
	.hword 0x1BDF,0x2B93,0x1AED,0x3646,0x15A9,0x112A,0x1CE6,0x38E7
	.hword 0x4186,0x71AB,0x7E6C,0x732B,0x7F79,0x7FFF,0x5AB3,0x41F0
	.hword 0x35AD,0x294B,0x450E,0x18D5,0x315B,0x5DFA,0x2651,0x19B1
	.hword 0x05BF,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(testC2)