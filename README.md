## Single header bitmap (bmp) reading/writing
Simple single-header-only implementation of both reading and writing Microsoft bitmap (.bmp) files. I've used this *in some form* across many of my graphics projects dating back to 1998 because it enables an easy way to dump visual data to a file for later analysis in a more sophisticated tool. 

Note, this implementation only supports one particular (albeit the most common) data format: **RGB24**. This is *not* a comprehensive implementation of the bitmap format!

## Usage
```C++
  uint32 src_width = 0;
  uint32 src_height = 0;
  vector<uint8> src_image;
 
  /* Load our bitmap file into memory. */
  if (!LoadBitmapImage("input.bmp", &src_image, &src_width, &src_height)) {
    /* handle bitmap read error. */
    return 0;
  }

  /* Image loaded with dimensions stored src_width and src_height. */

  /* Save our image back out to a bitmap file. */
  if (!SaveBitmapImage("output.bmp", &src_image, src_width, src_height)) {
    /* handle bitmap write error. */
    return 0;
  }
```

## More Information
This software is released under the terms of the BSD 2-Clause “Simplified” License.

For more information visit [http://www.bertolami.com](http://bertolami.com).