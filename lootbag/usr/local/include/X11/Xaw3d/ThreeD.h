/***********************************************************
Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts,
and the Massachusetts Institute of Technology, Cambridge, Massachusetts.
Copyright 1992 by Kaleb Keithley

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation, and that the names of Digital, MIT, or Kaleb
Keithley not be used in advertising or publicity pertaining to distribution
of the software without specific, written prior permission.

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/

#ifndef _XawThreeD_h
#define _XawThreeD_h

/***********************************************************************
 *
 * ThreeD Widget
 *
 ***********************************************************************/

#include <X11/Xmu/Converters.h>

/* Parameters:

 Name                 Class              RepType         Default Value
 ----                 -----              -------         -------------
 shadowWidth	      ShadowWidth          Dimension     2
 topShadowPixel       TopShadowPixel       Pixel         dynamic
 bottomShadowPixel    BottomShadowPixel    Pixel         dynamic
 topShadowContrast    TopShadowContrast    Int           20
 bottomShadowContrast BottomShadowContrast Int           40
 userData             UserData             XtPointer     NULL
 beNiceToColormap     BeNiceToColormap     Boolean       False
 relief               Relief               XtRelief      XtReliefRaised

*/

#define XtNshadowWidth "shadowWidth"
#define XtCShadowWidth "ShadowWidth"
#define XtNtopShadowPixel "topShadowPixel"
#define XtCTopShadowPixel "TopShadowPixel"
#define XtNbottomShadowPixel "bottomShadowPixel"
#define XtCBottomShadowPixel "BottomShadowPixel"
#define XtNtopShadowContrast "topShadowContrast"
#define XtCTopShadowContrast "TopShadowContrast"
#define XtNbottomShadowContrast "bottomShadowContrast"
#define XtCBottomShadowContrast "BottomShadowContrast"
#define XtNbeNiceToColormap "beNiceToColormap"
#define XtCBeNiceToColormap "BeNiceToColormap"
#define XtNbeNiceToColourmap "beNiceToColormap"
#define XtCBeNiceToColourmap "BeNiceToColormap"
#define XtNuserData "userData"
#define XtCUserData "UserData"
#define XtNrelief "relief"
#define XtCRelief "Relief"

typedef enum {
    XtReliefNone,
    XtReliefRaised,
    XtReliefSunken,
    XtReliefRidge,
    XtReliefGroove
} XtRelief;

typedef struct _ThreeDRec *ThreeDWidget;
typedef struct _ThreeDClassRec *ThreeDWidgetClass;

extern WidgetClass threeDWidgetClass;

_XFUNCPROTOBEGIN

extern void Xaw3dComputeTopShadowRGB (
    Widget 		/* new */,
    XColor*		/* xcol_out */
);

extern void Xaw3dComputeBottomShadowRGB (
    Widget		/* new */,
    XColor*		/* xcol_out */
);

extern void _ShadowSurroundedBox (
    Widget,
    ThreeDWidget,
    Position,
    Position,
    Position,
    Position,
    XtRelief,
    Boolean
);

_XFUNCPROTOEND

#endif /* _XawThreeD_h */
