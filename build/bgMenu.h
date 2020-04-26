
//{{BLOCK(bgMenu)

//======================================================================
//
//	bgMenu, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 145 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 9280 + 1536 = 11328
//
//	Time-stamp: 2020-01-18, 03:11:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BGMENU_H
#define GRIT_BGMENU_H

#define bgMenuTilesLen 9280
extern const unsigned int bgMenuTiles[2320];

#define bgMenuMapLen 1536
extern const unsigned short bgMenuMap[768];

#define bgMenuPalLen 512
extern const unsigned short bgMenuPal[256];

#endif // GRIT_BGMENU_H

//}}BLOCK(bgMenu)
