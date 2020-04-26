
//{{BLOCK(bgforest)

//======================================================================
//
//	bgforest, 512x512@8, 
//	+ palette 256 entries, not compressed
//	+ 443 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 64x64 
//	Total size: 512 + 28352 + 8192 = 37056
//
//	Time-stamp: 2020-01-18, 12:19:45
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BGFOREST_H
#define GRIT_BGFOREST_H

#define bgforestTilesLen 28352
extern const unsigned int bgforestTiles[7088];

#define bgforestMapLen 8192
extern const unsigned short bgforestMap[4096];

#define bgforestPalLen 512
extern const unsigned short bgforestPal[256];

#endif // GRIT_BGFOREST_H

//}}BLOCK(bgforest)
