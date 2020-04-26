
//{{BLOCK(bgSky)

//======================================================================
//
//	bgSky, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 11 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 704 + 1536 = 2752
//
//	Time-stamp: 2020-01-18, 03:11:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BGSKY_H
#define GRIT_BGSKY_H

#define bgSkyTilesLen 704
extern const unsigned int bgSkyTiles[176];

#define bgSkyMapLen 1536
extern const unsigned short bgSkyMap[768];

#define bgSkyPalLen 512
extern const unsigned short bgSkyPal[256];

#endif // GRIT_BGSKY_H

//}}BLOCK(bgSky)
