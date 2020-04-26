
//{{BLOCK(bgCastle)

//======================================================================
//
//	bgCastle, 512x512@8, 
//	+ palette 256 entries, not compressed
//	+ 493 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 64x64 
//	Total size: 512 + 31552 + 8192 = 40256
//
//	Time-stamp: 2020-01-18, 03:11:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BGCASTLE_H
#define GRIT_BGCASTLE_H

#define bgCastleTilesLen 31552
extern const unsigned int bgCastleTiles[7888];

#define bgCastleMapLen 8192
extern const unsigned short bgCastleMap[4096];

#define bgCastlePalLen 512
extern const unsigned short bgCastlePal[256];

#endif // GRIT_BGCASTLE_H

//}}BLOCK(bgCastle)
