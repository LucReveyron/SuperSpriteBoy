
//{{BLOCK(ForestScreen)

//======================================================================
//
//	ForestScreen, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 50 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 3200 + 1536 = 5248
//
//	Time-stamp: 2020-01-18, 03:11:06
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FORESTSCREEN_H
#define GRIT_FORESTSCREEN_H

#define ForestScreenTilesLen 3200
extern const unsigned int ForestScreenTiles[800];

#define ForestScreenMapLen 1536
extern const unsigned short ForestScreenMap[768];

#define ForestScreenPalLen 512
extern const unsigned short ForestScreenPal[256];

#endif // GRIT_FORESTSCREEN_H

//}}BLOCK(ForestScreen)
