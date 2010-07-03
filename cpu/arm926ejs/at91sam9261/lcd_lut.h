#ifndef _LCDLUT_H
#define _LCDLUT_H 

typedef struct _PALETTEENTRY {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char peFlags;
} PALETTEENTRY, *PPALETTEENTRY;

const PALETTEENTRY rgbPalette[256] =                                               
{                                                                            
    { 0x00, 0x00, 0x00, 0 },    /* 0 Sys Black      gray 0  */               
    { 0x80, 0x00, 0x00, 0 },    /* 1 Sys Dk Red  */                                     
    { 0x00, 0x80, 0x00, 0 },    /* 2 Sys Dk Green  */                                   
    { 0x80, 0x80, 0x00, 0 },    /* 3 Sys Dk Yellow  */                                  
    { 0x00, 0x00, 0x80, 0 },    /* 4 Sys Dk Blue  */                                    
    { 0x80, 0x00, 0x80, 0 },    /* 5 Sys Dk Violet  */                                  
    { 0x00, 0x80, 0x80, 0 },    /* 6 Sys Dk Cyan  */                                    
    { 0xc0, 0xc0, 0xc0, 0 },    /* 7 Sys Lt Grey    gray 192  */                        
    { 0xc0, 0xdc, 0xc0, 0 },    /* 8 Sys 8  */                                          
    { 0xa6, 0xca, 0xf0, 0 },    /* 9 Sys 9 (the first 10 are fixed by Windows)  */      
    { 0x04, 0x04, 0x04, 0 },    /* 10       gray 4  */                                  
    { 0x08, 0x08, 0x08, 0 },    /* 11       gray 8  */                                  
    { 0x0c, 0x0c, 0x0c, 0 },    /* 12       gray 12  */                                 
    { 0x11, 0x11, 0x11, 0 },    /* 13       gray 17  */                                 
    { 0x16, 0x16, 0x16, 0 },    /* 14       gray 22  */                                 
    { 0x1c, 0x1c, 0x1c, 0 },    /* 15       gray 28  */                                 
    { 0x22, 0x22, 0x22, 0 },    /* 16       gray 34  */                                 
    { 0x29, 0x29, 0x29, 0 },    /* 17       gray 41  */                                 
    { 0x55, 0x55, 0x55, 0 },    /* 18 swapped so inversions look good       gray 85  */ 
    { 0x4d, 0x4d, 0x4d, 0 },    /* 19 swapped so inversions look good       gray 77  */ 
    { 0x42, 0x42, 0x42, 0 },    /* 20 swapped so inversions look good       gray 66  */ 
    { 0x39, 0x39, 0x39, 0 },    /* 21 swapped so inversions look good       gray 57  */ 
    { 0xFF, 0x7C, 0x80, 0 },    /* 22 R255 G124 B128  */                                
    { 0xFF, 0x50, 0x50, 0 },    /* 23 R255 G80  B80  */                                 
    { 0xD6, 0x00, 0x93, 0 },    /* 24 R214 G0   B147  */                                
    { 0xCC, 0xEC, 0xFF, 0 },    /* 25 R204 G236 B255  */                                
    { 0xEF, 0xD6, 0xC6, 0 },    /* 26 R239 G214 B198  */                                
    { 0xE7, 0xE7, 0xD6, 0 },    /* 27 R231 G231 B214  */                                
    { 0xAD, 0xA9, 0x90, 0 },    /* 28 R173 G169 B144  */                                
    { 0x33, 0x00, 0x00, 0 },    /* 29  */                                               
    { 0x66, 0x00, 0x00, 0 },    /* 30  */                                               
    { 0x99, 0x00, 0x00, 0 },    /* 31  */                                               
    { 0xcc, 0x00, 0x00, 0 },    /* 32  */                                               
    { 0x00, 0x33, 0x00, 0 },    /* 33  */                                               
    { 0x33, 0x33, 0x00, 0 },    /* 34  */                                               
    { 0x66, 0x33, 0x00, 0 },    /* 35  */                                               
    { 0x99, 0x33, 0x00, 0 },    /* 36  */                                               
    { 0xcc, 0x33, 0x00, 0 },    /* 37  */                                               
    { 0xff, 0x33, 0x00, 0 },    /* 38  */                                               
    { 0x00, 0x66, 0x00, 0 },    /* 39  */                                               
    { 0x33, 0x66, 0x00, 0 },    /* 40  */                                               
    { 0x66, 0x66, 0x00, 0 },    /* 41  */                                               
    { 0x99, 0x66, 0x00, 0 },    /* 42  */                                               
    { 0xcc, 0x66, 0x00, 0 },    /* 43  */                                               
    { 0xff, 0x66, 0x00, 0 },    /* 44  */                                               
    { 0x00, 0x99, 0x00, 0 },    /* 45  */                                               
    { 0x33, 0x99, 0x00, 0 },    /* 46  */                                               
    { 0x66, 0x99, 0x00, 0 },    /* 47  */                                               
    { 0x99, 0x99, 0x00, 0 },    /* 48  */                                               
    { 0xcc, 0x99, 0x00, 0 },    /* 49  */                                               
    { 0xff, 0x99, 0x00, 0 },    /* 50  */                                               
    { 0x00, 0xcc, 0x00, 0 },    /* 51  */                                               
    { 0x33, 0xcc, 0x00, 0 },    /* 52  */                                               
    { 0x66, 0xcc, 0x00, 0 },    /* 53  */                                               
    { 0x99, 0xcc, 0x00, 0 },    /* 54  */                                               
    { 0xcc, 0xcc, 0x00, 0 },    /* 55  */                                               
    { 0xff, 0xcc, 0x00, 0 },    /* 56  */                                               
    { 0x66, 0xff, 0x00, 0 },    /* 57  */                                               
    { 0x99, 0xff, 0x00, 0 },    /* 58  */                                               
    { 0xcc, 0xff, 0x00, 0 },    /* 59  */                                               
    { 0x00, 0x00, 0x33, 0 },    /* 60  */                                               
    { 0x33, 0x00, 0x33, 0 },    /* 61  */                                               
    { 0x66, 0x00, 0x33, 0 },    /* 62  */                                               
    { 0x99, 0x00, 0x33, 0 },    /* 63  */                                               
    { 0xcc, 0x00, 0x33, 0 },    /* 64  */                                               
    { 0xff, 0x00, 0x33, 0 },    /* 65  */                                               
    { 0x00, 0x33, 0x33, 0 },    /* 66  */                                               
    { 0x33, 0x33, 0x33, 0 },    /* 67       gray 51  */                                 
    { 0x66, 0x33, 0x33, 0 },    /* 68  */                                               
    { 0x99, 0x33, 0x33, 0 },    /* 69  */                                               
    { 0xcc, 0x33, 0x33, 0 },    /* 70  */                                               
    { 0xff, 0x33, 0x33, 0 },    /* 71  */                                               
    { 0x00, 0x66, 0x33, 0 },    /* 72  */                                               
    { 0x33, 0x66, 0x33, 0 },    /* 73  */                                               
    { 0x66, 0x66, 0x33, 0 },    /* 74  */                                               
    { 0x99, 0x66, 0x33, 0 },    /* 75  */                                               
    { 0xcc, 0x66, 0x33, 0 },    /* 76  */                                               
    { 0xff, 0x66, 0x33, 0 },    /* 77  */                                               
    { 0x00, 0x99, 0x33, 0 },    /* 78  */                                               
    { 0x33, 0x99, 0x33, 0 },    /* 79  */                                               
    { 0x66, 0x99, 0x33, 0 },    /* 80  */                                               
    { 0x99, 0x99, 0x33, 0 },    /* 81  */                                               
    { 0xcc, 0x99, 0x33, 0 },    /* 82  */                                               
    { 0xff, 0x99, 0x33, 0 },    /* 83  */                                               
    { 0x00, 0xcc, 0x33, 0 },    /* 84  */                                               
    { 0x33, 0xcc, 0x33, 0 },    /* 85  */                                               
    { 0x66, 0xcc, 0x33, 0 },    /* 86  */                                               
    { 0x99, 0xcc, 0x33, 0 },    /* 87  */                                               
    { 0xcc, 0xcc, 0x33, 0 },    /* 88  */                                               
    { 0xff, 0xcc, 0x33, 0 },    /* 89  */                                               
    { 0x33, 0xff, 0x33, 0 },    /* 90  */                                               
    { 0x66, 0xff, 0x33, 0 },    /* 91  */                                               
    { 0x99, 0xff, 0x33, 0 },    /* 92  */                                               
    { 0xcc, 0xff, 0x33, 0 },    /* 93  */                                               
    { 0xff, 0xff, 0x33, 0 },    /* 94  */                                               
    { 0x00, 0x00, 0x66, 0 },    /* 95  */                                               
    { 0x33, 0x00, 0x66, 0 },    /* 96  */                                               
    { 0x66, 0x00, 0x66, 0 },    /* 97  */                                               
    { 0x99, 0x00, 0x66, 0 },    /* 98  */                                               
    { 0xcc, 0x00, 0x66, 0 },    /* 99  */                                               
    { 0xff, 0x00, 0x66, 0 },    /* 100  */                                              
    { 0x00, 0x33, 0x66, 0 },    /* 101  */                                              
    { 0x33, 0x33, 0x66, 0 },    /* 102  */                                              
    { 0x66, 0x33, 0x66, 0 },    /* 103  */                                              
    { 0x99, 0x33, 0x66, 0 },    /* 104  */                                              
    { 0xcc, 0x33, 0x66, 0 },    /* 105  */                                              
    { 0xff, 0x33, 0x66, 0 },    /* 106  */                                              
    { 0x00, 0x66, 0x66, 0 },    /* 107  */                                              
    { 0x33, 0x66, 0x66, 0 },    /* 108  */                                              
    { 0x66, 0x66, 0x66, 0 },    /* 109      gray 102  */                                
    { 0x99, 0x66, 0x66, 0 },    /* 110  */                                              
    { 0xcc, 0x66, 0x66, 0 },    /* 111  */                                              
    { 0x00, 0x99, 0x66, 0 },    /* 112  */                                              
    { 0x33, 0x99, 0x66, 0 },    /* 113  */                                              
    { 0x66, 0x99, 0x66, 0 },    /* 114  */                                              
    { 0x99, 0x99, 0x66, 0 },    /* 115  */                                              
    { 0xcc, 0x99, 0x66, 0 },    /* 116  */                                              
    { 0xff, 0x99, 0x66, 0 },    /* 117  */                                              
    { 0x00, 0xcc, 0x66, 0 },    /* 118  */                                              
    { 0x33, 0xcc, 0x66, 0 },    /* 119  */                                              
    { 0x99, 0xcc, 0x66, 0 },    /* 120  */                                              
    { 0xcc, 0xcc, 0x66, 0 },    /* 121  */                                              
    { 0xff, 0xcc, 0x66, 0 },    /* 122  */                                              
    { 0x00, 0xff, 0x66, 0 },    /* 123  */                                              
    { 0x33, 0xff, 0x66, 0 },    /* 124  */                                              
    { 0x99, 0xff, 0x66, 0 },    /* 125  */                                              
    { 0xcc, 0xff, 0x66, 0 },    /* 126  */                                              
    { 0xff, 0x00, 0xcc, 0 },    /* 127  */                                              
    { 0xcc, 0x00, 0xff, 0 },    /* 128  */                                              
    { 0x00, 0x99, 0x99, 0 },    /* 129  */                                              
    { 0x99, 0x33, 0x99, 0 },    /* 130  */                                              
    { 0x99, 0x00, 0x99, 0 },    /* 131  */                                              
    { 0xcc, 0x00, 0x99, 0 },    /* 132  */                                              
    { 0x00, 0x00, 0x99, 0 },    /* 133  */                                              
    { 0x33, 0x33, 0x99, 0 },    /* 134  */                                              
    { 0x66, 0x00, 0x99, 0 },    /* 135  */                                              
    { 0xcc, 0x33, 0x99, 0 },    /* 136  */                                              
    { 0xff, 0x00, 0x99, 0 },    /* 137  */                                              
    { 0x00, 0x66, 0x99, 0 },    /* 138  */                                              
    { 0x33, 0x66, 0x99, 0 },    /* 139  */                                              
    { 0x66, 0x33, 0x99, 0 },    /* 140  */                                              
    { 0x99, 0x66, 0x99, 0 },    /* 141  */                                              
    { 0xcc, 0x66, 0x99, 0 },    /* 142  */                                              
    { 0xff, 0x33, 0x99, 0 },    /* 143  */                                              
    { 0x33, 0x99, 0x99, 0 },    /* 144  */                                              
    { 0x66, 0x99, 0x99, 0 },    /* 145  */                                              
    { 0x99, 0x99, 0x99, 0 },    /* 146      gray 153  */                                
    { 0xcc, 0x99, 0x99, 0 },    /* 147  */                                              
    { 0xff, 0x99, 0x99, 0 },    /* 148  */                                              
    { 0x00, 0xcc, 0x99, 0 },    /* 149  */                                              
    { 0x33, 0xcc, 0x99, 0 },    /* 150  */                                              
    { 0x66, 0xcc, 0x66, 0 },    /* 151  */                                              
    { 0x99, 0xcc, 0x99, 0 },    /* 152  */                                              
    { 0xcc, 0xcc, 0x99, 0 },    /* 153  */                                              
    { 0xff, 0xcc, 0x99, 0 },    /* 154  */                                              
    { 0x00, 0xff, 0x99, 0 },    /* 155  */                                              
    { 0x33, 0xff, 0x99, 0 },    /* 156  */                                              
    { 0x66, 0xcc, 0x99, 0 },    /* 157  */                                              
    { 0x99, 0xff, 0x99, 0 },    /* 158  */                                              
    { 0xcc, 0xff, 0x99, 0 },    /* 159  */                                              
    { 0xff, 0xff, 0x99, 0 },    /* 160  */                                              
    { 0x00, 0x00, 0xcc, 0 },    /* 161  */                                              
    { 0x33, 0x00, 0x99, 0 },    /* 162  */                                              
    { 0x66, 0x00, 0xcc, 0 },    /* 163  */                                              
    { 0x99, 0x00, 0xcc, 0 },    /* 164  */                                              
    { 0xcc, 0x00, 0xcc, 0 },    /* 165  */                                              
    { 0x00, 0x33, 0x99, 0 },    /* 166  */                                              
    { 0x33, 0x33, 0xcc, 0 },    /* 167  */                                              
    { 0x66, 0x33, 0xcc, 0 },    /* 168  */                                              
    { 0x99, 0x33, 0xcc, 0 },    /* 169  */                                              
    { 0xcc, 0x33, 0xcc, 0 },    /* 170  */                                              
    { 0xff, 0x33, 0xcc, 0 },    /* 171  */                                              
    { 0x00, 0x66, 0xcc, 0 },    /* 172  */                                              
    { 0x33, 0x66, 0xcc, 0 },    /* 173  */                                              
    { 0x66, 0x66, 0x99, 0 },    /* 174  */                                              
    { 0x99, 0x66, 0xcc, 0 },    /* 175  */                                              
    { 0xcc, 0x66, 0xcc, 0 },    /* 176  */                                              
    { 0xff, 0x66, 0x99, 0 },    /* 177  */                                              
    { 0x00, 0x99, 0xcc, 0 },    /* 178  */                                              
    { 0x33, 0x99, 0xcc, 0 },    /* 179  */                                              
    { 0x66, 0x99, 0xcc, 0 },    /* 180  */                                              
    { 0x99, 0x99, 0xcc, 0 },    /* 181  */                                              
    { 0xcc, 0x99, 0xcc, 0 },    /* 182  */                                              
    { 0xff, 0x99, 0xcc, 0 },    /* 183  */                                              
    { 0x00, 0xcc, 0xcc, 0 },    /* 184  */                                              
    { 0x33, 0xcc, 0xcc, 0 },    /* 185  */                                              
    { 0x66, 0xcc, 0xcc, 0 },    /* 186  */                                              
    { 0x99, 0xcc, 0xcc, 0 },    /* 187  */                                              
    { 0xcc, 0xcc, 0xcc, 0 },    /* 188      gray 204  */                                
    { 0xff, 0xcc, 0xcc, 0 },    /* 189  */                                              
    { 0x00, 0xff, 0xcc, 0 },    /* 190  */                                              
    { 0x33, 0xff, 0xcc, 0 },    /* 191  */                                              
    { 0x66, 0xff, 0x99, 0 },    /* 192  */                                              
    { 0x99, 0xff, 0xcc, 0 },    /* 193  */                                              
    { 0xcc, 0xff, 0xcc, 0 },    /* 194  */                                              
    { 0xff, 0xff, 0xcc, 0 },    /* 195  */                                              
    { 0x33, 0x00, 0xcc, 0 },    /* 196  */                                              
    { 0x66, 0x00, 0xff, 0 },    /* 197  */                                              
    { 0x99, 0x00, 0xff, 0 },    /* 198  */                                              
    { 0x00, 0x33, 0xcc, 0 },    /* 199  */                                              
    { 0x33, 0x33, 0xff, 0 },    /* 200  */                                              
    { 0x66, 0x33, 0xff, 0 },    /* 201  */                                              
    { 0x99, 0x33, 0xff, 0 },    /* 202  */                                              
    { 0xcc, 0x33, 0xff, 0 },    /* 203  */                                              
    { 0xff, 0x33, 0xff, 0 },    /* 204  */                                              
    { 0x00, 0x66, 0xff, 0 },    /* 205  */                                              
    { 0x33, 0x66, 0xff, 0 },    /* 206  */                                              
    { 0x66, 0x66, 0xcc, 0 },    /* 207  */                                              
    { 0x99, 0x66, 0xff, 0 },    /* 208  */                                              
    { 0xcc, 0x66, 0xff, 0 },    /* 209  */                                              
    { 0xff, 0x66, 0xcc, 0 },    /* 210  */                                              
    { 0x00, 0x99, 0xff, 0 },    /* 211  */                                              
    { 0x33, 0x99, 0xff, 0 },    /* 212  */                                              
    { 0x66, 0x99, 0xff, 0 },    /* 213  */                                              
    { 0x99, 0x99, 0xff, 0 },    /* 214  */                                              
    { 0xcc, 0x99, 0xff, 0 },    /* 215  */                                              
    { 0xff, 0x99, 0xff, 0 },    /* 216  */                                              
    { 0x00, 0xcc, 0xff, 0 },    /* 217  */                                              
    { 0x33, 0xcc, 0xff, 0 },    /* 218  */                                              
    { 0x66, 0xcc, 0xff, 0 },    /* 219  */                                              
    { 0x99, 0xcc, 0xff, 0 },    /* 220  */                                              
    { 0xcc, 0xcc, 0xff, 0 },    /* 221  */                                              
    { 0xff, 0xcc, 0xff, 0 },    /* 222  */                                              
    { 0x33, 0xff, 0xff, 0 },    /* 223  */                                              
    { 0x66, 0xff, 0xcc, 0 },    /* 224  */                                              
    { 0x99, 0xff, 0xff, 0 },    /* 225  */                                              
    { 0xcc, 0xff, 0xff, 0 },    /* 226  */                                              
    { 0xff, 0x66, 0x66, 0 },    /* 227  */                                              
    { 0x66, 0xff, 0x66, 0 },    /* 228  */                                              
    { 0xff, 0xff, 0x66, 0 },    /* 229  */                                              
    { 0x66, 0x66, 0xff, 0 },    /* 230  */                                              
    { 0xff, 0x66, 0xff, 0 },    /* 231  */                                              
    { 0x66, 0xff, 0xff, 0 },    /* 232  */                                              
    { 0xA5, 0x00, 0x21, 0 },    /* 233      R165 G0 B33  */                             
    { 0x5f, 0x5f, 0x5f, 0 },    /* 234      gray 95  */                                 
    { 0x77, 0x77, 0x77, 0 },    /* 235      gray 119  */                                
    { 0x86, 0x86, 0x86, 0 },    /* 236      gray 134  */                                
    { 0x96, 0x96, 0x96, 0 },    /* 237      gray 150  */                                
    { 0xcb, 0xcb, 0xcb, 0 },    /* 238      gray 203  */                                
    { 0xb2, 0xb2, 0xb2, 0 },    /* 239      gray 178  */                                
    { 0xd7, 0xd7, 0xd7, 0 },    /* 240      gray 215  */                                
    { 0xdd, 0xdd, 0xdd, 0 },    /* 241      gray 221  */                                
    { 0xe3, 0xe3, 0xe3, 0 },    /* 242      gray 227  */                                
    { 0xea, 0xea, 0xea, 0 },    /* 243      gray 234  */                                
    { 0xf1, 0xf1, 0xf1, 0 },    /* 244      gray 241  */                                
    { 0xf8, 0xf8, 0xf8, 0 },    /* 245      gray 248  */                                
    { 0xff, 0xfb, 0xf0, 0 },    /* 246 Sys Reserved  */                                 
    { 0xa0, 0xa0, 0xa4, 0 },    /* 247 Sys Reserved  */                                 
    { 0x80, 0x80, 0x80, 0 },    /* 248 Sys Lt Gray  gray 128  */                        
    { 0xff, 0x00, 0x00, 0 },    /* 249 Sys Red  */                                      
    { 0x00, 0xff, 0x00, 0 },    /* 250 Sys Green  */                                    
    { 0xff, 0xff, 0x00, 0 },    /* 251 Sys Yellow  */                                   
    { 0x00, 0x00, 0xff, 0 },    /* 252 Sys Blue  */                                     
    { 0xff, 0x00, 0xff, 0 },    /* 253 Sys Violet  */                                   
    { 0x00, 0xff, 0xff, 0 },    /* 254 Sys Cyan  */                                     
    { 0xff, 0xff, 0xff, 0 }     /* 255 Sys White     gray 255  */                       
};																	   

#endif
