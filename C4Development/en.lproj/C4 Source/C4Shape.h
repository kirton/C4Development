//
//  C4Shape.h
//  Created by Travis Kirton
//


#import <Cocoa/Cocoa.h>

@interface C4Shape : C4Object {
    BOOL useFill;
    BOOL useStroke;
    BOOL checkShape;
    BOOL firstPoint;
    BOOL drawShapesToPDF;
    BOOL isClean;
    
    CGContextRef pdfContext;
    
    int rectMode;
    int ellipseMode;
    
    float strokeWidth;
    
    C4Color		*fillColor;
    C4Color		*strokeColor;
    NSBezierPath	*vertexPath;
    CGFloat			fillColorComponents[4];
    CGFloat			strokeColorComponents[4];
    
    CGMutablePathRef currentShape;
}

#pragma mark Singleton
+(C4Shape *)sharedManager;

/*
 Not too sure what to do...
 Should I make this an object container?
 At the moment it simply draws shapes, but doesn't keep them in memory.
 
 I think I should make it an object into which you can add/compound shapes.
 */

#pragma mark Shapes
+(void)arcWithCenterAt:(NSPoint)p 
                radius:(float)r
            startAngle:(float)startAngle
              endAngle:(float)endAngle;
+(void)circleAt:(NSPoint)p radius:(int)r;
+(void)curveFromPoint:(NSPoint)p1 
              toPoint:(NSPoint)p2 
        controlPoint1:(NSPoint)c1 
        controlPoint2:(NSPoint)c2;
+(void)curveFromX:(int)x1 Y:(int)y1 
              toX:(int)x2 Y:(int)y2 
   controlPoint1X:(int)cx1 Y:(int)cx1 
   controlPoint2X:(int)cx2 Y:(int)cy2;
+(void)ellipseAt:(NSPoint)p size:(NSSize)s;
+(void)ellipseWithXPos:(int)x yPos:(int)y width:(int)w andHeight:(int)h;
+(void)lineFromX:(int)x1 Y:(int)y1 toX:(int)x2 Y:(int)y2;
+(void)lineFromPoint:(NSPoint)p1 toPoint:(NSPoint)p2;
+(void)pointAtX:(int)x1 Y:(int)y1;
+(void)pointAt:(NSPoint)p;
+(void)rectWithXPos:(int)x yPos:(int)y width:(float)w andHeight:(float)h;
+(void)rectAt:(NSPoint)p size:(NSSize)s;
+(void)triangleFromX:(int)x1 Y:(int)y1 toX:(int)x2 Y:(int)y2 toX:(int)x3 Y:(int)y3;
+(void)triangleUsingPoint:(NSPoint)p1 point:(NSPoint)p2 point:(NSPoint)p3;
+(void)quadUsingPoint:(NSPoint)p1 point:(NSPoint)p2 point:(NSPoint)p3 point:(NSPoint)p4;
+(void)quadFromX:(int)x1 Y:(int)y1 
             toX:(int)x2 Y:(int)y2 
             toX:(int)x3 Y:(int)y3 
             toX:(int)x4 Y:(int)y4;

#pragma mark Vertex Shapes
+(void)beginShape;
+(void)endShape;
+(void)closeShape;
+(void)vertexAtX:(int)x Y:(int)y;
+(void)vertexAt:(NSPoint)point;
+(void)vertices:(NSPoint *)vertices length:(NSInteger)length;

#pragma mark Current Shape 
+(void)clearCurrentShape;
+(CGMutablePathRef)currentShape;
+(void)addArcWithCenterAt:(NSPoint)p 
                   radius:(float)r 
               startAngle:(float)startAngle 
                 endAngle:(float)endAngle;
+(void)addCircleAt:(NSPoint)p radius:(int)r;
+(void)addCurveFromPoint:(NSPoint)p1 
                 toPoint:(NSPoint)p2 
           controlPoint1:(NSPoint)c1 
           controlPoint2:(NSPoint)c2;
+(void)addCurveFromX:(int)x1 Y:(int)y1 
                 toX:(int)x2 Y:(int)y2 
      controlPoint1X:(int)cx1 Y:(int)cx1
      controlPoint2X:(int)cx2 Y:(int)cy2;
+(void)addEllipseAt:(NSPoint)p size:(NSSize)s;
+(void)addEllipseWithXPos:(int)x yPos:(int)y width:(int)w andHeight:(int)h;
+(void)addLineFromX:(int)x1 Y:(int)y1 toX:(int)x2 Y:(int)y2;
+(void)addLineFromPoint:(NSPoint)p1 toPoint:(NSPoint)p2;
+(void)addLineTo:(NSPoint)p;
+(void)addLineToX:(int)x Y:(int)y;
+(void)addPointAtX:(int)x1 Y:(int)y1;
+(void)addPointAt:(NSPoint)p;
+(void)addRectWithXPos:(int)x yPos:(int)y width:(float)w andHeight:(float)h;
+(void)addTriangleFromX:(int)x1 Y:(int)y1 toX:(int)x2 Y:(int)y2 toX:(int)x3 Y:(int)y3;
+(void)addTriangleUsingPoint:(NSPoint)p1 point:(NSPoint)p2 point:(NSPoint)p3;
+(void)addQuadUsingPoint:(NSPoint)p1 point:(NSPoint)p2 point:(NSPoint)p3 point:(NSPoint)p4;
+(void)addQuadFromX:(int)x1 Y:(int)y1 toX:(int)x2 Y:(int)y2 toX:(int)x3 Y:(int)y3 toX:(int)x4 Y:(int)y4;

#pragma mark Attributes
+(void)strokeWidth:(float)width;
+(void)rectMode:(int)mode;
+(void)ellipseMode:(int)mode;
+(void)strokeCapMode:(int)mode;
+(void)strokeJoinMode:(int)mode;
+(void)strokeDetail:(float)level;

#pragma mark Colors
+(void)fill;
+(void)fillColor:(C4Color *)color;
+(void)fillColor:(C4Color *)color alpha:(CGFloat)alpha;
+(void)fill:(float)grey;
+(void)fill:(float)grey alpha:(float)alpha;
+(void)fillRed:(float)red green:(float)green blue:(float)blue;
+(void)fillRed:(float)red green:(float)green blue:(float)blue alpha:(float)alpha;
+(void)noFill;
+(void)stroke;
+(void)strokeColor:(C4Color *)color;
+(void)stroke:(float)grey;
+(void)stroke:(float)grey alpha:(float)alpha;
+(void)strokeRed:(float)red green:(float)green blue:(float)blue;
+(void)strokeRed:(float)red green:(float)green blue:(float)blue alpha:(float)a;
+(void)noStroke;

#pragma mark Coordinates
-(void)flipCoordinates;
-(void)nativeCoordinates;

#pragma mark Output
+(BOOL)isClean;
+(void)beginDrawShapesToPDFContext:(CGContextRef)context;
+(void)endDrawShapesToPDFContext;
@end
