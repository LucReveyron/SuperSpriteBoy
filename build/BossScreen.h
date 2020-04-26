
//{{BLOCK(BossScreen)

//======================================================================
//
//	BossScreen, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 81 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 5184 + 1536 = 7232
//
//	Time-stamp: 2020-01-18, 03:11:04
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BOSSSCREEN_H
#define GRIT_BOSSSCREEN_H

#define BossScreenTilesLen 5184
extern const unsigned int BossScreenTiles[1296];

#define BossScreenMapLen 1536
extern const unsigned short BossScreenMap[768];

#define BossScreenPalLen 512
extern const unsigned short BossScreenPal[256];

#endif // GRIT_BOSSSCREEN_H

//}}BLOCK(BossScreen)
