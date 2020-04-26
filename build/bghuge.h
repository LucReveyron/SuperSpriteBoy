
//{{BLOCK(bghuge)

//======================================================================
//
//	bghuge, 512x512@8, 
//	+ palette 256 entries, not compressed
//	+ 69 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 64x64 
//	Total size: 512 + 4416 + 8192 = 13120
//
//	Time-stamp: 2020-01-18, 03:11:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BGHUGE_H
#define GRIT_BGHUGE_H

#define bghugeTilesLen 4416
extern const unsigned int bghugeTiles[1104];

#define bghugeMapLen 8192
extern const unsigned short bghugeMap[4096];

#define bghugePalLen 512
extern const unsigned short bghugePal[256];

#endif // GRIT_BGHUGE_H

//}}BLOCK(bghuge)
