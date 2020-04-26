
@{{BLOCK(ForestScreen)

@=======================================================================
@
@	ForestScreen, 256x192@8, 
@	+ palette 256 entries, not compressed
@	+ 50 tiles (t|f reduced) not compressed
@	+ regular map (flat), not compressed, 32x24 
@	Total size: 512 + 3200 + 1536 = 5248
@
@	Time-stamp: 2020-01-18, 03:11:06
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global ForestScreenTiles		@ 3200 unsigned chars
ForestScreenTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x15151520,0x15151515
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x15151515,0x15151515

	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20201515,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x15151520
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x15151515,0x20201515
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x15151515

	.word 0x15151520,0x15151515,0x15151520,0x15151515,0x15151520,0x15151515,0x15151520,0x15151515
	.word 0x15151520,0x15151515,0x15151520,0x15151515,0x15151520,0x15151515,0x15151520,0x20151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x20202020,0x20202020
	.word 0x20201515,0x20202020,0x20201515,0x20202020,0x20201515,0x20202020,0x20201515,0x20202020
	.word 0x20201515,0x20202020,0x20201515,0x20202020,0x20201515,0x20202020,0x20202020,0x20202020
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x20201515

	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x20202020,0x15151515
	.word 0x20201515,0x20202020,0x20201515,0x20202020,0x20201515,0x20202020,0x20201515,0x20202020
	.word 0x20201515,0x20202020,0x20201515,0x20202020,0x20201515,0x20202020,0x20201515,0x20202020
	.word 0x20202020,0x15151520,0x20202020,0x15151520,0x20202020,0x15151520,0x20202020,0x15151520
	.word 0x20202020,0x15151520,0x20202020,0x15151520,0x20202020,0x15151520,0x20202020,0x15151520
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x20151515,0x20202020

	.word 0x15151515,0x20151515,0x15151515,0x20151515,0x15151515,0x20151515,0x15151515,0x20151515
	.word 0x15151515,0x20151515,0x15151515,0x20151515,0x15151515,0x20151515,0x20202020,0x20202020
	.word 0x15151515,0x20201515,0x15151515,0x20201515,0x15151515,0x20201515,0x15151515,0x20201515
	.word 0x15151515,0x20201515,0x15151515,0x20201515,0x15151515,0x20201515,0x20202020,0x20202020
	.word 0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x15151515
	.word 0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x20202020
	.word 0x15151520,0x20151515,0x15151520,0x20151515,0x15151520,0x20151515,0x15151520,0x20151515
	.word 0x15151520,0x20151515,0x15151520,0x20151515,0x15151520,0x15151515,0x15151520,0x15151515

	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x15151515,0x20202015,0x15151515,0x20202015
	.word 0x15151515,0x20201515,0x15151515,0x20201515,0x15151515,0x20201515,0x15151515,0x20201515
	.word 0x15151515,0x20201515,0x15151515,0x20201515,0x15151515,0x20201515,0x15151515,0x20201515
	.word 0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x15151515
	.word 0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x15151515
	.word 0x15151515,0x20201515,0x15151515,0x20201515,0x15151515,0x20201515,0x15151515,0x20201515
	.word 0x15151515,0x20201515,0x15151515,0x20201515,0x15151515,0x15151515,0x15151515,0x15151515

	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x20151515,0x20202020,0x20151515,0x20202020,0x20151515,0x20202020,0x20151515,0x20202020
	.word 0x20151515,0x20202020,0x20151515,0x20202020,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202015,0x20202020,0x20202015,0x20202020
	.word 0x20202020,0x15151520,0x20202020,0x15151520,0x20202020,0x15151520,0x20202020,0x15151520
	.word 0x20202020,0x15151520,0x20202020,0x15151520,0x20202020,0x20202020,0x20202020,0x20202020

	.word 0x20151515,0x20202020,0x20151515,0x20202020,0x20151515,0x20202020,0x20151515,0x20202020
	.word 0x20151515,0x20202020,0x20151515,0x20202020,0x15202020,0x15151515,0x15202020,0x15151515
	.word 0x15151520,0x15151515,0x15151520,0x15151515,0x15151520,0x15151515,0x15151520,0x15151515
	.word 0x15151520,0x15151515,0x15151520,0x15151515,0x15151520,0x20151515,0x15151520,0x20151515
	.word 0x15151515,0x20202015,0x15151515,0x20202015,0x15151515,0x20202015,0x15151515,0x20202015
	.word 0x15151515,0x20202015,0x15151515,0x20202015,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x20201515,0x15151515,0x20201515

	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x20202020,0x15151515,0x20202020,0x15151515
	.word 0x15151515,0x20151515,0x15151515,0x20151515,0x15151515,0x20151515,0x15151515,0x20151515
	.word 0x15151515,0x20151515,0x15151515,0x20151515,0x20202015,0x20202020,0x20202015,0x20202020
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x20151515,0x20202020,0x20151515,0x20202020
	.word 0x20202015,0x20202020,0x20202015,0x20202020,0x20202015,0x20202020,0x20202015,0x20202020
	.word 0x20202015,0x20202020,0x20202015,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020

	.word 0x20202015,0x20202020,0x20202015,0x20202020,0x20202015,0x20202020,0x20202015,0x20202020
	.word 0x20202015,0x20202020,0x20202015,0x20202020,0x15151520,0x20201515,0x15151520,0x20201515
	.word 0x15151520,0x20151515,0x15151520,0x20151515,0x15151520,0x20151515,0x15151520,0x20151515
	.word 0x15151520,0x20151515,0x15151520,0x20151515,0x15151520,0x20151515,0x15151520,0x20151515
	.word 0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x15151515
	.word 0x20202020,0x15151515,0x20202020,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x15151515
	.word 0x20202020,0x15151515,0x20202020,0x15151515,0x20202020,0x20202020,0x20202020,0x20202020

	.word 0x20202015,0x20202020,0x20202015,0x20202020,0x20202015,0x20202020,0x20202015,0x20202020
	.word 0x20202015,0x20202020,0x20202015,0x20202020,0x15151520,0x20151515,0x15151520,0x20151515
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x15151515,0x20151515,0x15151515,0x20151515
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20202020,0x15151520,0x20202020,0x15151520
	.word 0x15151520,0x20201515,0x15151520,0x20201515,0x15151520,0x20201515,0x15151520,0x20201515
	.word 0x15151520,0x20201515,0x15151520,0x20201515,0x15151515,0x20201515,0x15151515,0x20201515

	.word 0x15151520,0x20151515,0x15151520,0x20151515,0x15151520,0x20151515,0x21212120,0x20212121
	.word 0x21212120,0x20212121,0x21212120,0x20212121,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x21212121,0x21212121
	.word 0x21212121,0x21212121,0x21212121,0x21212121,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x20201515,0x20202020,0x20201515,0x20202020,0x20201515,0x20202020,0x20202121,0x20202020
	.word 0x20202121,0x20202020,0x20202121,0x20202020,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x15151515,0x20201515,0x15151515,0x20201515,0x15151515,0x20201515,0x21212121,0x20202121
	.word 0x21212121,0x20202121,0x21212121,0x20202121,0x20202020,0x20202020,0x20202020,0x20202020

	.word 0x20202020,0x15151520,0x20202020,0x15151520,0x20202020,0x15151520,0x20202020,0x21212120
	.word 0x20202020,0x21212120,0x20202020,0x21212120,0x20202020,0x20202020,0x20202020,0x20202020
	.word 0x15151515,0x20151515,0x15151515,0x20151515,0x15151515,0x20151515,0x21212121,0x20212121
	.word 0x21212121,0x20212121,0x21212121,0x20212121,0x20202020,0x20202020,0x20202020,0x20202020

	.section .rodata
	.align	2
	.global ForestScreenMap		@ 1536 unsigned chars
ForestScreenMap:
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002
	.hword 0x0003,0x0004,0x0003,0x0003,0x0004,0x0003,0x0003,0x0402
	.hword 0x0005,0x0003,0x0402,0x0005,0x0003,0x0006,0x0007,0x0003
	.hword 0x0006,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0008
	.hword 0x0009,0x000A,0x000B,0x000C,0x000D,0x000B,0x0009,0x0408
	.hword 0x000E,0x000F,0x0010,0x000E,0x000F,0x0011,0x0012,0x040B
	.hword 0x0011,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0013
	.hword 0x0014,0x0001,0x0015,0x0016,0x000D,0x0017,0x0018,0x0413
	.hword 0x000E,0x0019,0x001A,0x001B,0x001C,0x001A,0x0001,0x0415
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x001D
	.hword 0x001E,0x0001,0x0015,0x0016,0x000D,0x001F,0x0020,0x0021
	.hword 0x000E,0x0022,0x0023,0x0001,0x041E,0x0024,0x0001,0x0415
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0025
	.hword 0x0001,0x0001,0x0017,0x0026,0x000D,0x0015,0x0027,0x0028
	.hword 0x000E,0x0019,0x0029,0x002A,0x0018,0x002B,0x0001,0x0415
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x002C
	.hword 0x0001,0x0001,0x002D,0x002D,0x002E,0x002F,0x0001,0x002C
	.hword 0x0030,0x002D,0x0031,0x0030,0x002D,0x002F,0x0001,0x042F
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.section .rodata
	.align	2
	.global ForestScreenPal		@ 512 unsigned chars
ForestScreenPal:
	.hword 0x0000,0x1884,0x1CA8,0x18EC,0x1D51,0x11DB,0x329B,0x4F1D
	.hword 0x1BDF,0x2B93,0x1AED,0x3646,0x15A9,0x112A,0x1CE6,0x38E7
	.hword 0x4186,0x71AB,0x7E6C,0x732B,0x7F79,0x7FFF,0x5AB3,0x41F0
	.hword 0x35AD,0x294B,0x450E,0x18D5,0x315B,0x5DFA,0x2651,0x19B1
	.hword 0x0421,0x6F7B,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
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

@}}BLOCK(ForestScreen)