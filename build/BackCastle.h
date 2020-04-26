
//{{BLOCK(BackCastle)

//======================================================================
//
//	BackCastle, 512x512@8, 
//	+ palette 256 entries, not compressed
//	+ 133 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 64x64 
//	Total size: 512 + 8512 + 8192 = 17216
//
//	Time-stamp: 2020-01-18, 03:11:02
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKCASTLE_H
#define GRIT_BACKCASTLE_H

#define BackCastleTilesLen 8512
extern const unsigned int BackCastleTiles[2128];

#define BackCastleMapLen 8192
extern const unsigned short BackCastleMap[4096];

#define BackCastlePalLen 512
extern const unsigned short BackCastlePal[256];

#endif // GRIT_BACKCASTLE_H

//}}BLOCK(BackCastle)
