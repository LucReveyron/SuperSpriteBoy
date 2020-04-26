
//{{BLOCK(CastleScreen)

//======================================================================
//
//	CastleScreen, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 38 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 2432 + 1536 = 4480
//
//	Time-stamp: 2020-01-18, 03:11:06
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CASTLESCREEN_H
#define GRIT_CASTLESCREEN_H

#define CastleScreenTilesLen 2432
extern const unsigned int CastleScreenTiles[608];

#define CastleScreenMapLen 1536
extern const unsigned short CastleScreenMap[768];

#define CastleScreenPalLen 512
extern const unsigned short CastleScreenPal[256];

#endif // GRIT_CASTLESCREEN_H

//}}BLOCK(CastleScreen)
