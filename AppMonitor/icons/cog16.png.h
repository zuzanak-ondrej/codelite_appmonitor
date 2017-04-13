#ifndef COG16_PNG_H
#define COG16_PNG_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char cog16_png[] = 
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x10, 
	0x00, 0x00, 0x00, 0x10, 0x08, 0x06, 0x00, 0x00, 0x00, 0x1F, 
	0xF3, 0xFF, 0x61, 0x00, 0x00, 0x00, 0x04, 0x73, 0x42, 0x49, 
	0x54, 0x08, 0x08, 0x08, 0x08, 0x7C, 0x08, 0x64, 0x88, 0x00, 
	0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x0D, 
	0xD7, 0x00, 0x00, 0x0D, 0xD7, 0x01, 0x42, 0x28, 0x9B, 0x78, 
	0x00, 0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6F, 
	0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x77, 0x77, 0x77, 
	0x2E, 0x69, 0x6E, 0x6B, 0x73, 0x63, 0x61, 0x70, 0x65, 0x2E, 
	0x6F, 0x72, 0x67, 0x9B, 0xEE, 0x3C, 0x1A, 0x00, 0x00, 0x02, 
	0xD5, 0x49, 0x44, 0x41, 0x54, 0x38, 0x8D, 0x75, 0x53, 0xC1, 
	0x4A, 0x23, 0x59, 0x14, 0x3D, 0xEF, 0xE5, 0xBD, 0x8A, 0x54, 
	0x62, 0xC5, 0xAA, 0xC2, 0x0F, 0x50, 0x10, 0x57, 0x82, 0x65, 
	0x67, 0xC0, 0x81, 0x5E, 0x3B, 0x42, 0x66, 0x23, 0xB3, 0xE9, 
	0x85, 0x20, 0xBD, 0x72, 0x56, 0x71, 0xD5, 0xFD, 0x11, 0xDD, 
	0x2B, 0x97, 0x82, 0xD0, 0x12, 0xB2, 0xE8, 0xD5, 0xB8, 0x98, 
	0x09, 0x64, 0x5C, 0xF7, 0x42, 0x68, 0x43, 0xC0, 0x95, 0x22, 
	0x51, 0xD7, 0x79, 0x16, 0xA5, 0x45, 0x52, 0xA9, 0x54, 0xDD, 
	0xF7, 0xAA, 0x37, 0x9D, 0x40, 0x0F, 0x3D, 0x67, 0x75, 0x2F, 
	0x9C, 0x0B, 0xF7, 0x9E, 0x7B, 0x0E, 0xC3, 0xFF, 0xE0, 0xFC, 
	0xFC, 0xFC, 0x6B, 0x96, 0x65, 0x75, 0x00, 0xB0, 0x2C, 0xEB, 
	0x6A, 0x6F, 0x6F, 0xEF, 0x97, 0x9F, 0xF1, 0xD8, 0xAC, 0x68, 
	0xB7, 0xDB, 0x4E, 0xB9, 0x5C, 0xFE, 0x60, 0x8C, 0xE9, 0x3C, 
	0x3F, 0x3F, 0x77, 0x1D, 0xC7, 0xC9, 0x1A, 0x8D, 0x06, 0x00, 
	0xA0, 0xD3, 0xE9, 0x20, 0x8E, 0x63, 0x6B, 0x69, 0x69, 0x69, 
	0x97, 0x73, 0xDE, 0x98, 0x4E, 0xA7, 0xEF, 0xF7, 0xF7, 0xF7, 
	0x63, 0x00, 0xE0, 0xB3, 0x61, 0x29, 0xE5, 0x17, 0xCF, 0xF3, 
	0xDE, 0x72, 0xCE, 0x3F, 0xD7, 0x6A, 0x35, 0xE5, 0xBA, 0xEE, 
	0x58, 0x6B, 0x0D, 0xAD, 0x35, 0x5C, 0xD7, 0x1D, 0xD7, 0x6A, 
	0x35, 0xC5, 0x39, 0xFF, 0xEC, 0x79, 0xDE, 0x5B, 0x29, 0xE5, 
	0x97, 0x76, 0xBB, 0xED, 0x00, 0x80, 0x00, 0x80, 0x52, 0xA9, 
	0xF4, 0xD1, 0xF7, 0xFD, 0xF5, 0xCD, 0xCD, 0x4D, 0x2B, 0x49, 
	0x12, 0x0B, 0x00, 0xB2, 0x2C, 0xC3, 0x60, 0x30, 0x00, 0x00, 
	0xAC, 0xAD, 0xAD, 0x55, 0x2C, 0xCB, 0x02, 0x00, 0xD8, 0xB6, 
	0x8D, 0x7E, 0xBF, 0xBF, 0x3E, 0x1C, 0x0E, 0x3F, 0x00, 0xF8, 
	0x93, 0x03, 0x40, 0x9E, 0xE7, 0xFF, 0x28, 0xA5, 0x68, 0x34, 
	0x1A, 0x81, 0x73, 0x8E, 0xC1, 0x60, 0x80, 0x9B, 0x9B, 0x1B, 
	0xA4, 0x69, 0x8A, 0x34, 0x4D, 0x71, 0x7B, 0x7B, 0x8B, 0xBB, 
	0xBB, 0x3B, 0x70, 0xCE, 0x31, 0x1A, 0x8D, 0xA0, 0x94, 0x22, 
	0x22, 0xEA, 0xCC, 0x4F, 0x98, 0x4C, 0x26, 0x5D, 0x22, 0xCA, 
	0x89, 0x08, 0x0F, 0x0F, 0x0F, 0x90, 0x52, 0x62, 0x75, 0x75, 
	0x15, 0x8C, 0x31, 0x30, 0xC6, 0xB0, 0xB2, 0xB2, 0x82, 0x85, 
	0x85, 0x05, 0x3C, 0x3E, 0x3E, 0x82, 0x88, 0x40, 0x44, 0xF9, 
	0x64, 0x32, 0xE9, 0x02, 0x80, 0x68, 0xB5, 0x5A, 0x5F, 0x89, 
	0xA8, 0xEE, 0x38, 0xCE, 0x88, 0x88, 0x60, 0x8C, 0x81, 0xEF, 
	0xFB, 0xE8, 0xF5, 0x7A, 0x89, 0x31, 0xA6, 0xCB, 0x18, 0x63, 
	0xF7, 0xF7, 0xF7, 0xBF, 0x6D, 0x6D, 0x6D, 0xD9, 0x4F, 0x4F, 
	0x4F, 0xD0, 0x5A, 0xC3, 0x71, 0x9C, 0x52, 0x9E, 0xE7, 0x59, 
	0xAB, 0xD5, 0xBA, 0x12, 0x59, 0x96, 0xD5, 0x77, 0x76, 0x76, 
	0x00, 0xA0, 0x1A, 0x45, 0x11, 0x6C, 0xDB, 0x86, 0x52, 0x0A, 
	0x5A, 0xEB, 0xEE, 0xC1, 0xC1, 0xC1, 0x1F, 0x00, 0x70, 0x76, 
	0x76, 0xF6, 0x97, 0x52, 0x6A, 0xAF, 0x5A, 0xAD, 0x22, 0x4D, 
	0x53, 0x04, 0x41, 0x50, 0x05, 0x80, 0x8B, 0x8B, 0x8B, 0xBA, 
	0x30, 0xC6, 0xC0, 0x18, 0x83, 0xEF, 0x62, 0x62, 0xD6, 0x6B, 
	0xAD, 0xE7, 0xBF, 0x2E, 0x8A, 0x82, 0x19, 0x63, 0x20, 0x84, 
	0x00, 0xE7, 0x7C, 0xCE, 0x37, 0xC6, 0x80, 0x9D, 0x9E, 0x9E, 
	0x5E, 0x11, 0xD1, 0x2B, 0xDF, 0xF7, 0xC7, 0x1B, 0x1B, 0x1B, 
	0x95, 0x2C, 0xCB, 0xA0, 0xB5, 0x46, 0xBF, 0xDF, 0x4F, 0x8A, 
	0xA2, 0xF8, 0xB7, 0x28, 0x0A, 0xC6, 0x39, 0xDF, 0x09, 0x82, 
	0xC0, 0x16, 0x42, 0xC0, 0xB2, 0x2C, 0x5C, 0x5F, 0x5F, 0x8F, 
	0xC3, 0x30, 0xAC, 0x08, 0x21, 0x7A, 0x0C, 0x00, 0x4E, 0x4E, 
	0x4E, 0x64, 0x51, 0x14, 0x6A, 0x7B, 0x7B, 0xBB, 0x56, 0x2E, 
	0x97, 0x51, 0x14, 0x05, 0x92, 0x24, 0x41, 0x18, 0x86, 0x00, 
	0x00, 0xDF, 0xF7, 0x61, 0xDB, 0x36, 0x18, 0x63, 0x98, 0x4E, 
	0xA7, 0xB8, 0xBC, 0xBC, 0x7C, 0x61, 0x8C, 0x2D, 0x1F, 0x1E, 
	0x1E, 0xE6, 0x02, 0x00, 0x88, 0x68, 0xB7, 0x54, 0x2A, 0xC9, 
	0xD9, 0xCA, 0x42, 0x08, 0x78, 0x9E, 0x87, 0xC5, 0xC5, 0x45, 
	0x00, 0x80, 0x94, 0x12, 0xC6, 0x18, 0xE4, 0x79, 0x3E, 0xA3, 
	0x48, 0x22, 0xDA, 0x05, 0xF0, 0x37, 0x07, 0x00, 0xC6, 0xD8, 
	0xEF, 0x9E, 0xE7, 0x09, 0x29, 0x25, 0x92, 0x24, 0xC1, 0xCB, 
	0xCB, 0x0B, 0xD2, 0x34, 0x9D, 0x6B, 0x90, 0xA6, 0x29, 0xA2, 
	0x28, 0x42, 0x92, 0x24, 0x90, 0x52, 0xC2, 0xF3, 0x3C, 0x01, 
	0xA0, 0x31, 0x77, 0x22, 0x11, 0xBD, 0x1B, 0x0E, 0x87, 0xBF, 
	0x6A, 0xAD, 0xD7, 0xA3, 0x28, 0x22, 0x63, 0x4C, 0xEE, 0x38, 
	0x8E, 0x08, 0x82, 0xA0, 0x02, 0x00, 0xFD, 0x7E, 0x7F, 0x1C, 
	0xC7, 0x31, 0x71, 0xCE, 0xA5, 0xEB, 0xBA, 0x22, 0x0C, 0xC3, 
	0x5B, 0x63, 0xCC, 0xFB, 0xB9, 0x91, 0x9A, 0xCD, 0x66, 0x6C, 
	0x8C, 0x79, 0xAD, 0x94, 0xFA, 0x44, 0x44, 0x6F, 0xA4, 0x94, 
	0xCB, 0x61, 0x18, 0x56, 0x66, 0x59, 0x08, 0xC3, 0xB0, 0x22, 
	0xA5, 0x5C, 0x26, 0xA2, 0x37, 0x4A, 0xA9, 0x4F, 0xC6, 0x98, 
	0xD7, 0xCD, 0x66, 0x33, 0xFE, 0x21, 0x8D, 0xFF, 0xC5, 0xF1, 
	0xF1, 0xF1, 0x15, 0x11, 0xBD, 0xFA, 0xAE, 0x49, 0xEF, 0xE8, 
	0xE8, 0xA8, 0xFE, 0x33, 0xDE, 0x37, 0xC5, 0xD6, 0x80, 0x52, 
	0xC1, 0x78, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 
	0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
};

wxBitmap& cog16_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( cog16_png, sizeof( cog16_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
};


#endif //COG16_PNG_H
