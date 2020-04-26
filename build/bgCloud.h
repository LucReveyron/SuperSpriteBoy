
//{{BLOCK(bgCloud)

//======================================================================
//
//	bgCloud, 256x128@8, 
//	+ palette 256 entries, not compressed
//	+ 117 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x16 
//	Total size: 512 + 7488 + 1024 = 9024
//
//	Time-stamp: 2020-01-18, 03:11:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BGCLOUD_H
#define GRIT_BGCLOUD_H

#define bgCloudTilesLen 7488
extern const unsigned int bgCloudTiles[1872];

#define bgCloudMapLen 1024
extern const unsigned short bgCloudMap[512];

#define bgCloudPalLen 512
extern const unsigned short bgCloudPal[256];

#endif // GRIT_BGCLOUD_H

//}}BLOCK(bgCloud)
