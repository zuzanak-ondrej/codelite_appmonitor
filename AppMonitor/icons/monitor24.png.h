#ifndef MONITOR24_PNG_H
#define MONITOR24_PNG_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char monitor24_png[] = 
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x18, 
	0x00, 0x00, 0x00, 0x18, 0x08, 0x06, 0x00, 0x00, 0x00, 0xE0, 
	0x77, 0x3D, 0xF8, 0x00, 0x00, 0x00, 0x04, 0x73, 0x42, 0x49, 
	0x54, 0x08, 0x08, 0x08, 0x08, 0x7C, 0x08, 0x64, 0x88, 0x00, 
	0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x0D, 
	0xD7, 0x00, 0x00, 0x0D, 0xD7, 0x01, 0x42, 0x28, 0x9B, 0x78, 
	0x00, 0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6F, 
	0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x77, 0x77, 0x77, 
	0x2E, 0x69, 0x6E, 0x6B, 0x73, 0x63, 0x61, 0x70, 0x65, 0x2E, 
	0x6F, 0x72, 0x67, 0x9B, 0xEE, 0x3C, 0x1A, 0x00, 0x00, 0x03, 
	0x95, 0x49, 0x44, 0x41, 0x54, 0x48, 0x89, 0xD5, 0x94, 0x4D, 
	0x68, 0x5D, 0x45, 0x14, 0xC7, 0x7F, 0x33, 0x77, 0x6E, 0x42, 
	0x53, 0x62, 0x45, 0xD1, 0x24, 0x2F, 0x95, 0xB6, 0x86, 0x20, 
	0xD5, 0x54, 0x48, 0xBA, 0x74, 0x23, 0x22, 0x2E, 0x04, 0x15, 
	0x2A, 0x48, 0xB5, 0xE2, 0xAA, 0x08, 0x1A, 0x45, 0xA8, 0xB8, 
	0x74, 0xE1, 0x42, 0x5C, 0xE8, 0xCE, 0x95, 0x2E, 0x1A, 0x10, 
	0x5A, 0x3F, 0x56, 0x12, 0x0B, 0xD2, 0x8D, 0x6E, 0xA4, 0x2D, 
	0x2A, 0x58, 0x35, 0xC1, 0x12, 0xAC, 0x16, 0xED, 0xC2, 0xB4, 
	0xC1, 0xB4, 0xF9, 0x78, 0xEF, 0xDD, 0x39, 0x67, 0xCE, 0xB8, 
	0xB8, 0xEF, 0xBD, 0x24, 0x2A, 0x54, 0x24, 0x2E, 0x3C, 0x70, 
	0x98, 0xB9, 0x17, 0xE6, 0x7F, 0xCE, 0xFF, 0x7F, 0x3E, 0xE0, 
	0xFF, 0x6E, 0x6E, 0x76, 0x76, 0xF6, 0x01, 0xE0, 0x64, 0xCE, 
	0x79, 0x68, 0x5B, 0x81, 0x9D, 0x5B, 0x04, 0x9E, 0x0A, 0xAA, 
	0x7A, 0x72, 0x62, 0x62, 0x62, 0x68, 0x70, 0x70, 0x70, 0xDB, 
	0xC0, 0x73, 0xCE, 0xAC, 0xAE, 0xAE, 0x0E, 0xCD, 0xCD, 0xCD, 
	0x9D, 0x08, 0x55, 0x55, 0x0D, 0xED, 0xDC, 0xB9, 0x93, 0xE7, 
	0xA7, 0xA7, 0x89, 0x31, 0xFE, 0x2B, 0x40, 0x33, 0x23, 0xA5, 
	0x54, 0xBB, 0x2A, 0x45, 0x08, 0xCC, 0x1C, 0x3F, 0x4E, 0x8C, 
	0x71, 0x38, 0xA8, 0x2A, 0xAA, 0x4A, 0x8C, 0x11, 0x33, 0x07, 
	0xDE, 0xE1, 0x9C, 0xC7, 0xE1, 0x70, 0x0E, 0x9C, 0x73, 0xE0, 
	0xBA, 0xA9, 0x6D, 0x64, 0x98, 0x33, 0xA8, 0x0A, 0x9A, 0x14, 
	0x89, 0x82, 0x88, 0xA0, 0x2A, 0x48, 0x14, 0x42, 0x70, 0x9D, 
	0x6F, 0x25, 0x88, 0x08, 0x66, 0x06, 0x40, 0x28, 0x03, 0xF8, 
	0x02, 0xEF, 0x3C, 0x14, 0x8E, 0x5C, 0x78, 0x7C, 0x06, 0x9F, 
	0x1D, 0xE4, 0xDC, 0x01, 0x37, 0x44, 0x95, 0x24, 0x4A, 0x4A, 
	0x86, 0xAA, 0xA1, 0x56, 0x67, 0x2F, 0x9A, 0x90, 0x94, 0xE8, 
	0x26, 0x2D, 0x22, 0x78, 0x55, 0x25, 0xA5, 0x04, 0x40, 0x11, 
	0x4A, 0x42, 0x08, 0x14, 0x7D, 0x81, 0xB4, 0x6B, 0x80, 0x7D, 
	0x8F, 0xDD, 0x4F, 0xBA, 0x79, 0x80, 0x50, 0x96, 0x14, 0x21, 
	0x90, 0x71, 0x24, 0xCB, 0x58, 0xB2, 0x5A, 0x96, 0x6C, 0x24, 
	0x4B, 0x24, 0x4D, 0x68, 0xCF, 0x85, 0x76, 0xBB, 0xDD, 0x63, 
	0xE0, 0x45, 0x64, 0x23, 0x80, 0x2F, 0x08, 0x45, 0xC0, 0x97, 
	0x7D, 0x94, 0xC3, 0xB7, 0xF0, 0xF0, 0xE1, 0x43, 0x0C, 0xEC, 
	0x6B, 0xA0, 0xDE, 0x61, 0x96, 0x31, 0x33, 0xCC, 0x32, 0xC9, 
	0x40, 0xBB, 0xD9, 0xAB, 0x21, 0x5A, 0xB3, 0x12, 0x15, 0x44, 
	0x6A, 0xB9, 0x45, 0x64, 0x83, 0x81, 0xAA, 0x02, 0xE0, 0x0B, 
	0x8F, 0xF3, 0x9E, 0x4C, 0xE6, 0xD6, 0xBD, 0xA3, 0x00, 0xEC, 
	0xDE, 0x3F, 0x46, 0x72, 0x19, 0x75, 0x8E, 0x54, 0x38, 0x52, 
	0xCE, 0xB5, 0xEE, 0x5D, 0x19, 0x62, 0x24, 0xC6, 0x48, 0x15, 
	0x85, 0xA4, 0xA9, 0xAB, 0x64, 0x4F, 0xA6, 0x2D, 0x0C, 0x24, 
	0x25, 0xAA, 0xAA, 0xA2, 0x32, 0xE1, 0xF6, 0x3B, 0x1A, 0x2C, 
	0x2F, 0x2F, 0xB3, 0x67, 0x7C, 0x8C, 0x96, 0xCF, 0x34, 0x77, 
	0x95, 0x84, 0xF1, 0x06, 0x4D, 0x12, 0xED, 0x2A, 0xD2, 0x6A, 
	0xB5, 0x69, 0xB5, 0x5A, 0x54, 0x31, 0xF6, 0xDE, 0x6F, 0xB6, 
	0x5E, 0x0D, 0xBA, 0x54, 0xDA, 0x55, 0x45, 0x33, 0x56, 0xAC, 
	0xA7, 0x48, 0x13, 0x63, 0x78, 0xB4, 0xC1, 0xB9, 0x33, 0xE7, 
	0xD8, 0xB3, 0x6F, 0x2F, 0xCD, 0xFE, 0x82, 0xFD, 0x0F, 0xDD, 
	0xC7, 0x91, 0x57, 0x9E, 0x43, 0x6E, 0x2A, 0x69, 0x6A, 0x85, 
	0xB8, 0x44, 0x2A, 0x1C, 0xB9, 0xF4, 0xE4, 0xB2, 0xC0, 0x95, 
	0x05, 0xF4, 0x05, 0x5C, 0x5F, 0x81, 0xF3, 0xBE, 0x27, 0x51, 
	0xE8, 0xB6, 0xE8, 0x2A, 0x4A, 0xE3, 0xDE, 0x3B, 0x21, 0x78, 
	0x5C, 0x7F, 0x60, 0x64, 0x77, 0x83, 0xD3, 0xA7, 0x3E, 0x65, 
	0xEA, 0xE0, 0x24, 0x23, 0x07, 0xC6, 0xB8, 0x67, 0xF2, 0x00, 
	0xBE, 0x28, 0x98, 0x7A, 0xE4, 0x41, 0xCE, 0x7C, 0xF4, 0x09, 
	0x8D, 0xB1, 0xBD, 0x94, 0xFD, 0x25, 0xB9, 0xD7, 0x5D, 0x75, 
	0x87, 0xA5, 0xA8, 0x5C, 0xFC, 0xEC, 0x8B, 0x9E, 0x44, 0x41, 
	0x44, 0x58, 0x59, 0x59, 0x61, 0x15, 0xE5, 0xD1, 0xA3, 0x47, 
	0x70, 0xDE, 0x01, 0x8E, 0xA5, 0xC5, 0x2B, 0xFC, 0x36, 0xBF, 
	0xC0, 0xC5, 0x85, 0x1F, 0x39, 0x70, 0x70, 0x92, 0xE1, 0x91, 
	0x11, 0xDE, 0x7F, 0xEF, 0x04, 0x87, 0x9E, 0x78, 0x9C, 0xF1, 
	0xBB, 0xEF, 0x62, 0x78, 0xB4, 0x41, 0x73, 0x6D, 0x7D, 0xD3, 
	0x70, 0x6C, 0xCC, 0xC8, 0x9B, 0xE7, 0xBF, 0xDB, 0xCA, 0x40, 
	0x55, 0x69, 0x5F, 0xBE, 0xC2, 0x1B, 0x4F, 0x4F, 0xE3, 0xFB, 
	0x4A, 0x1C, 0x90, 0xD5, 0xB0, 0x66, 0x9B, 0x85, 0x6F, 0xE6, 
	0x78, 0xE6, 0xC5, 0x67, 0x99, 0xFF, 0xF6, 0x7B, 0x7E, 0xF8, 
	0xFC, 0x0C, 0x3F, 0x4F, 0x4D, 0x72, 0xFD, 0xF7, 0x65, 0x66, 
	0x5E, 0x7B, 0x8B, 0xF6, 0xB5, 0x15, 0xB2, 0x59, 0x27, 0xFB, 
	0x5C, 0x33, 0xA8, 0x22, 0x5C, 0x5B, 0xDD, 0xCA, 0x40, 0x44, 
	0x48, 0xAD, 0x8A, 0xF5, 0x9F, 0x7E, 0xC5, 0xFB, 0xA2, 0x9E, 
	0x5E, 0xC0, 0x97, 0x25, 0x17, 0xCE, 0x7E, 0x45, 0x7E, 0xE1, 
	0x28, 0xE7, 0xCF, 0x7E, 0xC9, 0xCA, 0x85, 0x4B, 0xBC, 0xFB, 
	0xD2, 0xAB, 0xA4, 0x76, 0x85, 0x5C, 0x5F, 0xC3, 0x24, 0xF5, 
	0x80, 0xCD, 0x8C, 0x6C, 0xF5, 0x5C, 0x0C, 0x0E, 0x0C, 0x6C, 
	0x65, 0x20, 0x22, 0x90, 0x33, 0x55, 0xB3, 0x59, 0xAF, 0x09, 
	0xE7, 0x6A, 0xF7, 0x9E, 0xA5, 0x85, 0x4B, 0x7C, 0xF0, 0xCE, 
	0x0C, 0x5F, 0x7F, 0x7C, 0x9A, 0xB5, 0xA5, 0x65, 0xB2, 0x26, 
	0x72, 0x36, 0x72, 0xB2, 0x1E, 0x78, 0xB6, 0x4C, 0xCE, 0x19, 
	0xCB, 0x75, 0x10, 0x76, 0xEC, 0xD8, 0xBA, 0x2A, 0x44, 0x04, 
	0x80, 0x58, 0x55, 0x1B, 0xE0, 0xAE, 0xAE, 0x85, 0xFE, 0x72, 
	0x99, 0x53, 0xAF, 0xBF, 0x4D, 0x8A, 0x8A, 0x89, 0x42, 0xB6, 
	0x4E, 0xAF, 0xE7, 0x4E, 0x80, 0x4D, 0x6E, 0x86, 0x75, 0x8A, 
	0xDE, 0x63, 0xB0, 0x25, 0x40, 0xEC, 0x04, 0xC0, 0x81, 0xAB, 
	0x97, 0x1D, 0xD1, 0xE1, 0xD6, 0x9A, 0x9B, 0xEB, 0x08, 0x39, 
	0xD7, 0xF7, 0x3F, 0x07, 0xC8, 0xD6, 0xEB, 0xAA, 0xBF, 0xB4, 
	0x69, 0x59, 0x96, 0x8C, 0x8E, 0x8E, 0xFE, 0x93, 0xED, 0x7C, 
	0x43, 0x2B, 0xCB, 0x92, 0x18, 0x63, 0x2D, 0x91, 0x99, 0x2D, 
	0x2E, 0x2D, 0x2D, 0x0D, 0xBD, 0x7C, 0xEC, 0xD8, 0xB6, 0x80, 
	0x77, 0xED, 0xEA, 0xD5, 0xAB, 0x98, 0xD9, 0x62, 0x48, 0x29, 
	0x3D, 0x39, 0x3F, 0x3F, 0xFF, 0xA1, 0x99, 0xDD, 0xB6, 0x9D, 
	0x01, 0xBC, 0xF7, 0x57, 0x54, 0xF5, 0xB0, 0xDB, 0xF4, 0xAF, 
	0x0F, 0xD8, 0xD1, 0x39, 0xDD, 0xDF, 0x3F, 0xBB, 0xA1, 0x65, 
	0x20, 0x02, 0xAD, 0xCE, 0xF9, 0xDF, 0xDB, 0x1F, 0x9B, 0x4E, 
	0xCB, 0x6B, 0x94, 0x7C, 0xC2, 0xFF, 0x00, 0x00, 0x00, 0x00, 
	0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
};

wxBitmap& monitor24_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( monitor24_png, sizeof( monitor24_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
};


#endif //MONITOR24_PNG_H