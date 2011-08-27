#ifndef PCKFILE_H
#define PCKFILE_H

#include <iostream>
#include <string>

namespace Importer {

class cTabFile;
class c8bppBitmap;

/** Class responsible for parsing and loading PCK file.
  after calling load file is stored inside class, so stream may be closed */
class cPckFile
{
public:
  cPckFile();
  ~cPckFile();

  /** Loads pck file to internal buffer, then file is parsed and bitmaps are extracted.
    Class may grow significantly here ;)
    @param file - opened file (at position 0 - loader will always parse whole file - seek used heavily).
  */
  bool loadPck(const cTabFile & f, std::istream & file);

  /** After loading pck returns n-th bitmap from that file. If number is invalid NULL is returned.
    Returned object belongs to cPckFile - should not be freed.
    @warning Number == number of raster in _PCK_ file (holes may be present in case of troubles with
    extracting some files).
    @todo Not yet sure whether bitmaps should be generated here on-demand or pre-generated by loadPCK...
  */
  const c8bppBitmap *getBitmap(int no) const;

  /** Returns number of bitmaps successfully parsed */
  int bitmapCount() const;

//  // don't pass extensions here
//  // loads .tab and associated .pck file if possible
//  bool LoadPackage(const std::string &source);
//  // loads palette to use when stripping files to .bmp
//  bool LoadPalette(const std::string &source);
//  // strips all loaded files and outputs them to $dest folder
//  bool StripTo(const std::string &dest, bool strip_pck = false, bool strip_stats = false);
//  // releases all internal data
//  void Release();

//  bool GetStats(sPckFileStats &stats);

  /** Returns true if loading was finished succesfully */
  bool isValid() const;

private:

  class Private;

//  void CreateBuffer(int size);
//  void DeleteBuffer();

//  void FillStats();

  Private * p;
};

}
#endif // PCKFILE_H