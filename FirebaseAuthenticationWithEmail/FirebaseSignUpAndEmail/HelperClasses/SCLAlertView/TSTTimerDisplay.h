//
//  TSTTimerDisplay.h
//  TSTAlertView
//
//  Created by Taylor Ryan on 8/18/15.
//  Copyright (c) 2015 AnyKey Entertainment. All rights reserved.
//
//  Taken from https://stackoverflow.com/questions/11783439/uibutton-with-timer

#if defined(__has_feature) && __has_feature(modules)
@import UIKit;
#else
#import <UIKit/UIKit.h>
#endif
#import "TSTButton.h"

@interface TSTTimerDisplay : UIView{
    CGFloat currentAngle;
    CGFloat currentTime;
    CGFloat timerLimit;
    CGFloat radius;
    CGFloat lineWidth;
    NSTimer *timer;
    TSTActionBlock completedBlock;
}

@property CGFloat currentAngle;
@property NSInteger buttonIndex;
@property (nonatomic) UIColor *color;
@property (nonatomic) BOOL reverse;

- (instancetype)initWithOrigin:(CGPoint)origin radius:(CGFloat)r;
- (instancetype)initWithOrigin:(CGPoint)origin radius:(CGFloat)r lineWidth:(CGFloat)width;
- (void)updateFrame:(CGSize)size;
- (void)cancelTimer;
- (void)stopTimer;
- (void)startTimerWithTimeLimit:(int)tl completed:(TSTActionBlock)completed;

@end
