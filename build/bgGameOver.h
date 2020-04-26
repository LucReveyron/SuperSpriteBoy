
//{{BLOCK(bgGameOver)

//======================================================================
//
//	bgGameOver, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 95 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 6080 + 1536 = 8128
//
//	Time-stamp: 2020-01-18, 03:11:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BGGAMEOVER_H
#define GRIT_BGGAMEOVER_H

#define bgGameOverTilesLen 6080
extern const unsigned int bgGameOverTiles[1520];

#define bgGameOverMapLen 1536
extern const unsigned short bgGameOverMap[768];

#define bgGameOverPalLen 512
extern const unsigned short bgGameOverPal[256];

#endif // GRIT_BGGAMEOVER_H

//}}BLOCK(bgGameOver)
